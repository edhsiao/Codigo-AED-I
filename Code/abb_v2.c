#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char nome[15];
    struct no *esquerda;
    struct no *direita;
} TipoNo;

TipoNo *raiz;
TipoNo *alocar;

void criarNo(TipoNo **no)
{
    *no = NULL;
}

int buscar(char *dado)
{

    TipoNo *aux;
    int visit=0;
    aux = raiz;

    while (aux)
    {
        if (strcmp(dado, aux->nome)==0)
            return visit;

        if (strcmp(dado, aux->nome)>0)
        {
            visit++;
            aux = aux->direita;
        }

        else
        {
            visit++;
            aux = aux->esquerda;
        }
    }

    return visit; //Retorna o aux nulo
}

void inserir(char *dado)
{
    TipoNo* novo = (TipoNo*) malloc(sizeof(TipoNo));

    strcpy(novo->nome, dado);

     printf("novo->nome = %s",novo>nome);

    if (!raiz)
        raiz = novo;
    else
    {
        TipoNo *aux;
        TipoNo *pontAnterior;
        aux = raiz;
        pontAnterior = NULL;

        while (aux)
        {

            pontAnterior = aux;

            if (strcmp(dado, aux->nome)>0)
            {
                aux = aux->direita;
            }
            else
            {
                aux = aux->esquerda;
            }
        }

        if  (strcmp(dado, pontAnterior->nome)>0)
        {
            pontAnterior->direita = alocar;
        }
        else
        {
            pontAnterior->esquerda = alocar;
        }
    }
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
    char dado[15];
    int qtd,teste,x,y,i,j,n,total=0;
    float media;
    scanf("%d",&teste);
    for(i=0; i<teste; i++)
    {
        criarNo(&raiz);
        scanf("%d",&x);
        scanf("%d",&qtd);
        for(j=0; j<qtd; j++)
        {
            printf("===%d====\n",j);
            fgets(dado,15,stdin);
            inserir(dado);
        }
        scanf("%d",&y);
        for(j=1; j<=y; j++)
        {
            fgets(dado,15,stdin);
            n= buscar(dado);
            total=total+n;
        }
        media=total/y;
        printf("%d %.2f\n",x,media);
        libera(&raiz);
    }
    return 0;
}

