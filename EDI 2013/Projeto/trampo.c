#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVERTICES 50

//*******************************************************************
// Projeto Estrutura de Dados I (RER)
// Autores: Diego Otávio  63552
//          Edward Hsiao  63563
// Data: 26/08/2013
// Curso : BCC Vespertino
// Prof: MARIÁ CRISTINA VASCONCELOS NASCIMENTO
//*******************************************************************
//Descrição:

//Uma Rede de Sensores Sem Fios (RSSF) é composta por pequenos dispositivos equipados com
//adaptadores de rede sem fio capazes de comunicar-se a curtas distâncias com baixas taxas de
//transmissão. A estrutura dessas RSSF pode ser representada por um grafo no qual os vértices
//representam dispositivos e as arestas representam a interligações entre cada um desses dispositivos,
//ou seja, existe uma aresta entre quaisquer dois vértices se os dispositivos representados por elas são
//capazes de comunicar-se um com o outro diretamente. Infelizmente, em uma RSSF é necessário que
//a comunicação também ocorra entre dispositivos que estão fisicamente distantes um dos outros, e,
//portanto, fora do alcance para a comunicação direta. Quando isso ocorre é necessário que os dados
//transmitidos (pacotes) sejam reconduzidos (roteados) entre os diversos dispositivos intermediários
//(caminho) a partir de uma origem até um destino. Existem diversas razões para a não existência de
//caminhos interconectando quaisquer dois dispositivos em uma RSSF. Por esse motivo, em alguns
//casos, torna-se necessário descobrir a existência de um caminho entre quaisquer dispositivos na
//rede antes da origem efetuar uma transmissão. Além disso, é importante que os pacotes sejam
//sempre roteados por dispositivos intermediários que possuam maior carga em sua bateria. Visto que
//os dispositivos desse tipo de rede não possuem um suprimento de energia inesgotável, utilizar essa
//estratégia de comunicação pode aumentar consideravelmente o tempo de vida da RSSF. Isso, na
//prática, significa aumentar o tempo de vida de bateria em cada um dos dispositivos através de um
//balanceamento na distribuição do trabalho de transmissão/roteamento.

//Os objetivos deste trabalho são:

//1. Dado um grafo G, que representa uma RSSF, desenvolver um programa para verificar a
//existência de um caminho que interliga dois vértices quaisquer se d; e
//2. No caso de existir mais de um caminho determinar o caminho de transmissão que maximize o
//tempo de vida RSSF.




struct aresta {
    // se adj=1 então ADJACENTE; se adj=0 então NÃO ADJACENTE
    int adj;
    int peso;
};

struct matriz {
    // matriz de adjacências
    struct aresta arestas[MAXVERTICES][MAXVERTICES];
};
typedef struct matriz matAdj;

struct caminho {
    int origem;
    int destino;
    int carga;
};
typedef struct caminho tipoCaminho;

void iniciarMatriz (matAdj *g,int numVertices)//Inicializa a Matriz
{

    int i;
    int j;
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j ++) {
            g->arestas[i][j].adj = 0;
            g->arestas[i][j].peso = 0; // 999 = "infinito"
        }
    }
}

void gerarMatrizAdjacencia(matAdj *g,int numAresta,char *arquivo)
{
    FILE *file,*file2;
    int i;
    int j;
    tipoCaminho pesos[numAresta];
    int numVertices;
    int numArestas;
    int vertOrigem;
    int vertDestino;


    file = fopen(arquivo,"r");
    file2 = fopen("Matriz.txt","w");
    if (file != NULL){
        //fseek(file,17,SEEK_SET);
        fscanf( file, "%d%d%d%d",&numVertices,&numArestas,&vertOrigem,&vertDestino);
        for(i=0;i<numArestas;i++){
            fscanf( file, "%d%d%d",&pesos[i].origem,&pesos[i].destino,&pesos[i].carga);
                g->arestas[pesos[i].origem-1][pesos[i].destino-1].adj = 1;
                g->arestas[pesos[i].origem-1][pesos[i].destino-1].peso = pesos[i].carga;
        }
    }
        else
            printf("Arquivo não pode ser aberto");
    fclose(file);
    for(i=0;i<numVertices;i++)
        for(j=0;j<numVertices;j++){
            fprintf(file2,"%d,",g->arestas[i][j].peso); // Gravando os pesos no grafo e salvando no arquivo
            if(j+1 == numVertices)
                fprintf(file2,"\n"); // fazendo o enter no arquivo.
        }
    fclose(file2);
}

