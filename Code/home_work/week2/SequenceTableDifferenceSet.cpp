#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
typedef int ElemType;
typedef struct node {
    ElemType data;
    struct node *next;
} Node;

void CreateList(Node *&head, ElemType arr[], int n);
void delNode(Node *&head, ElemType x, int &n);
void disList(Node *head, int n);

int main () {
    int arr[MAX];
    int arr2[MAX];
    int n1 = 0, n2 = 0;
    int i = 0;
    while(1) {
        scanf("%d", &arr[i]);
        if (arr[i] == 0) break;
        i++;
    }
    n1 = i;
    i = 0;
    Node *List1;
    CreateList(List1, arr, n1);
    while(1) {
        scanf("%d", &arr2[i]);
        if (arr2[i] == 0) break;
        i++;
    }
    n2 = i;
    Node *List2;
    CreateList(List2, arr2, n2);
    Node *ptr;
    ptr = List2;
    for (int j = 0; j < n2; j++) {
        delNode(List1, ptr->data, n1);
        ptr = ptr->next;
    }
    disList(List1, n1);
    return 0;
}

void CreateList(Node *&head, ElemType arr[], int n) {
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    Node *tail;
    tail = head;
    Node *ptr;
    head->data = arr[0];
    for (int i = 1; i < n; i++) {
        ptr = (Node *)malloc(sizeof(Node));
        ptr->data = arr[i];
        ptr->next = NULL;
        tail->next = ptr;
        tail = ptr;
    }
}

void delNode(Node *&head, ElemType x, int &n) {
    Node *front, *rear;
    front = head;
    rear = front->next;
    while (rear->next != NULL) {
        if (head->data == x) {
            head = rear;
            front = head;
            rear = rear->next;
            n--;
            continue;
        }
        if (rear->data == x) {
            rear = rear->next;
            front->next = rear;
            n--;
            continue;
        }
        front = rear;
        rear = rear->next;
    }
    //此时raer指向尾部
    if (rear->data == x) {
        front->next = NULL;
        n--;
    }
}

void disList(Node *head, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", head->data);
        if(i != n - 1) printf(" ");
        head = head->next;
    }
}