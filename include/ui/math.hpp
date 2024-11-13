#pragma once

#include "SKSEMenuFramework.h"

namespace solus::ui
{
inline ImVec2 vec_min(const ImVec2 a, const ImVec2 b)
{
  return { std::fmin(a.x, b.x), std::fmin(a.y, b.y) };
}

inline ImVec2 vec_min(const ImVec2 vec, const float scalar)
{
  return { std::fmin(vec.x, scalar), std::fmin(vec.y, scalar) };
}

inline ImVec2 vec_min(const ImVec2 vec, const float x, const float y)
{
  return { std::fmin(vec.x, x), std::fmin(vec.y, y) };
}

inline ImVec2 vec_max(const ImVec2 a, const ImVec2 b)
{
  return { std::fmax(a.x, b.x), std::fmax(a.y, b.y) };
}

inline ImVec2 vec_max(const ImVec2 vec, const float scalar)
{
  return { std::fmax(vec.x, scalar), std::fmax(vec.y, scalar) };
}

inline ImVec2 vec_max(const ImVec2 vec, const float x, const float y)
{
  return { std::fmax(vec.x, x), std::fmax(vec.y, y) };
}

inline ImVec2 vec_clamp(const ImVec2 vec, const ImVec2 min, const ImVec2 max)
{
  return vec_max(min, vec_min(max, vec));
}

} // namespace solus::ui