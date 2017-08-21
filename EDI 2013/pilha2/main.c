#include <stdio.h>
#include <stdlib.h>

struct no{
    int id;
    int valor;
    struct no *prox;
    };


//void inserir (tipo_no pilha,)


int main()
{
    int opt;
    int id,valor;
    struct no *primeiro =(struct no*)NULL;
    struct no *ultimo =(struct no*)NULL;
    struct no *atual =(struct no*)NULL;

    do{
        system("cls");
        printf("1 - Consultar Valor\n");
        printf("2 - Listar Tudo\n");
        printf("3 - Substituir\n");
        printf("4 - Inserir\n");
        printf("5 - Remover\n");
        printf("6 - Sair\n");

    scanf("%d",&opt);
    switch(opt){
        case 1:
            atual=primeiro;
            printf("Informe o valor:");
            scanf("%d",&valor);
            while (atual!=(struct no*)NULL)
            {
                if (atual->valor==valor)
                {
                    printf("ID: %d\n",atual->id);
                }
                atual=atual->prox;
            }
        case 2:
            atual =primeiro;
            while(atual!=(struct no*)NULL)
            {
                printf("Id: %d  |Valor %d \n",atual->id,atual->valor);
                atual=atual->prox;
            }
            system("pause");
        case 3:
            atual =primeiro;

            printf("Informe o id e o novo valor\n");
            scanf("%d %d", &id,&valor);
            while (atual!=(struct no*)NULL)
            {
                if (atual->id=id)
                {
                    atual->valor=valor;
                    break;
                }
                atual=atual->prox;
            }
        system("pause");


        case 4:if(primeiro==(struct no*)NULL)
        {
            atual = primeiro = ultimo =(struct no*)malloc(sizeof(struct no*));
            atual->id=1;
        }
       else{
            ultimo->prox=(struct no*)malloc(sizeof(struct no*));
            atual=ultimo->prox;
            atual->id =ultimo->id+1;
            ultimo=atual;
       }

        atual->prox=(struct no*)NULL;


        printf("Informe o Valor:\n");
        scanf("%d",&valor);
        atual->valor = valor;
        break;
        case 5:
            if(primeiro ==(struct no* )NULL)
                continue;
            if(primeiro==ultimo)
            {
                atual=primeiro;
                free(atual);
                primeiro=ultimo=(struct no*)NULL;
                continue;
            }
            atual=primeiro;
            while(atual->prox!=ultimo)
                atual=atual->prox;
            free(ultimo);
            ultimo=atual;
            atual->prox=(struct no*)NULL;
           }}
           while (opt!=6);

           return 0;






}
