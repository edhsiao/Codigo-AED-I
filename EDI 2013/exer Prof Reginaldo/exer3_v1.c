#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000000

typedef struct{
	
	int codigo;
	char nome[50];
	} tipoCadastro;

typedef struct{
	tipoCadastro cadastro[1000];
	int tam;
	}tipoRegistro;

void iniciaRegistro( tipoRegistro *registro){
	registro->tam=0;
	}

int insere(tipoRegistro *registro,tipoCadastro novoCadastro,int cap){
	int pos =registro->tam;
	if(pos < cap){
	registro->cadastro[pos] =novoCadastro;
	registro->tam++;}
	else 
	printf("List is full\n");
	return 1;
	}


void remover(tipoRegistro *registro,char nome[]){

	int i,j,achou=0,pos=registro->tam;
    	for(i=0; i<registro->tam; i++)
    	{
        	if(strcmp(nome,registro->cadastro[i].nome)==0)
        	{
            	achou=1;
           	 if(i==0)
           	 {
               	 for(j=0; j<pos-1; j++)
                	    registro->cadastro[i]=registro->cadastro[i+1];
               	 registro->tam--;
           	 }
           	 else if(i==pos-1)
                	registro->tam--;
            	 else
           	 {
                	for(j=i; j<pos-1; j++)
                    	registro->cadastro[j]=registro->cadastro[j+1];
                	registro->tam--;
            	}
        	}
    	}
   	 if(achou==0)
	printf("%s was not found\n",nome);
	}


void imprime(tipoRegistro *registro){	
	int i=0;
	for(i=0; i < registro->tam; i++)
	printf("%d %s\n",registro->cadastro[i].codigo,registro->cadastro[i].nome);

	}




int main(){

	int i,n,cap,op;
	tipoCadastro cadastros;
	tipoRegistro registros;
	scanf("%d %d",&n,&cap);
	iniciaRegistro(&registros);
	for(i=0; i<n; i++)
	{
		scanf("%d",&op);
		switch(op){
		case 1:
		scanf("%d %s",&cadastros.codigo,cadastros.nome);
		insere(&registros,cadastros,cap);
		break;
		case 2:
		scanf("%s",cadastros.nome);
		remover(&registros,cadastros.nome);
		break;
	}}
	imprime(&registros);
	return 0;

}
	
