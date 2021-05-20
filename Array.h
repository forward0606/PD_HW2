#ifndef __ARRAY_H
#define __ARRAY_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int Afind(const char **array, const int arraySize, const char *key);

void ArrayInsert(char **array, const char *A[], int size);
void ArrayFind(const char **array, const int arraySize,\
			const char *q[], int exist[], const int qSize);
void delArray(char **array, int n);


#endif
