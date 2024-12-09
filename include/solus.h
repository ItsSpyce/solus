#pragma once
#include "filesystem.h"

namespace solus
{
using ModuleExportInterface = sol::object (*)(lua_State *) noexcept;

enum LoadModuleStatus : std::uint8_t
{
  // status flags
  kStatusUnknown = 0,
  kStatusNone = 1,
  kStatusLoaded = 2,
  // error flags
  kErrModuleNotFound = 4,
  kErrModuleLoadError = 8,
  // module type flags
  kModuleTypeLua = 64,
  kModuleTypeNative = 128,
};

struct LoadModuleRequest
{
  uint8_t status;
  std::string target;
};

bool initialize(LUA_STATE);
void import_module(ModuleExportInterface module);
bool test_lua();

inline std::optional<std::filesystem::path> solus_root_directory = FS_JOIN("Data", "SKSE", "Plugins", "Solus");
inline sol::state state;
} // namespace solus