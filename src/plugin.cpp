#include <cassert>

#include "PCH.h"
#include "solus.hpp"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/msvc_sink.h"
#include "modules/solus_module.hpp"
#include "modules/skse_module.hpp"

namespace modules = solus::modules;

void initialize_logging()
{
  auto path = solus::solus_root_directory;

  if (!path)
  {
    SKSE::stl::report_and_fail("Unable to lookup SKSE logs directory");
  }

  *path /= SKSE::PluginDeclaration::GetSingleton()->GetName();
  *path += L".log";
  std::shared_ptr<spdlog::logger> log;

  if (IsDebuggerPresent())
  {
    log = std::make_shared<spdlog::logger>("Global", std::make_shared<spdlog::sinks::msvc_sink_mt>());
  }
  else
  {
    log = std::make_shared<spdlog::logger>("Global",
                                           std::make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true));
  }
  log->set_level(spdlog::level::info);
  log->flush_on(spdlog::level::info);

  spdlog::set_default_logger(std::move(log));
  spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^%l%$] %v");
  logger::info("Logging initialized");
}

void handle_message(SKSE::MessagingInterface::Message *msg)
{
  switch (msg->type)
  {
    case SKSE::MessagingInterface::kPostLoad:
      logger::info("Setting up core modules ===");
      solus::import_module(modules::solus::solus_module);
      solus::import_module(modules::skse::skse_module);
      break;
    case SKSE::MessagingInterface::kPostPostLoad:
      break;
    default:
      break;
  }
}

SKSEPluginLoad(const SKSE::LoadInterface *a_skse)
{
  SKSE::Init(a_skse);
  initialize_logging();
  SKSE::GetMessagingInterface()->RegisterListener(handle_message);
  solus::initialize();
  assert(solus::test_lua());
  return true;
}
