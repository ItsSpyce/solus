Disposable = class {
	prototype = {
		_disposed = false,
		dispose = abstract(function() end),
		---@param fn function
		---@return nil
		use = function(self, fn)
			if self._disposed then throw(InvalidOperationException()) end
			pcall(fn);
			self:dispose()
		end,
	},
}
function using(disposable, fn)
	try(
		function()
			local result, err = pcall(fn);
		end,
		nil,
		function()
			disposable:dispose()
		end
	)
end
