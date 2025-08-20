#include "stack.h"

// 创建一个新的栈
Stack* stack_create() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// 销毁栈并释放所有节点内存
void stack_destroy(Stack* stack) {
    if (stack == NULL) {
        return;
    }
    
    StackNode* current = stack->top;
    while (current != NULL) {
        StackNode* next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}

// 将元素压入栈顶
void stack_push(Stack* stack, int data) {
    if (stack == NULL) {
        return;
    }
    
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// 从栈顶弹出元素
int stack_pop(Stack* stack) {
    if (stack == NULL || stack->top == NULL) {
        printf("Stack underflow\n");
        return -1; // 或者定义一个错误码
    }
    
    StackNode* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

// 查看栈顶元素但不弹出
int stack_peek(Stack* stack) {
    if (stack == NULL || stack->top == NULL) {
        printf("Stack is empty\n");
        return -1; // 或者定义一个错误码
    }
    return stack->top->data;
}

// 检查栈是否为空
int stack_is_empty(Stack* stack) {
    if (stack == NULL) {
        return 1; // 空指针视为"空"
    }
    return stack->top == NULL;
}

// 打印栈内容
void stack_print(Stack* stack) {
    if (stack == NULL) {
        printf("Stack is NULL\n");
        return;
    }
    
    StackNode* current = stack->top;
    printf("Stack (size: %d): ", stack->size);
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}