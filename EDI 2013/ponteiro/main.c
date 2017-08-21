#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    int idade;
} CLIENTE;

typedef struct no
{
    CLIENTE info;
    struct no *prox;
} LISTA;
//LISTA =struct no

LISTA * criarlista ()
{
    return NULL;
}
void inserirInicio(LISTA ** lista,CLIENTE c1)
{
    LISTA *novo = (LISTA*)calloc(1,sizeof(LISTA));
    novo->info=c1;
    novo->prox=*lista;
    *lista=novo;
}

void inserirFinal(LISTA ** lista,CLIENTE c1)
{
    LISTA *novo = (LISTA*)calloc(1,sizeof(LISTA));
    novo->info=c1;
    novo->prox=NULL;
    *lista=novo;
}

    if (LISTA ==NULL)
    {

    }


int main()
{
    int LISTA * lista;
    lista =criarlista();



    return 0;
}
