/*
 * @desc: this program reads in an integer n from stdin. It prints
 *        all combinations of balanced n pairs of parentheses, i.e.,
 *        n '(' and n ')'. 
 *
 *        A recursive function is used to compute all strings having
 *        balanced parentheses. The logic is simple.  
 *
 * @author: Ajay
 * @time: Monday 17 December 2012, 8:36 PM
 *
 *
 */

#include <stdio.h>

#define MAX_LEN 100

void print_paran(int pos, int n, int open, int close);

int main(void) {
    int n;
    scanf("%d", &n);
    print_paran(0, n, 0, 0);
    return 0;
}

void print_paran(int pos, int n, int open, int close) {
    static char s[MAX_LEN];
    static int count = 0;
    if(close == n) {
        s[pos] = '\0';
        printf("%2d. %s\n", ++count, s);
        return;
    }
    if(open < n) {
        s[pos] = '(';
        print_paran(pos + 1, n, open + 1, close);
    }
    if(open > close) {
        s[pos] = ')';
        print_paran(pos + 1, n, open, close + 1);
    }
}
