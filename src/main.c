#include <stdio.h>
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "custom_string.h"

// Windows console needs code page set to UTF-8 for correct display of UTF-8 strings
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    printf("=== 数据结构演示 ===\n\n");

    // --- 字符串演示 ---
    printf("--- 字符串演示 ---\n");
    String* s1 = string_create("Hello");
    String* s2 = string_create(" World");

    printf("字符串1: ");
    string_print(s1);
    printf("\n");

    printf("字符串2: ");
    string_print(s2);
    printf("\n");

    String* s3 = string_concat(s1, s2);
    printf("拼接后的字符串: ");
    string_print(s3);
    printf("\n");

    printf("比较 s1 和 s2: %d\n", string_compare(s1, s2));
    printf("比较 s1 和 'Hello': %d\n", string_compare(s1, string_create("Hello")));

    String* s4 = string_copy(s1);
    printf("复制的字符串: ");
    string_print(s4);
    printf("\n");

    string_destroy(s1);
    string_destroy(s2);
    string_destroy(s3);
    string_destroy(s4);
    printf("\n");

    // --- 链表演示 ---
    printf("--- 链表演示 ---\n");
    List* list = list_create();
    list_add(list, 10);
    list_add(list, 20);
    list_add(list, 30);
    list_print(list);

    list_remove(list, 20);
    list_print(list);

    printf("包含 10: %s\n", list_contains(list, 10) ? "true" : "false");
    printf("包含 20: %s\n", list_contains(list, 20) ? "true" : "false");

    list_destroy(list);
    printf("\n");

    // --- 栈演示 ---
    printf("--- 栈演示 ---\n");
    Stack* stack = stack_create();
    stack_push(stack, 100);
    stack_push(stack, 200);
    stack_push(stack, 300);
    stack_print(stack);

    printf("栈顶元素: %d\n", stack_peek(stack));
    printf("出栈元素: %d\n", stack_pop(stack));
    stack_print(stack);

    stack_destroy(stack);
    printf("\n");

    // --- 队列演示 ---
    printf("--- 队列演示 ---\n");
    Queue* queue = queue_create();
    queue_enqueue(queue, 1000);
    queue_enqueue(queue, 2000);
    queue_enqueue(queue, 3000);
    queue_print(queue);

    printf("队首元素: %d\n", queue_front(queue));
    printf("出队元素: %d\n", queue_dequeue(queue));
    queue_print(queue);

    queue_destroy(queue);
    printf("\n");

    printf("=== 演示完成 ===\n");
    return 0;
}
