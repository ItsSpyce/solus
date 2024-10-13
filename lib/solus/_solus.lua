local skse = require("skse")

return namespace("solus", function(_)
  _.handlemessage = function(msg)
    if msg.type == 8 then
    elseif msg.type == 2 then
    elseif msg.type == 0 then
    elseif msg.type == 1 then
    elseif msg.type == 4 then
    end
  end
end)
