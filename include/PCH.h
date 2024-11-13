#pragma once

#include <sol/sol.hpp>

#include "RE/Skyrim.h"
#include "REL/Relocation.h"
#include "SKSE/SKSE.h"
#include "matchit.h"

using namespace std::literals;
using namespace REL::literals;

namespace logger = SKSE::log;
namespace util
{
using SKSE::stl::report_and_fail;
}
