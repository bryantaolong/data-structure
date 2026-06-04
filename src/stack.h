#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

// 定义栈节点结构
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// 定义栈结构
typedef struct Stack {
    StackNode* top;
    int size;
} Stack;

// 函数声明
Stack* stack_create();
void stack_destroy(Stack* stack);
void stack_push(Stack* stack, int data);
int stack_pop(Stack* stack);
int stack_peek(Stack* stack);
int stack_is_empty(Stack* stack);
void stack_print(Stack* stack);

#endif // STACK_H