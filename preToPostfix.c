/*
 *
 *
 *
 *
 */

#include <stdio.h>

int main(void) {
    char ch = getchar();
    (ch == '+' || ch == '-' || ch == '*' || ch == '/') ? main(), main() : 0;
    putchar(ch);
    return 0;
}
