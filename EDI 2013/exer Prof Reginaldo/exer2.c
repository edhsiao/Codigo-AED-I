#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 1000


criar_lista(long vet[],long tam)
{
        int i,num=2;
	printf("\ncriando lista\n");
        for (i=0;i<tam-1;i++)
        {
	printf("\nDentro for\n");
        vet[i]=num;
	printf("%d",vet[i]);
        num++;
        }
}

int main()
{	
	long tam=N, vet[N], primo[N];
	long i,j,k=0,cont=0,n;
	printf("\niniciando\n");
	criar_lista(vet,N);	
	printf("\nentrando for \n");
	for(i=0;i<N;i++)
	{
	printf("dentro for 1");
    		for(j=1; j<=vet[i]; j++)
   		{	
        		if((vet[i] % i) == 0)
            		cont++;
        	}
	printf("\ncontador maior que 2\n");
    		if(cont == 2)
   		{
        	primo[k]=primo[i];
		k++;
    		}
	cont=0;
	}

	scanf("%d",n);
	printf("\n%d:Primo =%d \n",n,primo[n]);
}
/*

for(i=1;i<b+1;i++)
{ if((b % i) == 0) {
 count++;
 }
}


if(count == 2)
 { return 1; }
 else {
 return 0; }
}

int main(void)
{
int i;
for(i=0;i<INTER;i++) { 
if(primo(i) == 1) {
 printf("%d\n", i);
}
}*/



	
	

