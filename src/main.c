#include <stdio.h>
#include "list/list.h"
#include "stack/stack.h"
#include "queue/queue.h"
#include "string/custom_string.h"

int main() {
    printf("=== Data Structures Demo ===\n\n");
    
    // --- 字符串演示 ---
    printf("--- String Demo ---\n");
    String* s1 = string_create("Hello");
    String* s2 = string_create(" World");
    
    printf("String 1: ");
    string_print(s1);
    printf("\n");
    
    printf("String 2: ");
    string_print(s2);
    printf("\n");
    
    String* s3 = string_concat(s1, s2);
    printf("Concatenated string: ");
    string_print(s3);
    printf("\n");
    
    printf("Comparing s1 and s2: %d\n", string_compare(s1, s2));
    printf("Comparing s1 and 'Hello': %d\n", string_compare(s1, string_create("Hello")));
    
    String* s4 = string_copy(s1);
    printf("Copied string: ");
    string_print(s4);
    printf("\n");
    
    string_destroy(s1);
    string_destroy(s2);
    string_destroy(s3);
    string_destroy(s4);
    printf("\n");
    
    // --- 链表演示 ---
    printf("--- List Demo ---\n");
    List* list = list_create();
    list_add(list, 10);
    list_add(list, 20);
    list_add(list, 30);
    list_print(list);
    
    list_remove(list, 20);
    list_print(list);
    
    printf("Contains 10: %s\n", list_contains(list, 10) ? "true" : "false");
    printf("Contains 20: %s\n", list_contains(list, 20) ? "true" : "false");
    
    list_destroy(list);
    printf("\n");
    
    // --- 栈演示 ---
    printf("--- Stack Demo ---\n");
    Stack* stack = stack_create();
    stack_push(stack, 100);
    stack_push(stack, 200);
    stack_push(stack, 300);
    stack_print(stack);
    
    printf("Top element: %d\n", stack_peek(stack));
    printf("Popped element: %d\n", stack_pop(stack));
    stack_print(stack);
    
    stack_destroy(stack);
    printf("\n");
    
    // --- 队列演示 ---
    printf("--- Queue Demo ---\n");
    Queue* queue = queue_create();
    queue_enqueue(queue, 1000);
    queue_enqueue(queue, 2000);
    queue_enqueue(queue, 3000);
    queue_print(queue);
    
    printf("Front element: %d\n", queue_front(queue));
    printf("Dequeued element: %d\n", queue_dequeue(queue));
    queue_print(queue);
    
    queue_destroy(queue);
    printf("\n");
    
    printf("=== Demo Complete ===\n");
    return 0;
}