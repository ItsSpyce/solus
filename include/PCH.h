#pragma once

#define SOL_ALL_SAFETIES_ON 1
#define SOL_ENABLE_INTEROP  1

#include "RE/Skyrim.h"
#include "REL/Relocation.h"
#include "SKSE/SKSE.h"
#include "matchit.h"
#include <sol/sol.hpp>

using namespace std::literals;
using namespace REL::literals;

namespace logger = SKSE::log;
namespace util
{
using SKSE::stl::report_and_fail;
}
