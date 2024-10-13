Exception = class("Exception", function(_)
  _.prototype.constructor = function(self, message)
    self.message = message
  end
end)

NotImplementedException = class.inherits("NotImplementedException", Exception, function (_, super)
  _.prototype.constructor = function(self)
    super(self, "Not implemented")
  end
end)