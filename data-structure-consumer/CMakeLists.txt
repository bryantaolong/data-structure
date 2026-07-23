cmake_minimum_required(VERSION 3.10)
project(data-structure-consumer C)

set(CMAKE_C_STANDARD 11)

# 头文件目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 可执行文件
add_executable(consumer src/main.c)

# 链接 DLL 的导入库
target_link_libraries(consumer PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/libdata-structure.dll
)

# 构建后自动把 DLL 复制到 exe 旁边
add_custom_command(TARGET consumer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/lib/libdata-structure.dll
        $<TARGET_FILE_DIR:consumer>
)
