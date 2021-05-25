#include    "dataGenerate.h"

int check(char *line, char **A, int j){
    int flag = 1;
    for(int i=0;i<j;i++){
        if(strcmp(line, A[i]) == 0){
            flag = 0;
        }
    }
    return flag;
}

char **generator(int n){
    char **A = (char **) malloc(sizeof(char *) * n);
    char line[MaxLineLen];
    int i = 0, j = 0, x;
    srand(time(NULL));
    for(int i = 0; i< MaxLineLen; i++){
        x = rand() % 52;
        if(x < 26){
            line[i] = x + 'A';
        }
        else{
            line[i] = x -26 + 'a';
        }
    }
    int g;
    while(j< n){
        g = rand()%MaxLineLen;
        x = rand() %52;
        if(x < 26){
            line[g] = x + 'A';
        }
        else{
            line[g] = x -26 + 'a';
        }
        int flag = check(line, A, j);
        if(flag == 1){
            A[j] = strdup(line);
            j++;
        }
    }
    return A;
}
