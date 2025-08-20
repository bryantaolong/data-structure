# 指定所需的最低 CMake 版本
cmake_minimum_required(VERSION 3.10)

# 定义项目名称和语言
project(data-structure C)

# 设置 C 标准
set(CMAKE_C_STANDARD 11)

# 定义源文件
set(SOURCES
    src/main.c
    src/list/list.c
    src/stack/stack.c
    src/queue/queue.c
    src/string/custom_string.c
)

# 定义头文件目录
include_directories(src)

# 添加可执行文件
add_executable(data-structure ${SOURCES})