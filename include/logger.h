#pragma once

#ifndef SOLUS_LOGGER_H
#define SOLUS_LOGGER_H

#include <string>

namespace solus
{
  class SolusLogger
  {
  public:
    SolusLogger() = default;
    void info(std::string msg);
    void warn(std::string msg);
    void error(std::string msg);
    void debug(std::string msg);
    void trace(std::string msg);
  };
}