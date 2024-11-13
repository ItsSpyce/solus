#include <cassert>

#include "PCH.h"
#include "logging.hpp"
#include "solus.hpp"
#include "modules/solus_module.hpp"
#include "modules/ui_module.hpp"
#include "ui/manager.hpp"

void handle_message(SKSE::MessagingInterface::Message *msg)
{
  switch (msg->type)
  {
    case SKSE::MessagingInterface::kPostLoad:
      logger::info("Setting up core modules ===");
      solus::import_module(solus::modules::solus::solus_module);
      solus::import_module(solus::modules::ui::ui_module);
      break;
    case SKSE::MessagingInterface::kPostPostLoad:
      // solus::render_ui();
      break;
    default:
      break;
  }
}

SKSEPluginLoad(const SKSE::LoadInterface *a_skse)
{
  SKSE::Init(a_skse);
  solus::initialize_logging(solus::solus_root_directory);
  SKSE::GetMessagingInterface()->RegisterListener(handle_message);
  return true;
}
