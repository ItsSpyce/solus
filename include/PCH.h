#pragma once

#include <sol/sol.hpp>
#include <filesystem>

#include "RE/Skyrim.h"
#include "REL/Relocation.h"
#include "SKSE/SKSE.h"
#include "matchit.h"
#include "modules/imgui/SKSEMenuFramework.h"
#include "filesystem.h"

using namespace std::literals;
using namespace REL::literals;

namespace logger = SKSE::log;
namespace WinAPI = SKSE::WinAPI;
namespace stl = SKSE::stl;
namespace util
{
using stl::report_and_fail;
}
