#include "lua_mod_manager.h"

#include "filesystem.h"
#include "solus.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/msvc_sink.h"

sol::environment get_environment_for_mod(LUA_STATE, const solus::LuaMod &mod) {
  sol::environment env(L, sol::create, solus::state.globals());

  const auto path = FS_JOIN(mod.directory(), "log.txt");
  std::shared_ptr<spdlog::logger> log;
  if (IsDebuggerPresent()) {
    log = std::make_shared<spdlog::logger>(
        "Global", std::make_shared<spdlog::sinks::msvc_sink_mt>());
  } else {
    log = std::make_shared<spdlog::logger>(
        "Global", std::make_shared<spdlog::sinks::basic_file_sink_mt>(
                      path.string(), true));
  }
  log->set_level(spdlog::level::info);
  log->flush_on(spdlog::level::info);
  log->set_pattern("[%H:%M:%S] [%^%l%$] %v");

  env["print"] = sol::protect([log](std::string fmt) { log->info("{}", fmt); });
  return env;
}

void solus::LuaModManager::initialize(LUA_STATE, const char *directory) {
  logger::info("Looking for mods in {}", directory);
  // get all folders in directory that have a mod.lua file
  for (const auto directories = fs::directory_iterator(directory);
       const auto &entry : directories) {
    if (!entry.is_directory()) {
      continue;
    }
    const auto lua_mod = new LuaMod(entry.path());
    if (const auto load_result = lua_mod->load_config(L);
        load_result > LuaMod::kModLoadErrorNone) {
      logger::error("Received bad result from loading {}: {}",
                    lua_mod->directory().string(), load_result);
      continue;
    }
    if (!lua_mod->config()) {
      logger::error("Failed to load mod: {}", entry.path().string());
      continue;
    }
    logger::info("Initialized mod: {}", lua_mod->config()->name);
    mods_.push_back(*lua_mod);
  }
  logger::info("Found {} mods", mods_.size());
}

void solus::LuaModManager::load_mods(LUA_STATE) const {
  sol::state_view lua(L);
  logger::info("Loading mods");
  for (const auto &mod : mods_) {
    logger::info("Loading mod {}", mod.config()->name);
    // load mod.lua
    const auto entry_point = FS_JOIN(mod.directory(), "init.lua");
    const auto env = get_environment_for_mod(L, mod);
    const auto result =
        lua.script_file(entry_point.string(), env,
                        [](lua_State *, sol::protected_function_result prf) {
                          if (!prf.valid()) {
                            const sol::error err = prf;
                            logger::error("Error loading mod: {}", err.what());
                            return prf;
                          }
                          return prf;
                        });
  }
}