local scope_type_NAMESPACE = 0;
local scope_type_CLASS = 1;
local scope_type_ENUM = 2;
local scope_type_INTERFACE = 3;

---@type table<integer, any>
local parentStack = {}
local parentCount = 0


local function def(name, kind, value)
  if parentStack[parentCount][name] then error("Cannot redefine " .. name) end
  parentStack[parentCount][name] = value
end

---@generic T
---@param table T
---@return T
function namespace(table)

end

---@generic T
---@param table T
---@return T
function class(table)

end

function class.inherits(name, base, fn)
  local result = fn({})
  return result
end

---@generic T : table<string, integer>
---@param table T
---@return T
function enum(table)
  -- iterate through the values and make sure they're integers
  for _, value in ipairs(table) do
    if type(value) ~= "number" then error("Enum values must be integers") end
  end
  return table
end

function new(cls)
  if cls.__type ~= scope_type_CLASS then error("Cannot construct something that is not a class") end
  return function(...)
    local instance = setmetatable({}, cls)
    if cls.prototype.constructor then
      cls.prototype.constructor(instance, ...)
    end
    return instance
  end
end

function try(fn, catch, finally)

end

function throw(e)

end
