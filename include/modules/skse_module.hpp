#pragma once

#include "solus.hpp"

namespace solus::modules::skse
{
EXPORT_MODULE(skse)
{
  EXPORT_FIELD(SKSE::kInvalidPluginHandle);
  EXPORT_FIELD(SKSE::RUNTIME_LATEST_VR);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_LATEST_AE);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_LATEST_SE);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_1_47);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_1_51);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_2_36);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_2_39);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_5_3);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_5_16);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_5_23);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_5_39);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_5_50);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_5_53);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_5_62);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_5_73);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_5_80);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_5_97);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_6_317);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_6_318);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_6_323);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_6_342);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_6_353);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_6_629);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_6_640);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_6_659);
  EXPORT_FIELD(SKSE::RUNTIME_SSE_1_6_678);
}
EXPORT_MODULE(skse_messaging)
{
  exports.add("RegisterListener", [](void (*handler)(SKSE::MessagingInterface::Message *msg)) {
    SKSE::GetMessagingInterface()->RegisterListener(handler);
  });
  EXPORT_FIELD(SKSE::MessagingInterface::kVersion);
  EXPORT_FIELD(SKSE::MessagingInterface::kPostLoad);
  EXPORT_FIELD(SKSE::MessagingInterface::kPostPostLoad);
  EXPORT_FIELD(SKSE::MessagingInterface::kPreLoadGame);
  EXPORT_FIELD(SKSE::MessagingInterface::kPostLoadGame);
  EXPORT_FIELD(SKSE::MessagingInterface::kSaveGame);
  EXPORT_FIELD(SKSE::MessagingInterface::kDeleteGame);
  EXPORT_FIELD(SKSE::MessagingInterface::kInputLoaded);
  EXPORT_FIELD(SKSE::MessagingInterface::kNewGame);
  EXPORT_FIELD(SKSE::MessagingInterface::kDataLoaded);
  EXPORT_FIELD(SKSE::MessagingInterface::kTotal);
}
} // namespace solus::modules::skse