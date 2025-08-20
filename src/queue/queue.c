#include "queue.h"

// 创建一个新的队列
Queue* queue_create() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// 销毁队列并释放所有节点内存
void queue_destroy(Queue* queue) {
    if (queue == NULL) {
        return;
    }
    
    QueueNode* current = queue->front;
    while (current != NULL) {
        QueueNode* next = current->next;
        free(current);
        current = next;
    }
    free(queue);
}

// 将元素添加到队列尾部
void queue_enqueue(Queue* queue, int data) {
    if (queue == NULL) {
        return;
    }
    
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    
    if (queue->rear == NULL) {
        // 队列为空
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

// 从队列头部移除元素并返回其值
int queue_dequeue(Queue* queue) {
    if (queue == NULL || queue->front == NULL) {
        printf("Queue underflow\n");
        return -1; // 或者定义一个错误码
    }
    
    QueueNode* temp = queue->front;
    int data = temp->data;
    
    queue->front = queue->front->next;
    // 如果队列变空，则rear也应设为NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(temp);
    queue->size--;
    return data;
}

// 查看队列头部元素但不移除
int queue_front(Queue* queue) {
    if (queue == NULL || queue->front == NULL) {
        printf("Queue is empty\n");
        return -1; // 或者定义一个错误码
    }
    return queue->front->data;
}

// 检查队列是否为空
int queue_is_empty(Queue* queue) {
    if (queue == NULL) {
        return 1; // 空指针视为"空"
    }
    return queue->front == NULL;
}

// 打印队列内容
void queue_print(Queue* queue) {
    if (queue == NULL) {
        printf("Queue is NULL\n");
        return;
    }
    
    QueueNode* current = queue->front;
    printf("Queue (size: %d): ", queue->size);
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}