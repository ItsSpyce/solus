#pragma once

#include "command.h"

namespace solus::commands {
class LuaCommand final : public Command {
 public:
  LuaCommand() : Command("lua") {}

protected:

  void internal_execute() override {
    //
  }
};
}  // namespace solus::commands