#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *data;
    size_t size;
    size_t capacity;
}Stack;
// 初始化栈
void initStack(Stack *stack, size_t capacity) {
    stack->data=malloc(capacity*sizeof(int));
    stack->size=0;
    stack->capacity=capacity;
}
// 返回栈内元素个数
size_t getSize(const Stack *stack) {
    return stack->size;
}
// 添加新元素
void push(Stack *stack, int element) {
    if (stack->size==stack->capacity) {
        stack->capacity=stack->capacity*2;
        stack->data=realloc(stack->data,stack->capacity*sizeof(int));
    }
    stack->data[stack->size]=element;
    stack->size++;
}
// 栈顶元素出栈并返回
int pop(Stack *stack) {
    if (stack->size==0) {
        return -1;
    }
    stack->size--;
    return stack->data[stack->size];
}
// 释放栈内存
void destroyStack(Stack *stack) {
    free(stack->data);
    stack->size=0;
    stack->data=NULL;
    stack->capacity=0;
}

int main() {
    Stack myStack;

    // 初始化栈
    initStack(&myStack, 2);
    printf("初始化栈,初始容量为2\n");

    // 向栈压入元素
    push(&myStack, 1);
    push(&myStack, 2);

    printf("栈内元素个数:%zu\n", getSize(&myStack));

    // 弹出栈顶元素
    printf("弹出栈顶元素:%d\n", pop(&myStack));

    // 释放栈内存
    destroyStack(&myStack);
    printf("栈内存已释放\n");

    return 0;
}