#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1001
int main()
{
    char vet[N];
    int i,cont[26];
    printf("Entre com uma string:\n");
    gets(vet);
    printf("String: %s\n",vet);
    
    for( i=0;i<cont[26];i++)
	cont[i]=0;

    for (i =0;i<(strlen(vet));i++)
    {
	if ((vet[i]>='A')&&(vet[i]<='Z'))
	{
		cont[vet[i] -'A']++;
	}	
	else
	{
		if((vet[i]>='a')&&(vet[i]<='z'))
		cont[vet[i]-'a']++;
	}
     }
	for (i=0;i<26;i++){
	if(cont[i]!=0)
		printf("%c  %d\n",(i+'A'),cont[i]);
   	 }
    return 0;
}


