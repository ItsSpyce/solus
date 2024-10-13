require "core"

return namespace("solus", function ()
  class("logger", function (logger)
    local level = enum("level", function (level)
      level.INFO = 1
      level.WARN = 2
      level.ERROR = 3
      level.TRACE = 4
      level.DEBUG = 5
    end)

    local log = function (level, msg, ...)

    end

    logger.info = function (msg, ...) log(level.INFO, msg, ...) end

    logger.warn = function (msg, ...) log(level.WARN, msg, ...) end

    logger.error = function (msg, ...) log(level.ERROR, msg, ...) end

    logger.trace = function (msg, ...) log(level.TRACE, msg, ...) end

    logger.debug = function (msg, ...) log(level.DEBUG, msg, ...) end
  end)
end)