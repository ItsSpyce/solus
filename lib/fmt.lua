---
---@param ... any
---@return table
local function f(...)
  local topargs = { ... }
  local ret = {}
  setmetatable(ret, {
    __call = function(self, ...)
      return table.concat({ ... }, ' ')
    end
  })
  return ret
end

return f
