#include "list.h"

// 创建一个新的链表
List* list_create() {
    List* list = (List*)malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

// 销毁链表并释放所有节点内存
void list_destroy(List* list) {
    if (list == NULL) {
        return;
    }
    
    ListNode* current = list->head;
    while (current != NULL) {
        ListNode* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

// 向链表末尾添加元素
void list_add(List* list, int data) {
    if (list == NULL) {
        return;
    }
    
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        ListNode* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}

// 从链表中移除指定值的第一个节点
void list_remove(List* list, int data) {
    if (list == NULL || list->head == NULL) {
        return;
    }
    
    // 如果要删除的是头节点
    if (list->head->data == data) {
        ListNode* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
        return;
    }
    
    // 查找并删除节点
    ListNode* current = list->head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    
    // 如果找到了要删除的节点
    if (current->next != NULL) {
        ListNode* temp = current->next;
        current->next = current->next->next;
        free(temp);
        list->size--;
    }
}

// 检查链表是否包含指定值
int list_contains(List* list, int data) {
    if (list == NULL) {
        return 0;
    }
    
    ListNode* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// 打印链表内容
void list_print(List* list) {
    if (list == NULL) {
        printf("List is NULL\n");
        return;
    }
    
    ListNode* current = list->head;
    printf("List (size: %d): ", list->size);
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}