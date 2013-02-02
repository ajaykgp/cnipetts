/*
 *
 * @desc: This program reads in two words(strings) s, t from stdin
 *        and find the minimum edit distance and the corresponding 
 *        edit sequence to transform the string s into the string
 *        t. The allowable operations are insert, delete and 
 *        substitute. The problem is solved using dynamic programming.
 *
 * @algo: Let d[i][j] denote the minimum edit distance between the first
 *        i chars of s and first j chars of t, i.e. between s[0..i] and
 *        t[0..j]. Then we have the following -
 *
 *        d[i][j] = 0 if i == 0 && j == 0
 *        d[i][j] = i if i != 0 && j == 0
 *        d[i][j] = j if i == 0 && j != 0
 *        d[i][j] = min(d[i-1][j-1] + subst(s[i-1], t[j-1]),
 *                      d[i][j-1] + insert(t[j-1]),
 *                      d[i-1][j] + delete(s[i-1]))
 *
 *                   where subst(c, d) is the cost of substituting
 *                   char c with char d, insert(c) is the cost of
 *                   inserting the char c, and delete(c) is the cost
 *                   of deleting the char in the string s (edit operations)
 *                   are done on string s.
 *
 *        To generate the edit sequence, we store the index of the cell in the 
 *        edit distance matrix which contributes to the minimum. In the edit 
 *        sequence: i = insert, d = delete, s = substitute, m = match.
 *        The complexity of the algorith is O(m*n) where m and n are lenghts of 
 *        the strings s and t respectively.
 *
 * @author: ajay
 * @time: Sunday 6 January 2013 12:22 PM
 *
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
    int p_i;
    int p_j;
    char op;
    int edit_dist;
} edit_struct;

int insert_cost(char c);
int delete_cost(char c);
int substitute_cost(char c, char d);

void edit_sequence(char s[], char t[]);
void print_sequence(edit_struct a[][MAX_LEN], int i, int j);

int main(void) {
    char s[MAX_LEN], t[MAX_LEN], val;
    int i = 0;
    while((val = getchar()) != '\n') s[i++] = val;
    s[i] = '\0';

    i = 0;
    while((val = getchar()) != '\n') t[i++] = val;
    t[i] = '\0';  

    edit_sequence(s, t); 
    return 0;
}

void edit_sequence(char s[], char t[]) {
    int m = strlen(s);  
    int n = strlen(t);          
    int i, j;
    int i_cost, d_cost, s_cost;
    edit_struct a[MAX_LEN][MAX_LEN];

    a[0][0].p_i = -1;
    a[0][0].p_j = -1;
    a[0][0].op = '\0';
    a[0][0].edit_dist = 0;

    for(i = 1; i <= m; i++) {
        a[i][0].p_i = i-1;
        a[i][0].p_j = 0;
        a[i][0].op = 'd';
        a[i][0].edit_dist = i;
    }

    for(j = 1; j <= n; j++) {
        a[0][j].p_i = 0;
        a[0][j].p_j = j-1;
        a[0][j].op = 'i';
        a[0][j].edit_dist = j;
    }
                                        
    for(i = 1; i <= m; i++) {
        for(j = 1; j <= n; j++) {
            i_cost = a[i][j-1].edit_dist + insert_cost(t[j-1]);
            d_cost = a[i-1][j].edit_dist + delete_cost(s[i-1]);
            s_cost = a[i-1][j-1].edit_dist + substitute_cost(s[i-1], t[j-1]);

            if(i_cost <= d_cost) {
                if(i_cost <= s_cost) {
                    a[i][j].p_i = i;
                    a[i][j].p_j = j-1;
                    a[i][j].op = 'i';
                    a[i][j].edit_dist = i_cost;
                }
                else {
                    a[i][j].p_i = i-1;
                    a[i][j].p_j = j-1;
                    if(substitute_cost(s[i-1], t[j-1]))
                        a[i][j].op = 's';
                    else 
                        a[i][j].op = 'm';
                    a[i][j].edit_dist = s_cost;
                }
            }
            else {
                if(d_cost <= s_cost) {
                    a[i][j].p_i = i-1;
                    a[i][j].p_j = j;
                    a[i][j].op = 'd';
                    a[i][j].edit_dist = d_cost;
                }
                else {
                    a[i][j].p_i = i-1;
                    a[i][j].p_j = j-1;
                    if(substitute_cost(s[i-1], t[j-1]))
                        a[i][j].op = 's';
                    else
                        a[i][j].op = 'm';
                    a[i][j].edit_dist = s_cost;
                }
            }
        }
    }
    printf("%d\n", a[m][n].edit_dist);
    print_sequence(a, m, n);
    printf("\n");
}

void print_sequence(edit_struct a[][MAX_LEN], int i, int j) {
    if(i == 0 && j == 0) return;
    print_sequence(a, a[i][j].p_i, a[i][j].p_j);
    printf("%c", a[i][j].op);
}

int insert_cost(char c) {
    return 1;
}

int delete_cost(char c) {
    return 1;
}

int substitute_cost(char c, char d) {
    if(c == d)
        return 0;
    else 
        return 1;
}
