--- standard library for Solus Lua
local solus = require('solus')
local _require = require

---@class Require
---@arg {string} name
---@return any
---@field resolve fun(name: string): string
---@field meta fun(name?: string): any
local function require(name)
  local builtIn = _require(name)
  if builtIn then
    return builtIn
  end
  local source = debug.getinfo(2, "S").source
  return solus.load_module(name, source)
end

function require.resolve(name)
  local source = debug.getinfo(2, "S").source
  return solus.resolve_module(name, source)
end

function require.meta(name)

end
