#include <stdio.h>
#include <stdlib.h>
typedef struct Fila
{
    int valor;
    struct Fila * prox;
} Fila;
Fila * insere(Fila * inicio, int valor)
{
    Fila * aux = (Fila * )malloc(sizeof(Fila));
    aux->valor = valor;
    if(inicio == NULL)   //Fila vazia
    {
        aux->prox = inicio;
        inicio = aux;
    }
    else
    {
        Fila * aux2;
        aux2 = inicio;
        while(aux2->prox != NULL)   //Procura ultimo elemento da fila
        {
            aux2 = aux2->prox;
        }
        aux2->prox = aux;
        aux->prox = NULL;
    }
    return inicio;
}
Fila * deleta(Fila * inicio)
{
    Fila * aux;
    aux = inicio;
    inicio = inicio->prox;
    free(aux);
    return inicio;
}
void mostraFila(Fila * inicio)
{
    Fila * aux;
    aux = inicio;
    while(aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}
int main()
{
    Fila * ini;
    ini = NULL;
    ini = insere(ini, 3);
    ini = insere(ini, 4);
    ini = insere(ini, 1);
    ini = insere(ini, 2);
    mostraFila(ini);
    ini = deleta(ini);
    ini = deleta(ini);
    mostraFila(ini);
    ini = deleta(ini);
    ini = deleta(ini);
    ini = insere(ini, 5);
    mostraFila(ini);
    return 0;
}
