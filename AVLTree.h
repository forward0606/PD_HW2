#ifndef __AVLTree_H
#define __AVLTree_H

#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#define max(a, b) ((a) > (b) ? (a):(b))

typedef struct ATNode{
    char *key;
    int height;
    struct ATNode *left, *right;
}ATNode;



ATNode *_AVLinsert(ATNode *root, char *key);
ATNode *_AVLFind(ATNode *root, char *key);
ATNode *AVLInsert(ATNode *root, char *A[], int size);
void *AVLFind(ATNode *root, char *q[], int exist[], int qsize);

#endif // __AVLTree_H