int* dijkstra (matAdj *g, int s, int t,int numVertices)
{
    int perm[numVertices];
    float dist[numVertices];
    int current, i, k, dc;
    int maiordist, newdist;
    int *path = (int*)malloc(numVertices*sizeof(int));
    /* Inicializa todos os índices de 'perm' como 0 e de 'dist' como INFINITY */
    for (i = 0; i < numVertices; i++) {
        perm[i] = 0;
        dist[i] = 0;
    }

    /* Inclui 's' em perm (perm[s]=1) e configura(armazena) sua carga como sendo zero */
    perm[s] = 1;
    dist[s] = 0;

    /* define 's' como origem (fonte) da busca */
    current = s;
    k = current;

    while (current != t) {
        maiordist = 0;
        dc = dist[current];
        //printf("dc %d\n",dc);

        for (i = 0; i < numVertices; i++) {

            //se o elemento NÃO está em perm
            if (perm[i] == 0) {

                //calcula distância a partir do vértice corrente ao vértice adjacente i
                newdist = dc + g->arestas[current][i].peso;

                //se a distância partindo do vértice corrente for menor, atualiza o vetor
                //de distâncias e de precedência
                if (newdist > dist[i] ) {
                    dist[i] = newdist;
                    path[i] = current;
                }

                //determina o vértice (entre todos os não pertencentes a perm) com menor distância
                if (dist[i] > maiordist) {
                    maiordist = dist[i];
                    k = i;
                }
            }
        } /* fim for */

        /* embora estamos assumindo grafos ponderados e conexos, este if garante que
         em caso de não existência de um caminho o programa não entre em loop infinito */
        if (current == k) {
            printf("\n\nCAMINHO NAO EXISTE\n\n");
            return 0;
        }

        current = k;
        perm[current] = 1;

    } /* fim while */

   /* impressao do resultado ****************/
    int caminho = t;

    printf("%d <- ", t+1);

    while (caminho != s)
    {
        printf("%d", path[caminho]+1);
        caminho = path[caminho];

        if (caminho != s)
            printf (" <- ");
    }

    //printf("\n\nCusto: %.2f\n\n", dist[t]);
    /******************************************/
    return path;
} /* fim dijkstra */



int main()
{
    FILE *file;
    int op;
    char arquivo[20];
    int numVertices;
    int numArestas ;
    int vertOrigem ;
    int vertDestino ;
    matAdj matriz;

    printf("*******************************************************************\n");
    printf("|Projeto Algoritmos e Estruturas de Dados I (RER)                 |\n");
    printf("|Autores: Diego Otavio  63552                                     |\n");
    printf("|         Edward Hsiao  63563                                     |\n");
    printf("|Data:    26/08/2013                                              |\n");
    printf("|Curso:   BCC                                                     |\n");
    printf("|Profa:   Maria Cristina Vasconcelos Nascimento                   |\n");
    printf("*******************************************************************\n\n");

    printf("\nDigite uma opcao:\n");
    printf("\n1 - Calcular o caminho (a partir de um arquivo).");
    printf("\n2 - Sair.\n");
    scanf("%d",&op);
    switch(op){

    case(1):
    strcpy(arquivo,"Input.txt");
    file = fopen(arquivo,"r");
    if (file != NULL)
        fscanf( file,"%d%d%d%d",&numVertices,&numArestas,&vertOrigem,&vertDestino);
    fclose(file);

    iniciarMatriz(&matriz,numVertices);
    gerarMatrizAdjacencia(&matriz,numArestas,arquivo);

    int *caminho = (int*)malloc(numVertices*sizeof(int));

    caminho = dijkstra (&matriz, vertOrigem-1, vertDestino-1,numVertices);
    case(2):
    printf("\n\n***************************FIM****************************************\n\n");
    }
    return 0;
}
