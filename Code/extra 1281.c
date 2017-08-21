#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    float preco;
} tipoFruta;

typedef struct
{
    tipoFruta fruta[50];
    int qtd;
} tipoProduto;

void inicia(tipoProduto *produto)
{
    produto->qtd=0;
}

void insere(tipoProduto *produto,tipoFruta prodAux)
{
    int a=produto->qtd;
    produto->fruta[a] = prodAux;
    produto->qtd++;
}

void compras(tipoProduto *produto,int k)
{
    int i,j,n;
    float total=0;
    char nomefruta[50];
    for (i=0;i<k;i++)
    {
        scanf("%s %d",nomefruta,&n);
        for(j=0; j < produto->qtd; j++)
        {
            if(strcmp(nomefruta,produto->fruta[j].nome)==0)
                total=total+(n*produto->fruta[j].preco);
        }
    }
    printf("R$ %.2f\n",total);
}

int main()
{
    int n,i,j,tam,k;

    tipoProduto produtos;
    tipoFruta frutas;
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        inicia(&produtos);
        scanf("%d",&tam);
        for(j=0; j<tam; j++)
        {
            scanf("%s %f",frutas.nome,&frutas.preco);
            insere(&produtos,frutas);
        }
        scanf("%d",&k);
        compras(&produtos,k);
    }
}
