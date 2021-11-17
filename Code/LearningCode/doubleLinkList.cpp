//双链表的创建，遍历，插入，删除
#include<cstdio>
#include<cstdlib>
typedef int Elemtype;
typedef struct DoubleNode {
    int val;
    struct DoubleNode *prior, *rear;
} DNode;

//尾插法创建
void Create_tail(DNode* &head, int *arr, int n) {
    head = (DNode *)malloc(sizeof(DNode));
    head->prior = head->rear = NULL;
    head->val = arr[0];
    DNode *pnt, *tail = head;
    for (int i = 1; i < n; i++) {
        pnt = (DNode *)malloc(sizeof(DNode));
        pnt->prior = tail;
        pnt->rear = NULL;
        pnt->val = arr[i];
        tail->rear = pnt;
        tail = pnt;
    }
}

//正逆序遍历
void disDList(DNode *head) {
    printf("The DList: ");
    printf("%d ", head->val);
    while (head->rear) {
        head = head->rear;
        printf("%d ", head->val);
    }
    printf("\n");
    printf("The DList(inverted): %d ", head->val);
    while (head->prior) {
        head = head->prior;
        printf("%d ", head->val);
    }
    printf("\n");
}

//在第k个节点后插入节点x（k从0开始）
void insertDNode(DNode *&head, int k, int x) {
    printf("%d is inserted into the NO.%d (pos)!\n", x, k);
    DNode *pnt;
    pnt = (DNode *)malloc(sizeof(DNode));
    pnt->val = x;
    if (!k) {
        pnt->rear = head;
        pnt->prior = NULL;
        head->prior = pnt;
        head = pnt;
        return;
    }
    DNode *p = head;
    while(--k) {
        p = p->rear;
    }
    
    pnt->prior = p;
    pnt->rear = p->rear;
    p->rear = pnt;
    //第k个节点的下一个节点非空时
    if(pnt->rear) pnt->rear->prior = pnt;
}

//删除第k + 1个节点（序号从0开始）
void delDNode(DNode *&head, int k) {
    printf("The No.%d node is deleted!\n");
    if (k == 0) {
        head = head->rear;
        head->prior = NULL;
        return;
    }
    DNode *p = head;
    while(--k) {
        p = p->rear;
    }
    p->rear = p->rear->rear;
    if (p->rear == NULL) return;
    p->rear->prior = p;
}

int main() {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 10;
    DNode *DList1;
    Create_tail(DList1, a, n);
    disDList(DList1);
    printf("\n");
    delDNode(DList1, 0);
    printf("\n");
    disDList(DList1);
    printf("\n");
    insertDNode(DList1, 1, 19);
    printf("\n");
    disDList(DList1);
    return 0;
}