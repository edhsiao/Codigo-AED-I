#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dias;
    scanf("%d",&dias);
    printf("%d anos(s)",dias/365);
    printf("%d mes(es)",(dias%365)/12);
    printf("%d dia(s)",((dias%365)%12)/30);


}
