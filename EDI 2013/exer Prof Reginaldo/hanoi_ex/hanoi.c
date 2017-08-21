#include <stdio.h>
#include <stdlib.h>

// Procedimentos
void Jogo();
void Instrucao();
void Sequencia();
void Sobre();

void Movimentos (int n, char orig, char dest, char aux);

int main()
{

    int op=0;

// Enquanto op diferente de 5
    while (op != 5)
    {


        printf("\t\t---------------------------------------------------\n");
        printf("\t\t\t\tTORRE DE HAN%cI\n",224);
        printf("\t\t---------------------------------------------------\n\n");

        // Menu de opções
        printf(" 1 - JOGAR\n");
        printf(" 2 - INSTRU%c%cES\n",384,229);
        printf(" 3 - SEQU%cNCIA DE MOVIMENTOS\n",210);
        printf(" 4 - SOBRE\n");
        printf(" 5 - SAIR\n\n");

        op=0; // Só serão aceitos valores entre 1(inclusive) e 5(inclusive)
        while (op<1 || op>5)
        {
            printf("  Digite op%c%co: ",135,454);
            scanf("%d",&op);
        }

        system("cls");
        // Desvio para o procedimento
        if (op == 1) Jogo();
        if (op == 2) Instrucao();
        if (op == 3) Sequencia();
        if (op == 4) Sobre();
    }
    return 0;
}




void Jogo()
{

    int n, op, posi=0;
    int cont_B, cont_C, n_mov=0;
    int posi_2=0, ok=0;
    int num=0,i;


    n=0; // Só serão aceitos valores entre 1(inclusive) e 8(inclusive)
    while ((n<1) || (n>8))
    {
        printf("\n N%cmero de Argolas..: ",419);
        scanf("%d",&n);
    }
    system("cls");

    // Declarando os vetores
    int A[n], B[n], C[n];

    // Inicializando os vetores
    for ( i=0; i<n; ++i)
    {
        A[i]=(i+1);
        B[i]=(0);
        C[i]=(0);
    }
    op = 0;
    while (op != 7)
    {
        system("cls");

        // Designer
        for ( i=0; i<n; ++i)
        {

            printf("\n\t");
            if (A[i] == 0)  printf("   ");
            else printf("<%d>", A[i]);
            if (B[i] == 0)  printf("     ");
            else printf("  <%d>", B[i]);
            if (C[i] == 0)  printf("     ");
            else printf("  <%d>",C[i]);
        }
        printf("\n\t=============\n");
        printf("\t A    B    C \n");
        printf("\t=============\n\n");


        // Verifica se o jogo acabou...
        cont_B = 0;
        cont_C = 0;
        for ( i=0; i<n; ++i)
        {
            if (B[i] == (i+1)) cont_B++;
            if (C[i] == (i+1)) cont_C++;
        }

        // ...caso sim imprimi uma mensagem e encerra o programa
        if (cont_B == n || cont_C == n)
        {
            printf("Parabens, voce conseguiu em %d movimentos!\n",n_mov);
            break;
        }

        // Menu de comandos
        printf("[1] A ==> B\t");
        printf("[2] A ==> C\n");
        printf("[3] B ==> A\t");
        printf("[4] B ==> C\n");
        printf("[5] C ==> A\t");
        printf("[6] C ==> B\t");
        printf("[7] SAIR\n\n");

        printf("N%cmero de Movimentos: %d\n",419,n_mov);
        op=0; // Inicializando a variável
        while (op<1 || op>7)
        {
            printf(" Digite op%c%co: ",135,454);
            scanf("%d", &op);
        }
        n_mov++; // Atualizando o número de movimentos


        // Primeira opção
        if (op == 1)
        {
            ok=0;
            // Verifica quantos elementos nulo existe no vetor
            for ( i=0; i<n; ++i) if (A[i]==0) ok++;

            // Existe pelo menos um elemento não nulo no vetor?
            if (ok!=n)
            {
                posi_2=0;

                // Será armazenado na variável num o primeiro elemento não nulo do vetor A
                for (i=0; i<n; ++i)
                {
                    if (A[i]!=0)
                    {
                        num = A[i];
                        A[i]=0;
                        posi=i;
                        break;
                    }
                }

                // Busca o primeiro elemento nulo do vetor B, olhando de baixo para cima, e armazena a sua posição
                for ( i=(n-1); i>=0; --i)
                {
                    if (B[i] == 0)
                    {
                        posi_2=i;
                        break;
                    }
                }

                // O vetor B[posi_2] irá receber o valor retirado do vetor A
                B[posi_2]=num;
                if (posi_2 != (n-1))
                {
                    // Verifica se o elemento anterior é maior que o novo elemento do vetor
                    if (B[posi_2]<B[posi_2+1]) num = B[posi_2];
                    else
                    {
                        // Caso não seja tudo vai voltar a ser como antes
                        A[posi]=num;
                        B[posi_2]=0;
                    }
                }
            }
        }



        // Segunda opção
        if (op == 2)
        {
            ok=0;
            for ( i=0; i<n; ++i) if (A[i]==0) ok++;

            if (ok!=n)
            {

                posi_2=0;

                for ( i=0; i<n; ++i)
                {
                    if (A[i]!=0)
                    {
                        num = A[i];
                        A[i]=0;
                        posi=i;
                        break;
                    }
                }

                for ( i=(n-1); i>=0; --i)
                {
                    if (C[i] == 0)
                    {
                        posi_2=i;
                        break;
                    }
                }

                C[posi_2]=num;
                if (posi_2 != (n-1))
                {
                    if (C[posi_2]<C[posi_2+1]) C[posi_2]=num;
                    else
                    {
                        A[posi]=num;
                        C[posi_2]=0;
                    }
                }
            }
        }



        // Terceira opção
        if (op == 3)
        {
            ok=0;
            for ( i=0; i<n; ++i) if (B[i]==0) ok++;

            if (ok!=n)
            {

                posi_2=0;

                for ( i=0; i<n; ++i)
                {
                    if (B[i]!=0)
                    {
                        num = B[i];
                        B[i]=0;
                        posi=i;
                        break;
                    }
                }

                for ( i=(n-1); i>=0; --i)
                {
                    if (A[i] == 0)
                    {
                        posi_2=i;
                        break;
                    }
                }

                A[posi_2]=num;
                if (posi_2 != (n-1))
                {
                    if (A[posi_2]<A[posi_2+1]) A[posi_2]=num;
                    else
                    {
                        B[posi]=num;
                        A[posi_2]=0;
                    }
                }
            }
        }



        // Quarta opção
        if (op == 4)
        {
            ok=0;
            for ( i=0; i<n; ++i) if (B[i]==0) ok++;

            if (ok!=n)
            {

                posi_2=0;

                for ( i=0; i<n; ++i)
                {
                    if (B[i]!=0)
                    {
                        num = B[i];
                        B[i]=0;
                        posi=i;
                        break;
                    }
                }

                for ( i=(n-1); i>=0; --i)
                {
                    if (C[i] == 0)
                    {
                        posi_2=i;
                        break;
                    }
                }

                C[posi_2]=num;
                if (posi_2 != (n-1))
                {
                    if (C[posi_2]<C[posi_2+1]) C[posi_2]=num;
                    else
                    {
                        B[posi]=num;
                        C[posi_2]=0;
                    }
                }
            }
        }



        // Quinta opção
        if (op == 5)
        {
            ok=0;
            for ( i=0; i<n; ++i) if (C[i]==0) ok++;

            if (ok!=n)
            {

                posi_2=0;

                for ( i=0; i<n; ++i)
                {
                    if (C[i]!=0)
                    {
                        num = C[i];
                        C[i]=0;
                        posi=i;
                        break;
                    }
                }

                for ( i=(n-1); i>=0; --i)
                {
                    if (A[i] == 0)
                    {
                        posi_2=i;
                        break;
                    }
                }

                A[posi_2]=num;
                if (posi_2 != (n-1))
                {
                    if (A[posi_2]<A[posi_2+1]) A[posi_2]=num;
                    else
                    {
                        C[posi]=num;
                        A[posi_2]=0;
                    }
                }
            }
        }



        // Sexta opção
        if (op == 6)
        {
            ok=0;
            for ( i=0; i<n; ++i) if (C[i]==0) ok++;

            if (ok!=n)
            {

                posi_2=0;

                for ( i=0; i<n; ++i)
                {
                    if (C[i]!=0)
                    {
                        num = C[i];
                        C[i]=0;
                        posi=i;
                        break;
                    }
                }

                for ( i=(n-1); i>=0; --i)
                {
                    if (B[i] == 0)
                    {
                        posi_2=i;
                        break;
                    }
                }

                B[posi_2]=num;
                if (posi_2 != (n-1))
                {
                    if (B[posi_2]<B[posi_2+1]) B[posi_2]=num;
                    else
                    {
                        C[posi]=num;
                        B[posi_2]=0;
                    }
                }
            }
        }


    } // Finaliza o laço while
    system("pause");
    system("cls");
}



