#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

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
Queue* queue_create();
void queue_destroy(Queue* queue);
void queue_enqueue(Queue* queue, int data);
int queue_dequeue(Queue* queue);
int queue_front(Queue* queue);
int queue_is_empty(Queue* queue);
void queue_print(Queue* queue);

#endif // QUEUE_H