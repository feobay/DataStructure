#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct node {
    int exp;//指数
    float coe;//系数
    struct node *next;
}Node;

void CreateList(Node *&head) {
    int n;
    cin >> n;
    head = (Node *)malloc(sizeof(Node));
    //scanf("%f", &(head->coe));
    //scanf("%d", &(head->exp));
    cin >> head->coe >> head->exp;
    head->next = NULL;
    Node *tail;
    tail = head;
    Node *p;
    for (int i = 1; i < n; i++) {
        p = (Node *)malloc(sizeof(Node));
        //scanf("%f %d", &(head->coe), &(head->exp));
        cin >> p->coe >> p->exp;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
}

/*
void addList(Node *&head1, Node *head2) {
    Node *p1 = head1;
    Node *p2 = head2;
    while(p1 != NULL) {
        p2 = head2;
        while (p2 != NULL) {
            if (p1->exp == p2->exp) {
                p1->coe = p1->coe + p2->coe;
                break;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
}
*/

void SelSortList(Node *&head) {
    Node *phead;
    phead = head;//指向当前未排序部分头结点
    Node *ptr;//用于遍历未排序节点
    Node *max;//用于指向数值最大节点
    ptr = head;
    while (phead != NULL) {
        max = phead;//注意指针语法
        while (ptr != NULL) {//找出最大节点
            if (ptr->exp > max->exp) {
                max = ptr;
            }
            //printf("ptr: %d ", ptr->data);
            //printf("min: %d\n", min->data);
            ptr = ptr->next;
        }
        if (max->exp > phead->exp) {
            int expT = max->exp;
            float coeT = max->coe;//暂时存储交换用的系数coe和指数exp
            max->coe = phead->coe;
            max->exp = phead->exp;
            phead->coe = coeT;
            phead->exp = expT;
        }
        phead = phead->next;
        ptr = phead;
    }
}

//遍历解法合并两个有序链表
//不断遍历两个链表，取出其中最大的一个追加到当前链表最后，直至两个链表其中一个为空
//再将另一链表追加到新链表最后
/*
Node *addList(Node *head1, Node *head2) {
    Node *MergeHead;
    Node *curNode = MergeHead;
    while (head1 && head2) {
        if (head1->exp > head2->exp) {
            curNode->next = head1;
            head1 = head1->next;
        } else if (head1->exp < head2->exp) {
            curNode->next = head2;
            head2 = head2->next;
        } else {
            head1->coe = head1->coe + head2->coe;
            curNode->next = head1;
            head1 = head1->next;
            head2 = head2->next;
        }
        curNode = curNode->next;
    }
    //将未加入链表的部分加入
    curNode->next = head1? head1 : head2;//如果head1不为空，追加head1，否则追加head2,此时head2为空也正常，保证尾节点为空。
    return MergeHead->next;
}
*/

//该版本改变了head1或者head2
Node *addList(Node *head1, Node *head2) {
    Node *MergeHead = NULL;
    if (head1->exp > head2->exp) {
        MergeHead = head1;
        head1 = head1->next;
    } else if (head1->exp == head2->exp) {
        MergeHead = head1;
        MergeHead->coe = head1->coe + head2->coe;
        head1 = head1->next;
        head2 = head2->next;
    } else {
        MergeHead = head2;
        head2 = head2->next;
    }
    Node *tmp = MergeHead;
    while (head1 && head2) {
        if (head1->exp > head2->exp) {
            MergeHead->next = head1;
            MergeHead = head1;
            head1 = head1->next;
        } else if (head1->exp == head2->exp) {
            MergeHead->next = head1;
            MergeHead = head1;
            MergeHead->coe = head1->coe + head2->coe;
            head1 = head1->next;
            head2 = head2->next;
        } else {
            MergeHead->next = head2;
            MergeHead = head2;
            head2 = head2->next;
        }
    }
    MergeHead->next = head1 ? head1 : head2;//将非空的部分加到结尾
    return tmp;
}

void del0(Node *&head) {//删除系数为零的节点
    while (head->coe == 0 && head != NULL) {
        head = head->next;
    }
    Node *front = head->next;
    Node *pre = head;
    while (front->next != NULL) {
        if(front->coe == 0) {//将下一节点的值域附到本节点，并把下一节点删除
            front->coe = front->next->coe;
            front->exp = front->next->exp;
            front->next = front->next->next;
            continue;
        }
        front = front->next;
        pre = pre->next;//不能写为pre = front,否则
    }
    //遍历完成还会差一个节点，再判断一下尾节点。改写法不会改变源节点，需要引入前置节点
    // if (front->coe == 0) {
    //     front = NULL;
    // }
    if (front->coe == 0) {
        pre->next = NULL;
    }
}

void disList(Node *&head) {//本处知识点可以写一个博客
    // while (head != NULL) {只有使用*&类型才会改变原来传入的指针，若传入类型为*head，则不会改变原指针，如果仅仅为*类型，则它可以改变源节点的下一节点指向
    //     printf("%.1f %d", head->coe, head->exp);
    //     //cout << head->coe << ' ' << head->exp;
    //     if(head->next != NULL) printf(" ");
    //     head = head->next;
    // }
    Node *tmp = head;
    while (tmp != NULL) {//若使用替代指针则不会影响原数组
        printf("%.1f %d", tmp->coe, tmp->exp);
        //cout << head->coe << ' ' << head->exp;
        if(tmp->next != NULL) printf(" ");
        tmp = tmp->next;
    }
}

void disNode(Node *head, int n) {
    for (int i = 1; i < n; i++) {//遍历到第n项，需要循环n-1次该语句
        if(head == NULL) break;
        head = head->next;
    }
    if (head != NULL) {
        printf("%.1f %d", head->coe, head->exp);
    } else {
        printf("Index exceeds limit!");
    }
}

int main() {
    Node *pol1, *pol2;//polymerization多项式
    CreateList(pol1);
    CreateList(pol2);
    SelSortList(pol1);
    SelSortList(pol2);
    Node *p;
    p = addList(pol1, pol2);
    while ((p->coe == 0) && p) {
        p = p->next;
    }
    del0(p);
    //del0(pol1);
    int x;
    cin >> x;
    disNode(p, x);
    //disNode(pol2, x);
    // printf("\n");
    // disList(p);
    // printf("\n");//用于测试原节点是否改变
    // disList(p);
    return 0;
}