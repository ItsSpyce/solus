--- standard library for Solus Lua
local solus = require('solus')
local path = require('path')
local _require = _G.require

local dependencydir = path.resolve(path.join(_G.rootdirectory or '.', 'pkg'))

---@class Require
---@field resolve fun(name?: string): string
---@field meta fun(name?: string): any
---@field __call fun(name: string): any
local require = {}
require.__call = function(name)
  if not name then error('missing required argument "name"') end
  local builtin = _require(name)
  if builtin then
    return builtin
  end
  local source = debug.getinfo(2, "S").source
  local target
  if path.isrelative(name) then
    local dirname = path.parent(source)
    local filename = path.normalize(path.join(dirname, name))
  end
end

function require.resolve(name)
  local source = debug.getinfo(2, "S").source
  if not name then
    -- return the current module
    return source
  end
  local builtin = _require(name)
  if builtin then
    return string.format('builtin:%s', name)
  end
end

function require.meta(name)
  local source = debug.getinfo(2, "S").source
  if not name then
    -- return the current module
    return {
      name = source,
      source = source
    }
  end
  local builtin = _require(name)
  if builtin then
    return {
      name = name,
      source = string.format('builtin:%s', name)
    }
  end
end

return require
