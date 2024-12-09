#pragma once

namespace fs = std::filesystem;
namespace solus
{

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

#define FS_EXISTS(p)           fs::exists(p)
#define FS_CREATE_DIR(p)       fs::create_directory(fs::path(p))
#define FS_STAT(p)             fs::status(fs::path(p))
#define FS_IS_SUB_OF(p, q)     q.c_str().find(p.c_str()) != std::string::npos
#define FS_JOIN(...)           solus::join_paths({__VA_ARGS__})
#define FS_CONVERT_TO_POSIX(p) fs::path(p).generic_string()