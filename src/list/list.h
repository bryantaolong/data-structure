#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

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
List* list_create();
void list_destroy(List* list);
void list_add(List* list, int data);
void list_remove(List* list, int data);
int list_contains(List* list, int data);
void list_print(List* list);

#endif // LIST_H