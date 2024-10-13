Disposable = class("Disposable", function(_)
  _.prototype.dispose = function()
    throw(new(NotImplementedException()))
  end
end)

function using(disposable, fn)
  try(
    function()
      fn()
    end, nil,
    function()
      disposable:dispose()
    end)
end
