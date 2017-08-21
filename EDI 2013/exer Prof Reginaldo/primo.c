#include <stdio.h>
#include <stdlib.h>

int primo(n)
{
    int j=2;
    while ((j < n) && (n % j != 0))
        j++;

    return (j >= n);
}

int main()
{
    int i=0, n=1, pos;
    scanf("%d",&pos);


    while (i < pos)
    {
        n++;
        if (primo(n))
            i++;
    }
    printf("%d",n);
    return 0;
}
