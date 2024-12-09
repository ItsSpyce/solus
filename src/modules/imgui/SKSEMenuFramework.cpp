#include "modules/native_module.h"

namespace SKSEMenuFramework {

struct LuaWindowInterface {
  Model::WindowInterface* window;

  bool GetIsOpen() const { return window->IsOpen; }

  void SetIsOpen(bool value) { window->IsOpen = value; }
};

LuaWindowInterface Lua_AddWindow(sol::object arg) {
  if (arg.get_type() != sol::type::function) {
    throw sol::error("AddWindow requires a render function");
  }
  static auto fn = arg.as<sol::function>();
  return LuaWindowInterface{AddWindow([] {
    fn();
  })};
}

DECLARE_MODULE {
  auto mod = solus::state.create_table();
  mod["IsInstalled"] = IsInstalled;
  mod["AddSectionItem"] = AddSectionItem;
  mod["AddWindow"] = Lua_AddWindow;
  mod["SetSection"] = SetSection;
  mod.set_function("SetSection", SetSection);
  mod.new_usertype<LuaWindowInterface>(
      "WindowInterface", "IsOpen",
      sol::property(&LuaWindowInterface::GetIsOpen,
                    &LuaWindowInterface::SetIsOpen));
  return mod;
}
}  // namespace SKSEMenuFramework