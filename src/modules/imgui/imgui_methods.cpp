#include "modules/imgui/imgui_methods.h"

#include "sol_ext.h"

ImVec2 im_vec2_from_table(const sol::table &table) {
  return ImVec2{table.get<float>("x"), table.get<float>("y")};
}

#pragma region ImGuiOutFuncOverrides

ImVec2 ImGui_GetWindowPos() {
  ImVec2 pos;
  ImGui::GetWindowPos(&pos);
  return pos;
}

ImVec2 ImGui_GetWindowSize() {
  ImVec2 size;
  ImGui::GetWindowSize(&size);
  return size;
}

ImVec2 ImGui_GetContentRegionAvail() {
  ImVec2 size;
  ImGui::GetContentRegionAvail(&size);
  return size;
}

ImVec2 ImGui_GetContentRegionMax() {
  ImVec2 size;
  ImGui::GetContentRegionMax(&size);
  return size;
}

ImVec2 ImGui_GetWindowContentRegionMin() {
  ImVec2 size;
  ImGui::GetWindowContentRegionMin(&size);
  return size;
}

ImVec2 ImGui_GetWindowContentRegionMax() {
  ImVec2 size;
  ImGui::GetWindowContentRegionMax(&size);
  return size;
}

ImVec2 ImGui_GetCursorScreenPos() {
  ImVec2 pos;
  ImGui::GetCursorScreenPos(&pos);
  return pos;
}

ImVec2 ImGui_GetCursorPos() {
  ImVec2 pos;
  ImGui::GetCursorPos(&pos);
  return pos;
}

ImVec2 ImGui_GetCursorStartPos() {
  ImVec2 pos;
  ImGui::GetCursorStartPos(&pos);
  return pos;
}

ImVec2 ImGui_GetItemRectMin() {
  ImVec2 pos;
  ImGui::GetItemRectMin(&pos);
  return pos;
}

ImVec2 ImGui_GetItemRectMax() {
  ImVec2 pos;
  ImGui::GetItemRectMax(&pos);
  return pos;
}

ImVec2 ImGui_GetItemRectSize() {
  ImVec2 pos;
  ImGui::GetItemRectSize(&pos);
  return pos;
}

ImVec2 ImGui_CalcTextSize(const char *text, const char *text_end,
                          bool hide_text_after_double_hash, float wrap_width) {
  ImVec2 size;
  ImGui::CalcTextSize(&size, text, text_end, hide_text_after_double_hash,
                      wrap_width);
  return size;
}

ImVec4 ImGui_ColorConvertU32ToFloat4(ImU32 in) {
  ImVec4 out;
  ImGui::ColorConvertU32ToFloat4(&out, in);
  return out;
}

std::tuple<float, float, float> ImGui_ColorConvertRGBtoHSV(float r, float g,
                                                           float b) {
  float h, s, v;
  ImGui::ColorConvertRGBtoHSV(r, g, b, &h, &s, &v);
  return {h, s, v};
}

std::tuple<float, float, float> ImGui_ColorConvertHSVtoRGB(float h, float s,
                                                           float v) {
  float r, g, b;
  ImGui::ColorConvertHSVtoRGB(h, s, v, &r, &g, &b);
  return {r, g, b};
}

ImVec2 ImGui_GetMousePos() {
  ImVec2 pos;
  ImGui::GetMousePos(&pos);
  return pos;
}

ImVec2 ImGui_GetMousePosOnOpeningCurrentPopup() {
  ImVec2 pos;
  ImGui::GetMousePosOnOpeningCurrentPopup(&pos);
  return pos;
}

ImVec2 ImGui_GetMouseDragDelta(int button, float lock_threshold) {
  ImVec2 delta;
  ImGui::GetMouseDragDelta(&delta, button, lock_threshold);
  return delta;
}

ImVec2 ImGui_ImMin(ImVec2 lhs, ImVec2 rhs) {
  ImVec2 min;
  ImGui::ImMin(&min, lhs, rhs);
  return min;
}

ImVec2 ImGui_ImMax(ImVec2 lhs, ImVec2 rhs) {
  ImVec2 max;
  ImGui::ImMax(&max, lhs, rhs);
  return max;
}

ImVec2 ImGui_ImClamp(ImVec2 v, ImVec2 mn, ImVec2 mx) {
  ImVec2 clamped;
  ImGui::ImClamp(&clamped, v, mn, mx);
  return clamped;
}

ImVec2 ImGui_ImLerp(ImVec2 a, ImVec2 b, float t) {
  ImVec2 lerped;
  ImGui::ImLerp(&lerped, a, b, t);
  return lerped;
}

ImVec2 ImGui_ImLerp(ImVec2 a, ImVec2 b, ImVec2 t) {
  ImVec2 lerped;
  ImGui::ImLerp(&lerped, a, b, t);
  return lerped;
}

ImVec4 ImGui_ImLerp(ImVec4 a, ImVec4 b, float t) {
  ImVec4 lerped;
  ImGui::ImLerp(&lerped, a, b, t);
  return lerped;
}

ImVec2 ImGui_ImTrunc(ImVec2 v) {
  ImVec2 trunc;
  ImGui::ImTrunc(&trunc, v);
  return trunc;
}

ImVec2 ImGui_ImFloor(ImVec2 v) {
  ImVec2 floor;
  ImGui::ImFloor(&floor, v);
  return floor;
}

ImVec2 ImGui_ImRotate(ImVec2 v, float cos_a, float cos_b) {
  ImVec2 rotated;
  ImGui::ImRotate(&rotated, v, cos_a, cos_b);
  return rotated;
}

ImVec2 ImGui_ImMul(ImVec2 lhs, ImVec2 rhs) {
  ImVec2 mul;
  ImGui::ImMul(&mul, lhs, rhs);
  return mul;
}

ImVec2 ImGui_ImBezierCubicCalc(ImVec2 p1, ImVec2 p2, ImVec2 p3, ImVec2 p4,
                               float t) {
  ImVec2 calc;
  ImGui::ImBezierCubicCalc(&calc, p1, p2, p3, p4, t);
  return calc;
}

ImVec2 ImGui_ImBezierCubicClosestPoint(ImVec2 p1, ImVec2 p2, ImVec2 p3,
                                       ImVec2 p4, ImVec2 p, int num_segments) {
  ImVec2 calc;
  ImGui::ImBezierCubicClosestPoint(&calc, p1, p2, p3, p4, p, num_segments);
  return calc;
}

ImVec2 ImGui_ImBezierCubicClosestPointCasteljau(ImVec2 p1, ImVec2 p2, ImVec2 p3,
                                                ImVec2 p4, ImVec2 p,
                                                float tess_tol) {
  ImVec2 calc;
  ImGui::ImBezierCubicClosestPointCasteljau(&calc, p1, p2, p3, p4, p, tess_tol);
  return calc;
}

