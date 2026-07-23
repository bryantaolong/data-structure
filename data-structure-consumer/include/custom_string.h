#ifndef CUSTOME_STRING_H
#define CUSTOME_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DLL 导出宏
#ifdef _WIN32
    #ifdef DATA_STRUCTURE_EXPORTS
        #define DATA_STRUCTURE_API __declspec(dllexport)
    #else
        #define DATA_STRUCTURE_API __declspec(dllimport)
    #endif
#else
    #define DATA_STRUCTURE_API
#endif

// 定义 String 结构体
typedef struct {
    char* data;      // 指向字符数据的指针
    size_t length;   // 字符串的实际长度
    size_t capacity; // 字符串的容量
} String;

// 函数声明
DATA_STRUCTURE_API String* string_create(const char* str);
DATA_STRUCTURE_API void string_destroy(String* s);
DATA_STRUCTURE_API String* string_copy(const String* s);
DATA_STRUCTURE_API int string_compare(const String* s1, const String* s2);
DATA_STRUCTURE_API String* string_concat(const String* s1, const String* s2);
DATA_STRUCTURE_API void string_print(const String* s);

#endif // CUSTOME_STRING_H