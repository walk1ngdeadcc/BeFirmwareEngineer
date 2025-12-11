#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
}Node;
typedef struct {
    Node *head;
    size_t size;
}LinkedList;
// 初始化链表
void initLinkedList(LinkedList *list) {
    list->head=NULL;
    list->size=0;
}
// 返回链表的长度
size_t getLength(const LinkedList *list) {
    return list->size;
}
// 在指定位置插入元素
void insertAt(LinkedList *list, size_t index, int element) {
    if (index>list->size) {
        return;
    }
    Node *newNode=malloc(sizeof(Node));
    newNode->data=element;
    if (index==0) {
        newNode->next=list->head;
        list->head=newNode;
    }else {
        Node *preNode=list->head;
        for (int i = 0; i < index-1; ++i) {
            preNode=preNode->next;
        }
        newNode->next=preNode->next;
        preNode->next=newNode;
    }
    list->size++;
}
// 在末尾插入元素
void insertEnd(LinkedList *list, int element) {
    insertAt(list,list->size,element);
}
// 删除指定位置的元素并返回被删除的元素
int deleteAt(LinkedList *list, size_t index) {
    if (index>list->size-1) {
        return -1;
    }
    int deleteElement=0;
    if (index==0) {
        deleteElement=list->head->data;
        Node *deleteNode=list->head;
        list->head=deleteNode->next;
        list->size--;
        free(deleteNode);
    }else {
        Node *preNode=list->head;
    for (int i = 0; i < index-1; ++i) {
        preNode=preNode->next;
    }
    Node *deleteNode=preNode->next;
        deleteElement=deleteNode->data;
    preNode->next=deleteNode->next;
        list->size--;
        free(deleteNode);
    }
    return deleteElement;
}
// 删除末尾元素
int deleteEnd(LinkedList *list) {
    deleteAt(list,list->size-1);
}
// 获取指定位置的元素
int getElementAt(const LinkedList *list, size_t index) {
    if (index>list->size-1) {
        return -1;
    }
    Node *getNode=list->head;
    for (int i = 0; i < index; ++i) {
        getNode=getNode->next;
    }
    return getNode->data;
}
// 修改指定位置的元素
void modifyAt(LinkedList *list, size_t index, int newValue) {
        if (index>list->size-1){return;}
    Node *modifyNode=list->head;
    for (int i = 0; i < index; ++i) {
        modifyNode=modifyNode->next;
    }
    modifyNode->data=newValue;
}
// 释放链表内存
void destroyLinkedList(LinkedList *list) {
    Node *currentNode=list->head;
    while (currentNode!=NULL) {
        Node *temp=currentNode;
        currentNode=currentNode->next;
        free(temp);
    }
    list->head=NULL;
    list->size=0;
}
int main() {
    LinkedList myList; // 声明链表

    initLinkedList(&myList); // 初始化链表
    printf("初始化链表成功!\n");

    insertEnd(&myList, 1); // 链表尾部插入元素1
    insertEnd(&myList, 2); // 链表尾部插入元素2
    printf("向链表插入了2个元素\n");

    printf("链表长度为: %zu\n", getLength(&myList)); // 获取链表长度

    insertAt(&myList, 1, 3); // 在索引1处插入元素3
    printf("在索引1处插入元素3\n");

    printf("链表长度为: %zu\n", getLength(&myList)); // 再次获取链表长度

    printf("索引1处的元素为: %d\n", getElementAt(&myList, 1)); // 获取索引1处的元素

    modifyAt(&myList, 0, 4); // 修改索引0处的元素
    printf("把索引0处的元素修改为4\n");

    printf("删除索引1处的元素,该元素值是: %d\n", deleteAt(&myList, 1)); // 删除索引1处的元素

    destroyLinkedList(&myList); // 销毁链表
    printf("链表销毁成功!\n");

    return 0;
}