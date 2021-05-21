#ifndef __ARRAY_H
#define __ARRAY_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int Afind(char **array, const int arraySize, const char *key);

char **ArrayInsert(char **array, char ** A, int size);
void ArrayFind(char **array, const int arraySize,\
			char *q[], int exist[], const int qSize);
void delArray(char **array, int n);


#endif
