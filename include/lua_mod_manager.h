#pragma once

#include "lua_mod.h"

namespace solus {
class LuaModManager {
 public:
  void initialize(LUA_STATE, const char *directory);
  void load_mods(LUA_STATE) const;

 private:
  std::vector<LuaMod> mods_{};
};
}  // namespace solus