#ifndef STACK_H
#define STACK_H

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
DATA_STRUCTURE_API Stack* stack_create();
DATA_STRUCTURE_API void stack_destroy(Stack* stack);
DATA_STRUCTURE_API void stack_push(Stack* stack, int data);
DATA_STRUCTURE_API int stack_pop(Stack* stack);
DATA_STRUCTURE_API int stack_peek(Stack* stack);
DATA_STRUCTURE_API int stack_is_empty(Stack* stack);
DATA_STRUCTURE_API void stack_print(Stack* stack);

#endif // STACK_H