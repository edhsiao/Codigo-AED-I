#include "stdio.h"
#include "stdlib.h"
#include "Aula_31.Arvore.c"

int main()
{
    struct No *Raiz = (struct No*) NULL;

    int Opt;
    do
    {
        system("cls");
        printf("1 - Inserir\n");
        printf("2 - Inserir Recursividade\n");
        printf("3 - Pre-Ordem\n");
        printf("4 - Pos-Ordem\n");
        printf("5 - Em-Ordem\n");
        printf("6 - Em-Ordem Inversa\n");
        printf("7 - Buscar Elemento\n");
        printf("8 - Buscar Elemento Recursividade\n");
        printf("9 - Remover\n");
        printf("0 - Sair\n");
        scanf("%d", &Opt);

        if (Opt == 1)
        {
            int Id;
            printf("Informe o Id: ");
            scanf("%d", &Id);
            Raiz = AdicionarNo(Raiz, Id);
        }
        else if (Opt == 2)
        {
            int Id;
            printf("Informe o Id: ");
            scanf("%d", &Id);
            Raiz = AdicionarNoComRecursividade(Raiz, Id);
        }
        else if (Opt == 3)
        {
            PreOrdem(Raiz);
            printf("\n");
            system("pause");
        }
        else if (Opt == 4)
        {
            PosOrdem(Raiz);
            printf("\n");
            system("pause");
        }
        else if (Opt == 5)
        {
            EmOrdem(Raiz);
            printf("\n");
            system("pause");
        }
        else if (Opt == 6)
        {
            EmOrdemInversa(Raiz);
            printf("\n");
            system("pause");
        }
        else if (Opt == 7)
        {
            int Id;
            printf("Informe o Id: ");
            scanf("%d", &Id);
            struct No *NoLocalizado = BuscarNo(Raiz, Id);

            if (NoLocalizado == (struct No*) NULL)
                printf("Nao Localizado");
            else
                printf("Localizado No Endereco %x", NoLocalizado);

            printf("\n");
            system("pause");
        }
        else if (Opt == 8)
        {
            int Id;
            printf("Informe o Id: ");
            scanf("%d", &Id);
            struct No *NoLocalizado = BuscarNoComRecursividade(Raiz, Id);

            if (NoLocalizado == (struct No*) NULL)
                printf("Nao Localizado");
            else
                printf("Localizado No Endereco %x", NoLocalizado);

            printf("\n");
            system("pause");
        }
        else if (Opt == 9)
        {
            int Id;
            printf("Informe o Id: ");
            scanf("%d", &Id);
            RemoverNo(&Raiz, Id);
        }
    } while (Opt != 0);

    return 0;
}
