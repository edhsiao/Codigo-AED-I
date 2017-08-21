#include<stdio.h>
#include<stdlib.h>
#define TAM 10

typedef struct pilha
{
    int pos;
    struct pilha *next;
} pilha_t;


pilha_t* criarPilha(int i)
{
    pilha_t *p = (pilha_t*) malloc(sizeof(pilha_t));
    if(!p)
    {
        printf ("Erro: Memoria Insuficiente.\n");
        exit(-1);
    }
    p->next = NULL;
    p->pos = i;
    return(p);
}

//Empilha Elementos
pilha_t* empilha(pilha_t *p, int pos)
{
    pilha_t *temp = (pilha_t*) malloc(sizeof(pilha_t));
    if(!temp)
    {
        printf ("Erro: Memoria Insuficiente.\n");
        exit(-1);
    }
    temp->pos = pos;
    temp->next = p;
    return(temp);
}

//Desempilha
pilha_t* desempilha(pilha_t* p)
{
    pilha_t *temp = p;
    p = p->next;
    free(temp);
    return(p);
}

//Preenche a pilha
pilha_t* prencherPilha(pilha_t *p, char str[])
{
    unsigned short int i;

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '(')
        {
            if(p == NULL)
                p = criarPilha(i);
            else
                p = empilha(p, i);
        }
        else if(str[i] == ')')
        {
            if(p == NULL)
            {
                p = empilha(p, i*(-1));
                return(p);
            }
            p = desempilha(p);
        }
    }
    return(p);
}


int main()
{
    char str[TAM],c;
    pilha_t *p = NULL;
    int retorno = -1;

    while((scanf("%c",&c)!=EOF))

    p = prencherPilha(p, str);

    if(p == NULL)
        printf("Correto\n");
    else if(p->pos > 0)
    printf("Incorreto");

}
