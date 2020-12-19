#pragma once

#include <map>
#include <algorithm>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <vector>
#include <exception>

#include <Windows.h>
#include <Psapi.h>
#include <MinHook.h>
#include <plog/Log.h>
#include <fmt/format.h>

#include <string_theory/st_string.h>
#include <string_theory/st_utf_conv.h>

#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/archives/json.hpp>