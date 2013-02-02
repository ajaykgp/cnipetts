/*
 * Desc: This program reads in two strings from stdin: text string t and pattern string
 *       p and prints the number of occurrences of the pattern string p in the text 
 *       string t.
 *
 * Algo: The algorithm is simple. Traverse the text string looking for a match. As we
 *       find a match, we increase the count and continue the iteration till we reach
 *       len(t) - len(p). Complexity of the algorithm is O(mn) where m and n are the lengths 
 *       of the pattern string and the text string respectively.
 *
 * Author: Ajay
 *
 * Time: Sunday 18 November 2012, 2:42 PM
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX 500

int countMatch(char p[], char t[]);

int main(void) {
    char t[MAX], p[MAX], ch;
    int i = 0, count;

    while((ch = getchar()) != '\n') t[i++] = ch;
    t[i] = '\0';

    i = 0;
    while((ch = getchar()) != '\n') p[i++] = ch;
    p[i] = '\0';
    
    count = countMatch(p, t);
    printf("%d\n", count);

    return 0;
}

int countMatch(char p[], char t[]) {
    int i, j;
    int m, n;
    int count = 0;

    m = strlen(p);
    n = strlen(t);

    if(n < m) return count;

    for(i = 0; i <= n-m; i++) {
        j = 0;
        while((p[j] == t[i+j]) && (j < m)) j++;
        if(j == m) count++;
    }

    return count;
}
