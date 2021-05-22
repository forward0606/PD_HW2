#include	"Hash.h"



int hashFunction(char *key, const int maxHash){
	long long sum = 0;
	char *p = key;
	while(*p){
		sum = sum*65 + *p;
		sum %= maxHash;
		p++;
	}
	return sum;
}

const LNode *hFind(hashdb *hash, char *key){
	int k = hashFunction(key, hash -> maxHash);
	return Lfind(hash -> hashTable[k], key);
}

void hInsert(hashdb *hash, char *key){
	int k = hashFunction(key, hash -> maxHash);
	hash -> hashTable[k] = Linsert(hash -> hashTable[k], key);
}

void hashInit(hashdb *hash, int maxHash){
	hash -> maxHash = maxHash;
	hash -> hashTable = (LNode **)malloc(sizeof(LNode *)*maxHash);
	for(int i=0;i< hash -> maxHash; i++){
		hash -> hashTable[i] = NULL;
	}
}

void HashInsert(hashdb *hash, char *A[], int size){
	hashInit(hash, size*2);
	for(int i=0;i<size;i++){
		hInsert(hash, A[i]);
	}
}
void HashFind(hashdb *hash, char *q[], int exist[], int qSize){
	for(int i=0;i<qSize;i++){
		if(hFind(hash, q[i]) == NULL){
			exist[i] = 0;
		}
		else{
			exist[i] = 1;
		}
	}
}
