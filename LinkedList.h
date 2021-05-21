#ifndef __LinkedList
#define __LinkedList
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LNode{
    char *key;
    struct LNode *next;
}LNode;

LNode *newLNode(const char *, LNode *);
void Ltraverse(const LNode *);
LNode *Linsert(LNode *, const char *);
const LNode *Lfind(const LNode *,const char *);
LNode *Ldel(LNode *, const char *);

//return new LinkedList Node
LNode *LinkedListInsert(LNode *head, char **A, const int n);
//exist[i]  means q[i] exist (1) or not (0)
void LinkedListFind(LNode *head, char *q[], int exist[], const int n);
// delete all node in linked list
void delLinkedList(LNode *);

#endif
