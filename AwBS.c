#include	"AwBS.h"


int cmp(const void *a, const void *b){
	char *_a = *(char **)a;
	char *_b = *(char **)b;
	return strcmp(_a, _b);
}

int binary_search(char **arr, int arrSize, char *key){
	int L = -1, R = arrSize, mid;
	while( L != R){
		if(L >= R-1){
			break;
		}
		mid = (L+R)/2;
		if(strcmp(key, arr[mid]) <= 0){
			R = mid;
		}
		else{
			L = mid;
		}
	}
	if( R == arrSize){
		return -1;
	}
	else if(strcmp(arr[R], key) == 0){
		return R;
	}
	return -1;
}


char **AwBSInsert(char **arr, char *A[], const int size){
	arr = (char **)malloc(sizeof(char *)*size);
	for(int i=0;i<size;i++){
		arr[i] = strdup(A[i]);
	}
	qsort(arr, size, sizeof(char *), cmp);
	return arr;
}

void AwBSFind(char **arr, int arrSize, char *q[], int exist[], int qsize){
	for(int i=0;i<qsize;i++){
		if(binary_search(arr, arrSize, q[i]) == -1 ){
			exist[i] = 0;
		}
		else{
			exist[i] = 1;
		}
	}
}
