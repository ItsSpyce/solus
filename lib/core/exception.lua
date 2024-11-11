Exception = class {
	prototype = {
		constructor = function(self, message)
			self.message = message
		end,
	}
}

NotImplementedException = class.extends(Exception) {
	prototype = {
		constructor = function(self)
			Exception.prototype.constructor(self, "Not implemented")
		end,
	}
}

InvalidOperationException = class.extends(Exception) {
	prototype = {
		constructor = function(self)
			Exception.prototype.constructor(self, "Invalid operation")
		end,
	}
}
