#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int length;//队列容量
    int size;//队列元素个数
    int front;
    int rear;
}Queue;
// 初始化队列
void initQueue(Queue *queue, size_t capacity) {
    queue->data=malloc(sizeof(int)*capacity);
    queue->length=capacity;
    queue->size=0;
    queue->front=0;
    queue->rear=0;
}
// 返回队列内元素个数
size_t getSize(const Queue *queue) {
    return queue->size;
}
// 添加新元素
void enqueue(Queue *queue, int element) {
    if (queue->size==queue->length) {
        return;
    }
    queue->data[queue->rear]=element;
    queue->size++;
    queue->rear=(queue->rear+1)%queue->length;
}
// 元素出队列
int dequeue(Queue *queue) {
    //判断队列是否为空
    if (queue->size==0) {
        return -1;
    }
    //从front指向的位置进行出队
    int n=queue->data[queue->front];
    queue->front=(queue->front+1)%queue->length;
    queue->size--;
    return n;
}
// 释放队列内存
void destroyQueue(Queue *queue) {
    free(queue->data);
    queue->data=NULL;
    queue->size=0;
    queue->front=0;
    queue->length=0;
    queue->rear=0;


}
// 遍历队列
void printQueue(Queue *queue) {
    for (int i = queue->front,j=0; j < queue->size; ++i,j++) {
        printf("%d ",queue->data[i%queue->length]);
    }
    printf("\n");
}

int main() {
    Queue myQueue;

    // 初始化队列
    initQueue(&myQueue, 5);
    printf("初始化队列,初始容量为5\n");

    // 入队元素
    enqueue(&myQueue, 1);
    enqueue(&myQueue, 2);
    enqueue(&myQueue, 3);

    printf("队列内元素个数:%zu\n", getSize(&myQueue));

    printQueue(&myQueue);

    // 出队元素
    printf("出队元素:%d\n", dequeue(&myQueue));
    printQueue(&myQueue);
    // 释放队列内存
    destroyQueue(&myQueue);
    printf("队列内存已释放\n");


    return 0;
}