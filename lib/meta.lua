Meta = {}

function Meta.new(name)
  local meta = {}
  return setmetatable({ __name = name, __string = name, __ismeta = true }, meta)
end

function Meta.isMeta(meta)
  return type(meta) == 'table' and meta.__ismeta
end

Meta.name = Meta.new('__name')
Meta.length = Meta.new('__len')
Meta.index = Meta.new('__index')
Meta.eq = Meta.new('__eq')
Meta.newindex = Meta.new('__newindex')
Meta.call = Meta.new('__call')
Meta.string = Meta.new('__string')
Meta.hash = Meta.new('__hash')
Meta.add = Meta.new('__add')
Meta.sub = Meta.new('__sub')
Meta.mul = Meta.new('__mul')
Meta.div = Meta.new('__div')
Meta.mod = Meta.new('__mod')
Meta.pow = Meta.new('__pow')
Meta.unm = Meta.new('__unm')
Meta.idiv = Meta.new('__idiv')
Meta.band = Meta.new('__band')
Meta.bor = Meta.new('__bor')
Meta.bxor = Meta.new('__bxor')
Meta.bnot = Meta.new('__bnot')
Meta.shl = Meta.new('__shl')
Meta.shr = Meta.new('__shr')
Meta.concat = Meta.new('__concat')
Meta.lt = Meta.new('__lt')
Meta.le = Meta.new('__le')
