--[[
    Pattern matching library

    Usage:
    local match = require('match')

    local myvalue = match(os.getenv('OS'))(
        { 'Windows', function() return "We're on windows" end },
        { function() return "We're not on windows" end }
    )
    print(myvalue)
]]

---@generic TIn, TOut
---@alias Pattern table<integer|TIn, (fun(in: TIn): TOut) | TOut>

---@generic TIn, TOut
---@param val TIn
---@return fun(...: table<integer, Pattern<TIn, TOut>>): TOut
local function match(val)
    return function(...)
        local args = { ... }
        local default = nil
        for i = 1, #args do
            if type(args[i][1]) == 'function' then
                -- If the first argument is a function, it's the default case
                default = args[i][1]
            else
                -- Otherwise, it's a table with the value and the function
                if args[i][1] == val then
                    if type(args[i][2]) == 'function' then
                        return args[i][2](val)
                    end
                    return args[i][2]
                end
            end
        end
        if default then
            return default(val)
        end
    end
end

return match
