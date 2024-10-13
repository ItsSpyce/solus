#include "PCH.h"

#include "engine.h"

namespace solus
{
namespace fs = std::filesystem;

void SolusEngine::Initialize()
{
  lua_.open_libraries(sol::lib::base,
                      sol::lib::package,
                      sol::lib::coroutine,
                      sol::lib::string,
                      sol::lib::os,
                      sol::lib::math,
                      sol::lib::table,
                      sol::lib::debug,
                      sol::lib::bit32,
                      sol::lib::io,
                      sol::lib::ffi);
}

bool SolusEngine::CanCompileTestScript()
{
  lua_.script("function test_compilation () return true end");
  const auto result = lua_["test_compilation"]();
  return result.valid() && result.get<bool>();
}
} // namespace solus