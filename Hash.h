#ifndef __HASH_H
#define __HASH_H

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	"LinkedList.h"

typedef struct hashdb{
	LNode **hashTable;
	int maxHash;
}hashdb;

int hashFunction(char *key, int maxHash);
const LNode *hFind(hashdb *hash, char *key);
void hInsert(hashdb *hash, char *key);
void hashInit(hashdb *hash, int maxHash);

void HashInsert(hashdb *hash, char *A[], int size);
void HashFind(hashdb *hash, char *q[], int exist[], int qSize);

#endif
