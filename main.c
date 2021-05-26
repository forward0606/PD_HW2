#include	"dataGenerate.h"
#include	"Array.h"
#include	"BST.h"
#include	"LinkedList.h"
#include	"AwBS.h"
#include	"Hash.h"
#include	"AVLTree.h"
#include    <sys/time.h>
#define		MaxLine		8
#define     false       0
#define     true        1

int mypow(int base, int r){
    int sum = 1;
    while(r != 0){
        if(r %2){
            sum *= base;
        }
        base *= base;
        r /= 2;
    }
    return sum;
}

int main(int argc, char **argv){
	int insertDataSize = 1000;
	int queryDataSize = 1000;
	int BSTQuery = false;
	int BinarySearchQuery = false;
	int ArrayQuery = false;
	int LinkedListQuery = false;
	int HashQuery = false;
	int AVLQuery = false;
    char *temp;
	// CMD input process
	for(int i=1;i<argc; i++){
        if(strcmp(argv[i], "-d") == 0){
            i++;
            if((temp = strchr(argv[i], 'e')) != NULL){
                *temp = '\0';
                insertDataSize = atoi(argv[i]) * mypow(10, atoi(temp+1));
            }else{
                insertDataSize = atoi(argv[i]);
            }
        }else if(strcmp(argv[i], "-q") == 0){
            i++;
            if((temp = strchr(argv[i], 'e')) != NULL){
                *temp = '\0';
                queryDataSize = atoi(argv[i]) * mypow(10, atoi(temp+1));
            }else{
                queryDataSize = atoi(argv[i]);
            }
        }else if(strcmp(argv[i], "-bst") == 0){
            BSTQuery = true;
        }else if(strcmp(argv[i], "-bs") == 0){
            BinarySearchQuery = true;
        }else if(strcmp(argv[i], "-arr") == 0){
            ArrayQuery = true;
        }else if(strcmp(argv[i], "-ll") == 0){
            LinkedListQuery = true;
        }else if(strcmp(argv[i], "-hash") == 0){
            HashQuery = true;
        }else if(strcmp(argv[i], "-avl") == 0){
            AVLQuery = true;
        }
	}

	// data generate
	char **A = generator(insertDataSize);
	char **q = generator(queryDataSize);
	int *exist = (int *)malloc(queryDataSize * sizeof(int));

	struct  timeval start;
    struct  timeval end;
    unsigned long diff;

    if(BSTQuery == true){
        printf("bst:\n");
        //build
        gettimeofday(&start, NULL);
        TNode *root = NULL;
        root = BSTInsert(root, A, insertDataSize);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("building time: %f sec\n",diff/1000000.0);

        //query
        gettimeofday(&start, NULL);
        BSTFind(root, q, exist, queryDataSize);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("query time: %f sec\n\n",diff/1000000.0);
    }
    if(BinarySearchQuery == true){
        printf("binary search:\n");
        //build
        gettimeofday(&start, NULL);
        char **bs;
        bs = AwBSInsert(bs, A, insertDataSize);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("building time: %f sec\n",diff/1000000.0);

        //query
        gettimeofday(&start, NULL);
        AwBSFind(bs, insertDataSize, q, exist, queryDataSize);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("query time: %f sec\n\n",diff/1000000.0);
    }
	if(ArrayQuery == true){
        printf("array:\n");
        //build
        gettimeofday(&start, NULL);
        char **arr;
        arr = ArrayInsert(arr, A, insertDataSize);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("building time: %f sec\n",diff/1000000.0);

        //query
        gettimeofday(&start, NULL);
        ArrayFind(arr, insertDataSize, q, exist, queryDataSize);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("query time: %f sec\n\n",diff/1000000.0);
	}
	if(LinkedListQuery == true){
	    printf("linked list:\n");
        //build
        gettimeofday(&start, NULL);
        LNode *L = NULL;
        L = LinkedListInsert(L, A, insertDataSize);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("building time: %f sec\n",diff/1000000.0);

        //query
        gettimeofday(&start, NULL);
        LinkedListFind(L, q, exist, queryDataSize);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("query time: %f sec\n\n",diff/1000000.0);
	}
	if(HashQuery == true){
        printf("hash:\n");
        //build
        gettimeofday(&start, NULL);
        hashdb hash;
        HashInsert(&hash, A, insertDataSize);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("building time: %f sec\n",diff/1000000.0);

        //query
        gettimeofday(&start, NULL);
        HashFind(&hash, q, exist, queryDataSize);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("query time: %f sec\n\n",diff/1000000.0);
	}
	if(AVLQuery == true){
        printf("AVL tree:\n");
        //build
        gettimeofday(&start, NULL);
        ATNode *root = NULL;
        root = AVLInsert(root, A, insertDataSize);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("building time: %f sec\n",diff/1000000.0);

        //query
        gettimeofday(&start, NULL);
        AVLFind(root, q, exist, queryDataSize);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("query time: %f sec\n\n",diff/1000000.0);
	}
	return 0;
}
