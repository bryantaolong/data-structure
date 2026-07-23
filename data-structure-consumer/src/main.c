#include <stdio.h>
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "custom_string.h"

int main() {
    // === 测试链表 ===
    printf("=== List ===\n");
    List* list = list_create();
    list_add(list, 10);
    list_add(list, 20);
    list_add(list, 30);
    list_print(list);
    printf("Contains 20? %s\n", list_contains(list, 20) ? "yes" : "no");
    list_destroy(list);

    // === 测试栈 ===
    printf("\n=== Stack ===\n");
    Stack* stack = stack_create();
    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_push(stack, 3);
    stack_print(stack);
    printf("Pop: %d\n", stack_pop(stack));
    stack_destroy(stack);

    // === 测试队列 ===
    printf("\n=== Queue ===\n");
    Queue* queue = queue_create();
    queue_enqueue(queue, 100);
    queue_enqueue(queue, 200);
    queue_print(queue);
    printf("Dequeue: %d\n", queue_dequeue(queue));
    queue_destroy(queue);

    // === 测试自定义字符串 ===
    printf("\n=== String ===\n");
    String* s1 = string_create("Hello");
    String* s2 = string_create(" World");
    String* s3 = string_concat(s1, s2);
    string_print(s3);
    string_destroy(s1);
    string_destroy(s2);
    string_destroy(s3);

    printf("\nAll tests passed!\n");
    return 0;
}
