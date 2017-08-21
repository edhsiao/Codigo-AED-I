#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[50]="viva o linux";
    char c;
    char *tmp;
    char var1[4], var2[32], var3[32];
    int p = 0,i;

    tmp=str;
    while(*tmp!=' ')
    {
        printf("tmp - str = %d\n",tmp-str);
        var1[tmp-str]=*tmp;
        printf("var1 -> %s\n",var1);
        tmp++;
    }

    printf("Parte 1 -> %s\n",var1);



    // guarda a posicao inicial da palavra
    for( i = 0; i < strlen(str); i++)
    {

        while (str[i] != ' ')
        {

            // ACHEI UMA PALAVRA - FAZ O QUE FOR PRECISO
            p = i + 1; // posicao inicial da possivel proxima palavra
        }
        printf("Parte 2 -> %s\n",var2);
    }

}
