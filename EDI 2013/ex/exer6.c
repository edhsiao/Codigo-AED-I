#include<stdio.h>
#include<stdlib.h>


typedef struct cadastro
{
    int cod;
    int tempo_entrada;
    struct cadastro *prox;
} tipo_cadastro;

typedef struct fila
{
    tipo_cadastro *primeiro;
    tipo_cadastro *ultimo;
}tipo_fila;

void inicializaFila(tipo_fila *filaAux)
{
    int i;
    filaAux->primeiro = NULL;
    filaAux->ultimo = NULL;
}

int filaVazia(tipo_fila *filaAux)
{
    if(filaAux->primeiro == NULL )
        return 1;
    else
        return 0;
}

void insere(tipo_fila *filas, int codigo,int tempo)
{
    tipo_cadastro *aux;
    aux=(tipo_cadastro*)malloc (sizeof(tipo_cadastro));

    aux->cod=codigo;
    aux->tempo_entrada=tempo;

    ultimo->prox=aux;
    ultimo=ultimo->prox;
    aux->prox=primeiro;
}



void remover ()
{
    primeiro->prox=primeiro->prox->prox;
}


void espera(tipo_fila *filaAux)
{
    tipo_cadastro *aux;
    int i;




}

int main()
{
    int dia,user,tempo_inicio,tempo_fim,tempo_atendimento;
    int i,j;
    int tempo_geral=tempo_fim-tempo_inicio;;
    int codigo,tempo;
    tipo_fila filas;


    scanf("%d",&dia);
    for(i=1; i<=dia; i++)
    {
        printf("Day %d\n",i);
        inicializaFila(&filas);
        scanf("%d %d %d %d",&user,&tempo_inicio,&tempo_fim,&tempo_atendimento);
        for(j=0; j<user; j++)
        {
            scanf("%d %d",&codigo,&tempo);
            insere(&filas);
            espera(&filas);
        }
        printf("Day %d\n",i);

        return 0;
    }





