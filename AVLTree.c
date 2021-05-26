#include    "AVLTree.h"


int countHeight(ATNode *root){
    int diff;
    if(root == NULL){
        return 0;
    }
    if(root -> left != NULL && root -> right != NULL){
        //printf("L:NOT NULL\tR:NOT NULL\n");
		root -> height = max(root -> right -> height, root -> left -> height)+1;
        diff = (root -> left -> height) - (root -> right -> height);
    }else if(root -> left != NULL){
        //printf("L:NOT NULL\tR:NULL\n");
        root -> height = (root -> left -> height)+1;
        diff = root -> left -> height - 0;
    }else if(root -> right !=NULL){
        //printf("L: NULL\tR:NOT NULL\n");
        root -> height = (root -> right -> height)+1;
        diff = 0 - root -> right -> height;
    }else{
        //printf("L: NULL\tR: NULL\n");
		root -> height = 1;
		diff = 0;
	}
    return diff;
}

ATNode *r_rotate(ATNode *root){
    ATNode *p = root -> left;
    root -> left = p -> right;
    p -> right = root;
    countHeight(root);
    countHeight(p);
    return p;
}

ATNode *l_rotate(ATNode *root){
    ATNode *p = root -> right;
    root -> right = p -> left;
    p -> left = root;
    countHeight(root);
    countHeight(p);
    return p;
}

ATNode *_AVLinsert(ATNode *root, char *key){
    if(root == NULL){
        ATNode *p = (ATNode *)malloc(sizeof(ATNode));
        p -> key = strdup(key), p -> height = 1;
        p -> left = NULL, p -> right = NULL;
        return p;
    }
    int c = strcmp(root-> key, key);
    if(c < 0){
        root -> right = _AVLinsert(root -> right, key);
    }else{
        root -> left = _AVLinsert(root -> left, key);
    }
    int diff = countHeight(root);
    //printf("%s : diff = %d\n", root -> key, diff);
	if(diff <= -2 ){
        diff = countHeight(root ->right);
        if(diff > 0){
            // RL
            root -> right = r_rotate(root ->right);
        }
        //printf("l_rotate\n");
		root = l_rotate(root);
    }else if(diff >= 2){
        diff = countHeight(root -> left);
        if(diff < 0){
            // LR
            root -> left = l_rotate(root ->left);
        }
		//printf("r_rotate\n");
        root = r_rotate(root);
    }
    return root;
}

ATNode *_AVLFind(ATNode *root, char *key){
    if(root == NULL)    return NULL;
    int c = strcmp(root->key, key);
    if(c < 0){
        return _AVLFind(root ->right, key);
    }else{
        return _AVLFind(root->left, key);
    }
}

void _AVL_traverse(ATNode *root){
	if(root == NULL){
		//printf("\n");
		return;
	}
	//printf("%s\n", root -> key);
	//printf("left:\t");
	_AVL_traverse(root -> left);
	//printf("right:\t");
	_AVL_traverse(root -> right);
}

ATNode *AVLInsert(ATNode *root, char *A[], int size){
    char k[120];
	for(int i=0;i<size;i++){
		//printf("%d:", i);
		//scanf("%s", k);
        root = _AVLinsert(root, A[i]);
		_AVL_traverse(root);
    }
    return root;
}

void *AVLFind(ATNode *root, char *q[], int exist[], int qsize){
    for(int i=0;i<qsize;i++){
        if(_AVLFind(root, q[i]) == NULL){
            exist[i] = 0;
        }else{
            exist[i] = 1;
        }
    }
}
