#ifndef QUEUE_H
#define QUEUE_H

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

// 定义队列节点结构
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

// 定义队列结构
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;

// 函数声明
DATA_STRUCTURE_API Queue* queue_create();
DATA_STRUCTURE_API void queue_destroy(Queue* queue);
DATA_STRUCTURE_API void queue_enqueue(Queue* queue, int data);
DATA_STRUCTURE_API int queue_dequeue(Queue* queue);
DATA_STRUCTURE_API int queue_front(Queue* queue);
DATA_STRUCTURE_API int queue_is_empty(Queue* queue);
DATA_STRUCTURE_API void queue_print(Queue* queue);

#endif // QUEUE_H