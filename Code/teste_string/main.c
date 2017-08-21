#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
//    int n = 5;
//    int i;
//    int numeros[n];
//    char v[50];
//    for( i = 0; i < n; i++)
//        numeros[i] = 0;
//   // char v = (char*)malloc (sizeof(char)*50);
//   printf("\strcpy\n");
//    strcpy(v,"abc");
//    printf("v = %s",v);
//    printf("\nentrando for\n");
//    for(i = 0; i < n; i++)
//    {
//        printf("\nentrou for 2\n");
//        if(numeros[i]==0)
//        {
//            printf("\nentrou if 1 \n");
//            strcat(v,(char)i +48);
//        }
//    }
    int i;
    char v[32];
    int a = 0;
    for(i = 0; i < 10; i++){
        v[a] = (char)i + 48;
            a++;
    }
    for(i = 0; i < 10; i++){
        printf("%c ", v[i]);
    }
}
