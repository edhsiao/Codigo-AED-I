#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000000

typedef struct
{
    char conteudoSaida[70];
} tipoConteudoSaida;

typedef struct
{
    tipoConteudoSaida *impressaoSaida;
    int size;
} tipoVetorSaida;

typedef struct
{
    int codigo;
    char nome[50];
} tipoCadastro;

typedef struct
{
    tipoCadastro cadastro[1000];
    int tam;
} tipoRegistro;

void iniciaRegistro(tipoRegistro *registro)
{
    registro->tam=0;
}
void iniciaVetorSaida(tipoVetorSaida *vetorSaidas)
{
    vetorSaidas->size=0;
}

int insere( tipoRegistro *registro,tipoCadastro novoCadastro,int cap, tipoVetorSaida *vetorSaida )
{
    int pos = registro->tam, ind=vetorSaida->size;
    if(pos < cap)
    {
        registro->cadastro[pos] =novoCadastro;
        registro->tam++;
    }
    else
    {
        strcpy((vetorSaida->impressaoSaida[ind].conteudoSaida),"List is full");
        vetorSaida->size++;
    }
    return 1;
}

void remover(tipoRegistro *registro,char nome[],tipoVetorSaida *vetorSaida)
{
    int i,j,achou=0,pos=registro->tam;
    for(i=0; i<registro->tam; i++)
    {
        if(strcmp(nome,registro->cadastro[i].nome)==0)
        {
            achou=1;
            if(i==0)
            {
                for(j=0; j<pos-1; j++)
                    registro->cadastro[j]=registro->cadastro[j+1];
                registro->tam--;
            }
            else if(i==pos-1)
                registro->tam--;
            else
            {
                for(j=i; j<pos-1; j++)
                    registro->cadastro[j]=registro->cadastro[j+1];
                registro->tam--;
            }
        }
    }
    if(achou==0)
    {
        strcpy((vetorSaida->impressaoSaida[vetorSaida->size].conteudoSaida),(strcat(nome," was not found")));
        vetorSaida->size++;
    }
}

void imprimeVetorSaida(tipoVetorSaida *vetorSaida)
{

    int i=0;
    for(i=0; i < vetorSaida->size; i++)
        printf("%s\n",vetorSaida->impressaoSaida[i].conteudoSaida);
}

void imprimeRegistro(tipoRegistro *registro)
{

    int i=0;
    for(i=0; i < registro->tam; i++)
        printf("%d %s\n",registro->cadastro[i].codigo,registro->cadastro[i].nome);
}

int main()
{

    int i,n,cap,op;
    tipoVetorSaida vetorSaidas;
    vetorSaidas.impressaoSaida=(tipoVetorSaida*)malloc(N*sizeof(tipoVetorSaida));
    tipoConteudoSaida conteudoSaidas;
    tipoCadastro cadastros;
    tipoRegistro registros;

    scanf("%d %d",&n,&cap);

    iniciaVetorSaida(&vetorSaidas);
    iniciaRegistro(&registros);
    for(i=0; i<n; i++)
    {
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            scanf("%d %s",&cadastros.codigo,cadastros.nome);
            insere(&registros,cadastros,cap,&vetorSaidas);
            break;
        case 2:
            scanf("%s",cadastros.nome);
            remover(&registros,cadastros.nome,&vetorSaidas);
            break;

        }
    }
    imprimeVetorSaida(&vetorSaidas);
    imprimeRegistro(&registros);

    return 0;

}

