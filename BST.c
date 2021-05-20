#include "BST.h"

TNode *bst_insert(TNode *root, char *key){
    if(root == NULL){
        TNode *p = malloc(sizeof(TNode));
        p -> key = strdup(key);
        p -> left = NULL;
        p -> right = NULL;
        return p;
    }
    int c = strcmp(root -> key, key);
    if(c>0){
        root -> left = bst_insert(root -> left, key);
    }
    else{
        root -> right = bst_insert(root -> right, key);
    }
    return root;
}

TNode *bst_find(TNode *root, char *key){
    if(root == NULL){
        return root;
    }
    int c = strcmp(root -> key, key);
    if(c == 0){
        return root;
    }
    else if(c > 0){
        return bst_find(root -> left, key);
    }
    return bst_find(root -> right, key);
}

void bst_midTraverse(TNode *root){
    if(root == NULL) return;
    bst_midTraverse(root -> left);
    printf("%s\n", root -> key);
    bst_midTraverse(root -> right);
}

TNode *BSTInsert(TNode *root, char *A[], int n){
    root = NULL;
    for(int i=0;i<n;i++){
        root = bst_insert(root, A[i]);
    }
    return root;
}

void BSTFind(TNode *root, char *q[], int exist[], int n){
    TNode *found;
    for(int i=0;i<n;i++){
        found = bst_find(root, q[i]);
        if(found == NULL){
            exist[i] = 0;
        }
        else{
            exist[i] = 1;
        }
    }
}

