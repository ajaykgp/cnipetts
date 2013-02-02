/*
 *
 *
 *
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX 1000
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int partition(char a[], int p, int r);
void qsort(char a[], int p, int r);

int main(void) {
    char c, a[MAX];
    int i = 0;
    while((c = getchar()) != '\n') a[i++] = c;
    a[i] = '\0';
    
    qsort(a, 0, strlen(a)-1);
    printf("%s\n", a);

    return 0;
}

int partition(char a[], int p, int r) {
    int i = p - 1, j;
    char pivot = a[r], temp;
    for(j = p; j < r; j++) 
        if(a[j] <= pivot) {
            SWAP(a[i+1], a[j], temp);
            i++;
        }
    SWAP(a[i+1], a[r], temp);
    return i+1;
}

void qsort(char a[], int p, int r) {
    if(p >= r) return;
    int q = partition(a, p, r);
    qsort(a, p, q-1);
    qsort(a, q+1, r);
}
