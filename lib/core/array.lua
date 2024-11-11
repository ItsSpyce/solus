IEnumerable = interface {
  GetEnumerator = function(self)
    return self
  end,
}

---@class Array<T>
---@field private _items table
---@field private _count integer
Array = class.implements
IEnumerable {
  _items = {},
  constructor = function(self, ...)
    self._items = {}
    self._count = 0
    for i = 1, select("#", ...) do
      self._items[i] = select(i, ...)
    end
  end,

  from = static(function(array)
    return Array(table.unpack(array))
  end),

  ---@generic T
  ---@param self Array<T>
  ---@return integer
  length = function(self)
    return #self._items
  end,

  -- override the # call
  ---@generic T
  ---@param self Array<T>
  ---@return integer
  __len = function(self)
    return #self._items
  end,

  push = function(self, ...)
    for i = 1, select("#", ...) do
      self._count = self._count + 1
      self._items[self._count] = select(i, ...)
    end
  end,

  pop = function(self)
    if self._count == 0 then
      return nil
    end
    local item = self._items[self._count]
    self._items[self._count] = nil
    self._count = self._count - 1
    return item
  end,

  shift = function(self)
    if self._count == 0 then
      return nil
    end
    local item = self._items[1]
    for i = 1, self._count - 1 do
      self._items[i] = self._items[i + 1]
    end
    self._items[self._count] = nil
    self._count = self._count - 1
    return item
  end,

  unshift = function(self, ...)
    for i = self._count, 1, -1 do
      self._items[i + select("#", ...)] = self._items[i]
    end
    for i = 1, select("#", ...) do
      self._items[i] = select(i, ...)
    end
    self._count = self._count + select("#", ...)
  end,

  slice = function(self, start, finish)
    local array = Array()
    for i = start, finish do
      array:push(self._items[i])
    end
    return array
  end,

  splice = function(self, start, finish, ...)
    local array = Array()
    for i = start, finish do
      array:push(self._items[i])
    end
    for i = 1, select("#", ...) do
      self._items[start + i - 1] = select(i, ...)
    end
    for i = start + select("#", ...), self._count do
      self._items[i] = self._items[i + finish - start - select("#", ...) + 1]
    end
    for i = self._count, self._count - finish + start + select("#", ...), -1 do
      self._items[i] = nil
    end
    self._count = self._count - finish + start + select("#", ...)
    return array
  end,
}
