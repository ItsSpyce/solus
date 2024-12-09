#include "modules/imgui/imgui_types.h"

void solus::modules::imgui_module::initialize_types(sol::table& mod) {
  mod.new_usertype<ImVec2>(
      "ImVec2", "new",
      sol::overload([] { return ImVec2{}; },
                    [](float x, float y) { return ImVec2{x, y}; }),
      "x", &ImVec2::x, "y", &ImVec2::y);
}
