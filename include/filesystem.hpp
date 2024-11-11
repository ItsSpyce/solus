#pragma once

#include <filesystem>

namespace solus
{
namespace fs = std::filesystem;

inline fs::path join_paths(const std::vector<fs::path> &paths)
{
  fs::path result;
  for (auto &path : paths)
  {
    result /= path;
  }
  return result;
}
} // namespace solus

#define FS_EXISTS(p)           std::filesystem::exists(p)
#define FS_CREATE_DIR(p)       std::filesystem::create_directory(std::filesystem::path(p))
#define FS_STAT(p)             std::filesystem::status(std::filesystem::path(p))
#define FS_IS_SUB_OF(p, q)     q.c_str().find(p.c_str()) != std::string::npos
#define FS_JOIN(...)           solus::join_paths({__VA_ARGS__})
#define FS_CONVERT_TO_POSIX(p) std::filesystem::path(p).generic_string()