#include	"dataGenerate.h"
#include	"Array.h"
#include	"BST.h"
#include	"LinkedList.h"
#include	"AwBS.h"
#include	"Hash.h"
#define MaxLine 8

int main(){
	char **A = generator(10);
	int Q;
	char line[32];
	fgets(line, 32, stdin);
	Q = atoi(line);
	for(int i=0;i<10;i++){
		printf("%s\n", A[i]);
	}
	char *lines[100];
	for(int i=0;i<Q;i++){
		fgets(line, MaxLine+4, stdin);
		if(line[strlen(line)-1] == '\n'){
			line[strlen(line)-1] = '\0';
		}
		lines[i] = strdup(line);
	}
	char  **arr = NULL;
	LNode *head = NULL;
	TNode *root = NULL;
	char **awbs = NULL;
	hashdb hash;
	head = LinkedListInsert(head, A, 10);
	arr = ArrayInsert(arr, A, 10);
	root = BSTInsert(root, A, 10);
	awbs = AwBSInsert(awbs, A, 10);
	HashInsert(&hash, A, 10);
	printf("insert finished!\n");
	/*for(int i=0;i<10;i++){
		printf("%s\n", awbs[i]);
	}
	*/
	int exist[10];
	memset(exist, 0, 10*sizeof(int));
	BSTFind(root, lines, exist, Q);
	printf("\nbst find:\n");
	for(int i=0;i<Q;i++){
		printf("%d", exist[i]);
	}
	printf("\nLinkedList find:\n");
	memset(exist, 0, 10*sizeof(int));
	LinkedListFind(head, lines, exist, Q);
	for(int i=0;i<Q;i++){
		printf("%d", exist[i]);
	}
	printf("\nArray find:\n");
	memset(exist, 0, 10*sizeof(int));
	ArrayFind(arr, 10, lines, exist, Q);
	for(int i=0;i<Q;i++){
		printf("%d", exist[i]);
	}
	printf("\nArray with Binary Search find:\n");
	memset(exist, 0, 10*sizeof(int));
	AwBSFind(awbs, 10, lines, exist, Q);
	for(int i=0;i<Q;i++){
		printf("%d", exist[i]);
	}
	
	printf("\nhash find:\n");
	memset(exist, 0, 10*sizeof(int));
	HashFind(&hash, lines, exist, Q);
	for(int i=0;i<Q;i++){
		printf("%d", exist[i]);
	}
	printf("\n");
    return 0;
}
