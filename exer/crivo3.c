#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 1000001
#define NUM 15

int main(){
  int i,j;
  int limite;
  char ehprimo[MAX];
  int cont=0;
  int primos[NUM];
  FILE *fp;
  fp = fopen("primos.txt","wt");

  for(i=2;i<MAX;i++)
    ehprimo[i]=1;
  limite = (int)sqrt(MAX);
  for(i=2;i<limite;i++){
    if(ehprimo[i]){
      for(j=i*i;j<MAX;j=j+i)
        ehprimo[j] = 0;
    }
  }

  for(i=2;i<MAX;i++){
    if(ehprimo[i]){
      fprintf(fp,"%d %d\n",cont,i);
      primos[cont]=i;
      cont++;
    }
  }
  printf("%d\n",cont);
  system("PAUSE");

}
