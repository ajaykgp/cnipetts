/* 
 * Desc: This program recursively computes all permutations
 *       of a given string read from stdin and prints them.
 *
 * Author: Ajay
 *
 * Time: Thursday, 29 November 2012, 12:33 AM 
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX 100
#define SWAP(a, b, c) ((c) = (a), (a) = (b), (b) = (c))

void permute(char s[], int k);

int main(void) {
    char ch;
    char s[MAX];
    int i = 0;
    while((ch = getchar()) != '\n') s[i++] = ch;
    s[i] = '\0';

    permute(s, 0);

    return 0;
}

void permute(char s[], int k) {
    int l = strlen(s);
    int i;
    static int count = 0;
    char temp;
    if(k == l-1) {
        printf("%4d. %s\n", ++count, s);
        return;
    }
    else {
        for(i = k; i < l; i++) {
            SWAP(s[k], s[i], temp);
            permute(s, k+1);
            SWAP(s[k], s[i], temp);
        }
    }
}