ImVec2 ImGui_ImBezierQuadraticCalc(ImVec2 p1, ImVec2 p2, ImVec2 p3, float t) {
  ImVec2 calc;
  ImGui::ImBezierQuadraticCalc(&calc, p1, p2, p3, t);
  return calc;
}

ImVec2 ImGui_ImLineClosestPoint(ImVec2 a, ImVec2 b, ImVec2 p) {
  ImVec2 calc;
  ImGui::ImLineClosestPoint(&calc, a, b, p);
  return calc;
}

ImVec2 ImGui_ImTriangleClosestPoint(ImVec2 a, ImVec2 b, ImVec2 c, ImVec2 p) {
  ImVec2 calc;
  ImGui::ImTriangleClosestPoint(&calc, a, b, c, p);
  return calc;
}

sol::lua_value ImGui_ImTriangleBarycentricCoords(ImVec2 a, ImVec2 b, ImVec2 c,
                                                 ImVec2 p) {
  float u, v, w;
  ImGui::ImTriangleBarycentricCoords(a, b, c, p, &u, &v, &w);
  std::vector coords = {u, v, w};
  return sol::as_returns(std::move(coords));
}

ImBitVector ImGui_ImBitVectorCreate(int sz) {
  ImBitVector bv;
  ImGui::ImBitVectorCreate(&bv, sz);
  return bv;
}

