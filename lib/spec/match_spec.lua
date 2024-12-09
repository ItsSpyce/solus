describe('match spec', function()
  it('chooses the correct return when the pattern is matched', function()
    local match = require('match')
    local value = match(2 + 2)(
      { 4, function() return 'correct' end },
      { function() return 'incorrect' end }
    )
    assert.are.equal(value, 'correct')
  end)

  it('chooses the fallback return when the pattern is not matched', function()
    local match = require('match')
    local value = match(2 + 3)(
      { 4, function() return 'correct' end },
      { function() return 'incorrect' end }
    )
    assert.are.equal(value, 'incorrect')
  end)
end)
