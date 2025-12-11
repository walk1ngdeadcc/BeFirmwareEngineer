#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    size_t length;
} DynamicArray;

//初始化数组
void initDynamicArray(DynamicArray *array, size_t capacity) {
    array->data = malloc(capacity * sizeof(int));
    array->size = 0;
    array->length = capacity;
}

//调整动态数组内存大小
void resizeDynamicArray(DynamicArray *array, size_t newCapacity) {
    array->data = realloc(array, newCapacity);
    array->length = newCapacity;
}

// 获取元素个数
int getLength(DynamicArray *array) {
    return array->size;
}

// 在指定位置插入元素
void insertAt(DynamicArray *array, size_t index, size_t element) {
    if (index > array->size) {
        return;
    }
    if (array->size == array->length) {
        resizeDynamicArray(array, array->length * 2);
    }
    for (int i = array->size; i > index; i--) {
        array->data[i] = array->data[i - 1];
    }
    array->data[index] = element;
    array->size++;
}

// 在末尾插入元素
void insertAtEnd(DynamicArray *array, size_t element) {
    if (array->size == array->length) {
        resizeDynamicArray(array, array->length * 2);
    }
    array->data[array->size] = element;
    array->size++;
}

// 删除指定位置元素并返回元素
int deleteIndex(DynamicArray *array, size_t index) {
    if (index >= array->size) return -1;
    int temp=array->data[index];
    for (int i = index ; i < array->size-1; ++i) {
        array->data[i]=array->data[i+1];
    }
    array->size--;
    return temp;
}
// 删除末尾元素并返回
int deleteEnd(DynamicArray *array) {
    int temp=array->data[array->size-1];
    array->size--;
    return temp;
}
// 遍历所有元素
void print(DynamicArray *array) {
    for (int i = 0; i < array->size; ++i) {
        printf("%d ",array->data[i]);
    }

}
// 释放数组内存
void freeArray(DynamicArray *array) {
    free(array->data);
    array->size=0;
    array->length=0;
}
int main() {
    DynamicArray array;
    initDynamicArray(&array,5);
    insertAtEnd(&array,1);
    insertAtEnd(&array,2);
    insertAtEnd(&array,3);
    insertAtEnd(&array,4);
    printf("向动态数组尾部插入了4个元素\n");
    printf("%d\n",getLength(&array));
    print(&array);
    return 0;
}
