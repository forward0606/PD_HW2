#ifndef __BST_H
#define __BST_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct TNode{
    char *key;
    struct TNode *left, *right;
}TNode;

TNode *bst_insert(TNode *root, char *key);
TNode *bst_find(TNode *root, char *key);
void bst_midTraverse(TNode *root);

TNode *BSTInsert(TNode *root, char *A[], int n);
void BSTFind(TNode *root, char *q[], int exist[], int n);


#endif
