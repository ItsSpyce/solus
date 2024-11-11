local function is_greater_than(state, arguments)
  local a = arguments[1]
  local b = arguments[2]
  return a > b
end

local function is_less_than(state, arguments)
  local a = arguments[1]
  local b = arguments[2]
  return a < b
end

local function is_greater_than_or_equal(state, arguments)
  local a = arguments[1]
  local b = arguments[2]
  return a >= b
end

local function is_less_than_or_equal(state, arguments)
  local a = arguments[1]
  local b = arguments[2]
  return a <= b
end

local function is_empty(state, arguments)
  local a = arguments[1]
  return #a == 0
end

local function is_not_empty(state, arguments)
  local a = arguments[1]
  return #a > 0
end

local function has_length(state, arguments)
  local a = arguments[1]
  local length = arguments[2]
  return #a == length
end

assert:register("assertion", "greater_than", is_greater_than, "assertion.greater_than.positive",
  "assertion.greater_than.negative")
assert:register("assertion", "less_than", is_less_than, "assertion.less_than.positive", "assertion.less_than.negative")
assert:register("assertion", "greater_than_or_equal", is_greater_than_or_equal,
  "assertion.greater_than_or_equal.positive", "assertion.greater_than_or_equal.negative")
assert:register("assertion", "less_than_or_equal", is_less_than_or_equal, "assertion.less_than_or_equal.positive",
  "assertion.less_than_or_equal.negative")
