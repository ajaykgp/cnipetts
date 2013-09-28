

#include <stdio.h>

int main(void) {
    char *s = "this is a very \ 
        very very \
        long string";
    char ch = '\142';
    printf("%s\n%c\n", s, ch);
    return 0;
}
