#include<iostream>
using namespace std;
//数组模拟链表
//第一行输入一个整数m
//第二行开始后面m行，每行先输入一个字符
//若字符为'H'，则再输入一个整数x，表示在头结点插入x
//若字符为'D'，输入k，表示删除第 k 个插入的数后面的数（当 k 为 0 时，表示删除头结点）
//若字符为'I'，输入k x, 表示在第 k 个插入的数后面插入一个数 x（此操作中 k 均大于 0）

const int N = 100010;
//head相当于头指针，存储头结点的地址，这里作为下标使用
//e[N]存储节点的值，ne[N]相当于next指针，指向下一节点
//个人理解：idx记录链表大小，即节点个数, idx++相当于为节点申请一个新空间，此时idx则相当于该新创建节点的指针
//以下注释均按照指针的理解来说明，关于idx的理解如果有更好的方法欢迎讨论~
int head, e[N], ne[N], idx;

void init() {
    head = -1;
    idx = 0;
}

//将x插入到链表中并作为头结点
void add_to_head(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

//在下标为k的节点后插入值为x的节点（在动态链表中相当于在地址/指针为k的节点后插入一个值为x的节点）
void add(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];//idx的next指针指向k后一个节点
    ne[k] = idx;//k节点的next指针指向idx节点
    idx++;//创建一个新的空节点，并用idx指向它
}

//移除k节点后的一个节点
void remove(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    int m;
    scanf("%d", &m);
    init();
    while (m--) {
        char op;
        scanf(" %c", &op);//c前加一个空格，防止直接接收上一次的换行
        //其余解决方法见文末，使用cin则不会有此问题
        if (op == 'H') {
            int x;
            scanf("%d", &x);
            add_to_head(x);
        } else if (op == 'D') {
            int k;
            scanf("%d", &k);
            if (!k) {
                head = ne[head];
            }
            remove(k - 1);
        } else {
            int k, x;
            scanf("%d%d", &k, &x);
            add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i]) printf("%d ", e[i]);
    printf("\n");
    return 0;
}

/*
C语言的scanf()函数在接收输入单个字符时会把上一次输入的回车符号当做这次输入的字符，造成无法正确的输入字符数据。提供四种解决方法供借鉴。
在scanf()中使用'\n'屏蔽回车符号。

1.scanf("%d\n",&n); //使用'\n'过滤回车
scanf("%c",&c);

2.在scanf()格式串最前面添加空格，屏蔽回车字符
scanf("%d",&n);
scanf(" %c",&c); //%c前面加空格，过滤回车

3.在接收字符前，使用getchar()来读取一次回车符号
scanf("%d",&n);
getchar();  //专门用来读取上次输入的回车符号
scanf("%c",&c);

4.在接收字符前，使用fflush()清空输入流中缓冲区中的内容
scanf("%d",&n)
fflush(stdin);  //清空输入流缓冲区的字符，注意必须引入#include <stdlib.h>头文件
scanf("%c",&c);
*/