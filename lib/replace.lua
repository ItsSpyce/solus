---Replaces the first occurence of a substring in a string with another string.
---@param str string
---@param substring string
---@param with string
---@return string
local function first(str, substring, with)
  local i, j = str:find(substring)
  if i then
    return str:sub(1, i - 1) .. with .. str:sub(j + 1)
  else
    return str
  end
end

---Replaces all occurences of a substring in a string with another string.
---@param str string
---@param substring string
---@param with string
---@return string
local function all(str, substring, with)
  local i = 1
  local j = 1
  local k = 1
  local result = ''
  while i do
    i, j = str:find(substring, k)
    if i then
      result = result .. str:sub(k, i - 1) .. with
      k = j + 1
    end
  end
  return result .. str:sub(k)
end

---Replaces the last occurence of a substring in a string with another string.
---@param str any
---@param substring any
---@param with any
local function last(str, substring, with)
  local i, j
  local k = 1
  while true do
    i, j = str:find(substring, k)
    if i then
      k = j + 1
    else
      break
    end
  end
  if k > 1 then
    return str:sub(1, i - 1) .. with .. str:sub(j + 1)
  else
    return str
  end
end

return {
  first = first,
  all = all,
  last = last,
}
