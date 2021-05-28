#include <iostream>
#include <stdio.h>
using namespace std;
int division_includes_7(int x) {
    while (x > 0) {
        if (x % 10 == 7) return 1;
        else x /= 10;
    }
    return 0;
}
int main () {
    int sum = 0;
    int n;
    scanf("%d", &n);
    int a[4] = {0};
    for (int i = 1; sum <= n; i++) {
        if (i % 7 == 0 || division_includes_7(i)) {
            a[i % 4 - 1]++;
            continue;
        }
        ++sum;
    }
    cout<<a[0]<<endl<<a[1]<<endl<<a[2]<<endl<<a[3];
    return 0;
}