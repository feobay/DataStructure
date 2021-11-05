#include<iostream>
using namespace std;
const int N = 10010, M = 100010;
char p[N], s[M];//p为模式串， s为主串（即待匹配串）
int n, m;
int ne[N];

int main() {
    cin >> n >> p + 1 >> m >> s + 1;
    //求next
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
    }
    //kmp匹配
    for (int i = 1, j = 0; i <= m; i++) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == n) {
            printf("%d ", i - n);//主串下标从正常来讲本处为i - n + 1, 但是本次要求下标从0开始，所以下标都要减一
        }
    }
    return 0;
}