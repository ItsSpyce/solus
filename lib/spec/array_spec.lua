local Array = require('array')

describe('array spec', function()
  it('creates an array', function()
    local arr = Array.new(1, 2, 3)
    assert.is_equal(3, #arr)
  end)

  it('pushes an element to the array', function()
    local arr = Array.new()
    arr:push(1)
    assert.is_equal(1, arr[1])
    assert.is_equal(1, #arr)
  end)

  it('pops an element from the array', function()
    local arr = Array.new(1, 2, 3)
    local popped = arr:pop()
    assert.is_equal(1, #popped)
    assert.is_equal(3, popped[1])
    assert.is_equal(2, #arr)
  end)

  it('shifts an element from the array', function()
    local arr = Array.new(1, 2, 3)
    local shifted = arr:shift()
    assert.is_equal(1, shifted)
    assert.is_equal(2, #arr)
  end)

  it('unshifts an element to the array', function()
    local arr = Array.new(1, 2, 3)
    arr:unshift(0)
    assert.is_equal(4, #arr)
    assert.is_equal(0, arr[1])
    assert.is_equal(1, arr[2])
    assert.is_equal(2, arr[3])
    assert.is_equal(3, arr[4])
  end)

  it('gets the length of the array', function()
    local arr = Array.new(1, 2, 3)
    assert.is_equal(3, #arr)
  end)

  it('gets an element from the array', function()
    local arr = Array.new(1, 2, 3)
    assert.is_equal(2, arr[2])
  end)

  it('sets an element to the array', function()
    local arr = Array.new(1, 2, 3)
    arr[2] = 4
    assert.is_equal(4, arr[2])
  end)

  it('iterates over the array', function()
    local arr = Array.new(1, 2, 3)
    local sum = 0
    local calls = 0
    arr:forEach(function(value, index, array)
      sum = sum + value
      calls = calls + 1
    end)
    assert.is_equal(3, calls)
    assert.is_equal(6, sum)
  end)

  it('maps over the array', function()
    local arr = Array.new(1, 2, 3)
    local mapped = arr:map(function(value, index, array)
      return value * 2
    end)
    assert.is_equal(3, #mapped)
    assert.is_equal(2, mapped[1])
    assert.is_equal(4, mapped[2])
    assert.is_equal(6, mapped[3])
  end)

  it('filters the array', function()
    local arr = Array.new(1, 2, 3)
    local filtered = arr:filter(function(value, index, array)
      return value % 2 == 0
    end)
    assert.is_equal(1, #filtered)
    assert.is_equal(2, filtered[1])
  end)

  it('slices the array', function()
    local arr = Array.new(1, 2, 3)
    local sliced = arr:slice(1, 2)
    assert.is_equal(2, #sliced)
    assert.is_equal(1, sliced[1])
    assert.is_equal(2, sliced[2])
  end)

  it('splices the array', function()
    local arr = Array.new(1, 2, 3)
    local spliced = arr:splice(1, 2, 4, 5)
    assert.is_equal(2, #spliced)
    assert.is_equal(1, spliced[1])
    assert.is_equal(2, spliced[2])
    assert.is_equal(3, #arr)
    assert.is_equal(4, arr[1])
    assert.is_equal(5, arr[2])
  end)

  it('reduces the array', function()
    local arr = Array.new(1, 2, 3)
    local reduced = arr:reduce(0, function(accumulator, value)
      return accumulator + value
    end)
    assert.is_equal(6, reduced)
  end)

  it('includes an element in the array', function()
    local arr = Array.new(1, 2, 3)
    assert.is_true(arr:includes(2))
    assert.is_false(arr:includes(4))
  end)

  it('finds an element in the array', function()
    local arr = Array.new(1, 2, 3)
    local found = arr:find(function(value, index, array)
      return value == 2
    end)
    assert.is_equal(2, found)
  end)

  it('finds an element index in the array', function()
    local arr = Array.new(1, 2, 3)
    local found = arr:findIndex(function(value, index, array)
      return value == 2
    end)
    assert.is_equal(2, found)
  end)

  it('joins the array', function()
    local arr = Array.new(1, 2, 3)
    local joined = arr:join(', ')
    assert.is_equal('1, 2, 3', joined)
  end)

  it('reverses the array', function()
    local arr = Array.new(1, 2, 3)
    local reversed = arr:reverse()
    assert.is_equal(3, #reversed)
    assert.is_equal(3, reversed[1])
    assert.is_equal(2, reversed[2])
    assert.is_equal(1, reversed[3])
  end)
end)
