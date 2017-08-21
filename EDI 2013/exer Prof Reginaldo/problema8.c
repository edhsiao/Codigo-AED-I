#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int numero;
    struct No *esquerda;
    struct No *direita;
} TipoNo;

void criarNo(TipoNo **no)
{
    *no = NULL;
}

void insereNo(TipoNo **no, int numero)
{
    if(*no == NULL)
    {
        *no = (TipoNo *) malloc(sizeof(TipoNo));
        (*no)->esquerda = NULL;
        (*no)->direita = NULL;
        (*no)->numero = numero;
    }
    else
    {
        if(numero < (*no)->numero)
            insereNo(&(*no)->esquerda, numero);
        if(numero >= (*no)->numero)
            insereNo(&(*no)->direita, numero);
    }
}


int maior(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}


int altura(TipoNo *no)
{
    if((no == NULL) || (no->esquerda == NULL && no->direita == NULL))
        return 0;
    else
        return 1 + maior(altura(no->esquerda), altura(no->direita));
}


void libera(TipoNo **no)
{
    if(*no!=NULL)
    {
        libera(&(*no)->esquerda);
        libera(&(*no)->direita);
        free(*no);
    }
}

int main()
{
    TipoNo *arvore;
    int num,qtd,i,j,teste,x;
    scanf("%d",&teste);
    for(i=0; i<teste; i++)
    {
        criarNo(&arvore);
        scanf("%d",&x);
        scanf("%d",&qtd);
        for(j=0; j<qtd; j++)
        {
            scanf("%d",&num);
            insereNo(&arvore,num);
        }
        printf("%d %d\n",x,altura(arvore));
        libera(&arvore);
    }
    return 0;
}
