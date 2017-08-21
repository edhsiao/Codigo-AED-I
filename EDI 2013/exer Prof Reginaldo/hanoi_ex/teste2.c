/*
.
.
		TORRES DE HANOI
.
*/
#include<stdio.h>
#include<stdlib.h>


#define N 5	//Numero de discos
int movimentos=0;
int A[N], B[N], C[N];  /* Estes são os três torres. Por exemplo, se o
estado de A é 0,1,3,4, o que significa que existem três discos em um dos tamanhos
1, 3 e 4. (Pense em direito como sendo o "baixo" direcção.) */

void Hanoi(int,int*,int*,int*);
void limpa_tela(void)
{
    system("cls");
}


void
imprimetorre(void)
{
    int i;

    limpa_tela();
    printf("\n\n\n\n");
    for(i=0; i<N; i++)printf("\t\t\t   ( %d )  ( %d )	( %d ) \n",A[i],B[i],C[i]);
    printf("\t\t\t ___  _____  _______  ___\n");
    printf("\t\t\t|						|\n");
    printf("\t\t\t|	A	  B		C   |\n");
    printf("\t\t\t|________________________|\n");
    printf("Movimentos %d",movimentos);

    movimentos++;
    return;
}

/* Mova o elemento não zero à esquerda da fonte para dest, deixar 0. */
/* Retorna o valor transferido (não utilizado). */

int Mover(int *origem, int *destino)
{
    int i=0,j=0;

    while((*(origem + i)==0)&&(i<N))i++; //o ponteiro apontará para o proximo valor armazenado na memória,
    while((*(destino + j)==0)&&(j<N))j++;


    *(destino+j-1) = *(origem+i);
    *(origem + i) = 0;
    imprimetorre();	   	/* Imprimir configuração após cada jogada. */
    return *(destino+j-1);
}


/* Move primeiros n números não zero a partir do código fonte para dest utilizando as regras de Hanói.
	Solicita própria recursivamente.
*/

void
Hanoi(int n,int *origem, int *destino, int *aux) //recebendo valores,  partir de agora
//o ponteiro estará apontando para A[0], B[0], C[0]
{
    int i;
    if(n==1)
    {
        Mover(origem,destino);
        return;
    }

    Hanoi(n-1,origem,aux,destino);
    Mover(origem,destino);
    Hanoi(n-1,aux,destino,origem);
    return;
}


int
main()
{
    int i,x;

    do
    {
        printf("				   Univerdade do Estado de Matro\n");
        printf("				Campus Universitario de Alto Araguaia\n");
        printf("			Estrutura de Dados e Tecnicas de Programacao\n");
        printf("Docente: Prof. Max Robert Marinho\n");
        printf("Discentes: Marcos Vinicios Campos Linhares\n");
        printf("		   Risiane Margarete Vieira Barroso\n");
        printf("		   Roni Pess\n");
        printf("		   Wagner Moraes Oliveira\n\n");

        printf("					  /////////////////////////\n");
        printf("					 /					   /\n");
        printf("					/	TORRES DE HANOI	/\n");
        printf("				   /					   /\n");
        printf("				  /////////////////////////\n\n");
        printf("1. Conheca a Historia;\n");
        printf("2. Ver a solucao do problema para 5 Entradas;\n");
        printf("3. Sair;\n\n");
        printf("Digite sua opcao:");
        scanf("%d",&x);
        switch (x)
        {
        case 1 :
            limpa_tela();
            printf("							   TORRES DE HANOI \n\n\n");
            printf("							 _	  _		_\n");
            printf("							(1)	| |	  | |\n");
            printf("							| |	| |	  | |\n");
            printf("						   (_2_)   | |	  | |\n");
            printf("						   _|_|_   | |	  | |\n");
            printf("						 _(__3__)__|_|______|_|_\n");
            printf("						|					   |\n");
            printf("						|	A	  B		C  |\n");
            printf("						|_______________________|\n");
            printf("\n\n	 A Torre de Hanoi e um quebra-cabeca que consiste em uma base contendo tres pinos, em um dos quais sao dispostos alguns discos uns sobre os outros, em ordem crescente de diametro, de cima para baixo. O problema consiste em passar todos os discos de um pino para outro qualquer, usando um dos pinos como auxiliar, de maneira que um disco maior nunca fique em cima de outro menor em nenhuma situacao.\n");
            printf("	 Existem varias lendas a respeito da origem do jogo, a mais conhecida diz respeito a um templo Hindu, situado no centro do universo. Diz-se que Brahma supostamente havia criado uma torre com 64 discos de ouro e mais duas estacas equilibradas sobre uma plataforma. Brahma ordenara-lhes que movessem todos os discos de uma estaca para outra segundo as suas instrucoes. As regras eram simples: apenas um disco poderia ser movido por vez e nunca um disco maior deveria ficar por cima de um disco menor. Segundo a lenda, quando todos os discos fossem transferidos de uma estaca para a outra, o templo desmoronar-se-ia e o mundo desapareceria.\n");
            printf("	 E interessante observar que o numero minimo de ""movimentos"" para conseguir transferir todos os discos da primeira estaca a terceira é (2 elevado n)-1, sendo n o numero de discos.\n\n");
            printf("	 Logo,para solucionar um Hanoi de:\n\n");
            printf("3 discos, sao necessarios: (2 elevado a n -1) = 7 movimentos\n");
            printf("5 discos, sao necessarios: (2 elevado a n -1) = 31 movimentos\n");
            printf("64 discos, sao necessarios: (2 elevado a n -1) = 18.446.744.073.709.551.615 movimentos\n\n");
            printf("						   fonte: http://pt.wikipedia.org/wiki/Torre_de_Hanoi\n\n");
            system("pause");
            limpa_tela();
            break;
        case 2 :
            /* Inicializar o torres */
            for(i=0; i<N; i++)A[i]=i+1;
            for(i=0; i<N; i++)B[i]=0;
            for(i=0; i<N; i++)C[i]=0;
            movimentos=0;

            printf("Solucao para o problema das Torres de Hanoi com %d Discos\n\n",N);

            /* Imprimir a partida estado */
            imprimetorre();
            printf("\n\t\t\t	 Torre Inicial\n\n");
            printf("\n\n Para comecar a solucao do problema,\n");
            system("pause");
            /* Faça isso! Use A = Origem, Destino = C, B = Auxiliar */
            Hanoi(N,A,C,B);
            printf("\n\n\nProblema resolvido....\n");
            system("pause");
            limpa_tela();
            break;
        case 3 :
            break;
        default:
            printf("OPCAO INVALIDA!!!\a\n");

            limpa_tela();

        }
    }
    while(x!=3);

    return 0;

}
