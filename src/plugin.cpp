#include <cassert>

#include "PCH.h"
#include "commands/lua_cmd.h"
#include "logging.h"
#include "lua_mod_manager.h"
#include "modules/imgui/imgui_managers.h"
#include "modules/imgui/imgui_module.h"
#include "solus.h"

const auto mod_manager = new solus::LuaModManager();

void handle_message(SKSE::MessagingInterface::Message *msg) {
  switch (msg->type) {
    case SKSE::MessagingInterface::kPostLoad:
      mod_manager->load_mods(solus::state);
      break;
    default:
      break;
  }
}

SKSEPluginLoad(const SKSE::LoadInterface *a_skse) {
  SKSE::Init(a_skse);
  solus::initialize_logging(solus::solus_root_directory);
  if (!solus::test_lua()) {
    logger::error("Lua test failed.");
    stl::report_and_fail("Lua test failed.");
  }
  SKSE::GetMessagingInterface()->RegisterListener(handle_message);
  logger::info("Setting up core modules");
  solus::initialize(solus::state);
  // solus::import_module(solus::modules::solus::solus_module);
  logger::info("Setting up ImGui");
  solus::modules::imgui_module::initialize(solus::state);
  solus::modules::imgui_module::managers::ImGuiViewportManager::initialize(
      solus::state);
  solus::modules::imgui_module::managers::ImRectManager::initialize(
      solus::state);
  solus::modules::imgui_module::managers::ImVec2Manager::initialize(
      solus::state);
  solus::modules::imgui_module::managers::ImVec4Manager::initialize(
      solus::state);
  logger::info("Core modules complete");
  logger::info("Setting up mods");
  mod_manager->initialize(solus::state,
                          solus::solus_root_directory->string().c_str());
  return true;
}