#pragma endregion
void solus::modules::imgui_module::initialize_methods(sol::table &mod) {
  mod.set_function("GetIO", [] { return ImGui::GetIO(); });
  mod.set_function("GetMainViewport", ImGui::GetMainViewport);
  mod.set_function("GetStyle", ImGui::GetStyle);
  mod.set_function("NewFrame", ImGui::NewFrame);
  mod.set_function("EndFrame", ImGui::EndFrame);
  mod.set_function("Render", ImGui::Render);
  mod.set_function("GetDrawData", ImGui::GetDrawData);
  mod.set_function("ShowDemoWindow", ImGui::ShowDemoWindow);
  mod.set_function("ShowMetricsWindow", ImGui::ShowMetricsWindow);
  mod.set_function("ShowAboutWindow", ImGui::ShowAboutWindow);
  mod.set_function("ShowUserGuide", ImGui::ShowUserGuide);
  mod.set_function("ShowStyleEditor", ImGui::ShowStyleEditor);
  mod.set_function("ShowStyleSelector", ImGui::ShowStyleSelector);
  mod.set_function("ShowFontSelector", ImGui::ShowFontSelector);
  mod.set_function("ShowDebugLogWindow", ImGui::ShowDebugLogWindow);
  mod.set_function("ShowIDStackToolWindow", ImGui::ShowIDStackToolWindow);
  mod.set_function("GetVersion", ImGui::GetVersion);
  mod.set_function("StyleColorsDark", ImGui::StyleColorsDark);
  mod.set_function("StyleColorsLight", ImGui::StyleColorsLight);
  mod.set_function("StyleColorsClassic", ImGui::StyleColorsClassic);
  mod.set_function("Begin", ImGui::Begin);
  mod.set_function("End", ImGui::End);
  mod.set_function(
      "BeginChild",
      sol::overload(sol::resolve<bool(ImGuiID, ImVec2, ImGuiChildFlags,
                                      ImGuiWindowFlags)>(ImGui::BeginChild),
                    sol::resolve<bool(const char *, ImVec2, ImGuiChildFlags,
                                      ImGuiWindowFlags)>(ImGui::BeginChild)));
  mod.set_function("EndChild", ImGui::EndChild);
  mod.set_function("IsWindowAppearing", ImGui::IsWindowAppearing);
  mod.set_function("IsWindowCollapsed", ImGui::IsWindowCollapsed);
  mod.set_function("IsWindowFocused", ImGui::IsWindowFocused);
  mod.set_function("IsWindowHovered", ImGui::IsWindowHovered);
  mod.set_function("GetWindowDrawList", ImGui::GetWindowDrawList);
  mod.set_function("GetWindowDpiScale", ImGui::GetWindowDpiScale);
  mod.set_function("GetWindowPos", ImGui_GetWindowPos);
  mod.set_function("GetWindowSize", ImGui_GetWindowSize);
  mod.set_function("GetWindowWidth", ImGui::GetWindowWidth);
  mod.set_function("GetWindowHeight", ImGui::GetWindowHeight);
  mod.set_function("GetWindowViewport", ImGui::GetWindowViewport);
  mod.set_function("SetNextWindowPos", ImGui::SetNextWindowPos);
  mod.set_function("SetNextWindowSize", ImGui::SetNextWindowSize);
  mod.set_function("SetNextWindowSizeConstraints",
                   ImGui::SetNextWindowSizeConstraints);
  mod.set_function("SetNextWindowContentSize", ImGui::SetNextWindowContentSize);
  mod.set_function("SetNextWindowCollapsed", ImGui::SetNextWindowCollapsed);
  mod.set_function("SetNextWindowFocus", ImGui::SetNextWindowFocus);
  mod.set_function("SetNextWindowScroll", ImGui::SetNextWindowScroll);
  mod.set_function("SetNextWindowBgAlpha", ImGui::SetNextWindowBgAlpha);
  mod.set_function("SetNextWindowViewport", ImGui::SetNextWindowViewport);
  mod.set_function(
      "SetWindowPos",
      sol::overload([](const ImVec2 pos,
                       ImGuiCond cond) { ImGui::SetWindowPos(pos, cond); },
                    [](const char *name, ImVec2 pos, ImGuiCond cond) {
                      ImGui::SetWindowPos(name, pos, cond);
                    },
                    [](ImGuiWindow *window, const ImVec2 pos, ImGuiCond cond) {
                      ImGui::SetWindowPos(window, pos, cond);
                    }));

  mod.set_function(
      "SetWindowSize",
      sol::overload([](const ImVec2 pos,
                       ImGuiCond cond) { ImGui::SetWindowSize(pos, cond); },
                    [](const char *name, ImVec2 pos, ImGuiCond cond) {
                      ImGui::SetWindowSize(name, pos, cond);
                    },
                    [](ImGuiWindow *window, const ImVec2 pos, ImGuiCond cond) {
                      ImGui::SetWindowSize(window, pos, cond);
                    }));
  mod.set_function("SetWindowCollapsed",
                   sol::overload(
                       [](bool collapsed, ImGuiCond cond) {
                         ImGui::SetWindowCollapsed(collapsed, cond);
                       },
                       [](const char *name, bool collapsed, ImGuiCond cond) {
                         ImGui::SetWindowCollapsed(name, collapsed, cond);
                       },
                       [](ImGuiWindow *window, bool collapsed, ImGuiCond cond) {
                         ImGui::SetWindowCollapsed(window, collapsed, cond);
                       }));
  mod.set_function(
      "SetWindowFocus",
      sol::overload([] { ImGui::SetWindowFocus(); },
                    [](const char *name) { ImGui::SetWindowFocus(name); }));
  mod.set_function("SetWindowFontScale", ImGui::SetWindowFontScale);
  mod.set_function("GetContentRegionAvail", ImGui_GetContentRegionAvail);
  mod.set_function("GetContentRegionMax", ImGui_GetContentRegionMax);
  mod.set_function("GetWindowContentRegionMin",
                   ImGui_GetWindowContentRegionMin);
  mod.set_function("GetWindowContentRegionMax",
                   ImGui_GetWindowContentRegionMax);
  mod.set_function("GetScrollX", ImGui::GetScrollX);
  mod.set_function("GetScrollY", ImGui::GetScrollY);
  mod.set_function(
      "SetScrollX",
      sol::overload([](float scroll_x) { ImGui::SetScrollX(scroll_x); },
                    [](ImGuiWindow *window, float scroll_x) {
                      ImGui::SetScrollX(window, scroll_x);
                    }));
  mod.set_function(
      "SetScrollY",
      sol::overload([](float scroll_y) { ImGui::SetScrollY(scroll_y); },
                    [](ImGuiWindow *window, float scroll_y) {
                      ImGui::SetScrollY(window, scroll_y);
                    }));
  mod.set_function("GetScrollMaxX", ImGui::GetScrollMaxX);
  mod.set_function("GetScrollMaxY", ImGui::GetScrollMaxY);
  mod.set_function("SetScrollHereX", ImGui::SetScrollHereX);
  mod.set_function("SetScrollHereY", ImGui::SetScrollHereY);
  mod.set_function(
      "SetScrollFromPosX",
      sol::overload(
          [](float local_x, float center_x_ratio = 0.5f) {
            ImGui::SetScrollFromPosX(local_x, center_x_ratio);
          },
          [](ImGuiWindow *window, float local_x, float center_x_ratio = 0.5f) {
            ImGui::SetScrollFromPosX(window, local_x, center_x_ratio);
          }));
  mod.set_function(
      "SetScrollFromPosY",
      sol::overload(
          [](float local_y, float center_y_ratio = 0.5f) {
            ImGui::SetScrollFromPosY(local_y, center_y_ratio);
          },
          [](ImGuiWindow *window, float local_y, float center_y_ratio = 0.5f) {
            ImGui::SetScrollFromPosY(window, local_y, center_y_ratio);
          }));
  mod.set_function("PushFont", ImGui::PushFont);
  mod.set_function("PopFont", ImGui::PopFont);
  // fill in pushes and pops here
  mod.set_function("GetCursorScreenPos", ImGui_GetCursorScreenPos);
  mod.set_function("GetCursorPos", ImGui_GetCursorPos);
  mod.set_function("SetCursorScreenPos", ImGui::SetCursorScreenPos);
  mod.set_function("GetCursorPosX", ImGui::GetCursorPosX);
  mod.set_function("GetCursorPosY", ImGui::GetCursorPosY);
  mod.set_function("SetCursorPos", ImGui::SetCursorPos);
  mod.set_function("SetCursorPosX", ImGui::SetCursorPosX);
  mod.set_function("SetCursorPosY", ImGui::SetCursorPosY);
  mod.set_function("GetCursorStartPos", ImGui_GetCursorStartPos);
  mod.set_function("Separator", ImGui::Separator);
  mod.set_function("SameLine", ImGui::SameLine);
  mod.set_function("NewLine", ImGui::NewLine);
  mod.set_function("Spacing", ImGui::Spacing);
  mod.set_function("Dummy", ImGui::Dummy);
  mod.set_function("Indent", ImGui::Indent);
  mod.set_function("Unindent", ImGui::Unindent);
  mod.set_function("BeginGroup", ImGui::BeginGroup);
  mod.set_function("EndGroup", ImGui::EndGroup);
  mod.set_function("AlignTextToFramePadding", ImGui::AlignTextToFramePadding);
  mod.set_function("GetTextLineHeight", ImGui::GetTextLineHeight);
  mod.set_function("GetTextLineHeightWithSpacing",
                   ImGui::GetTextLineHeightWithSpacing);
  mod.set_function("GetFrameHeight", ImGui::GetFrameHeight);
  mod.set_function("GetFrameHeightWithSpacing",
                   ImGui::GetFrameHeightWithSpacing);
  mod.set_function("PushID", sol::overload([](int id) { ImGui::PushID(id); },
                                           [](const char *str_id) {
                                             ImGui::PushID(str_id);
                                           }));
  mod.set_function("PopID", ImGui::PopID);
  mod.set_function(
      "GetID",
      sol::overload([](const char *str_id) { return ImGui::GetID(str_id); },
                    [](const char *str_id_begin, const char *str_id_end) {
                      return ImGui::GetID(str_id_begin, str_id_end);
                    },
                    [](const void *ptr_id) { return ImGui::GetID(ptr_id); }));
  mod.set_function("TextUnformatted", ImGui::TextUnformatted);
  mod.set_function("Text", ImGui::Text);
  mod.set_function("TextV", ImGui::TextV);
  mod.set_function("TextColored", ImGui::TextColored);
  mod.set_function("TextColoredV", ImGui::TextColoredV);
  mod.set_function("TextDisabled", ImGui::TextDisabled);
  mod.set_function("TextDisabledV", ImGui::TextDisabledV);
  mod.set_function("TextWrapped", ImGui::TextWrapped);
  mod.set_function("TextWrappedV", ImGui::TextWrappedV);
  mod.set_function("LabelText", ImGui::LabelText);
  mod.set_function("LabelTextV", ImGui::LabelTextV);
  mod.set_function("BulletText", ImGui::BulletText);
  mod.set_function("BulletTextV", ImGui::BulletTextV);
  mod.set_function("SeparatorText", ImGui::SeparatorText);
  mod.set_function("Button", ImGui::Button);
  mod.set_function("SmallButton", ImGui::SmallButton);
  mod.set_function("InvisibleButton", ImGui::InvisibleButton);
  mod.set_function("ArrowButton", ImGui::ArrowButton);
  mod.set_function("Checkbox", ImGui::Checkbox);
  mod.set_function("CheckboxFlags",
                   [](const char *label, int *flags, int flags_value) {
                     return ImGui::CheckboxFlags(label, flags, flags_value);
                   });
  mod.set_function("RadioButton",
                   sol::overload(
                       [](const char *label, bool active) {
                         return ImGui::RadioButton(label, active);
                       },
                       [](const char *label, int *v, int v_button) {
                         return ImGui::RadioButton(label, v, v_button);
                       }));
  mod.set_function("ProgressBar", ImGui::ProgressBar);
  mod.set_function("Bullet", ImGui::Bullet);
  mod.set_function("Image", ImGui::Image);
  mod.set_function("ImageButton", ImGui::ImageButton);
  mod.set_function("BeginCombo", ImGui::BeginCombo);
  mod.set_function("EndCombo", ImGui::EndCombo);
  mod.set_function(
      "Combo",
      sol::overload(
          [](const char *label, int *current_item, const char *const items[],
             int items_count, int height_in_items = -1) {
            return ImGui::Combo(label, current_item, items, items_count,
                                height_in_items);
          },
          [](const char *label, int *current_item,
             const char *items_separated_by_zeros, int height_in_items = -1) {
            return ImGui::Combo(label, current_item, items_separated_by_zeros,
                                height_in_items);
          },
          [](const char *label, int *current_item,
             const char *(*getter)(void *user_data, int idx), void *user_data,
             int items_count, int popup_max_height_in_items = -1) {
            return ImGui::Combo(label, current_item, getter, user_data,
                                items_count, popup_max_height_in_items);
          }));
  mod.set_function("DragFloat", ImGui::DragFloat);
  mod.set_function("DragFloat2", ImGui::DragFloat2);
  mod.set_function("DragFloat3", ImGui::DragFloat3);
  mod.set_function("DragFloat4", ImGui::DragFloat4);
  mod.set_function("DragFloatRange2", ImGui::DragFloatRange2);
  mod.set_function("DragInt", ImGui::DragInt);
  mod.set_function("DragInt2", ImGui::DragInt2);
  mod.set_function("DragInt3", ImGui::DragInt3);
  mod.set_function("DragInt4", ImGui::DragInt4);
  mod.set_function("DragIntRange2", ImGui::DragIntRange2);
  mod.set_function("DragScalar", ImGui::DragScalar);
  mod.set_function("DragScalarN", ImGui::DragScalarN);
  mod.set_function("SliderFloat", ImGui::SliderFloat);
  mod.set_function("SliderFloat2", ImGui::SliderFloat2);
  mod.set_function("SliderFloat3", ImGui::SliderFloat3);
  mod.set_function("SliderFloat4", ImGui::SliderFloat4);
  mod.set_function("SliderAngle", ImGui::SliderAngle);
  mod.set_function("SliderInt", ImGui::SliderInt);
  mod.set_function("SliderInt2", ImGui::SliderInt2);
  mod.set_function("SliderInt3", ImGui::SliderInt3);
  mod.set_function("SliderInt4", ImGui::SliderInt4);
  mod.set_function("SliderScalar", ImGui::SliderScalar);
  mod.set_function("SliderScalarN", ImGui::SliderScalarN);
  mod.set_function("VSliderFloat", ImGui::VSliderFloat);
  mod.set_function("VSliderInt", ImGui::VSliderInt);
  mod.set_function("VSliderScalar", ImGui::VSliderScalar);
  mod.set_function("InputText", ImGui::InputText);
  mod.set_function("InputTextMultiline", ImGui::InputTextMultiline);
  mod.set_function("InputTextWithHint", ImGui::InputTextWithHint);
  mod.set_function("InputFloat", ImGui::InputFloat);
  mod.set_function("InputFloat2", ImGui::InputFloat2);
  mod.set_function("InputFloat3", ImGui::InputFloat3);
  mod.set_function("InputFloat4", ImGui::InputFloat4);
  mod.set_function("InputInt", ImGui::InputInt);
  mod.set_function("InputInt2", ImGui::InputInt2);
  mod.set_function("InputInt3", ImGui::InputInt3);
  mod.set_function("InputInt4", ImGui::InputInt4);
  mod.set_function("InputDouble", ImGui::InputDouble);
  mod.set_function("InputScalar", ImGui::InputScalar);
  mod.set_function("InputScalarN", ImGui::InputScalarN);
  mod.set_function("ColorEdit3", ImGui::ColorEdit3);
  mod.set_function("ColorEdit4", ImGui::ColorEdit4);
  mod.set_function("ColorPicker3", ImGui::ColorPicker3);
  mod.set_function("ColorPicker4", ImGui::ColorPicker4);
  mod.set_function("ColorButton", ImGui::ColorButton);
  mod.set_function("SetColorEditOptions", ImGui::SetColorEditOptions);
  mod.set_function(
      "TreeNode",
      sol::overload(
          [](const char *label) { return ImGui::TreeNode(label); },
          [](const char *str_id, const char *fmt, sol::variadic_args va) {
            EXPAND_VARARGS(args, const char *)
            return ImGui::TreeNode(str_id, fmt, args.data());
          }));
  mod.set_function("TreeNodeEx",
                   sol::overload(
                       [](const char *label, ImGuiTreeNodeFlags flags) {
                         return ImGui::TreeNodeEx(label, flags);
                       },
                       [](const char *str_id, ImGuiTreeNodeFlags flags,
                          const char *fmt, sol::variadic_args va) {
                         EXPAND_VARARGS(args, const char *)
                         return ImGui::TreeNodeEx(str_id, flags, fmt,
                                                  args.data());
                       }));
  mod.set_function("TreePush",
                   [](const char *str_id) { ImGui::TreePush(str_id); });
  mod.set_function("TreePop", ImGui::TreePop);
  mod.set_function("GetTreeNodeToLabelSpacing",
                   ImGui::GetTreeNodeToLabelSpacing);
  mod.set_function("CollapsingHeader",
                   [](const char *label, ImGuiTreeNodeFlags flags = 0) {
                     return ImGui::CollapsingHeader(label, flags);
                   });
  mod.set_function("SetNextItemOpen", ImGui::SetNextItemOpen);
  mod.set_function("Selectable", [](const char *label, bool selected,
                                    ImGuiSelectableFlags flags = 0,
                                    const ImVec2 size = ImVec2(0, 0)) {
    return ImGui::Selectable(label, selected, flags, size);
  });
  mod.set_function("BeginListBox", ImGui::BeginListBox);
  mod.set_function("EndListBox", ImGui::EndListBox);
  mod.set_function("ListBox", [](const char *label, int *current_item,
                                 const char *const items[], int items_count,
                                 int height_in_items = -1) {
    return ImGui::ListBox(label, current_item, items, items_count,
                          height_in_items);
  });
  mod.set_function(
      "Value",
      sol::overload(
          [](const char *prefix, bool b) { ImGui::Value(prefix, b); },
          [](const char *prefix, int v) { ImGui::Value(prefix, v); },
          [](const char *prefix, float v, const char *float_format = NULL) {
            ImGui::Value(prefix, v, float_format);
          }));
  mod.set_function("BeginMenuBar", ImGui::BeginMenuBar);
  mod.set_function("EndMenuBar", ImGui::EndMenuBar);
  mod.set_function("BeginMainMenuBar", ImGui::BeginMainMenuBar);
  mod.set_function("EndMainMenuBar", ImGui::EndMainMenuBar);
  mod.set_function("BeginMenu",
                   [](const char *text, sol::optional<bool> enabled) {
                     return ImGui::BeginMenu(text, enabled.value_or(true));
                   });
  mod.set_function("EndMenu", ImGui::EndMenu);
  mod.set_function("MenuItem", [](const char *label,
                                  sol::optional<std::string> maybe_shortcut,
                                  sol::optional<bool> maybe_selected,
                                  sol::optional<bool> maybe_enabled) {
    const auto shortcut = maybe_shortcut.has_value() ? maybe_shortcut->c_str() : NULL;
    const auto selected = maybe_selected.value_or(false);
    const auto enabled = maybe_enabled.value_or(true);
    return ImGui::MenuItem(label, shortcut, selected, enabled);
  });
  mod.set_function("BeginTooltip", ImGui::BeginTooltip);
  mod.set_function("EndTooltip", ImGui::EndTooltip);
  mod.set_function("SetTooltip", ImGui::SetTooltip);
  mod.set_function("BeginItemTooltip", ImGui::BeginItemTooltip);
  mod.set_function("SetItemTooltip",
                   [](const char *fmt, sol::variadic_args va) {
                     EXPAND_VARARGS(args, const char *)
                     return ImGui::SetItemTooltip(fmt, args.data());
                   });
  mod.set_function("BeginPopup", ImGui::BeginPopup);
  mod.set_function("BeginPopupModal", ImGui::BeginPopupModal);
  mod.set_function("EndPopup", ImGui::EndPopup);
  mod.set_function("OpenPopup",
                   [](const char *str_id) { return ImGui::OpenPopup(str_id); });
  mod.set_function("OpenPopupOnItemClick", ImGui::OpenPopupOnItemClick);
  mod.set_function("CloseCurrentPopup", ImGui::CloseCurrentPopup);
  mod.set_function("BeginPopupContextItem", ImGui::BeginPopupContextItem);
  mod.set_function("BeginPopupContextWindow", ImGui::BeginPopupContextWindow);
  mod.set_function("IsPopupOpen",
                   [](const char *str_id, ImGuiPopupFlags flags = 0) {
                     return ImGui::IsPopupOpen(str_id, flags);
                   });
  mod.set_function("BeginTable", ImGui::BeginTable);
  mod.set_function("EndTable", ImGui::EndTable);
  mod.set_function("TableNextRow", ImGui::TableNextRow);
  mod.set_function("TableNextColumn", ImGui::TableNextColumn);
  mod.set_function("TableSetColumnIndex", ImGui::TableSetColumnIndex);
  mod.set_function("TableSetupColumn", ImGui::TableSetupColumn);
  mod.set_function("TableSetupScrollFreeze", ImGui::TableSetupScrollFreeze);
  mod.set_function("TableHeadersRow", ImGui::TableHeadersRow);
  mod.set_function("TableHeader", ImGui::TableHeader);
  mod.set_function("TableAngledHeadersRow", ImGui::TableAngledHeadersRow);
  mod.set_function("TableGetSortSpecs", ImGui::TableGetSortSpecs);
  mod.set_function("TableGetColumnCount", ImGui::TableGetColumnCount);
  mod.set_function("TableGetColumnIndex", ImGui::TableGetColumnIndex);
  mod.set_function("TableGetRowIndex", ImGui::TableGetRowIndex);
  mod.set_function(
      "TableGetColumnName",
      sol::overload(
          [](int column_n = -1) { return ImGui::TableGetColumnName(column_n); },
          [](const ImGuiTable *table, int column_n = -1) {
            return ImGui::TableGetColumnName(table, column_n);
          }));
  mod.set_function("TableGetColumnFlags", ImGui::TableGetColumnFlags);
  mod.set_function("TableSetColumnEnabled", ImGui::TableSetColumnEnabled);
  mod.set_function("TableSetBgColor", ImGui::TableSetBgColor);
  mod.set_function("Columns", ImGui::Columns);
  mod.set_function("NextColumn", ImGui::NextColumn);
  mod.set_function("GetColumnIndex", ImGui::GetColumnIndex);
  mod.set_function("GetColumnWidth", ImGui::GetColumnWidth);
  mod.set_function("SetColumnWidth", ImGui::SetColumnWidth);
  mod.set_function("GetColumnOffset", ImGui::GetColumnOffset);
  mod.set_function("SetColumnOffset", ImGui::SetColumnOffset);
  mod.set_function("GetColumnsCount", ImGui::GetColumnsCount);
  mod.set_function("BeginTabBar", ImGui::BeginTabBar);
  mod.set_function("EndTabBar", ImGui::EndTabBar);
  mod.set_function("BeginTabItem", ImGui::BeginTabItem);
  mod.set_function("EndTabItem", ImGui::EndTabItem);
  mod.set_function("TabItemButton", ImGui::TabItemButton);
  mod.set_function("SetTabItemClosed", ImGui::SetTabItemClosed);
  mod.set_function("BeginDragDropSource", ImGui::BeginDragDropSource);
  mod.set_function(
      "SetDragDropPayload",
      [](const char *type, sol::lua_value data, ImGuiCond cond = 0) {
        const void *ref = &data;
        return ImGui::SetDragDropPayload(type, ref, sizeof(ref), cond);
      });
  mod.set_function("EndDragDropSource", ImGui::EndDragDropSource);
  mod.set_function("BeginDragDropTarget", ImGui::BeginDragDropTarget);
  mod.set_function("AcceptDragDropPayload", ImGui::AcceptDragDropPayload);
  mod.set_function("EndDragDropTarget", ImGui::EndDragDropTarget);
  mod.set_function("GetDragDropPayload", [] {
    const auto payload = ImGui::GetDragDropPayload();
    sol::lua_value value(payload->Data);
    return sol::meta::tuplefy(value, payload);
  });
  mod.set_function("BeginDisabled", ImGui::BeginDisabled);
  mod.set_function("EndDisabled", ImGui::EndDisabled);
  mod.set_function("PushClipRect", ImGui::PushClipRect);
  mod.set_function("PopClipRect", ImGui::PopClipRect);
  mod.set_function("SetItemDefaultFocus", ImGui::SetItemDefaultFocus);
  mod.set_function("SetKeyboardFocusHere", ImGui::SetKeyboardFocusHere);
  mod.set_function("SetNextItemAllowOverlap", ImGui::SetNextItemAllowOverlap);
  mod.set_function("IsItemHovered", ImGui::IsItemHovered);
  mod.set_function("IsItemActive", ImGui::IsItemActive);
  mod.set_function("IsItemFocused", ImGui::IsItemFocused);
  mod.set_function("IsItemClicked", ImGui::IsItemClicked);
  mod.set_function("IsItemVisible", ImGui::IsItemVisible);
  mod.set_function("IsItemEdited", ImGui::IsItemEdited);
  mod.set_function("IsItemActivated", ImGui::IsItemActivated);
  mod.set_function("IsItemDeactivated", ImGui::IsItemDeactivated);
  mod.set_function("IsItemDeactivatedAfterEdit",
                   ImGui::IsItemDeactivatedAfterEdit);
  mod.set_function("IsItemToggledOpen", ImGui::IsItemToggledOpen);
  mod.set_function("IsAnyItemHovered", ImGui::IsAnyItemHovered);
  mod.set_function("IsAnyItemActive", ImGui::IsAnyItemActive);
  mod.set_function("IsAnyItemFocused", ImGui::IsAnyItemFocused);
  mod.set_function("GetItemID", ImGui::GetItemID);
  mod.set_function("GetItemRectMin", ImGui_GetItemRectMin);
  mod.set_function("GetItemRectMax", ImGui_GetItemRectMax);
  mod.set_function("GetItemRectSize", ImGui_GetItemRectSize);
  mod.set_function(
      "GetBackgroundDrawList",
      sol::overload([] { return ImGui::GetBackgroundDrawList(); },
                    [](ImGuiViewport *viewport) {
                      return ImGui::GetBackgroundDrawList(viewport);
                    }));
  mod.set_function(
      "GetForegroundDrawList",
      sol::overload([] { return ImGui::GetForegroundDrawList(); },
                    [](ImGuiViewport *viewport) {
                      return ImGui::GetForegroundDrawList(viewport);
                    }));
  mod.set_function(
      "IsRectVisible",
      sol::overload([](ImVec2 size) { return ImGui::IsRectVisible(size); },
                    [](ImVec2 rect_min, ImVec2 rect_max) {
                      return ImGui::IsRectVisible(rect_min, rect_max);
                    }));
  mod.set_function("GetTime", ImGui::GetTime);
  mod.set_function("GetFrameCount", ImGui::GetFrameCount);
  mod.set_function("GetDrawListSharedData", ImGui::GetDrawListSharedData);
  mod.set_function("GetStyleColorName", ImGui::GetStyleColorName);
  mod.set_function("SetStateStorage", ImGui::SetStateStorage);
  mod.set_function("GetStateStorage", ImGui::GetStateStorage);
  mod.set_function("CalcTextSize", ImGui_CalcTextSize);
  mod.set_function("ColorConvertU32ToFloat4", ImGui_ColorConvertU32ToFloat4);
  mod.set_function("ColorConvertFloat4ToU32", ImGui::ColorConvertFloat4ToU32);
  mod.set_function("ColorConvertRGBtoHSV", ImGui_ColorConvertRGBtoHSV);
  mod.set_function("ColorConvertHSVtoRGB", ImGui_ColorConvertHSVtoRGB);
  mod.set_function(
      "IsKeyDown",
      sol::overload([](ImGuiKey key) { return ImGui::IsKeyDown(key); },
                    [](ImGuiKey key, ImGuiID owner_id) {
                      return ImGui::IsKeyDown(key, owner_id);
                    }));
  mod.set_function(
      "IsKeyPressed",
      sol::overload(
          [](ImGuiKey key, bool repeat = true) {
            return ImGui::IsKeyPressed(key, repeat);
          },
          [](ImGuiKey key, ImGuiInputFlags flags, ImGuiID owner_id) {
            return ImGui::IsKeyPressed(key, flags, owner_id);
          }));
  mod.set_function(
      "IsKeyReleased",
      sol::overload([](ImGuiKey key) { return ImGui::IsKeyReleased(key); },
                    [](ImGuiKey key, ImGuiID owner_id) {
                      return ImGui::IsKeyReleased(key, owner_id);
                    }));
  mod.set_function(
      "IsKeyChordPressed",
      sol::overload(
          [](ImGuiKeyChord key) { return ImGui::IsKeyChordPressed(key); },
          [](ImGuiKeyChord key, ImGuiInputFlags flags, ImGuiID owner_id) {
            return ImGui::IsKeyChordPressed(key, flags, owner_id);
          }));
  mod.set_function("GetKeyPressedAmount", ImGui::GetKeyPressedAmount);
  mod.set_function("GetKeyName", ImGui::GetKeyName);
  mod.set_function("SetNextFrameWantCaptureKeyboard",
                   ImGui::SetNextFrameWantCaptureKeyboard);
  mod.set_function(
      "Shortcut",
      sol::overload(
          [](ImGuiKeyChord key_chord, ImGuiInputFlags flags = 0) {
            return ImGui::Shortcut(key_chord, flags);
          },
          [](ImGuiKeyChord key_chord, ImGuiInputFlags flags, ImGuiID owner_id) {
            return ImGui::Shortcut(key_chord, flags, owner_id);
          }));
  mod.set_function("SetNextItemShortcut", ImGui::SetNextItemShortcut);
  mod.set_function(
      "IsMouseDown",
      sol::overload(
          [](ImGuiMouseButton button) { return ImGui::IsMouseDown(button); },
          [](ImGuiMouseButton button, ImGuiID owner_id) {
            return ImGui::IsMouseDown(button, owner_id);
          }));
  mod.set_function(
      "IsMouseClicked",
      sol::overload(
          [](ImGuiMouseButton button, bool repeat = false) {
            return ImGui::IsMouseClicked(button, repeat);
          },
          [](ImGuiMouseButton button, ImGuiInputFlags flags, ImGuiID owner_id) {
            return ImGui::IsMouseClicked(button, flags, owner_id);
          }));
  mod.set_function("IsMouseReleased",
                   sol::overload(
                       [](ImGuiMouseButton button) {
                         return ImGui::IsMouseReleased(button);
                       },
                       [](ImGuiMouseButton button, ImGuiID owner_id) {
                         return ImGui::IsMouseReleased(button, owner_id);
                       }));
  mod.set_function("IsMouseDoubleClicked",
                   sol::overload(
                       [](ImGuiMouseButton button) {
                         return ImGui::IsMouseDoubleClicked(button);
                       },
                       [](ImGuiMouseButton button, bool repeat = false) {
                         return ImGui::IsMouseDoubleClicked(button, repeat);
                       }));
  mod.set_function("IsMouseHoveringRect", ImGui::IsMouseHoveringRect);
  mod.set_function("GetMouseClickedCount", ImGui::GetMouseClickedCount);
  mod.set_function("IsMousePosValid", ImGui::IsMousePosValid);
  mod.set_function("IsAnyMouseDown", ImGui::IsAnyMouseDown);
  mod.set_function("GetMousePos", ImGui_GetMousePos);
  mod.set_function("GetMousePosOnOpeningCurrentPopup",
                   ImGui_GetMousePosOnOpeningCurrentPopup);
  mod.set_function("IsMouseDragging", ImGui::IsMouseDragging);
  mod.set_function("GetMouseDragDelta", ImGui_GetMouseDragDelta);
  mod.set_function("ResetMouseDragDelta", ImGui::ResetMouseDragDelta);
  mod.set_function("GetMouseCursor", ImGui::GetMouseCursor);
  mod.set_function("SetMouseCursor", ImGui::SetMouseCursor);
  mod.set_function("SetNextFrameWantCaptureMouse",
                   ImGui::SetNextFrameWantCaptureMouse);
  mod.set_function("GetClipboardText", ImGui::GetClipboardText);
  mod.set_function("SetClipboardText", ImGui::SetClipboardText);
  mod.set_function("LoadIniSettingsFromDisk", ImGui::LoadIniSettingsFromDisk);
  mod.set_function("LoadIniSettingsFromMemory",
                   ImGui::LoadIniSettingsFromMemory);
  mod.set_function("SaveIniSettingsToDisk", ImGui::SaveIniSettingsToDisk);
  mod.set_function("SaveIniSettingsToMemory", ImGui::SaveIniSettingsToMemory);
  mod.set_function("DebugTextEncoding", ImGui::DebugTextEncoding);
  mod.set_function("DebugFlashStyleColor", ImGui::DebugFlashStyleColor);
  mod.set_function("DebugStartItemPicker", ImGui::DebugStartItemPicker);
  mod.set_function("DebugCheckVersionAndDataLayout",
                   ImGui::DebugCheckVersionAndDataLayout);
  mod.set_function("SetAllocatorFunctions", ImGui::SetAllocatorFunctions);
  mod.set_function("GetAllocatorFunctions", ImGui::GetAllocatorFunctions);
  mod.set_function("MemAlloc", ImGui::MemAlloc);
  mod.set_function("MemFree",
                   [](sol::lua_value value) { ImGui::MemFree(&value); });
  mod.set_function("GetPlatformIO", ImGui::GetPlatformIO);
  mod.set_function("UpdatePlatformWindow", ImGui::UpdatePlatformWindows);
  mod.set_function("RenderPlatformWindowsDefault",
                   [](sol::lua_value platform_renderer_arg,
                      sol::lua_value renderer_renderer_arg) {
                     ImGui::RenderPlatformWindowsDefault(
                         &platform_renderer_arg, &renderer_renderer_arg);
                   });
  mod.set_function("DestroyPlatformWindows", ImGui::DestroyPlatformWindows);
  mod.set_function("FindViewportByID", ImGui::FindViewportByID);

  // more or less useless functions in Lua but might be useful to someone
  mod.set_function("ImHashData", [](sol::lua_value args, ImGuiID seed) {
    void *data = &args;
    return ImGui::ImHashData(data, sizeof(data), seed);
  });
  mod.set_function("ImHashStr", ImGui::ImHashStr);
  mod.set_function("ImQsort", ImGui::ImQsort);
  mod.set_function("ImAlphaBlendColors", ImGui::ImAlphaBlendColors);
  mod.set_function("ImIsPowerOfTwo", [](sol::lua_value value) {
    return ImGui::ImIsPowerOfTwo(value.as<ImU64>());
  });
  mod.set_function("ImUpperPowerOfTwo", ImGui::ImUpperPowerOfTwo);
  mod.set_function("ImStricmp", ImGui::ImStricmp);
  mod.set_function("ImStrnicmp", ImGui::ImStrnicmp);
  mod.set_function("ImStrncpy", ImGui::ImStrncpy);
  mod.set_function("ImStrdup", ImGui::ImStrdup);
  mod.set_function("ImStrdupcpy", ImGui::ImStrdupcpy);
  mod.set_function("ImStrchrRange", ImGui::ImStrchrRange);
  mod.set_function("ImStreolRange", ImGui::ImStreolRange);
  mod.set_function("ImStristr", ImGui::ImStristr);
  mod.set_function("ImStrTrimBlanks", ImGui::ImStrTrimBlanks);
  mod.set_function("ImStrSkipBlank", ImGui::ImStrSkipBlank);
  mod.set_function("ImStrbolW", ImGui::ImStrbolW);
  mod.set_function("ImToUpper", ImGui::ImToUpper);
  mod.set_function("ImCharIsBlankA", ImGui::ImCharIsBlankA);
  mod.set_function("ImCharIsBlankW", ImGui::ImCharIsBlankW);
  mod.set_function(
      "ImFormatString",
      [](char *buf, size_t buf_size, const char *fmt, sol::variadic_args va) {
        EXPAND_VARARGS(args, const char *)
        return ImGui::ImFormatString(buf, buf_size, fmt, args.data());
      });
  mod.set_function("ImFormatStringToTempBuffer", [] { return sol::nil; });
  mod.set_function("ImParseFormatFindStart", ImGui::ImParseFormatFindStart);
  mod.set_function("ImParseFormatFindEnd", ImGui::ImParseFormatFindEnd);
  mod.set_function("ImParseFormatSanitizeForPrinting",
                   ImGui::ImParseFormatSanitizeForPrinting);
  mod.set_function("ImParseFormatSanitizeForScanning",
                   ImGui::ImParseFormatSanitizeForScanning);
  mod.set_function("ImParseFormatPrecision", ImGui::ImParseFormatPrecision);
  mod.set_function("ImTextCharToUtf8", ImGui::ImTextCharToUtf8);
  mod.set_function("ImTextStrToUtf8", ImGui::ImTextStrToUtf8);
  mod.set_function("ImTextCharFromUtf8", ImGui::ImTextCharFromUtf8);
  mod.set_function("ImTextStrFromUtf8", ImGui::ImTextStrFromUtf8);
  mod.set_function("ImTextCountCharsFromUtf8", ImGui::ImTextCountCharsFromUtf8);
  mod.set_function("ImTextCountUtf8BytesFromChar",
                   ImGui::ImTextCountUtf8BytesFromChar);
  mod.set_function("ImTextCountUtf8BytesFromStr",
                   ImGui::ImTextCountUtf8BytesFromStr);
  mod.set_function("ImTextFindPreviousUtf8Codepoint",
                   ImGui::ImTextFindPreviousUtf8Codepoint);
  mod.set_function("ImTextCountLines", ImGui::ImTextCountLines);
  mod.set_function("ImFileOpen", ImGui::ImFileOpen);
  mod.set_function("ImFileClose", ImGui::ImFileClose);
  mod.set_function("ImFileGetSize", ImGui::ImFileGetSize);
  mod.set_function("ImFileRead", ImGui::ImFileRead);
  mod.set_function("ImFileWrite", ImGui::ImFileWrite);
  mod.set_function("ImFileLoadToMemory", ImGui::ImFileLoadToMemory);
  mod.set_function(
      "ImPow",
      sol::overload([](float x, float y) { return ImGui::ImPow(x, y); },
                    [](double x, double y) { return ImGui::ImPow(x, y); }));
  mod.set_function("ImLog",
                   sol::overload([](float x) { return ImGui::ImLog(x); },
                                 [](double x) { return ImGui::ImLog(x); }));
  mod.set_function("ImAbs",
                   sol::overload([](int x) { return ImGui::ImAbs(x); },
                                 [](float x) { return ImGui::ImAbs(x); },
                                 [](double x) { return ImGui::ImAbs(x); }));
  mod.set_function("ImSign",
                   sol::overload([](float x) { return ImGui::ImSign(x); },
                                 [](double x) { return ImGui::ImSign(x); }));
  mod.set_function("ImRsqrt",
                   sol::overload([](float x) { return ImGui::ImRsqrt(x); },
                                 [](double x) { return ImGui::ImRsqrt(x); }));
  mod.set_function("ImMin", ImGui_ImMin);
  mod.set_function("ImMax", ImGui_ImMax);
  mod.set_function("ImClamp", ImGui_ImClamp);
  mod.set_function(
      "ImLerp",
      sol::overload(
          [](ImVec2 a, ImVec2 b, float t) { return ImGui_ImLerp(a, b, t); },
          [](ImVec2 a, ImVec2 b, ImVec2 t) { return ImGui_ImLerp(a, b, t); },
          [](ImVec4 a, ImVec4 b, float t) { return ImGui_ImLerp(a, b, t); }));
  mod.set_function("ImSaturate", ImGui::ImSaturate);
  mod.set_function(
      "ImLengthSqr",
      sol::overload([](ImVec2 lhs) { return ImGui::ImLengthSqr(lhs); },
                    [](ImVec4 lhs) { return ImGui::ImLengthSqr(lhs); }));
  mod.set_function("ImInvLength", ImGui::ImInvLength);
  mod.set_function("ImTrunc",
                   sol::overload([](float f) { return ImGui::ImTrunc(f); },
                                 [](ImVec2 v) { return ImGui_ImTrunc(v); }));
  mod.set_function("ImFloor",
                   sol::overload([](float f) { return ImGui::ImFloor(f); },
                                 [](ImVec2 v) { return ImGui_ImFloor(v); }));
  mod.set_function("ImModPositive", ImGui::ImModPositive);
  mod.set_function("ImDot", ImGui::ImDot);
  mod.set_function("ImRotate", ImGui_ImRotate);
  mod.set_function("ImLinearSweep", ImGui::ImLinearSweep);
  mod.set_function("ImMul", ImGui_ImMul);
  mod.set_function("ImIsFloatAboveGuaranteedIntegerPrecision",
                   ImGui::ImIsFloatAboveGuaranteedIntegerPrecision);
  mod.set_function("ImExponentialMovingAverage",
                   ImGui::ImExponentialMovingAverage);
  mod.set_function("ImBezierCubicCalc", ImGui_ImBezierCubicCalc);
  mod.set_function("ImBezierCubicClosestPoint",
                   ImGui_ImBezierCubicClosestPoint);
  mod.set_function("ImBezierCubicClosestPointCasteljau",
                   ImGui_ImBezierCubicClosestPointCasteljau);
  mod.set_function("ImBezierQuadraticCalc", ImGui_ImBezierQuadraticCalc);
  mod.set_function("ImLineClosestPoint", ImGui_ImLineClosestPoint);
  mod.set_function("ImTriangleContainsPoint", ImGui::ImTriangleContainsPoint);
  mod.set_function("ImTriangleClosestPoint", ImGui_ImTriangleClosestPoint);
  mod.set_function("ImTriangleBarycentricCoords",
                   ImGui_ImTriangleBarycentricCoords);
  mod.set_function("ImTriangleArea", ImGui::ImTriangleArea);
  mod.set_function("ImTriangleIsClockwise", ImGui::ImTriangleIsClockwise);
  mod.set_function("ImBitArrayGetStorageSizeInBytes",
                   ImGui::ImBitArrayGetStorageSizeInBytes);
  mod.set_function("ImBitArrayClearAllBits", ImGui::ImBitArrayClearAllBits);
  mod.set_function("ImBitArrayTestBit", ImGui::ImBitArrayTestBit);
  mod.set_function("ImBitArrayClearBit", ImGui::ImBitArrayClearBit);
  mod.set_function("ImBitArraySetBit", ImGui::ImBitArraySetBit);
  mod.set_function("ImBitArraySetBitRange", ImGui::ImBitArraySetBitRange);
  mod.set_function("ImBitVectorCreate", ImGui_ImBitVectorCreate);
  mod.set_function("ImBitVectorClear", ImGui::ImBitVectorClear);
  mod.set_function("ImBitVectorTestBit", ImGui::ImBitVectorTestBit);
  mod.set_function("ImBitVectorSetBit", ImGui::ImBitVectorSetBit);
  mod.set_function("ImBitVectorClearBit", ImGui::ImBitVectorClearBit);
  mod.set_function("ImGuiTextIndexClear", ImGui::ImGuiTextIndexClear);
  mod.set_function("ImGuiTextIndexSize", ImGui::ImGuiTextIndexSize);
  mod.set_function("ImGuiTextIndexGetLineBegin",
                   ImGui::ImGuiTextIndexGetLineBegin);
  mod.set_function("ImGuiTextIndexGetLineEnd", ImGui::ImGuiTextIndexGetLineEnd);
  mod.set_function("ImGuiTextIndexAppend", ImGui::ImGuiTextIndexAppend);
}