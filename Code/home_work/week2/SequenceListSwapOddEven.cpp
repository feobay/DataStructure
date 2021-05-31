#include <stdio.h>
#include <stdlib.h>
#define MAX 10001

void rearrange(int *p, int low, int high) {
    while (low < high) {
        while(low < high && p[low] % 2 != 0) {
            low++;
        }
        while(low < high && p[high] %2 == 0) {
            high--;
        }
        p[low] ^= p[high] ^= p[low] ^= p[high];
    }
}

void disArray(int *p, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", p[i]);
        i != n - 1 && printf(" ");
    }
}

int main () {
    int arr[MAX];
    int cnt = 0;
    for (int i = 0; ; i++) {
        scanf("%d", &arr[i]);
        if(arr[i] == 0) break;
        cnt++;
    }
    rearrange(arr, 0, cnt - 1);
    disArray(arr, cnt);
    return 0;
}