#pragma once
#include "sol_ext.h"

namespace solus {
class LuaMod {
 public:
  struct ModDependency {
    std::string name;
    std::string version;
    bool dev;
    bool optional;
  };
  struct ModConfig {
    std::string name;
    std::string version;
    std::string author;
    std::string description;
    std::vector<ModDependency> dependencies;
  };

  enum ModLoadError : std::uint8_t {
    kModLoadErrorNone = 0,
    kModLoadErrorFileNotFound = 1 << 0,
    kModLoadErrorInvalidFile = 1 << 1,
    kModLoadErrorInvalidConfig = 1 << 2,
    kModLoadErrorDependencyError = 1 << 3,
    kModLoadErrorEntryPointNotFound = 1 << 4,
    kModLoadErrorUnknown = 1 << 7,
  };
  explicit LuaMod(fs::path directory) : directory_(std::move(directory)) {}

  ModLoadError load_config(LUA_STATE);
  [[nodiscard]] std::optional<ModConfig> config() const { return config_; }

  [[nodiscard]] const fs::path &directory() const { return directory_; }

 private:
  fs::path directory_;
  std::optional<ModConfig> config_;
};
}  // namespace solus