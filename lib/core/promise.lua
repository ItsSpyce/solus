Promise = class {
  prototype = {
    constructor = function(self, fn)
      self._resolvedWith = nil
      self._rejectedWith = nil
      self._fn = fn
      self._then = nil
      self._catch = nil
      self._finally = nil
    end,
    isResolved = function(self)
      return self._resolvedWith ~= nil
    end,
    isRejected = function(self)
      return self._rejectedWith ~= nil
    end,
    hasCompleted = function(self)
      return self:isResolved() or self:isRejected()
    end,
    onResolve = function(self, fn)
      self._then = fn
      return self
    end,
    onReject = function(self, fn)
      self._catch = fn
      return self
    end,
    finally = function(self, fn)
      self._finally = fn
      return self
    end,
  },
  resolve = function(value)
    local promise = Promise()
    promise._resolvedWith = value
    return promise
  end,
  reject = function(err)
    local promise = Promise()
    promise._rejectedWith = err
    return promise
  end,
}
