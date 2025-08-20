#ifndef CUSTOME_STRING_H
#define CUSTOME_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义 String 结构体
typedef struct {
    char* data;      // 指向字符数据的指针
    size_t length;   // 字符串的实际长度
    size_t capacity; // 字符串的容量
} String;

// 函数声明
String* string_create(const char* str);
void string_destroy(String* s);
String* string_copy(const String* s);
int string_compare(const String* s1, const String* s2);
String* string_concat(const String* s1, const String* s2);
void string_print(const String* s);

#endif // CUSTOME_STRING_H