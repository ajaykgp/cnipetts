/* 
 *
 * Desc: This program reads in two strings s, t from stdin and
 *       computes minimum-cost way to edit s into t using
 *       three operations of insert, delete and substitute.
 *
 *       The problem satisfies the two conditions for dynamic
 *       programming - optimal substructure and overlapping subproblems.
 *       We define edit[i][j] the cost of editing the first i chars of
 *       s into first j chars of t. Then edit[i][j] is the minimum of the the below
 *       three:
 *              edit[i-1][j-1] + sub, (sub = 0 if s[i] == t[j] else s = 1)  
 *                             for matching or substitution resp.
 *                                    
 *              edit[i][j-1] + 1, inserting t[j] into s[i+1] so now we have to
 *                                edit the first i chars of s into first j-1 chars of t.
 *
 *              edit[i-1] + 1, deleting s[i] so that now we have to edit the first 
 *                             i-1 chars of s into the first j chars of t.
 *
 *        edit[m][n] stores the minimum-cost way to edit the string s into the
 *        string t, where m = strlen(s) and n = strlen(t);
 *
 *
 * Author: Ajay
 * 
 * Time: Tuesday, 27 November 2012, 12:41 AM
 *
 *
 *
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX 1000

int min(int a, int b, int c);
int stringCompare(char *s, char *t);

int main(void) {
    char s[MAX], t[MAX];
    char c;
    int i = 0, j = 0;

    while((c = getchar()) != '\n') s[i++] = c;
    s[i] = '\0';
    
    while((c = getchar()) != '\n') t[j++] = c;
    t[j] = '\0';

    int d = stringCompare(s, t);
    printf("%d\n", d);

    return 0;
}

int stringCompare(char *s, char *t) {
    char edit[MAX][MAX];

    int m = strlen(s);
    int n = strlen(t);

    int i, j;
    int minCost, sub;
   
    for(i = 0; i < MAX; i++) edit[i][0] = i;
    for(j = 0; j < MAX; j++) edit[0][j] = j;

    for(i = 1; i <= m; i++) {
        for(j = 1; j <= n; j++) {
            (s[i-1] == t[j-1]) ? (sub = 0) : (sub = 1);
            int match = edit[i-1][j-1] + sub;
            int insert = edit[i][j-1] + 1;
            int delete = edit[i-1][j] +1;

            minCost = min(match, insert, delete);
            edit[i][j] = minCost;
        }
    }
    return edit[m][n];
}

int min(int a, int b, int c) {
    int res = a;
    if(res > b) res = b;
    if(res > c) res = c;
    return res;
}
