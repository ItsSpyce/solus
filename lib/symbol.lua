Symbol = {}

function Symbol.new(name)
  local meta = {}
  return setmetatable({ __name = name, __string = name, __ismeta = true }, meta)
end

function Symbol.isMeta(meta)
  return type(meta) == 'table' and meta.__ismeta
end

Symbol.name = Symbol.new('__name')
Symbol.length = Symbol.new('__len')
Symbol.index = Symbol.new('__index')
Symbol.eq = Symbol.new('__eq')
Symbol.newindex = Symbol.new('__newindex')
Symbol.call = Symbol.new('__call')
Symbol.string = Symbol.new('__string')
Symbol.hash = Symbol.new('__hash')
Symbol.add = Symbol.new('__add')
Symbol.sub = Symbol.new('__sub')
Symbol.mul = Symbol.new('__mul')
Symbol.div = Symbol.new('__div')
Symbol.mod = Symbol.new('__mod')
Symbol.pow = Symbol.new('__pow')
Symbol.unm = Symbol.new('__unm')
Symbol.idiv = Symbol.new('__idiv')
Symbol.band = Symbol.new('__band')
Symbol.bor = Symbol.new('__bor')
Symbol.bxor = Symbol.new('__bxor')
Symbol.bnot = Symbol.new('__bnot')
Symbol.shl = Symbol.new('__shl')
Symbol.shr = Symbol.new('__shr')
Symbol.concat = Symbol.new('__concat')
Symbol.lt = Symbol.new('__lt')
Symbol.le = Symbol.new('__le')
