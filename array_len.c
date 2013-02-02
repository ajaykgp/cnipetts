/*
 *
 *
 */

#include <stdio.h>

int main(void) {
    int len, a[10] = {0};
    len = *(&a + 1) - a; // len = 1[&a] - a
    printf("%d\n", len);
    return 0;
}
