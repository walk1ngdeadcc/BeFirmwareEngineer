#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *data;
    size_t length;
    size_t size;
}DynamicArray;
// //初始化动态数组
void initDynamicArray(DynamicArray *array, size_t initialCapacity) {
    array->data=malloc(sizeof(int)*initialCapacity);
    array->length=initialCapacity;
    array->size=0;
}
// //释放动态数组内存
void destroyDynamicArray(DynamicArray *array) {
    free(array->data);
    array->length=0;
    array->size=0;

}
// //调整动态数组内存大小
void resizeDynamicArray(DynamicArray *array, size_t newCapacity) {
    array->data=realloc(array->data,sizeof(int)*newCapacity);
    array->length=newCapacity;
}
// //获取动态数组长度（元素个数）
size_t getLength(const DynamicArray *array) {
    return array->size;
}
// //在指定位置插入新元素
void insertAt(DynamicArray *array, size_t index, int element) {
    if (index>array->size) {
        return;
    }
    if (array->size==array->length) {
        array->length=array->length*2;
        resizeDynamicArray(array,array->length);
    }
    //添加元素
    for (int i=array->size;i>index;i--) {
        array->data[i]=array->data[i-1];
    }
    array->data[index]=element;
    array->size++;
}
// //在末尾插入新元素
void insertEnd(DynamicArray *array, int element) {
    if (array->size==array->length) {
        array->length=array->length*2;
        resizeDynamicArray(array,array->length);
    }
    array->data[array->size]=element;
    array->size++;
}
// //删除指定位置的元素并返回被删除的元素
int deleteAt(DynamicArray *array, size_t index) {
    if (index>=array->size) {
        return -1;
    }
    int temp=array->data[index];
    for (int i=index;i<array->size-1;i++) {
        array->data[index]=array->data[index+1];
    }
    array->size--;
    return temp;
}
// //删除末尾的元素并返回被删除的元素
int deleteEnd(DynamicArray *array) {
    int temp=array->data[array->size-1];
    array->size--;
    return temp;
}
// //遍历所有的元素
void print(DynamicArray *array) {
    for (int i=0;i<array->size;i++) {
        printf("%d ",array->data[i]);
    }
}

int main() {
    DynamicArray myArray; // 声明动态数组

    // 初始化动态数组
    initDynamicArray(&myArray, 2);
    printf("初始化动态数组,初始容量为2\n");

    // 向动态数组尾部插入元素
    insertEnd(&myArray, 1);
    insertEnd(&myArray, 2);
    printf("向动态数组尾部插入了2个元素\n");

    // 打印动态数组当前长度
    printf("动态数组当前长度:%zu\n", getLength(&myArray));

    // 在索引1的位置插入元素3
    insertAt(&myArray, 1, 3);
    printf("在索引1的位置插入元素3\n");

    // 再次打印动态数组当前长度
    printf("动态数组当前长度:%zu\n", getLength(&myArray));

    // 删除索引1的元素
    printf("删除索引1的元素,该元素是%d\n", deleteAt(&myArray, 1));

    // 删除动态数组末尾元素
    printf("删除动态数组末尾元素,该元素是%d\n", deleteEnd(&myArray));

    // 释放动态数组内存
    destroyDynamicArray(&myArray);
    printf("动态数组内存释放完成\n");



}