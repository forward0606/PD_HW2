#include "Array.h"


int Afind(char *array[], const int arraySize, const char *key){
	for(int i=0;i<arraySize;i++){
		if(strcmp(array[i], key) == 0){
			return i;
		}
	}
	return -1;
}

char **ArrayInsert(char **array, char **A, int size){
	array = (char **)malloc(sizeof(char *) * size);
	if(array == NULL){
		//
	}
	for(int i=0;i<size;i++){
		array[i] = strdup(A[i]);
	}
	return array;
}

void ArrayFind(char **array, const int arraySize, char *q[], int exist[], const int qSize){
	for(int i=0;i<qSize;i++){
		if(Afind(array, arraySize, q[i]) == -1){
			exist[i] = 0;
		}
		else{
			exist[i] = 1;
		}
	
	}
}

void delArray(char **array, int n){
	for(int i=0;i<n;i++){
		if(array[i] != NULL){
			free(array[i]);
			array[i] = NULL;
		}
	}
	free(array);
	array = NULL;
}
