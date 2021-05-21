#ifndef __AwBS_H
#define __AwBS_H

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>


int binary_search(char**, int, char *);

char **AwBSInsert(char **arr, char *A[], const int size);
void AwBSFind(char **arr, int arrSize, char *q[], int exist[], int qsize);

#endif
