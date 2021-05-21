#ifndef __HASH_H
#define __HASH_H

#include	<stdio.h>
#include	<string.h>
#include	<strlib.h>
#include	"LinkedList.h"

struct hashdb{
	LNode **hashTable;
	int maxHash;
};

int hashFunction(char *key);
int hFind(hashdb *hash, char *key);
void hInsert(hashdb *hash, char *key);
void hashInit(hashdb *hash);

hashdb *HashInsert(hashdb *hash, char *A[], int size);
void HashFind(hashdb *hash, char *q[], int exist[], int qSize);

