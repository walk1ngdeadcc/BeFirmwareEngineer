#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    size_t length;
}DynamicArray;
//初始化动态数组
void initDynamicArray(DynamicArray *array,size_t capacity) {
    array->data=malloc(capacity*sizeof(int));
    array->size=0;
    array->length=capacity;
}
//释放动态数组内存
void destroyDynamicArray(DynamicArray *array) {
    free(array->data);
    array->size=0;
    array->length=0;
}
//调整动态数组内存大小
void resizeDynamicArray(DynamicArray *array,size_t newCapacity) {
    array->data=realloc(array->data,sizeof(int)*newCapacity);
    array->length=newCapacity;
}
//获取动态数组长度（元素个数）
size_t getLength(DynamicArray *array) {
    return array->size;
}
//在指定位置插入新元素
void insertAt(DynamicArray *array,size_t index,int element) {
    if (index>array->size)
}
//在末尾插入新元素
void insertAtEnd(DynamicArray *array,int element) {
    if (array->size==array->length) {
        resizeDynamicArray(array,2*array->length);
    }
    array->data[array->size]=element;
    array->size++;
}
//删除指定位置的元素并返回被删除的元素
//删除末尾的元素并返回被删除的元素
//打印数组
void printArray(DynamicArray *array) {
    for (int i = 0; i < array->size; ++i) {
        printf("%d ",array->data[i]);
    }
    printf("\n");
}
int main() {
    DynamicArray array;
    DynamicArray *p=&array;

    initDynamicArray(&array,10);
    //initDynamicArray(p,10);
    printf("数组初始化成功，容量为10\n");
    printf("数组的元素个数为%zu\n",getLength(&array));
    // printf("末尾插入元素：1\n");
    // insertAtEnd(&array,1);
    for (int i = 0; i < 10; ++i) {
        insertAtEnd(&array,i);
    }
    printf("数组的容量：%zu\n",array.length);
    printf("数组的元素个数为%zu\n",getLength(&array));
    printf("打印数组：");
    printArray(&array);
    insertAtEnd(&array,10);
    printf("数组的容量：%zu\n",array.length);
    printf("数组的元素个数为%zu\n",getLength(&array));
    destroyDynamicArray(&array);
    printf("数组销毁成功");
    return 0;
}