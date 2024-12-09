#include "solus.h"

#include <unordered_map>

#include "modules/imgui/SKSEMenuFramework.h"
#include "modules/imgui/imgui_module.h"

using namespace solus::modules;

std::unordered_map<std::string, solus::ModuleExportInterface> module_map{
    {"imgui", imgui_module::initialize},
    {"sksemenuframework", SKSEMenuFramework::initialize},
};

bool solus::initialize(LUA_STATE) {
  state.open_libraries(sol::lib::base, sol::lib::package, sol::lib::coroutine,
                       sol::lib::string, sol::lib::os, sol::lib::math,
                       sol::lib::table, sol::lib::debug, sol::lib::io,
                       sol::lib::bit32, sol::lib::utf8);
  /*state["_createBindings"] = [](const std::string& module) {
    if (const auto it = module_map.find(module); it != module_map.end()) {
      return it->second(state);
    }
    return sol::make_object(
        state.lua_state(),
        fmt::format("\n\tno bindings for module '{}'", module));
  };
  state.add_package_loader([](const std::string& module) {
    return state.load(fmt::format("return _createBindings('{}')", module));
  });*/
  auto globals = state.globals();
  for (const auto& [name, export_interface] : module_map) {
    const auto exports = export_interface(L);
    globals[name] = exports;
  }

  state.set("rootdirectory", solus_root_directory->string());
  return true;
}

void solus::import_module(ModuleExportInterface module) {
  const auto exports = module(state);
}

bool solus::test_lua() {
  const auto result = state.safe_script("return true");
  return result.valid() && result.get<bool>();
}