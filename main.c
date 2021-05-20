#include "LinkedList.h"
#define MaxLine 8

int main(){
    char line[100][MaxLine+1];
	int T, Q, n = 0;
	scanf("%d %d", &T, &Q);
    
	while(T--){
		fgets(line[n], MaxLine +1 , stdin);
        n++;
    }
	while(Q--){
		fgets(line[n], MaxLine +1 , stdin);
        n++;		
	}
    return 0;
}
