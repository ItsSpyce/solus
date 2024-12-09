require('class')

describe('class spec', function()
  it('creates an table that has prototype and new', function()
    local FooClass = class {}

    assert.is_function(FooClass.new)
    assert.is_table(FooClass.prototype)
  end)

  it('creates an instance of a class', function()
    local FooClass = class {
      add = function(self, a, b)
        return a + b
      end
    }

    local foo = FooClass.new()
    assert.is_table(foo)
    assert.is_equal(3, foo:add(1, 2))
  end)

  it('overwrites the tostring method', function()
    local FooClass = class {
      tostring = function(self)
        return 'FooClass'
      end
    }

    local foo = FooClass.new()
    assert.is_equal('FooClass', foo:tostring())
  end)

  it('compares two instances of the same class with __eq', function()
    local FooClass = class {
      equals = function(self, other)
        return self == other
      end
    }

    local foo1 = FooClass.new()
    local foo2 = FooClass.new()
    assert.is_false(foo1 == foo2)
  end)
end)
