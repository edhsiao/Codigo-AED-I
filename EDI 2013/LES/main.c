#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500

typedef struct{
char nome[30];
int idade;
}CLIENTE;

typedef struct{
    CLIENTE vetor[MAX];
    int nElem;
}LISTA;

void criarlista(LISTA *lista)
{
    lista->nElem = 0;
}

void inserirFinal(LISTA *lista,CLIENTE c1)
{
    lista->vetor[lista->nElem]=c1;
    lista->nElem = lista->nElem+1;

}

void inserirPosicao(LISTA *lista,int pos,CLIENTE c1)
{
    int i;
    if(pos>=lista->nElem)
        inserirFinal(lista, c1);
    else
        {
        for(i=lista->nElem;i > pos;i--)
            lista->vetor[i] =lista->vetor[i-1];

        lista->vetor[pos] = c1;
        lista->nElem = lista->nElem +1;
        }
}

void inserirInicio(LISTA *lista,CLIENTE c1)
{
    inserirPosicao(lista, 0 ,c1);
}

CLIENTE *acessoAPartirInicio(LISTA *lista,int pos)
{
    if(pos<lista->nElem)
        return &lista->vetor[pos];
    else
        return NULL;
}
CLIENTE *acessoAPartirFim(LISTA *lista,int pos)
{
        if(pos<lista->nElem)
        return &lista->vetor[lista->nElem-pos-1];
    else
        return NULL;
}

void listarInicioAoFim(LISTA *lista)
{
    int i;
    CLIENTE c1;
    for (i=0;i<lista->nElem;i++)
    {
        c1=lista->vetor[i];
        printf("nome: %s\n", c1.nome);
        printf("idade: %d\n", c1.idade);
    }
}
void listarFimAoInicio(LISTA *lista)
{
    int i;
    CLIENTE c1;
    for (i=lista->nElem-1;i<0;i--)
    {
        c1=lista->vetor[i];
        printf("nome: %s\n", c1.nome);
        printf("idade: %d\n", c1.idade);
    }
}
int tamanho(LISTA lista)
{
    return lista.nElem;
}
void destruir (LISTA *lista)
{
    lista->nElem = 0;
}
void eliminarPosicao(LISTA *lista, int pos)
{
    int i;
    if(pos<lista->nElem)
    {
        if(pos == (lista->nElem-1))
        {
            lista->nElem = lista->nElem-1;
        }
        else
        {
            for (i=pos;i<lista->nElem-1;i++)
            {
                lista->vetor[i]=lista->vetor[i+1];
            }
            lista->nElem = lista ->nElem-1;
        }
    }
}

CLIENTE *buscarPosicaoNome(char nome[],LISTA *lista)
{
    int i;

    for (i=0;i<lista->nElem;i++)
    {
        if(strcmp(nome, lista->vetor[i].nome)==0)
        return &lista->vetor[i];
    }
    return NULL;
}
int buscarEnderecoNome(char nome[],LISTA *lista)
{
    int i;

    for (i=0;i<lista->nElem;i++)
    {
        if(strcmp(nome, lista->vetor[i].nome)==0)
        return i;
    }
    return -1;
}

int main()
{
        int pos;
        int op=0;
        LISTA lista;
        CLIENTE c1;
        CLIENTE *cp;
        char nome[30];
        criarlista(&lista);

        do
            {
            printf("1 - Criar Lista\n");
            printf("2 - Inserir Inicio\n");
            printf("3 - Inserir Final\n");
            printf("4 - Inserir Posicao\n");
            printf("5 - Acessr a partir do Inicio\n");
            printf("6 - Acessar a partir do fim\n");
            printf("7 - Listar do Inicio ao fim\n");
            printf("8 - Listar do Fim ao inicio\n");
            printf("9 - Eliminar\n");
            printf("10 - Busca nome retorna endereco\n");
            printf("11 - Buscar nome retorna posicao\n");
            printf("12 - Tamanho da lista\n");
            printf("13 - Destruir\n");
            printf("14 - Sair\n");

;

            printf("opcao:");
            scanf("%d",&op);

        switch(op)
        {
            case 1:
                criarlista(&lista);
                    break;
            case 2:
                printf("nome: ");
                scanf("%s",c1.nome);
                printf("idade: ");
                scanf("%d",&c1.idade);
                inserirInicio(&lista,c1);
                break;
            case 3:
                printf("nome: ");
                scanf("%s",c1.nome);
                printf("idade: ");
                scanf("%d",&c1.idade);
                inserirFinal(&lista,c1);
                break;
            case 4:
                printf("nome: ");
                scanf("%s",c1.nome);
                printf("idade: ");
                scanf("%d",&c1.idade);
                printf("posicao:");
                scanf("%d",&pos);
                inserirPosicao(&lista,pos,c1);
                break;
            case 5:
                printf("posicao:");
                scanf("%d",&pos);
                cp=acessoAPartirInicio(&lista, pos);
                if(cp != NULL)
                {
                printf("nome: %s\n",cp->nome);
                printf("idade: %d",cp->idade);
                }else
                printf("posicao nao existe\n");
                break;
            case 6:
                printf("posicao:");
                scanf("%d",&pos);
                cp=acessoAPartirFim(&lista, pos);
                if(cp != NULL)
                {
                printf("nome: %s\n",cp->nome);
                printf("idade: %d\n",cp->idade);
                }else
                printf("posicao nao existe\n");
                break;
            case 7:
                listarInicioAoFim(&lista);
                break;
            case 8:
                listarFimAoInicio(&lista);
                break;
            case 9:
                printf("posicao: ");
                scanf("%d",&pos);
                eliminarPosicao(&lista,pos);
                break;
            case 10:
                printf("nome:");
                scanf("%s",nome);
                cp = buscarEnderecoNome(nome,&lista);
                if(cp!=NULL)
                {
                    printf("nome:%s\n",cp->nome);
                    printf("idade:%d\n",cp->idade);
                }else
                    printf("nao existe o nome\n");
                break;
            case 11:
                printf("nome:");
                scanf("%s",nome);
                pos = buscarPosicaoNome(nome,&lista);
                if(pos>=0)
                {
                printf("posicao:%d\n",pos);

                    cp=acessoAPartirInicio(&lista,pos);
                    printf("nome:%s\n",cp->nome);
                    printf("idade:%d\n",cp->idade);
                }else
                    printf("nao existe o nome\n");
                break;
            case 12:
                printf("tamanho: %d\n",tamanho(lista));
                break;
            case 13:
                destruir(&lista);
                break;
        }
        }while(op!=14);
}



