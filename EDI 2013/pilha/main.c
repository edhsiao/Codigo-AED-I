#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int inicio, fim;
int pilha[MAX];

int pilhavazia()
{
    return (inicio=fim);
}
int pilhacheia()
{
    return(fim==MAX);
}

void push(int x)
{
    if(!pilhacheia())
    {
        printf("inserindo %d\n",x);
        pilha[fim++]=x;
    }
    else
    {
        printf("Pilha CHEIA!\n");
    }
}
int pop()
{
    int aux;
    if(!pilhavazia)
    {
        aux= pilha[fim-1];
        fim--;
        return aux;
    }
    else
    {
        printf("Pilha VAZIA!\n");
        return -1;
    }
    return 0;
}




int main()
{
    int i;
    inicio=0;
    fim=0;
    for(i=0;i<12;i++)
        push(i+1);


}
