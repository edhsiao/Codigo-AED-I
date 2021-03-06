#include<stdio.h>
#include<stdlib.h>

typedef struct elemento
{
    char nome[50];
    struct elemento *prox;
    struct elemento *ant;
} elemento;

typedef struct listaCirc
{
    elemento *inicio;
    int tam;
} tipoLista;

void inicializacao (tipoLista *listaAux)
{
    listaAux->inicio = NULL;
    listaAux->tam = 0;
}

void inserir ( tipoLista *listaAux )
{
    char pessoa[50];
    elemento *novo = (elemento*)malloc(sizeof(elemento));
    scanf("%s", pessoa);
    strcpy(novo->nome,pessoa);
    if (listaAux->tam == 0)
    {
        novo->prox = novo;
        novo->ant = novo;
        listaAux->inicio = novo;
    }
    else
    {
        novo->prox = listaAux->inicio;
        novo->ant = listaAux->inicio->ant;
        listaAux->inicio->ant->prox = novo;
        listaAux->inicio->ant = novo;
    }
    listaAux->tam++;
}

void remover ( tipoLista *listaAux, int pass,int surv)
{
    elemento *del=listaAux->inicio; //ponteiro que vai percorrer a lista;
    int cont=0;

    while(listaAux->tam!=surv)
    {
        while(cont!=pass) //procurar posicao de remocao
        {
            del=del->prox;
            cont++;
        }
        cont=0;

        if ( del == listaAux->inicio )
        {
            printf("%s\n",del->nome);
            listaAux->inicio->prox->ant = listaAux->inicio->ant;
            listaAux->inicio->ant->prox=listaAux->inicio->prox;
            listaAux->inicio = listaAux->inicio->prox;
            free(del);
            del = listaAux->inicio;

        }
        else
        {
            printf("%s\n",del->nome);
            del->ant->prox= del->prox;
            del->prox->ant = del->ant;
            free(del);
            del = del->prox;
        }
        listaAux->tam--;
    }
}

void listar ( tipoLista *listaAux )
{
    elemento *atual;
    atual = listaAux->inicio;

    while ( atual->prox != listaAux->inicio )
    {
        printf("%s\n",atual->nome);
        atual = atual->prox;
    }
    printf("%s\n",atual->nome);
}

int main()

{
    int i,num,pass,surv;
    tipoLista lista;
    inicializacao(&lista);
    scanf("%d %d %d",&num,&pass,&surv);
    for(i=0; i<num; i++)
        inserir(&lista);
    printf("Execution list\n");
    remover(&lista,pass,surv);
    printf("List of survivors\n");
    listar(&lista);
}

