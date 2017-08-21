#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVERTICES 50

int guardaCaminho;

struct aresta {
    // se adj=1 então ADJACENTE; se adj=0 então NÃO ADJACENTE
    int adj;
    int peso;
};

struct matriz {
    // matriz de adjacências
    struct aresta arestas[MAXVERTICES][MAXVERTICES];
};
typedef struct matriz matrizAdjacencia;

struct rodovia {
    int cidadeOrigem;
    int cidadeDestinho;
    int comprimentoKM;
};
typedef struct rodovia tipoRodovia;

void iniciarMatriz (matrizAdjacencia *g,int numVertices)//Inicializa a Matriz
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

void gerarMatrizAdjacencia(matrizAdjacencia *g,int numAresta,char *arquivo)
{
    FILE *file,*file2;
    int i;
    int j;
    tipoRodovia pesos[numAresta];
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
            fscanf( file, "%d%d%d",&pesos[i].cidadeOrigem,&pesos[i].cidadeDestinho,&pesos[i].comprimentoKM);
                g->arestas[pesos[i].cidadeOrigem-1][pesos[i].cidadeDestinho-1].adj = 1;
                g->arestas[pesos[i].cidadeOrigem-1][pesos[i].cidadeDestinho-1].peso = pesos[i].comprimentoKM;
        }
    }
        else
            printf("Arquivo não pode ser aberto");
    fclose(file);
    for(i=0;i<numVertices;i++)
        for(j=0;j<numVertices;j++){
            fprintf(file2,"%d ",g->arestas[i][j].peso); // Gravando os pesos no grafo e salvando no arquivo
            if(j+1 == numVertices)
                fprintf(file2,"\n"); // fazendo o enter no arquivo.
        }
    fclose(file2);
}

int* dijkstra (matrizAdjacencia *g, int s, int t,int numVertices, int tiraVertice)
{
    guardaCaminho = 0;
    int perm[numVertices];
    float dist[numVertices];
    int current, i, k, dc; //k=proximo vertice a ser visitado // dc = distancia atual
    int maiordist, newdist;
    int *path = (int*)malloc(numVertices*sizeof(int));
    int *caminhoNovo = (int*)malloc(numVertices*sizeof(int));
    /* Inicializa todos os índices de 'perm' como 0 e de 'dist' como INFINITY */
    for (i = 0; i < numVertices; i++) {
        perm[i] = 0;
        dist[i] = 0;
    }
    // perm verifica se o nó já foi visitado. se o nó já foi visitado, perm[s] = 1.
    
    perm[s] = 1;
    dist[s] = 0;
    perm[tiraVertice] = 1;
    dist[tiraVertice] = 0;

    /* define 's' como origem (fonte) da busca */
    current = s;
    k = current;

    while (current != t) {
        maiordist = 0;
        dc = dist[current];
        //printf("dc %d\n",dc);

        for (i = 0; i < numVertices; i++) {

            //se o vertice ainda não foi visitado
            if (perm[i] == 0) {

                //calcula distância a partir do vértice corrente ao vértice adjacente i
                newdist = dc + g->arestas[current][i].peso;

                //se a distância partindo do vértice corrente for maior, atualiza o vetor
                //de distâncias e de caminho
                if (newdist > dist[i] ) {
                    dist[i] = newdist;
                    path[i] = current;
                    guardaCaminho++;
                }

                //determina o vértice entre todos os não visitados com maior distância
                if (dist[i] > maiordist) {
                    maiordist = dist[i];
                    k = i;
                }
            }
        } /* fim for */

        /* embora estamos assumindo grafos ponderados e conexos, este if garante que
         em caso de não existência de um caminho o programa não entre em loop infinito */
        if (current == k) {
            //printf("\n\nCAMINHO NAO EXISTE\n\n");
            return 0;
        }

        current = k;
        perm[current] = 1;

    } /* fim while */

   /* impressao do resultado ****************/
    int caminho = t;

    //printf("%d <- ", t+1);
    i = 0;
    caminhoNovo[i] = t+1;
    while (caminho != s)
    {
        i++;
       // printf("%d", path[caminho]+1);
        caminhoNovo[i] = path[caminho]+1;// essa logica do while garante o caminho maior para ser colocado em um vetor.
        caminho = path[caminho];
        //if (caminho != s)
           // printf (" <- ");
    }

    caminhoNovo[i+1] = -1;

    return caminhoNovo;
} /* fim dijkstra */



int main()
{
    FILE *file;
    char arquivo[20];
    int numVertices;
    int numArestas ;
    int vertOrigem ;
    int vertDestino ;
    int i,j;
    int menor = 999;
    matrizAdjacencia matriz;


    strcpy(arquivo,"Input.txt");
    file = fopen(arquivo,"r");
    if (file != NULL)
        fscanf( file,"%d%d%d%d",&numVertices,&numArestas,&vertOrigem,&vertDestino);
    fclose(file);
    iniciarMatriz(&matriz,numVertices);
    gerarMatrizAdjacencia(&matriz,numArestas,arquivo);

    int **caminho = (int**)malloc(numVertices*sizeof(int));
    for(i=0;i<numVertices;i++)
        caminho[i] = (int*)malloc(numVertices*sizeof(int));


    int *tamanhoCaminho = (int*)calloc(numVertices,sizeof(int));
    for(i=0;i<numVertices;i++){
        if ((i != vertOrigem-1) && (i != vertDestino-1)){
            caminho[i] = dijkstra (&matriz, vertOrigem-1, vertDestino-1,numVertices,i);
            tamanhoCaminho[i] = guardaCaminho;
        }
    }

    for(i=0;i<numVertices;i++){
        if((tamanhoCaminho[i] < menor) && (tamanhoCaminho[i] != 0))
            menor = tamanhoCaminho[i];
    }
    menor--;
    i = menor;
   // for(i = 1; i < numVertices-1 ; i++){
        printf("\n");
        for(j = 0;caminho[i][j] != -1; j++){
			printf("%d ", caminho[i][j]);
			if (caminho[i][j+1] != -1)
				printf("<- ");
        }
    //}

    return 0;
}
