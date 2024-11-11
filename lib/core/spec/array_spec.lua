require("core.spec.assert")

describe("array spec tests", function()
  it("should create an empty array-like table", function()
    local array = Array()
    assert.is_true(array:count() == 0)
  end)
end)
