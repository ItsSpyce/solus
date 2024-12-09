require('tablext')
require('symbol')

local getinfo = debug.getinfo

---@alias Constructor<T> fun(self: T, ...: unknown): nil
---@alias BuiltInProto<T> { constructor: Constructor<T>; tostring: fun(self: any): string; equals: fun(self: T, other: any) }
---@alias Prototype<T> BuiltInProto<T> | T
---@alias Class<T> { new: fun(...: unknown): T; prototype: Prototype<T>, hasOwnProperty: fun(prop: string): boolean; getOwnProperty: fun(prop: string): any; getOwnProperties: fun(): table<string> }
---@alias InstanceOf<T> Prototype<T>

local function noop(...) return nil end

local builtinproto = {
  constructor = noop,
  [Symbol.string] = function(self) return self.__name end,
  [Symbol.name] = 'Class-' .. string.format('%02x', getinfo(2, 'S').short_src:byte(1, 2)),
  tostring = function(self) return tostring(self) end,
  equals = function(self, other) return self == other end,
}

---@generic T : table
---@param proto T
---@return Class<T>
function class(proto)
  local prototype = table.merge(builtinproto, proto)
  local metamethods = getmetatable(prototype) or {}
  if type(metamethods) == 'table' then
    for k, v in pairs(prototype) do
      if type(k) == 'table' and Symbol.isMeta(k) then
        metamethods[k.__name] = v
      end
    end
  end
  local ownproperties = table.xor(table.keys(prototype), table.keys(builtinproto))
  math.randomseed(os.time())
  local c = t {
    __hash = function(self) return self.__name end,
    __metatable = {
      ownproperties = ownproperties,
      metamethods = metamethods
    },
    prototype = prototype,
    new = function(...)
      local instance = table.clone(prototype)
      local instanceid = math.random(0, 2 ^ 32)
      if prototype.constructor then
        prototype.constructor(instance, ...)
      end
      local meta = table.merge(metamethods, {
        __instanceid = instanceid,
        __eq = function(self, other)
          return getmetatable(self).__instanceid == getmetatable(other).__instanceid
        end
      })
      setmetatable(instance, meta)
      return instance
    end,
    hasOwnProperty = function(prop)
      return ownproperties[prop] ~= nil
    end,
    getOwnProperty = function(prop)
      return ownproperties[prop]
    end,
    getOwnProperties = function(prop)
      return ownproperties
    end,
  }

  return c
end
