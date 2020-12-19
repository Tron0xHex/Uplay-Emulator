cmake_minimum_required(VERSION 3.16.0)

set(CMAKE_TOOLCHAIN_FILE "../vcpkg/scripts/buildsystems/vcpkg.cmake")

project(Uplay_r1_loader)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(VERSION 1.0.0)

file(GLOB_RECURSE CPP_HPP_FILES "src/*.cpp" "src/*.hpp" "src/*.h")
add_library(Uplay_r1_loader SHARED ${CPP_HPP_FILES})

find_package(string_theory CONFIG REQUIRED)
target_link_libraries(Uplay_r1_loader PRIVATE string_theory)

find_package(cereal CONFIG REQUIRED)
target_include_directories(Uplay_r1_loader PRIVATE cereal)

find_path(PLOG_INCLUDE_DIRS "plog/Appenders/AndroidAppender.h")
target_include_directories(Uplay_r1_loader PRIVATE ${PLOG_INCLUDE_DIRS})

find_package(fmt CONFIG REQUIRED)
target_link_libraries(Uplay_r1_loader PRIVATE fmt::fmt fmt::fmt-header-only)

if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
set_target_properties(Uplay_r1_loader PROPERTIES OUTPUT_NAME "uplay_r1_loader64") 
target_include_directories(Uplay_r1_loader PRIVATE "D:/Uplay_r1_loader/vcpkg/installed/x64-windows-static/include")
target_link_libraries(Uplay_r1_loader PRIVATE "D:/Uplay_r1_loader/vcpkg/installed/x64-windows-static/lib/minhook.x64.lib")
else()
set_target_properties(Uplay_r1_loader PROPERTIES OUTPUT_NAME "uplay_r1_loader")
target_include_directories(Uplay_r1_loader PRIVATE "D:/Uplay_r1_loader/vcpkg/installed/x86-windows-static/include")
target_link_libraries(Uplay_r1_loader PRIVATE "D:/Uplay_r1_loader/vcpkg/installed/x86-windows-static/lib/minhook.x32.lib")
endif()

target_include_directories(Uplay_r1_loader PRIVATE ${CMAKE_SOURCE_DIR})
target_precompile_headers(Uplay_r1_loader PUBLIC "src/pch.h")

target_compile_definitions(Uplay_r1_loader PRIVATE WIN32_LEAN_AND_MEAN)