#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

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

// 定义链表节点结构
typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

// 定义链表结构
typedef struct List {
    ListNode* head;
    int size;
} List;

// 函数声明
DATA_STRUCTURE_API List* list_create();
DATA_STRUCTURE_API void list_destroy(List* list);
DATA_STRUCTURE_API void list_add(List* list, int data);
DATA_STRUCTURE_API void list_remove(List* list, int data);
DATA_STRUCTURE_API int list_contains(List* list, int data);
DATA_STRUCTURE_API void list_print(List* list);

#endif // LIST_H