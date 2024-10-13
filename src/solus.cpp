#include <cassert>

#include "PCH.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/msvc_sink.h"

#include "engine.h"
namespace fs = std::filesystem;
namespace stl = SKSE::stl;

void InitializeLogging()
{
  auto path = logger::log_directory();

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

solus::SolusEngine *engine{};

void HandleMessage(SKSE::MessagingInterface::Message *a_msg)
{
  switch (a_msg->type)
  {
    case SKSE::MessagingInterface::kDataLoaded:
      logger::info("Data loaded");
      break;
    case SKSE::MessagingInterface::kPreLoadGame:
      logger::info("Pre-load-game");
      break;
    case SKSE::MessagingInterface::kPostLoad:
      logger::info("Post-load");
      break;
    case SKSE::MessagingInterface::kPostPostLoad:
      logger::info("Post-post-load");
      if (engine->CanCompileTestScript())
      {
        logger::info("Test script compiled successfully");
      }
      else
      {
        stl::report_and_fail("Test script failed to compile");
      }
      break;
    case SKSE::MessagingInterface::kSaveGame:
      logger::info("Save-game");
      break;
    default:
      break;
  }
}

SKSEPluginLoad(const SKSE::LoadInterface *a_skse)
{
  SKSE::Init(a_skse);
  InitializeLogging();
  SKSE::GetMessagingInterface()->RegisterListener(HandleMessage);
  return true;
}