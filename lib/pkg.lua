local semver = require('semver')

local rootdirectory = _ENV.rootdirectory or '.'
local pkgCache = {}

local function loadpackage(name)

end

local function resolvepackage(name)

end

local function getpackagemeta(name)

end

return {
  loadpackage = loadpackage,
  resolvepackage = resolvepackage,
  getpackagemeta = getpackagemeta
}
