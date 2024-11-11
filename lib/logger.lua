require "core"

local LogLevel = enum {
  DEBUG = 0,
  INFO = 1,
  WARN = 2,
  ERROR = 3,
}

local Logger = class {
  constructor = function(self)

  end,

  log = function(self, level, message)

  end,

  debug = function(self, message)
    self:log(LogLevel.DEBUG, message)
  end,

  info = function(self, message)
    self:log(LogLevel.INFO, message)
  end,

  warn = function(self, message)
    self:log(LogLevel.WARN, message)
  end,

  error = function(self, message)
    self:log(LogLevel.ERROR, message)
  end,
}

return {
  Logger,
  LogLevel,
  console = Logger.new(),
}
