#pragma once

#include <sol/sol.hpp>

const char *GetLastPartOfDeclaration(const char *declaration)
{
  const auto str = std::string(declaration);
  const auto lastColon = str.find_last_of(':');
  return lastColon == std::string::npos ? declaration : str.substr(lastColon + 1).c_str();
}

const char *LuaifyDeclaration(const char *declaration)
{
  // convert something like "MyNamespace::MyStruct" to "my_namespace.my_struct"

  std::string luaified;
  for (auto i = 0; declaration[i] != '\0'; i++)
  {
    if (declaration[i] == ':' && declaration[i + 1] == ':')
    {
      luaified += '.';
      i++;
    }
    else if (islower(declaration[i]) && isupper(declaration[i]))
    {
      luaified += '_';
      luaified += declaration[i];
    }
    else
    {
      luaified += declaration[i];
    }
  }
  std::ranges::transform(luaified, luaified.begin(), ::tolower);
  return luaified.c_str();
}
namespace sol
{
template <typename... Args> sol::table enum_table(lua_State *L, Args... args)
{
  auto table = sol::table(L);
  table.set(args...);
  return table;
}

template <typename Ut>
sol::usertype<Ut> usertype_factory(lua_State *L, const char *typeName, void (*builder)(lua_State *, sol::usertype<Ut>))
{
  sol::state_view lua(L);
  auto userType = lua.new_usertype<Ut>(typeName);
  builder(L, userType);
  return userType;
}

inline sol::environment current_env(lua_State *L)
{
  lua_Debug info;
  auto preStackSize = lua_gettop(L);
  if (lua_getstack(L, 1, &info) != 1)
  {
    lua_settop(L, preStackSize);
    return nullptr;
  }
  if (lua_getinfo(L, "fnluS", &info) == 0)
  {
    // failed
    lua_settop(L, preStackSize);
    return nullptr;
  }
  // create a fake function at the top of the stack
  sol::function f(L, -1);
  sol::environment env(sol::env_key, f);
  if (!env.valid())
  {
    lua_settop(L, preStackSize);
    return nullptr;
  }
  return env;
}

#define TYPE_TO_STR(x)     #x
#define USERTYPE           [](auto state, auto usertype)
#define PUBLIC_FIELD(x)    usertype.set(GetLastPartOfDeclaration(#x), x)
#define PUBLIC_METHOD(x)   usertype.set_function(GetLastPartOfDeclaration(#x), x)
#define PUBLIC_READONLY(x) usertype.set(GetLastPartOfDeclaration(#x), sol::readonly(x))
#define C_MODULE           [](auto state, auto exports)

// Lua helper functions
#define LUA_RETURN_ERROR \
  lua_error(L);          \
  return -1

// sol helper functions
#define ENV_STR(x)       env.get<std::string>(x)
#define ENV_INT(x)       env.get<int>(x)
#define ENV_BOOL(x)      env.get<bool>(x)
#define ENV_FLOAT(x)     env.get<float>(x)
#define ENV_DOUBLE(x)    env.get<double>(x)
#define ENV_TABLE(x)     env.get<sol::table>(x)
#define STACK_STR(d)     sol::stack::get<std::string>(L, d)
#define STACK_INT(d)     sol::stack::get<int>(L, d)
#define STACK_BOOL(d)    sol::stack::get<bool>(L, d)
#define STACK_FLOAT(d)   sol::stack::get<float>(L, d)
#define STACK_DOUBLE(d)  sol::stack::get<double>(L, d)
#define STACK_TABLE(d)   sol::stack::get<sol::table>(L, d)
#define OVERRIDE_REQUIRE int override_require(lua_State *L)
}