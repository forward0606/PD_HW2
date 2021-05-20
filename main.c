#include "dataGenerate.h"
#define MaxLine 8

int main(){
	char **A = generator(10);
	for(int i=0;i<10;i++){
		printf("%s\n", A[i]);
	}
    return 0;
}
