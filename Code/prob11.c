#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char jap[81];
    char port[81];
} tipoPalavra;

typedef struct
{
    tipoPalavra palavra[1000];
    int tam;
} tipoMusica;

void inicia(tipoMusica *musica)
{
    musica->tam=0;
}

void insere(tipoMusica *musica,tipoPalavra palavraAux)
{
    int a=musica->tam;
    musica->palavra[a] = palavraAux;
    musica->tam++;
}

void traducao(tipoMusica *musica,int n)
{
    int i,j,k;
    char palavraTrad[81];

    for (i=0; i<n; i++)
    {
        setbuf(stdin, NULL);
        scanf("%[^\n]s",palavraTrad);

        for(j=0; j < musica->tam; j++)
        {
            if(strcmp(palavraTrad,musica->palavra[j].jap)==0)
            {
                printf("%s ",musica->palavra[j].port);
                break;
            }
            else
            {
                printf("%s ",palavraTrad);
                break;
            }
        }
        printf("\b\n");
    }
}

int main()
{
    int t,i,j,m,n;

    tipoMusica musicas;
    tipoPalavra palavras;
    scanf("%d",&t);

    for(i=0; i<t; i++)
    {
        inicia(&musicas);
        scanf("%d %d",&m,&n);
        for(j=0; j<m; j++)
        {
            setbuf(stdin, NULL);
            scanf("%[^\n]s",palavras.jap);
            setbuf(stdin, NULL);
            scanf("%[^\n]s",palavras.port);
            setbuf(stdin, NULL);
            insere(&musicas,palavras);
        }
            traducao(&musicas,n);
    }
}

