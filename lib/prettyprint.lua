local function prettyprint(o)
  if type(o) == 'table' then
    local s = '{ '
    for k, v in pairs(o) do
      if type(k) ~= 'number' then k = '"' .. k .. '"' end
      s = s .. '[' .. k .. '] = ' .. prettyprint(v) .. ','
    end
    return s .. '} '
  else
    return tostring(o)
  end
end

return prettyprint
