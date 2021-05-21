#include "LinkedList.h"


LNode *newLNode(const char *key, LNode *next){
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p -> key = strdup(key);
    p -> next = next;
    return p;
}

LNode *Ldel(LNode *head, const char *key){
    LNode *p = head;
    LNode *last = NULL;
    while(p){
        if(strcmp(p->key, key) == 0){
            break;
        }
        last = p;
        p = p -> next;
    }
    if(last == NULL){
        last =  p -> next;
        free(p);
        return last;
    }
    last -> next = p -> next;
    free(p);
    return head;
}

LNode *Linsert(LNode *root, const char *key){
    return newLNode(key, root);
}

const LNode *Lfind(const LNode *root, const char *key){
    const LNode *p = root;
    while(p){
        if(strcmp(p -> key, key) == 0){
            return p;
        }
        p = p -> next;
    }
    return NULL;
}

void Ltraverse(const LNode *root){
    const LNode *p = root;
    while(p){
        printf("%s", p-> key);
        p = p -> next;
    }
}

LNode *LinkedListInsert(LNode *head, char **A, const int n){
    head = NULL;
    for(int i = 0; i< n;i++){
        head = Linsert(head, A[i]);
    }
    return head;
}

void LinkedListFind(LNode *head, char *q[], int exist[], const int n){
    const LNode *found = NULL;
    for(int i = 0; i< n; i++){
        found = Lfind(head, q[i]);
        if(found != NULL){
            exist[i] = 1;
        }
        else{
            exist[i] = 0;
        }
    }
}


void delLinkedList(LNode *root){
    if(root == NULL) return;
    free(root -> key);
    delLinkedList(root -> next);
    free(root);
    root = NULL;
}