void Sequencia()
{

    int discos,op;
    discos=0;
    while ((discos<1) || (discos>8))
    {
        printf("\n N%cmeros de discos: ",419);
        scanf("%d",&discos);
    }

    printf("\n\n\n|1| Para Destino em (C)\n");
    printf("|2| Para Destino em (B)\n");
    printf("|3| SAIR\n\n\n");
    op=0;
    while ((op<1) || (op>3))
    {
        printf("Op%c%co para o Destino: ",135,454);
        scanf("%d",&op);
    }
    printf("\n");


    if (op == 1) Movimentos(discos,'A','C','B');
    if (op == 2) Movimentos(discos,'A','B','C');

    printf("\n");
    system("pause");
    system("cls");
}


void Movimentos (int num, char origem, char destino, char aux)
{

    if (num==1)
    {
        printf(" Mover disco 1 da torre %c para a torre %c\n", origem, destino);
        return;
    }

    // Recursividade
    Movimentos(num-1,origem,aux,destino);
    printf(" Mover disco %d da torre %c para a torre %c\n", num, origem, destino);
    Movimentos(num-1,aux,destino,origem);
}



void Instrucao()
{
    printf("\n  - MOVIMENTAR UMA S%c PE%cA DE CADA VEZ.\n\n",224,384);
    printf("   - UMA PE%cA MAIOR N%cO PODE FICAR ACIMA DE UMA MENOR.\n\n",384,455);
    printf("    - N%cO %c PERMITIDO MOVIMENTAR UMA PE%cA QUE ESTEJA ABAIXO DA OUTRA.\n\n",455,144,384);
    system("pause");
    system("cls");
}


void Sobre()
{
    printf("\n  IFBA: INSTITUTO FEDERAL DE EDUCA%c%cO, CI%cNCIA E TECNOLOGIA DA BAHIA.\n",384,455,210);
    printf("   CAMPUS VALEN%cA.\n\n",384);
    printf("    FUNDADOR: JO%cO MATHEUS SANTOS ASSIS.\n",455);
    printf("    CO-FUNDADOR: MATHIAS SANTOS ASSIS.\n\n");
    system("pause");
    system("cls");
}
