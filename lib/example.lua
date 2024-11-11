local skse = require("skse")

skse.HandleMessage(skse.kDataLoaded, function(msg)
  skse.log("Data loaded")
end)

return {
  init = function()
    skse.log("init")
  end,
}
