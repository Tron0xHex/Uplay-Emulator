// stdafx.h: включаемый файл для стандартных системных включаемых файлов
// или включаемых файлов для конкретного проекта, которые часто используются, но
// не часто изменяются
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN 

#define UPLAY_FUNC __cdecl
#define UPLAY_API extern "C" __declspec(dllexport)

#include <windows.h>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iterator>
#include <map>
#include <any>
#include <memory>
#include <optional>
#include <mutex>
#include <atomic>

#include <nlohmann/json.hpp>

using namespace std;

using json = nlohmann::json;
using std::filesystem::directory_iterator;
using std::filesystem::path;

static constexpr auto UPLAY_LOG = 1;

// TODO: Установите здесь ссылки на дополнительные заголовки, требующиеся для программы

