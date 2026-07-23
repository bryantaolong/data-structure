# 指定所需的最低 CMake 版本
cmake_minimum_required(VERSION 3.10)

# 定义项目名称和语言
project(data-structure C)

# 设置 C 标准
set(CMAKE_C_STANDARD 11)

# 定义头文件目录
include_directories(include)

# For MSVC, treat source files as UTF-8 so Chinese comments are parsed correctly
if(MSVC)
    add_compile_options(/utf-8)
endif()

# === DLL 库源文件 ===
set(LIB_SOURCES
    src/list.c
    src/stack.c
    src/queue.c
    src/custom_string.c
)

# 构建动态库 (DLL)
add_library(data-structure SHARED ${LIB_SOURCES})

# 定义导出宏：构建 DLL 时启用 dllexport
target_compile_definitions(data-structure PRIVATE DATA_STRUCTURE_EXPORTS)

# 构建可执行文件 (演示/测试用)
add_executable(data-structure-demo src/main.c)
target_link_libraries(data-structure-demo PRIVATE data-structure)
