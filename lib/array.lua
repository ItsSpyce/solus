require('class')
require('tablext')
local match = require('match')

---@class ArraySelf
---@field constructor fun(self: ArraySelf, ...: any)
---@field length fun(self: ArraySelf): integer Returns the length of the array
---@field push fun(self: ArraySelf, ...: any): integer Adds one or more elements to the end of an array
---@field pop fun(self: ArraySelf, count?: integer): ArraySelf Removes the last element from an array and returns it
---@field shift fun(self: ArraySelf): any Removes the first element from an array and returns it
---@field unshift fun(self: ArraySelf, ...: any): integer Adds one or more elements to the beginning of an array
---@field slice fun(self: ArraySelf, start: integer, finish: integer): ArraySelf Returns a shallow copy of a portion of an array into a new array object
---@field splice fun(self: ArraySelf, start: integer, finish: integer, ...: any): ArraySelf Changes the contents of an array by removing or replacing existing elements and/or adding new elements
---@field map fun(self: ArraySelf, callback: fun(value: any, index: integer, array: ArraySelf): any): ArraySelf Creates a new array with the results of calling a provided function on every element in the calling array
---@field filter fun(self: ArraySelf, callback: fun(value: any, index: integer, array: ArraySelf): boolean): ArraySelf Creates a new array with all elements that pass the test implemented by the provided function
---@field reduce fun(self: ArraySelf, initialValue: any, callback: fun(accumulator: any, value: any, index: integer, array: ArraySelf): any): any Reduces the array to a single value
---@field forEach fun(self: ArraySelf, callback: fun(value: any, index: integer, array: ArraySelf): nil) Executes a provided function once for each array element
---@field includes fun(self: ArraySelf, value: any): boolean Determines whether an array includes a certain value among its entries, returning true or false as appropriate
---@field indexOf fun(self: ArraySelf, value: any): integer Returns the first index at which a given element can be found in the array, or -1 if it is not present
---@field lastIndexOf fun(self: ArraySelf, value: any): integer Returns the last index at which a given element can be found in the array, or -1 if it is not present
---@field find fun(self: ArraySelf, predicate: fun(value: any, index: integer, array: ArraySelf): boolean): any Returns the value of the first element in the provided array that satisfies the provided testing function
---@field findIndex fun(self: ArraySelf, predicate: fun(value: any, index: integer, array: ArraySelf): boolean): integer Returns the index of the first element in the array that satisfies the provided testing function
---@field some fun(self: ArraySelf, predicate: fun(value: any, index: integer, array: ArraySelf): boolean): boolean Tests whether at least one element in the array passes the test implemented by the provided function
---@field every fun(self: ArraySelf, predicate: fun(value: any, index: integer, array: ArraySelf): boolean): boolean Tests whether all elements in the array pass the test implemented by the provided function
---@field reverse fun(self: ArraySelf): ArraySelf Reverses an array in place
---@field join fun(self: ArraySelf, separator: string): string Joins all elements of an array into a string

local Array
---@type Class<ArraySelf>
Array = class {
  constructor = function(self, ...)
    self.__table = t { ... }
    self.__length = #self.__table or 0
  end,

  [Symbol.index] = function(self, key)
    return match(type(key))(
      { 'number', function()
        return self.__table[key]
      end }
    )
  end,

  [Symbol.newindex] = function(self, key, value)
    if type(key) == 'number' then
      self.__table[key] = value
      if key > self.__length then
        self.__length = key
      end
    end
  end,

  [Symbol.length] = function(self)
    return self.__length
  end,

  length = function(self)
    return self.__length
  end,

  push = function(self, ...)
    local items = { ... }
    for i = 1, #items do
      self.__table[self.__length + i] = items[i]
    end
    self.__length = self.__length + #items
    return self.__length
  end,

  pop = function(self, count)
    count = count or 1
    local new = Array.new()
    for i = 1, count do
      new:push(self.__table[self.__length - i + 1])
      self.__table[self.__length - i + 1] = nil
    end
    self.__length = self.__length - count

    return new
  end,

  shift = function(self)
    local value = self.__table[1]
    for i = 1, self.__length do
      self.__table[i] = self.__table[i + 1]
    end
    self.__length = self.__length - 1
    return value
  end,

  unshift = function(self, ...)
    for i = self.__length, 1, -1 do
      self.__table[i + select('#', ...)] = self.__table[i]
    end
    for i = 1, select('#', ...) do
      self.__table[i] = select(i, ...)
    end
    self.__length = self.__length + select('#', ...)
    return self.__length
  end,

  slice = function(self, start, finish)
    local new = Array.new()
    for i = start, finish do
      new:push(self.__table[i])
    end
    return new
  end,

  splice = function(self, start, finish, ...)
    local new = Array.new()
    for i = start, finish do
      new:push(self.__table[i])
    end
    for i = 1, select('#', ...) do
      self.__table[start + i - 1] = select(i, ...)
    end
    for i = start + select('#', ...), self.__length do
      self.__table[i] = self.__table[i + finish - start - select('#', ...) + 1]
    end
    self.__length = self.__length - finish - start + select('#', ...)
    return new
  end,

  map = function(self, callback)
    local new = Array.new()
    for i = 1, self.__length do
      new:push(callback(self[i], i, self))
    end
    return new
  end,

  filter = function(self, callback)
    local new = Array.new()
    for i = 1, self.__length do
      if callback(self[i], i, self) then
        new:push(self[i])
      end
    end
    return new
  end,

  reduce = function(self, initialValue, callback)
    local accumulator = initialValue
    for i = 1, self.__length do
      accumulator = callback(accumulator, self.__table[i], i, self)
    end
    return accumulator
  end,

  forEach = function(self, callback)
    for i = 1, self.__length do
      callback(self.__table[i], i, self)
    end
  end,

  includes = function(self, value)
    return table.contains(self.__table, value)
  end,

  indexOf = function(self, value)
    for i = 1, self.__length do
      if self.__table[i] == value then
        return i
      end
    end
    return -1
  end,

  lastIndexOf = function(self, value)
    for i = self.__length, 1, -1 do
      if self.__table[i] == value then
        return i
      end
    end
    return -1
  end,

  find = function(self, predicate)
    for i = 1, self.__length do
      if predicate(self.__table[i], i, self) then
        return self.__table[i]
      end
    end
    return nil
  end,

  findIndex = function(self, predicate)
    for i = 1, self.__length do
      if predicate(self.__table[i], i, self) then
        return i
      end
    end
    return -1
  end,

  some = function(self, predicate)
    for i = 1, self.__length do
      if predicate(self.__table[i], i, self) then
        return true
      end
    end
    return false
  end,

  every = function(self, predicate)
    for i = 1, self.__length do
      if not predicate(self.__table[i], i, self) then
        return false
      end
    end
    return true
  end,

  reverse = function(self)
    local new = Array.new()
    for i = self.__length, 1, -1 do
      new:push(self.__table[i])
    end
    return new
  end,

  join = function(self, separator)
    local str = ''
    for i = 1, self.__length do
      str = str .. self.__table[i]
      if i < self.__length then
        str = str .. separator
      end
    end
    return str
  end,

  tostring = function(self)
    return self:join(',')
  end,

  equals = function(self, other)
    if self.__length ~= other.__length then
      return false
    end
    for i = 1, self.__length do
      if self[i] ~= other[i] then
        return false
      end
    end
    return true
  end,
}

return Array
