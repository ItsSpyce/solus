---Splits a string into a table of strings
---@param str string
---@param sep string
---@return table<integer, string>
local function stringsplit(str, sep)
  local parts = {}
  local iterator = str:gmatch('([^' .. sep .. ']+)')
  for part in iterator do
    table.insert(parts, part)
  end
  return parts
end

return stringsplit
