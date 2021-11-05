// 第一行输入整数 N，表示字符串 P 的长度。

// 第二行输入字符串 P。

// 第三行输入整数 M，表示字符串 S 的长度。

// 第四行输入字符串 S。

#include<iostream>
using namespace std;
const int N = 10010, M = 100010;
char p[N], s[M];//p为模式串， s为主串（即待匹配串）
int n, m;
int ne[N];

int main() {
    cin >> n >> p + 1 >> m >> s + 1;//p+1, s+1, 表示从下标为1开始输入
    //求next
    for (int i = 2, j = 0; i <= n; i++) {//ne[1] = 0, 所以不需要求，下标从2开始
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
    }
    //kmp匹配
    for (int i = 1, j = 0; i <= m; i++) {
        while (j && s[i] != p[j + 1]) j = ne[j];//主串中已匹配串最后位的下一位为s[i]
        if (s[i] == p[j + 1]) j++;//如果相等，则已匹配的长度j增加1
        if (j == n) {
            printf("%d ", i - n);//主串下标从正常来讲本处为i - n + 1, 但是本次要求下标从0开始，所以下标都要减一
            j = ne[j];//匹配成功之后再往后退一步
        }
    }
    return 0;
}