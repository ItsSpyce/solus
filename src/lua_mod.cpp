#include "lua_mod.h"

#include "filesystem.h"

solus::LuaMod::ModLoadError solus::LuaMod::load_config(LUA_STATE) {
  sol::state_view lua(L);
  // read mod.lua file
  try {
    logger::info("Searching for mod in {}", directory_.string());
    const auto mod_file = FS_JOIN(directory_, "mod.lua").string();
    if (!fs::exists(mod_file)) {
      logger::error("Mod config not found: {}", mod_file);
      return kModLoadErrorFileNotFound;
    }
    const auto result = lua.safe_script_file(mod_file, sol::load_mode::text);
    if (!result.valid()) {
      logger::error("Failed to load mod config: {}", result.get<std::string>());
      return kModLoadErrorInvalidConfig;
    }
    logger::info("Mod config for {} looks good, reading information", mod_file);
    const auto mod = result.get<sol::table>();
    config_ = ModConfig{mod.get<std::string>("name"),
                        mod.get<std::string>("version"),
                        mod.get<std::string>("author"),
                        mod.get<std::string>("description"),
                        {}};
    logger::info("Config parsed: {}; {}; {}; {}", config_->name,
                 config_->version, config_->author, config_->description);
    const auto entry_point = FS_JOIN(directory_, "init.lua");
    if (!fs::exists(entry_point)) {
      logger::error("Mod entry point not found: {}", entry_point.string());
      return kModLoadErrorEntryPointNotFound;
    }
    logger::info("Entry point found at {}", entry_point.string());
    return kModLoadErrorNone;
  } catch (std::exception &ex) {
    logger::error("Unknown error loading mod config: {}", ex.what());
    return kModLoadErrorUnknown;
  }
}