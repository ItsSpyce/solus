#pragma once
#include "solus.hpp"

namespace solus::modules::ui
{
  inline sol::lua_value signal(sol::lua_value value)
  {
    return sol::nil;
  }

  inline sol::lua_value render()
  {
    return sol::nil;
  }

  EXPORT_MODULE(ui)
  {
    EXPORT_METHOD(signal);
    EXPORT_METHOD(render);
  }
  }