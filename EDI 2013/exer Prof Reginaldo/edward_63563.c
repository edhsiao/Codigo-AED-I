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


void insereOrdenado(tipoRegistro *registro ,tipoCadastro novoCadastro)
{
    tipoCadastro *novo;
    tipoCadastro *anterior=NULL;  /* ponteiro para elemento anterior */
    tipoCadastro *p=registro->inicio;/* ponteiro para percorrer a lista */

    while((p != NULL) ||  p->nota >= novoCadastro.nota )        /* procura posição de inserção */
    {
        if (p->nota == novoCadastro.nota)
        {
            if (p->insc<=novoCadastro.insc)
            {
                anterior=p;
                p=p->prox;
                break;
            }
            p=p->prox;
            break;
        }
        anterior=p;
        p=p->prox;
    }

    novo=(tipoCadastro*)malloc(sizeof(tipoCadastro));
    *novo=novoCadastro;

    if(anterior==NULL)
    {
        novo->prox=&novoCadastro;
        novoCadastro=*novo;
    }
    else
    {
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }
    registro->tam++;

}


void removeCadastro(tipoRegistro *registro,int inscricao)
{
    tipoCadastro *atual=registro->inicio;
    tipoCadastro *antes;
    antes=NULL;
    while((atual!=NULL) && (atual->insc!=inscricao))
    {
        antes=atual;
        atual=atual->prox;
    }
    if(atual=NULL)
    {
        printf("%d was not found\n",inscricao);
    }
    if(antes==NULL)
    {
        registro->inicio=atual->prox;
    }
    else
    {
        antes->prox=atual->prox;
    }
    registro->tam--;
}

void listarTop(tipoRegistro *registro,int top)
{
    tipoCadastro *p=registro->inicio;
    int i;
    if(top>=registro->tam)
    {
        printf("Top %d\n",top);
        for(i=1; i<top; i++)
        {
            printf("%d: %d %d\n",i,p->insc,p->nota);
            p=p->prox;
        }
    }
    else
    {
        printf("Top %d\n",registro->tam);
        for(i=1; i<registro->tam; i++)
        {
            printf("%d: %d %d\n",i,p->insc,p->nota);
            p=p->prox;
        }
    }
}


//void imprimeLista(tipoRegistro *registro)
//{
//    tipoCadastro *atual;
//    atual=registro->inicio;
//    printf("Tamanho lista =%d\n",registro->tam);
//    do
//    {
//        printf("%d %d\n",atual->insc,atual->nota);
//        atual = atual->prox;
//    }
//    while(atual != NULL);
//}




int main()
{

    int i,n,top,op,inscricao;
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
            insereOrdenado(&registros,cadastros);
            break;
        case 2:
            scanf("%d",&inscricao);
            removeCadastro(&registros,inscricao);
            break;
        case 3:
             scanf("%d",&top);
             listarTop(&registros,top);
            break;
        }
    }
   // imprimeLista(&registros);
}
