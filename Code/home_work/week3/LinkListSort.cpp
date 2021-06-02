#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef int ElemType;
typedef struct node {
    ElemType data;
    struct node *next;
} Node;

void CreateList(Node *&head, ElemType *arr, int n);
void SelSortList(Node *&head, int n);
void disList(Node *head);

int main () {
    ElemType arr[MAX];
    int cnt = 0;
    for (int i = 0; ; i++) {
        scanf("%d", &arr[i]);
        if(arr[i] == 0) break;
        cnt++;
    }
    printf("%d\n", cnt);
    Node *List;
    CreateList(List, arr, cnt);
    SelSortList(List, cnt);
    disList(List);
    return 0;
}

void CreateList(Node *&head, ElemType *arr, int n) {
    head = (Node *)malloc(sizeof(Node));
    head->data = arr[0];
    head->next = NULL;
    Node *tail;
    tail = head;
    Node *p;
    for (int i = 1; i < n; i++) {
        p = (Node *)malloc(sizeof(Node));
        p->data = arr[i];
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
}

void SelSortList(Node *&head, int n) {
    Node *phead;
    phead = head;//指向当前未排序部分头结点
    Node *ptr;//用于遍历未排序节点
    Node *min;//用于指向数值最小节点
    ptr = head;
    while (phead != NULL) {
        min = phead;//注意指针语法
        while (ptr != NULL) {//找出最小节点
            if (ptr->data < min->data) {
                min = ptr;
            }
            printf("ptr: %d ", ptr->data);
            printf("min: %d\n", min->data);
            ptr = ptr->next;
        }
        if (min->data < phead->data) {
            int temp = min->data;
            min->data = phead->data;
            phead->data = temp;
        }
        phead = phead->next;
        ptr = phead;
    }
}

void disList(Node *head) {
    while(head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" ");
        head = head->next;
    }
}

