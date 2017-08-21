#include<stdio.h>
#include<stdlib.h>


typedef struct fila
{
    int cod;
    struct lista *prox;
} tipo_fila;

tipo_fila *primeiro;
tipo_fila *ultimo;

void fila_vazia()
{
    tipo_fila *aux;
    aux=(tipo_fila*)malloc(sizeof(tipo_fila));
    primeiro=aux;
    ultimo=primeiro;
}

void insere(int x)
{
    tipo_fila *aux;
    aux=(tipo_fila*)malloc (sizeof(tipo_fila));
    aux->cod=x;
    ultimo->prox=aux;
    ultimo=ultimo->prox;
    aux->prox=primeiro;
}

void imprime()
{
    tipo_fila *aux;
    aux=primeiro->prox;
    while(aux!=primeiro)
    {
        printf("Item = %d\n",aux->cod);
        aux=aux->prox;
    }
}

void remover (int x){
    primeiro->prox=primeiro->prox->prox;
}

void pesquisa(int x)
{
    tipo_fila *aux;
    int flag =0;
    aux=primeiro->prox;
    while(aux !=primeiro){
        if(aux->cod==x){
            printf("achou %d\n",x);
            flag=1;
            aux=primeiro;
        }
        else aux=aux->prox;
        }
        if (flag==0)
            prinf("nao achou%d\n",x);
        }
    }
}

}
