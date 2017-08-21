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

void insereMeio(tipoRegistro *registro,tipoCadastro *novoCadastro)
{
    tipoCadastro *atual;
    tipoCadastro *antes;
    antes=registro->inicio;
    for(atual=registro->inicio->prox; atual!=NULL; atual=atual->prox)
    {
        if(novoCadastro->nota < atual->nota)
        {
            novoCadastro->prox=atual;
            antes->prox=novoCadastro;
        }
        antes=atual;
    }

}

void insereOrdenado(tipoRegistro *registro,int inscricao, int nota)
{
    tipoCadastro *novo;
    tipoCadastro *ant=NULL;  /* ponteiro para elemento anterior */
    tipoCadastro *p=registro->inicio;/* ponteiro para percorrer a lista */

    while((p != NULL) ||  p->nota >= nota )      /* procura posição de inserção */
    {
        if (p->nota == nota)
        {
            if (p->insc==inscricao)
            {
                ant=p;
            }
        }
        p=p->prox;
    }
    /* cria novo elemento */
    novo=(tipoCadastro*)malloc(sizeof(tipoCadastro));
    novo->nota=nota;
    novo->insc=inscricao;
    if(registro->tam==0){
        novo->prox=NULL;
        registro->inicio=novo;
        registro->fim=novo;
    }
    else{
        if(novo->nota>registro->fim->nota)
        {
            novo->prox=NULL;
            registro->fim->prox=novo;
            registro->fim=novo;
        }
        else{
            if(novo->nota< registro->inicio->nota){
                novo->prox=registro->inicio;
            }
            else{
                insereMeio(registro,novo);
            }
        }
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
        if(antes==NULL){
            registro->inicio=atual->prox;
        }
        else{
            antes->prox=atual->prox;
        }
        registro->tam--;
}

//void consulta(tipoRegistro *registro,int top)
//{
//    tipoCadastro *novo
//    novo=registro->inicio;
//    int i,maior=novo->nota;
//    if(top>=registro->tam)
//        printf("Top %d\n",top);
//    else
//        printf("Top %d\n",registro->tam);
//    for(i=0; i<top; atual->prox)
//    {
//        if()
//        }
//}


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

    int i,n,top,op,inscricao,nota;
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
            scanf("%d %d",&inscricao,&nota);
            insereOrdenado(&registros,inscricao,nota);
            break;
        case 2:
            scanf("%d",&inscricao);
            removeCadastro(&registros,inscricao);
            break;
        case 3:
            scanf("%d",&top);
            //  consulta(&registros,top);
            break;
        }
    }
    imprimeLista(&registros);
}
