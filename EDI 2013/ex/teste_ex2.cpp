#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct
{
    char s[MAX];
    int topo;
} tipoPilha;

void inicializar(tipoPilha *pilha)
{
    pilha->topo = 0; // pilha vazia
}


int empilhar(tipoPilha *pilha, char x)
{
    if(pilha->topo < MAX)
    {
        pilha->topo++;
        pilha->s[pilha->topo] = x;
    }
    else return 0;
    return 1;
}

void desempilha(tipoPilha *pilha)
{
    char returnVal;
    if(pilha->topo < 0)
    {
        returnVal = -1; //retorna erro de pilha vazia
    }
    else
    {
        returnVal = pilha->s[pilha->topo];
        pilha->topo--;
    }
}

int pilha_vazia(tipoPilha *pilha)
{
    if(pilha->topo==0)
        return 0;
}


int main()
{
    tipoPilha pilha;
    char c,x;
    int flag=0;
    inicializar(&pilha);
    while((scanf("%c",&c)!=EOF))
    {
        if(c == '\n')
        {
            if((pilha_vazia(&pilha)==0) && (flag==0))
            {
                printf("correct\n");
                inicializar(&pilha);
            }
            if((pilha_vazia(&pilha)!=0) || (flag==1))
            {
                printf("incorrect\n");
                inicializar(&pilha);
                flag=0;
            }
        }

        if(c=='(')
        {
            empilhar(&pilha,c);
        }

        if((c==')') &&  pilha.topo!=0)
        {
            desempilha(&pilha);
        }
        else if ((c==')') &&  pilha.topo==0)
        {
            flag=1;
        }
    }
    return 0;
}

