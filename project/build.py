import os
import shutil
import pathlib
import inspect
import subprocess

PROJECT_PATH = os.path.dirname(os.getcwd())

VCPKG_PATH = f'{PROJECT_PATH}/vcpkg/vcpkg.exe'
VCPKG_GIT_CMD = f'git clone https://github.com/microsoft/vcpkg {os.path.join(PROJECT_PATH, "vcpkg")}'
VCPKG_BOOTSTRAP = f'{PROJECT_PATH}/vcpkg/bootstrap-vcpkg.bat'

ALLOWED_DIRS = ["src", ".git"]
ALLOWED_FILES = [".cpp", ".bat", ".hpp",
                 ".json", ".md", ".py", ".gitignore", ".gitattributes"]


def remove_build_files():
    root = os.getcwd()

    for item in os.listdir(root):
        path = os.path.join(root, item)

        if os.path.isdir(path):
            if item not in ALLOWED_DIRS:
                shutil.rmtree(path)

        elif os.path.isfile(path):
            if item in ALLOWED_FILES:
                continue

            suffix = pathlib.Path(path).suffix

            if suffix not in ALLOWED_FILES:
                os.remove(path)


def gen_cmake_script() -> str:
    cwd: str = os.getcwd()
    path: str = pathlib.Path(cwd).parent.as_posix()

    script: str = f"""
    cmake_minimum_required(VERSION 3.16.0)
    
    set(CMAKE_TOOLCHAIN_FILE \"../vcpkg/scripts/buildsystems/vcpkg.cmake\")
    
    project(Uplay_r1_loader)
    
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(VERSION 1.0.0)
    
    file(GLOB_RECURSE CPP_HPP_FILES \"src/*.cpp\" \"src/*.hpp\" \"src/*.h\")
    add_library(Uplay_r1_loader SHARED ${{CPP_HPP_FILES}})
    
    find_package(string_theory CONFIG REQUIRED)
    target_link_libraries(Uplay_r1_loader PRIVATE string_theory)
    
    find_package(cereal CONFIG REQUIRED)
    target_include_directories(Uplay_r1_loader PRIVATE cereal)
    
    find_path(PLOG_INCLUDE_DIRS \"plog/Appenders/AndroidAppender.h\")
    target_include_directories(Uplay_r1_loader PRIVATE ${{PLOG_INCLUDE_DIRS}})
    
    find_package(fmt CONFIG REQUIRED)
    target_link_libraries(Uplay_r1_loader PRIVATE fmt::fmt fmt::fmt-header-only)
    
    if (${{CMAKE_SIZEOF_VOID_P}} MATCHES 8)
    set_target_properties(Uplay_r1_loader PROPERTIES OUTPUT_NAME \"uplay_r1_loader64\") 
    target_include_directories(Uplay_r1_loader PRIVATE \"{path}/vcpkg/installed/x64-windows-static/include\")
    target_link_libraries(Uplay_r1_loader PRIVATE \"{path}/vcpkg/installed/x64-windows-static/lib/minhook.x64.lib\")
    else()
    set_target_properties(Uplay_r1_loader PROPERTIES OUTPUT_NAME \"uplay_r1_loader\")
    target_include_directories(Uplay_r1_loader PRIVATE \"{path}/vcpkg/installed/x86-windows-static/include\")
    target_link_libraries(Uplay_r1_loader PRIVATE \"{path}/vcpkg/installed/x86-windows-static/lib/minhook.x32.lib\")
    endif()
    
    target_include_directories(Uplay_r1_loader PRIVATE ${{CMAKE_SOURCE_DIR}})
    target_precompile_headers(Uplay_r1_loader PUBLIC \"src/pch.h\")
    
    target_compile_definitions(Uplay_r1_loader PRIVATE WIN32_LEAN_AND_MEAN)
    """

    return script


def execute(cmd: str):
    result = subprocess.run(cmd)

    if result.stderr is not None and len(result.stderr) > 0:
        raise Exception(str(result.stderr))


def main():
    remove_build_files()

    if not os.path.isfile(VCPKG_PATH):
        execute(VCPKG_GIT_CMD)
        execute(VCPKG_BOOTSTRAP)

    execute(f'{VCPKG_PATH} install minhook:x86-windows-static')
    execute(f'{VCPKG_PATH} install minhook:x64-windows-static')
    execute(f'{VCPKG_PATH} install string-theory:x86-windows')
    execute(f'{VCPKG_PATH} install string-theory:x64-windows')
    execute(f'{VCPKG_PATH} install cereal:x86-windows')
    execute(f'{VCPKG_PATH} install cereal:x64-windows')
    execute(f'{VCPKG_PATH} install plog:x86-windows')
    execute(f'{VCPKG_PATH} install plog:x64-windows')
    execute(f'{VCPKG_PATH} install fmt:x86-windows')
    execute(f'{VCPKG_PATH} install fmt:x64-windows')

    cmake_script = gen_cmake_script()

    cmake_file = open('CMakeLists.txt', 'w+')
    cmake_file.write(inspect.cleandoc(cmake_script))


if __name__ == "__main__":
    main()
