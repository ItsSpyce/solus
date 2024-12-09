#include "modules/imgui/imgui_managers.h"

#include "modules/native_module.h"
#include "sol_ext.h"

namespace solus::modules::imgui_module::managers::ImVec2Manager {
DECLARE_MODULE {
  auto mod = state.create_table();
  mod.set_function("Create",
                   sol::overload([] { return ImGui::ImVec2Manager::Create(); },
                                 [](float x, float y) {
                                   return ImGui::ImVec2Manager::Create(x, y);
                                 }));
  mod.set_function("Destroy", ImGui::ImVec2Manager::Destroy);
  return mod;
}
}  // namespace solus::modules::imgui_module::managers::ImVec2Manager

namespace solus::modules::imgui_module::managers::ImVec4Manager {
DECLARE_MODULE {
  auto mod = state.create_table();
  mod.set_function(
      "Create", sol::overload([] { return ImGui::ImVec4Manager::Create(); },
                              [](float x, float y, float z, float w) {
                                return ImGui::ImVec4Manager::Create(x, y, z, w);
                              }));
  mod.set_function("Destroy", ImGui::ImVec4Manager::Destroy);
  return mod;
}
}  // namespace solus::modules::imgui_module::managers::ImVec4Manager

namespace solus::modules::imgui_module::managers::ImRectManager {
ImVec2 ImGui_ImRectManager_GetCenter(ImRect *self) {
  ImVec2 center;
  ImGui::ImRectManager::GetCenter(&center, self);
  return center;
}

ImVec2 ImGui_ImRectManager_GetSize(ImRect *self) {
  ImVec2 size;
  ImGui::ImRectManager::GetSize(&size, self);
  return size;
}

ImVec2 ImGui_ImRectManager_GetTL(ImRect *self) {
  ImVec2 tl;
  ImGui::ImRectManager::GetTL(&tl, self);
  return tl;
}

ImVec2 ImGui_ImRectManager_GetTR(ImRect *self) {
  ImVec2 tr;
  ImGui::ImRectManager::GetTR(&tr, self);
  return tr;
}

ImVec2 ImGui_ImRectManager_GetBL(ImRect *self) {
  ImVec2 bl;
  ImGui::ImRectManager::GetBL(&bl, self);
  return bl;
}

ImVec2 ImGui_ImRectManager_GetBR(ImRect *self) {
  ImVec2 br;
  ImGui::ImRectManager::GetBR(&br, self);
  return br;
}

ImVec4 ImGui_ImRectManager_ToVec4(ImRect *self) {
  ImVec4 vec4;
  ImGui::ImRectManager::ToVec4(&vec4, self);
  return vec4;
}
DECLARE_MODULE {
  auto mod = state.create_table();
  mod.set_function("ImRect_Nil", ImGui::ImRectManager::ImRect_Nil);
  mod.set_function("destroy", ImGui::ImRectManager::destroy);
  mod.set_function("ImRect_Vec2", ImGui::ImRectManager::ImRect_Vec2);
  mod.set_function("ImRect_Vec4", ImGui::ImRectManager::ImRect_Vec4);
  mod.set_function("ImRect_Float", ImGui::ImRectManager::ImRect_Float);
  mod.set_function("GetCenter", ImGui_ImRectManager_GetCenter);
  mod.set_function("GetSize", ImGui_ImRectManager_GetSize);
  mod.set_function("GetWidth", ImGui::ImRectManager::GetWidth);
  mod.set_function("GetHeight", ImGui::ImRectManager::GetHeight);
  mod.set_function("GetArea", ImGui::ImRectManager::GetArea);
  mod.set_function("GetTL", ImGui_ImRectManager_GetTL);
  mod.set_function("GetTR", ImGui_ImRectManager_GetTR);
  mod.set_function("GetBL", ImGui_ImRectManager_GetBL);
  mod.set_function("GetBR", ImGui_ImRectManager_GetBR);
  mod.set_function("Contains_Vec2", ImGui::ImRectManager::Contains_Vec2);
  mod.set_function("Contains_Rect", ImGui::ImRectManager::Contains_Rect);
  mod.set_function("ContainsWithPad", ImGui::ImRectManager::ContainsWithPad);
  mod.set_function("Overlaps", ImGui::ImRectManager::Overlaps);
  mod.set_function("Add_Vec2", ImGui::ImRectManager::Add_Vec2);
  mod.set_function("Add_Rect", ImGui::ImRectManager::Add_Rect);
  mod.set_function("Expand_Float", ImGui::ImRectManager::Expand_Float);
  mod.set_function("Expand_Vec2", ImGui::ImRectManager::Expand_Vec2);
  mod.set_function("Translate", ImGui::ImRectManager::Translate);
  mod.set_function("TranslateX", ImGui::ImRectManager::TranslateX);
  mod.set_function("TranslateY", ImGui::ImRectManager::TranslateY);
  mod.set_function("ClipWith", ImGui::ImRectManager::ClipWith);
  mod.set_function("ClipWithFull", ImGui::ImRectManager::ClipWithFull);
  mod.set_function("Floor", ImGui::ImRectManager::Floor);
  mod.set_function("IsInverted", ImGui::ImRectManager::IsInverted);
  mod.set_function("ToVec4", ImGui_ImRectManager_ToVec4);
  return mod;
}
}  // namespace solus::modules::imgui_module::managers::ImRectManager

namespace solus::modules::imgui_module::managers::ImGuiViewportManager {
ImVec2 ImGui_ImGuiViewportManager_GetCenter(ImGuiViewport *viewport) {
  ImVec2 center;
  ImGui::ImGuiViewportManager::GetCenter(&center, viewport);
  return center;
}

DECLARE_MODULE {
  auto mod = state.create_table();
  mod.set_function("GetCenter", ImGui_ImGuiViewportManager_GetCenter);
  return mod;
}
}  // namespace solus::modules::imgui_module::managers::ImGuiViewportManager