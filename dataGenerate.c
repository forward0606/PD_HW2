#include    "dataGenerate.h"

char **generator(int n){
    char **A = (char **) malloc(sizeof(char *) * n);
    char line[MaxLineLen];
    int i = 0, j = 0, x;
    srand(time(NULL));
    while(j< n){
        for(int i = 0; i< MaxLineLen; i++){
            x = rand() % 52;
            if(x < 26){
                line[i] = x + 'A';
            }
            else{
                line[i] = x -26 + 'a';
            }
        }
        int flag = 1;
        for(int i=0;i<j;i++){
            if(strcmp(line, A[i]) == 0){
                flag = 0;
            }
        }
        if(flag == 1){
            A[j] = strdup(line);
            j++;
        }
    }
    return A;
}

