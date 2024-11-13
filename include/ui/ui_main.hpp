#pragma once

#include "SKSEMenuFramework.h"
#include "./math.hpp"

namespace solus::ui
{
enum class WindowID : uint8_t
{
  kWindowMain,
  kWindowConsole,
  kWindowSettings,
  kWindowAbout,
  kWindowPlugins,
};

class UIWindow
{
public:
  UIWindow() = default;
  virtual ~UIWindow() noexcept = default;

  UIWindow(const UIWindow &) = delete;
  UIWindow(UIWindow &&) = delete;
  UIWindow &operator=(const UIWindow &) = delete;
  UIWindow &operator=(UIWindow &&) = delete;

  bool try_draw() noexcept
  {
    const bool should_draw = try_draw_impl();
    if (!did_draw_last_ && should_draw)
    {
      on_open();
    }
    else
    {
      on_close();
    }
    did_draw_last_ = should_draw;
    return should_draw;
  }

protected:
  virtual bool try_draw_impl() noexcept = 0;
  virtual bool on_open()
  {
    return false;
  }
  virtual bool on_close()
  {
    return false;
  }

  void set_window_position(const ImVec2 position) noexcept
  {
    size_data_.position =
      vec_clamp(position, { 0.f, 0.f }, { ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y });
    mark_for_layout_update();
  }

  void set_window_pivot(const ImVec2 pivot) noexcept
  {
    size_data_.pivot = pivot;
    mark_for_layout_update();
  }

  void set_window_size(const ImVec2 size) noexcept
  {
    const auto &io = ImGui::GetIO();
    size_data_.size = vec_clamp(size, { 300.f, 200.f }, { io.DisplaySize.x - 40.f, io.DisplaySize.y - 40.f });
    mark_for_layout_update();
  }

  bool did_draw_last_ = false;

private:
  struct
  {
    ImVec2 position;
    ImVec2 pivot;
    ImVec2 size;
  } size_data_;

  void mark_for_layout_update() const
  {
    ImGui::SetNextWindowPos(size_data_.position, ImGuiCond_Always, size_data_.pivot);
    ImGui::SetNextWindowSize(size_data_.size, ImGuiCond_Always);
  }
};
} // namespace solus::ui