require('meta')
local readonly = Meta.new('readonly')

---Checks if a table contains a value
---@param self table
---@param value any
---@return boolean
function table.contains(self, value)
  if type(value) ~= 'table' then
    for _, v in pairs(self) do
      if v == value then return true end
    end
  else
    for _, v in pairs(self) do
      if v == value or table.contains(v, value) then return true end
    end
  end
  return false
end

---Returns the keys of a table
---@param self table
---@return table
function table.keys(self)
  local keys = {}
  for k in pairs(self) do
    keys[#keys + 1] = k
  end
  return keys
end

---Returns the values of a table
---@param self table
---@return table
function table.values(self)
  local values = {}
  for _, v in pairs(self) do
    values[#values + 1] = v
  end
  return values
end

---Clones a table
---@generic T : table
---@param self T
---@param mapperFn? fun(key: any, value: any, accumulator: T): any
---@return T
function table.clone(self, mapperFn)
  mapperFn = mapperFn or function(_, v) return v end
  local new = {}
  for k, v in pairs(self) do
    new[k] = type(v) == 'table' and table.clone(v, mapperFn) or mapperFn(k, v, new)
  end
  return new
end

---Merges two tables
---@generic T1 : table
---@generic T2 : table
---@param t1 T1
---@param t2 T2
---@return T1 | T2
function table.merge(t1, t2)
  local result = table.clone(t1)
  for k, v in pairs(t2) do
    if type(v) == 'table' then
      result[k] = table.merge(result[k] or {}, v)
    else
      result[k] = v
    end
  end

  return result
end

---Returns the difference between two tables
---@generic T1 : table
---@generic T2 : table
---@param t1 T1
---@param t2 T2
---@return T1 | T2
function table.xor(t1, t2)
  local result = {}
  for k, v in pairs(t1) do
    if not t2[k] then
      result[k] = v
    end
  end

  return result
end

---Clears a table and returns how many elements were removed
---@param self table
---@return number
function table.clear(self)
  local count = #self
  for k in pairs(self) do
    self[k] = nil
  end
  return count
end

---Freezes a table
---@generic T : table
---@param self T
---@return T
function table.freeze(self)
  local copy = table.clone(self)
  local meta = getmetatable(self)
  local len = table.clear(self)
  setmetatable(self, {
    __index = meta and setmetatable(copy, meta) or copy,
    __newindex = function()
      error('Cannot modify a frozen table')
    end,
    __metatable = readonly,
    __len = function() return len end,
    __pairs = function() return next, copy end,
  })

  return self
end

---Checks if a table is frozen
---@param self table
---@return boolean
function table.isfrozen(self)
  return getmetatable(self) == readonly
end

---@class Table : table
---@field contains fun(self: Table, value: any): boolean
---@field keys fun(self: Table): table
---@field values fun(self: Table): table
---@field clone fun(self: Table): Table
---@field merge fun(self: Table, t: Table): Table
---@field clear fun(self: Table): number
---@field freeze fun(self: Table): Table
---@field isfrozen fun(self: Table): boolean
function t(arg)
  setmetatable(arg, {
    contains = table.contains,
    keys = table.keys,
    values = table.values,
    clone = table.clone,
    merge = table.merge,
    clear = table.clear,
    freeze = table.freeze,
    isfrozen = table.isfrozen,
  })

  return arg
end
