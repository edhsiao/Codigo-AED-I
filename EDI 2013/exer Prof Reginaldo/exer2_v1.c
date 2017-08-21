#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 15485863

criar_lista(int vet[],int tam)
{
	int i,cont=2;
	for (i=0;i<tam-1;i++)
	{
	vet[i]=cont;
	cont++;
	}
}
int primo(int b)
{
    int i, count = 0;
    for(i=1; i<b+1; i++)
    {
        if((b % i) == 0)
        {
            count++;
        }
    }

    if(count == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

imprime_lista(int vet[],int tam)
{
	int i;
	for(i=0;i<tam-1;i++)
	printf("%d ",vet[i]);
}

int main()
{
	int vet[N], primo[N];
	int i,j,k=0,cont=0;

	criar_lista(vet,N);
	imprime_lista(vet,N);	
	
	for(i=0;i<N-1;i++)
	{
    		for(j=1; j<=vet[i]; j++)
   		{	
        		if((vet[i] % i) == 0)
            		cont++;
        	}

    		if(cont == 2)
   		{
        	primo[k]=primo[i];
		k++;
    		}
	}
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



	
	

