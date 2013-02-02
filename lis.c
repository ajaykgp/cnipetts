/*
 * @desc: This program reads in a sequence of integers from stdin
 *        terminated by the EOF (ctrl+D). It then prints the length
 *        of the longest increasing subsequence of the input sequence,
 *        the length of the longest increasing sequence ending at 
 *        each element of the input sequence, and finally the longest
 *        increasing subsequence itself. 
 *
 * @algo: The algorithm is simple. For the input element a[i], we find
 *        the longest increasing subsequence containing a[i] as its last
 *        element. We find this for all the elements in the input sequence.
 *        Then we select the a[i] for which this length is maximum. If l[i]
 *        denotes this value, then l[i] = max{l[j] : a[i] >= a[j]}. We also 
 *        store this value of j so that we can construct the actual subsequence.
 *        The complexity of the program is O(n^2) where n is the length of the 
 *        input sequence.
 *
 *  @author: ajay
 *
 *  @time: Monday, 31st December 2012, 1:48 PM
 *
 *
 */

#include <stdio.h>

#define MAX_LEN 100

typedef struct {
    int prev_index;
    int len;
} lis_struct;

void lis(int a[], int len);
void print_lis(int a[], lis_struct b[], int max_index);

int main(void) {
    int i = 0, a[MAX_LEN];
    int val;
    while(scanf("%d", &val) != EOF) a[i++] = val;
    lis(a, i);
    return 0;
}

void lis(int a[], int len) {
    lis_struct b[MAX_LEN];
    int i, j;
    int max_index = 0;
    for(i = 0; i < len; i++) {
        b[i].len = 1;
        b[i].prev_index = -1;
        for(j = 0; j < i; j++) {
            if(a[j] <= a[i] && b[j].len >= b[i].len) {
                b[i].len = b[j].len + 1;
                b[i].prev_index = j;
            }
        }
        if(b[i].len > b[max_index].len)
            max_index = i;
    }
    printf("\nthe array b\n");
    for(i = 0; i < len; i++) printf("%d ", b[i].len);
    printf("\n%d\n", b[max_index].len);
    print_lis(a, b, max_index);
    printf("\n");
}

void print_lis(int a[], lis_struct b[], int max_index) {
    if(b[max_index].prev_index == -1) {
        printf("%d ", a[max_index]);
        return;
    }
    print_lis(a, b, b[max_index].prev_index);
    printf("%d ", a[max_index]);
}
