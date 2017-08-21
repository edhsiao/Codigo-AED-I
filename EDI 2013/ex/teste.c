#include <stdio.h>

void teste(int *ptr)
{
    ptr=ptr+10;
}


int main()
  {
    int numero = 35;
    int *ptr;

    scanf("%d",&ptr);
    teste(ptr);
    printf("%d %x",ptr,&ptr);

    return(0);
  }


