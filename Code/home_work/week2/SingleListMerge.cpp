#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef int ElemType;

typedef struct node {
    ElemType data;
    struct node *next;
}Node;

void CreateList(Node *&head, ElemType *p, int n);
void MergeList(Node *&head1, Node *head2);

int main() {
    int arr1[MAX], arr2[MAX];
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; ; i++) {
        scanf("%d", &arr1[i]);
        if (!arr1[i]) break;
        cnt1++;
    }
    for (int i = 0; ; i++) {
        scanf("%d", &arr2[i]);
        if (!arr2[i]) break;
        cnt2++;
    }
    Node *List1, *List2;
    CreateList(List1, arr1, cnt1);
    CreateList(List2, arr2, cnt2);
    MergeList(List1, List2);
    Node *ptr;
    ptr = List1;
    ptr->next = List1->next;
    while (1) {
        printf("%d", ptr->data);
        ptr = ptr->next;
        if (ptr != NULL) printf(" ");
        else break;
    }
    return 0;
}

void CreateList(Node *&head, ElemType *p, int n) {
    head = (Node *)malloc(sizeof(Node));
    head->data = p[0];
    head->next = NULL;
    Node *tail;
    tail = head;
    Node *ptr;
    for (int i = 1; i < n; i++) {
        ptr = (Node *)malloc(sizeof(Node));
        ptr->data = p[i];
        ptr->next = NULL;
        tail->next = ptr;
        tail = ptr;
    }
}

void MergeList(Node *&head1, Node *head2) {
    Node *front, *rear;
    front = head1;
    rear = head1->next;
    Node *ptr;
    Node *p = head2;
    while (rear != NULL) {
        while (p != NULL) {
            int temp = p->data;
            if(front->data < temp && temp < rear->data) {
                ptr = (Node *)malloc(sizeof(Node));
                ptr->data = temp;
                front->next = ptr;
                ptr->next = rear;
                front = ptr;
            }
            p = p->next;
        }
        front = rear;
        rear = rear->next;
        p = head2;
    }
}