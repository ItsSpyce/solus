#pragma once

#include "filesystem.hpp"
#include "sol_ext.hpp"

namespace solus
{
namespace fs = std::filesystem;
using ModuleExportInterface = void (*)(lua_State *, sol::table);

inline std::optional solus_root_directory = FS_JOIN("Data", "SKSE", "Plugins", "Solus");
inline sol::state state;

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

inline bool initialize()
{
  state.open_libraries(sol::lib::base,
                       sol::lib::package,
                       sol::lib::coroutine,
                       sol::lib::string,
                       sol::lib::os,
                       sol::lib::math,
                       sol::lib::table,
                       sol::lib::debug,
                       sol::lib::io,
                       sol::lib::bit32,
                       sol::lib::utf8);

  return true;
}

inline void import_module(ModuleExportInterface module)
{
  const sol::table exports(state);
  module(state, exports);
}

inline bool test_lua()
{
  const auto result = state.safe_script("return true");
  return result.valid() && result.get<bool>();
}

#define EXPORT_MODULE(name) void name##_module(lua_State *L, sol::table exports)
#define EXPORT_FIELD(x)     exports.set(GetLastPartOfDeclaration(#x), x)
#define EXPORT_METHOD(x)    exports.set_function(GetLastPartOfDeclaration(#x), x)
#define EXPORT_TABLE(x)     exports.set(GetLastPartOfDeclaration(#x), x(L))
} // namespace solus