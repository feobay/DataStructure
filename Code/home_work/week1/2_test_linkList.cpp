#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *create_node(int new_number) {
    Node *temp_node;
    temp_node = (Node *)malloc(sizeof(Node));
    temp_node->data = new_number;
    temp_node->next = NULL;
    return temp_node;
}

int main() {
    int n;
    int cnt = 0;
    Node *head, *tail;
    head = (Node *)malloc(sizeof(Node));
    head->next=NULL;
    tail = head;
    while(1) {
        scanf("%d", &n);
        if (n == 0) break;
        if(cnt == 0) {
            tail->data = n;
            cnt++;
            continue;
        }
        Node *temp = create_node(n);
        tail->next = temp;
        tail = temp;
        cnt++;
    }
    Node *pnt = head;
    for (int i = 0; i < cnt; i++) {
        printf("%d ", pnt->data);
        pnt = pnt->next;
    }
    return 0;
}