function class(args)
	return {
		new = function(...)
			local instance = setmetatable({}, args)
			if instance.constructor then
				instance:constructor(...)
			end
			return instance
		end
	}
end

function class.extends(base)
	return class
end

function class.implements(base)
	return class
end

function namespace(name)
	return function(decl)
		return decl
	end
end

--- Syntax sugar for creating an enum.
---@generic T
---@param table T
---@return T
function enum(table)
	return table
end

--- Parses an enum value.
---@param enum table
---@param value string
---@return integer
---@overload fun(enum: table, value: integer): string
enum.parse = function(enum, value)
	for k, v in pairs(enum) do
		if v == value then
			return k
		elseif k == value then
			return v
		end
	end
end

static = function(decl)
	return decl
end

abstract = function(decl)
	return function(...)
		throw(NotImplementedException())
	end
end

function throw(exception)
	error(exception.message)
end

function new(class)
	return function(...)
		return class:constructor(...)
	end
end
