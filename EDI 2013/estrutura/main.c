#include <stdio.h>
#include <stdlib.h>


int main(){

    int **vet =NULL;
    vet =(int**)malloc (sizeof(int*)*3);
    int i=0;
    for (i=0;i<3;i++){
        vet[i]=(int*)malloc(sizeof(int)*3);
            vet[2][2]=3;
            printf("%d",vet[2][2]);
    }

}


