/*
 *
 *
 *
 *
 *
 */

#include <stdio.h>

#define MAX 100

int lis(int a[], int k);

int main(void) {
    int a[MAX], i = 0;
    int val, res;
    while(scanf("%d", &val) != EOF) 
        a[i++] = val;
    res = lis(a, i - 1);
    printf("\n%d\n", res);
    return 0;
}

int lis(int a[], int k) {
    if(k == 0) return 1;
    int i, len = 0, max = 0;
    for(i = 0; i < k; i++) {
        if(a[k] >= a[i]) len = lis(a, i) + 1;
        if(len > max) max = len;
    }
    //printf("%d\n", max);
    return max;
}

