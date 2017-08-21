#include <stdio.h>
#include <stdlib.h>

typedef struct cadastro
{
    int insc;
    int nota;
    struct cadastro *prox;
} tipoCadastro;

typedef struct
{
    tipoCadastro *inicio;
    tipoCadastro *fim;
    int tam;
} tipoRegistro;

void inicializaCadastro(tipoRegistro *registro)
{
    registro->inicio=NULL;
    registro->fim=NULL;
    registro->tam=0;
}


void insereCadastro(tipoRegistro *registro,tipoCadastro novoCadastro)
{
    tipoCadastro *cadastroPt;
    tipoCadastro *p=registro->inicio;

    cadastroPt=(tipoCadastro*)malloc(sizeof(tipoCadastro));

    *cadastroPt=novoCadastro;

    if(p==NULL)
       registro->inicio=cadastroPt;
       else{
        while(p->prox!=NULL)
            p=p->prox;
       p->prox=cadastroPt;
       }
    registro->tam++;
}


void removeCadastro(tipoRegistro *registro,int insc)
{
    int achou=0;
    tipoCadastro *c1=registro->inicio;
    tipoCadastro *c2;
    c2=NULL;
    while(c1!=NULL)
    {
        if(insc==c1->insc)
        {
            achou=1;
            if(c2==NULL)
                registro->inicio=c1->prox;
            else
                c2->prox=c1->prox;
            free(c1);
            registro->tam--;
            break;
        }
        c2=c1;
        c1=c1->prox;
    }
    if(achou==0)
        printf("%d was not found\n",insc);
}

/*void consulta(tipoRegistro *registro,int top)
{
    tipoCadastro *novo
    novo=registro->inicio;
    int i,maior=novo->nota;
    printf("Top %d\n",top);
    for(i=0;i<top;atual->prox)
    {
        if()
    }
}*/


void imprimeLista(tipoRegistro *registro)
{
    tipoCadastro *atual;
    atual=registro->inicio;
    printf("Tamanho lista =%d\n",registro->tam);
    do
    {
        printf("%d %d\n",atual->insc,atual->nota);
        atual = atual->prox;
    }
    while(atual != NULL);
}




int main()
{

    int i,n,top,op;
    tipoCadastro cadastros;
    tipoRegistro registros;
    cadastros.prox=NULL;
    scanf("%d ",&n);
    inicializaCadastro(&registros);
    for(i=0; i<n; i++)
    {
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            scanf("%d %d",&cadastros.insc,&cadastros.nota);
            insereCadastro(&registros,cadastros);
            break;
        case 2:
            scanf("%d",&cadastros.insc);
            removeCadastro(&registros,cadastros.insc);
            break;
        case 3:
            scanf("%d",&top);
            //consulta(&registros,top);
            break;
        }
    }

    imprimeLista(&registros);
}
