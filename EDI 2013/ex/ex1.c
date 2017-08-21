#include <stdio.h>
#include <stdlib.h>


int fibCall(int n,int *call)
{
    if(n<=1)
    {
        *call++;
        return *call;
    }
    else
    {
        (fibCall(n-1,call)+fibCall(n-2,call));
        *call++;
        return *call;
    }

}

int fib(int x)
{
    if(x==0)
    {
        return(0);
    }
    else if(x==1)
    {
        return(1);
    }
    else
    {
        return(fib(x-1)+fib(x-2));
    }
}

int main()

{
    int n,entrada,i;

    scanf("%d",&entrada);
    for ( i=0; i<entrada; i++)
    {
        int call=0;
        scanf("%d",&n);
        printf("fib(%d) = %d calls = %d\n",n,fibCall(n,&call),fib(n));
    }
}

//Por exemplo, o fib(0) é chamado uma vez, certo? Por mais que o seu valor seja 0.
//O fib(2) chama ele mesmo, o fib(1) e o fib(0), isso seriam 3 chamadas.



