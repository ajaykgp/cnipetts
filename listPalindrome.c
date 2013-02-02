/*
 *
author: Ajay

time: Monday 29 October 2012, 10:43 AM

desc: This program checks if a linked list is a palindrome WITHOUT USING 
      EXTRA SPACE. It prints 1 in case it is and 0 otherwise.

algo: First, the first node of the second half of the list is found. Then
      the second half is reversed and checked with the first half until we 
      we reach the end of the second half(NULL) or when the equality 
      condition fails(data of a node from the first half should be equal to
      the data of the corresponding node from the second half of the list).
      The second half is then reversed back.
 *
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Pnode;

Pnode *createList(void);
Pnode *reverseList(Pnode *head);
Pnode *recursiveRevList(Pnode *newHead, Pnode *oldHead, Pnode *temp);
int isPalindrome(Pnode *head);


int main(void) {
    Pnode *head = createList();
    int res = isPalindrome(head);
    printf("%d \n", res);
    return 0;
}

int isPalindrome(Pnode *head) {
    Pnode *m = head, *p = head, *temp = NULL;
    while(p != NULL) {
        p = p -> next;
        if(p != NULL) p = p -> next;
        m = m -> next;
    }
    m = reverseList(m);
    temp = m;
    p = head;
    while(m != NULL) {
        if((p -> data) != (m -> data)) {
            m = reverseList(temp);
            return 0;
        }
        p = p -> next;
        m = m -> next;
    }
    m = reverseList(temp);
    return 1;
}

Pnode *createList(void) {
    char c;
    Pnode *head = NULL, *temp, *current;
    c = getchar();
    if(c != '\n') {
        current = (Pnode *) malloc(sizeof(Pnode));
        current -> data = (int) c;
        current -> next = NULL;
    }
    else return head;

    head = current;

    while((c = getchar()) != '\n') {
        temp = (Pnode *) malloc(sizeof(Pnode));
        temp -> data = (int) c;
        temp -> next = NULL;
        current -> next = temp;
        current = temp;
    }
    return head;
}

Pnode *recursiveRevList(Pnode *newHead, Pnode *oldHead, Pnode *temp) {
    if(oldHead == NULL) return newHead;
    temp = oldHead -> next;
    oldHead -> next = newHead;
    newHead = oldHead;
    oldHead = temp;
    return recursiveRevList(newHead, oldHead, temp);
}

Pnode *reverseList(Pnode *head) {
    Pnode *newHead = NULL, *temp = NULL;
    newHead = recursiveRevList(newHead, head, temp);
    return newHead;
}

void printList(Pnode *head) {
    Pnode *node = head;
    while(node != NULL) {
        printf("%d", node -> data);
        node = node -> next;
    }
    printf("\n");
}
