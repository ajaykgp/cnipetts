/*
 * Desc: This program reads in two command line arguments:
 *       first - the name of a text file, and second- the word
 *       or string which is searched for in the file. It outputs
 *       the number of occurrences of the search string in the file. 
 *
 *       The program defines a function called getword which reads the
 *       next word from the argument file pointer. It basically uses the 
 *       standard library function getc.
 *     
 * Author: Ajay    
 *
 * Time: Sunday, 25 November 2012, 2:10 AM
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 200

char *getword(FILE *fp, char *w);

int main(int argc, char *argv[]) {
    char w[MAX_LEN], *s;
    char *fname = *++argv;
    char *word = *++argv;

    FILE *fp = fopen(fname, "r");
    int count = 0;
    while((s = getword(fp, w)) != NULL) 
        if(strcmp(s, word) == 0)
            count++;
    printf("%d\n", count);

    return 0;
}

char *getword(FILE *fp, char *w) {
    char ch;
    char *s = w;
    ch = getc(fp);
    if(ch == EOF) return NULL;
    while((ch != ' ') && (ch != '\n')) {
        *w++ = ch;
        ch = getc(fp);
    }
    *w = '\0';
    return s;
}
