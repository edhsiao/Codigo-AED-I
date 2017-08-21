#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *x,i,z;
    x=(int*)calloc(1000000,sizeof(int));

    for(z=2; z<1000; z++)
    {

        if(x[z]==1)
            continue;

        for(i=z+z; i<1000000; i=i+z)
            x[i]=1;

    }
    for(i=2; i<1000000; i++)
        if(!x[i])
            printf("%d\n",i);
}
