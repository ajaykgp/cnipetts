/*
 *This program reads an expression containing '(', ')', '{', '}', 
 *'[', ']' and checks if the epression is valid. The expression 
 *is valid if the all the brackets are properly matched. Stack data struture is
 *used to push(store) an opening bracket and as we  get a closing bracket, we pop
 *from the stack and check for the match. If the check fails, the expression is 
 *illegal else continue till we reach the end of the expression.
 *
 *Date: Saturday 3 November 2012, 3:19 PM
 *Author: Ajay 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} stack;


void push(stack *s, char ch);
char pop(stack *s);
int top(stack *S);
void readExpr(char expr[]);
int isExprValid(stack *s, char expr[]);
void printStack(stack *s);

int main(void) {
    char expr[MAX];
    stack *s = (stack *) malloc(sizeof(stack));
    s -> top = -1;
    readExpr(expr);
    int i = isExprValid(s, expr);
    printf("%d\n", i);
    return 0;
}

void readExpr(char expr[]) {
    char ch;
    int i = 0;
    while((ch = getchar()) != '\n') expr[i++] = ch;
    expr[i] = '\0';
}

int isExprValid(stack *s, char expr[]) {
    char ch, foo;
    int i = 0;
    while((ch = expr[i++]) != '\0') {
        switch(ch) {
            case '(':
                push(s, ch);
               // printStack(s);
                break;
            case '{':
                push(s, ch);
               // printStack(s);
                break;
            case '[':
                push(s, ch);
               // printStack(s);
                break;
            case ')':
                foo = pop(s);
               // printStack(s);
                if(foo != '(') return 0;
                break;
            case '}':
                foo = pop(s);
               // printStack(s);
                if(foo != '{') return 0;
                break;
            case ']':
                foo = pop(s);
               // printStack(s);
                if(foo != '[') return 0;
                break;
            default:
                break;
        }
    }
    if(top(s) == -1) return 1;
    printf("here\n");
    return 0;
}

void push(stack *s, char ch) {
    if(top(s) < MAX - 1) {
        s -> top += 1;
        s -> data[s -> top] = ch;
    }
    else printf("stack full\n");
}

char pop(stack *s) {
    if(top(s) > -1) {
        s -> top -= 1;
        return s -> data[(s -> top) + 1];
    }
    else return '\0';
}

int top(stack *s) {
    return s -> top;
}

void printStack(stack *s) {
    int i;
    printf("top of the stack is %d\n", s -> top);
    for(i = 0; i <= (s -> top); i++) printf("%c ", s -> data[i]);
    printf("\n");
}

