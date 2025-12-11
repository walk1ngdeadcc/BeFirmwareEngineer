#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    size_t size;
} LinkedList;

// 初始化链表
void initLinkedList(LinkedList *linkedList) {
    linkedList->head = NULL;
    linkedList->size = 0;
}

// 返回链表的长度
size_t getLength(LinkedList *list) {
    return list->size;
}

// 在指定位置插入元素
void insertAt(LinkedList *list, size_t index, int element) {
    if (index > list->size) {
        return;
    }
    Node *newNode = malloc(sizeof(Node));
    newNode->data = element;
    if (index == 0) {
        newNode->next = list->head;
        list->head=newNode;
    } else {
        Node *node = list->head;
        for (int i = 0; i < index-1; ++i) {
            node = node->next;
        }
        newNode->next = node->next;
        node->next = newNode;
    }
    list->size++;
}

//在末尾插入元素
void insertAtEnd(LinkedList *list, int element) {
    insertAt(list,list->size,element);
}

//删除指定位置元素并放回
int deleteAt(LinkedList *list, int index) {
    if (index > list->size) {
        return -1;
    }
    int deleteElement = 0;
    if (index == 0) {
        Node *deleteNode = list->head;
        deleteElement = deleteNode->data;
        list->head = deleteNode->next;
        free(deleteNode);
    } else {
        Node *preNode = list->head;
        for (int i = 0; i < list->size - 1; ++i) {
            preNode = preNode->next;
        }
        Node *deleteNode = preNode->next;
        deleteElement = deleteNode->data;
        preNode->next = deleteNode->next;
        free(deleteNode);
    }

    list->size--;
    return deleteElement;
}
//删除末尾元素
int deleteAtEnd(LinkedList *list) {
    return deleteAt(list,list->size-1);
}
// 查看指定位置元素
int searchAt(LinkedList *list,int index) {
    if (index>=list->size||index<0) {
        return -1;
    }
    Node *node=list->head;
    for (int i = 0; i < list->size; ++i) {
        node=node->next;
    }
    return node->data;
}
// 修改指定位置元素
void modifyAt(LinkedList *list,size_t index,int element) {
    if (index>list->size-1) {
        return;
    }
    Node *node=list->head;
    for (int i = 0; i < list->size; ++i) {
        node=node->next;
    }
    node->data=element;
}

void destroyLinkedList(LinkedList * list) {
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

    insertAtEnd(&myList, 1); // 链表尾部插入元素1
    insertAtEnd(&myList, 2); // 链表尾部插入元素2
    printf("向链表插入了2个元素\n");

    printf("链表长度为: %zu\n", getLength(&myList)); // 获取链表长度

    insertAt(&myList, 1, 3); // 在索引1处插入元素3
    printf("在索引1处插入元素3\n");

    printf("链表长度为: %zu\n", getLength(&myList)); // 再次获取链表长度

    printf("索引1处的元素为: %d\n", searchAt(&myList, 1)); // 获取索引1处的元素

    modifyAt(&myList, 0, 4); // 修改索引0处的元素
    printf("把索引0处的元素修改为4\n");

    printf("删除索引1处的元素,该元素值是: %d\n", deleteAt(&myList, 1)); // 删除索引1处的元素
    destroyLinkedList(&myList); // 销毁链表
    printf("链表销毁成功!\n");
    return 0;
}
