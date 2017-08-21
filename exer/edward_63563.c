#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 15485863

int main() {
    long i, j, *x,pos,cont=0;
    long valorMax=MAX, raiz;
     x=(long*)calloc(MAX+1,sizeof(long));

    scanf("%d", &pos);

    raiz=sqrt(valorMax);

    for (i=2; i<=valorMax; i++) {
        x[i]=i;
    }

    for (i=2; i<=raiz; i++) {
            for (j=i+i; j<=valorMax; j+=i) {
                x[j]=0;
            }
        }
    i=2;
    while((cont<pos) && (i<=valorMax))
    {
        if (x[i]!=0){
            j=i;
            cont++;
            }
        i++;
    }
    printf("%ld",j);

}
