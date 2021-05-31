#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct node {
    ElemType data;
    struct node *next;
} Node;

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

void CreateListHead(Node *&head, ElemType number[], int n) {
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
    CreateListTail(ListTail, arr, n);
    printf("ListTail: ");
    disList(ListTail, n);
    printf("\n");
    CreateListHead(ListHead, arr, n);
    printf("ListHead: ");
    disList(ListHead, n);
    //printf("\n");
    return 0;
}