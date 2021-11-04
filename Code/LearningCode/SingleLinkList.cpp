// 单链表相关操作
// 输入格式：第一行输入一个整数n, 第二行输入n个整数
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct node {
    ElemType data;
    struct node *next;
} Node;

//尾插法创建链表（结果正序）
void CreateListTail(Node *&head, ElemType number[], int n) {
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    Node *tail;
    tail = head;
    head->data = number[0];
    Node *pnt;
    for(int i = 1; i < n; i++) {
        pnt = (Node *)malloc(sizeof(Node));
        pnt->data = number[i];
        pnt->next = NULL;
        tail->next = pnt;
        tail = pnt;
    }
}

//头插法创建链表（结果逆序）
void CreateListHead(Node* &head, ElemType number[], int n) {
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    head->data = number[0];
    Node *pnt;
    for(int i = 1; i < n; i++) {
        pnt = (Node *)malloc(sizeof(Node));
        pnt->data = number[i];
        pnt->next = head;
        head = pnt;
    }
}

//删除节点
void del_node(Node* &p, int n) {//Node*表示指针类型， &p表示引用, 指针其本质就是数据类型，引用操作可以类比整型
    Node *dummy = (Node *)malloc(sizeof(Node));
    dummy->data = -1;
    dummy->next = p;
    Node *pnt1 = dummy;
    while (--n) {//n的最小值为1
        dummy = dummy->next;
    }
    if (dummy->next == p) {
        p = p->next;
        free(dummy->next);
    } else {
        Node* pnt2 = dummy->next;
        dummy->next = dummy->next->next;
        free(pnt2);
    }
    free(pnt1);
}

//插入操作
void insert_node(Node* &p, ElemType num, int n) {//num表示要插入的值, n表示要插入到第几个位置
    if (n == 1) {
        Node* tmp = (Node *)malloc(sizeof(Node));
        tmp->data = num;
        tmp->next = p;
        p = tmp;
        return;
    }
    n--;
    Node *dummy = p;
    while (--n) {
        dummy = dummy->next;
    }
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = num;
    tmp->next = dummy->next;
    dummy->next = tmp;
}

//遍历输出链表
void disList(Node *head, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    ElemType arr[100];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    Node *ListTail, *ListHead;
    //头插法创建
    CreateListTail(ListTail, arr, n);
    printf("ListTail: ");
    disList(ListTail, n);
    printf("\n");
    //尾插法创建
    CreateListHead(ListHead, arr, n);
    printf("ListHead: ");
    disList(ListHead, n);
    //删除尾插法链表的第3个节点
    del_node(ListTail, 3);
    printf("\nListTail(Deleted): ");
    disList(ListTail, n - 1);
    printf("\n");
    //在头插法链表的第1个位置插入一个节点
    insert_node(ListHead, 19, 1);
    printf("ListHead(Inserted): ");
    disList(ListHead, 6);
    return 0;
}