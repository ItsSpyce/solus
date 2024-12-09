#pragma once
#include "solus.hpp"

namespace solus::modules::ui
{
struct SignalValue
{
  sol::lua_value value;
  void signal_set(sol::lua_value value)
  {
    this->value = std::move(value);
  }

  sol::lua_value signal_get()
  {
    return this->value;
  }
};

inline SignalValue signal(sol::this_state ts, sol::lua_value value)
{
  SignalValue clone{ &value };
  // TODO: should we register this somewhere for tracking?
  return clone;
}

inline sol::lua_value render()
{
  return sol::nil;
}

inline void comp(sol::function func)
{
}

inline void traverse_props(sol::table table, sol::table &props)
{
  auto children = props["children"].get_or_create<sol::table>();
  auto named_props = props["named_props"].get_or_create<sol::table>();
  for (const auto &[key, value] : table)
  {
    if (key.get_type() == sol::type::string)
    {
      // named prop
      named_props[key] = value;
    }
    else if (key.get_type() == sol::type::number)
    {
      // child element
      children.add(value);
    }
  }
}

EXPORT_MODULE(ui)
{
  EXPORT_METHOD(signal);
  EXPORT_METHOD(render);
  EXPORT_METHOD(traverse_props);
  state.new_usertype<SignalValue>("SignalValue",
                                  sol::constructors<SignalValue(sol::lua_value)>(),
                                  "value",
                                  sol::property(&SignalValue::signal_get, &SignalValue::signal_set));
}
} // namespace solus::modules::ui