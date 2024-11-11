#pragma once
#include "solus.hpp"

namespace solus::modules::solus
{

inline LoadModuleRequest find_module(const std::string &name, const std::string &path)
{
  const auto filename = fs::path(path);
  const auto dirname = filename.parent_path();
  auto target_path = fs::path(name);
  LoadModuleRequest request{};
  if (target_path.is_relative())
  {
    target_path = filename.parent_path() / target_path;
    request.status |= kModuleTypeLua;
  }
  else if (target_path.extension() == ".lua")
  {
    request.status |= kModuleTypeLua;
    target_path = dirname / name;
  }
  // check if the module status is kStatusUnknown
  if (request.status & kStatusUnknown)
  {
    if (const auto local_lua_file_to_caller = dirname / (name + ".lua"); FS_EXISTS(local_lua_file_to_caller))
    {
      request.status = kModuleTypeLua & kStatusNone;
      target_path = local_lua_file_to_caller;
    }
  }

  // TODO: finish
  return request;
}

inline sol::lua_value load_module(std::string name, std::string path)
{
  const auto [status, target] = find_module(name, path);

  return sol::nil;
}

inline std::string resolve_module(std::string name, std::string path)
{
  const auto [status, target] = find_module(name, path);
  if (status & kModuleTypeLua)
  {
    return target;
  }
  return fmt::format("<native module '{}'>", target);
}

inline void console_log(std::string message, sol::variadic_args va)
{
  //
}

inline void console_error(std::string message, sol::variadic_args va)
{
  //
}

inline void console_warn(std::string message, sol::variadic_args va)
{
  //
}

inline void console_debug(std::string message, sol::variadic_args va)
{
  //
}

inline sol::table console(lua_State *L)
{
  sol::table console(L);
  console.set_function("log", console_log);
  console.set_function("error", console_error);
  console.set_function("warn", console_warn);
  console.set_function("debug", console_debug);
  return console;
}

EXPORT_MODULE(solus)
{
  EXPORT_METHOD(load_module);
  EXPORT_METHOD(resolve_module);
  EXPORT_TABLE(console);
}
} // namespace solus::modules::solus