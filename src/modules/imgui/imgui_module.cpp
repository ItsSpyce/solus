#include "modules/imgui/imgui_module.h"

#include "modules/imgui/imgui_enums.h"
#include "modules/imgui/imgui_methods.h"
#include "modules/imgui/imgui_types.h"
#include "modules/imgui/imgui_managers.h"
#include "modules/native_module.h"

namespace solus::modules::imgui_module {
DECLARE_MODULE {
  auto mod = state.create_table();
  // this method will bind functions from #SKSEMenuFramework.h to the Lua state.
  initialize_types(mod);
  initialize_enums(mod);
  initialize_methods(mod);

  mod["ImGuiViewportManager"] = managers::ImGuiViewportManager::initialize(L);
  mod["ImRectManager"] = managers::ImRectManager::initialize(L);
  mod["ImVec2Manager"] = managers::ImVec2Manager::initialize(L);
  mod["ImVec4Manager"] = managers::ImVec4Manager::initialize(L);
  return mod;
}
}  // namespace solus::modules::imgui_module
