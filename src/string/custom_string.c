#include "custom_string.h"

// 创建一个新的 String 对象
String* string_create(const char* str) {
    if (str == NULL) {
        return NULL;
    }

    String* s = (String*)malloc(sizeof(String));
    if (s == NULL) {
        return NULL;
    }

    size_t len = strlen(str);
    // 分配足够的内存以容纳字符串和终止符 '\0'
    s->data = (char*)malloc(len + 1);
    if (s->data == NULL) {
        free(s);
        return NULL;
    }

    strcpy(s->data, str);
    s->length = len;
    s->capacity = len;

    return s;
}

// 销毁一个 String 对象
void string_destroy(String* s) {
    if (s != NULL) {
        free(s->data);
        free(s);
    }
}

// 复制一个 String 对象
String* string_copy(const String* s) {
    if (s == NULL) {
        return NULL;
    }

    return string_create(s->data);
}

// 比较两个 String 对象
int string_compare(const String* s1, const String* s2) {
    if (s1 == NULL && s2 == NULL) {
        return 0;
    }
    if (s1 == NULL) {
        return -1;
    }
    if (s2 == NULL) {
        return 1;
    }

    return strcmp(s1->data, s2->data);
}

// 连接两个 String 对象
String* string_concat(const String* s1, const String* s2) {
    if (s1 == NULL || s2 == NULL) {
        return NULL;
    }

    String* result = (String*)malloc(sizeof(String));
    if (result == NULL) {
        return NULL;
    }

    size_t new_length = s1->length + s2->length;
    result->data = (char*)malloc(new_length + 1);
    if (result->data == NULL) {
        free(result);
        return NULL;
    }

    strcpy(result->data, s1->data);
    strcat(result->data, s2->data);
    result->length = new_length;
    result->capacity = new_length;

    return result;
}

// 打印 String 对象的内容
void string_print(const String* s) {
    if (s != NULL && s->data != NULL) {
        printf("%s", s->data);
    }
}