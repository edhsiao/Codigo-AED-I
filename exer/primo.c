#include <stdio.h>
#include <stdlib.h>

int primo(n)
{
    int i=2;
    while ((i < n) && (n % i != 0))
        i++;
    return (i >= n);
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
