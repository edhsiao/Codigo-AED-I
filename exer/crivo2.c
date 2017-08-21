#include <stdio.h>
#include <math.h>

int main()
{
    long i, j, *vetor,cont;
    long valorMaximo, raiz;

    scanf("%d", &valorMaximo);
    printf("Calculando numeros primos ate %d\n", valorMaximo);

    vetor = (long*)malloc((valorMaximo + 1) * sizeof(long));

    raiz = sqrt(valorMaximo);

    for(i = 2; i <= valorMaximo; i++)
    {
        vetor[i] = i;
    }

    for(i = 2; i <= raiz; i++)
    {
        if(vetor[i] == i)
        {
            for(j = i + i; j <= valorMaximo; j += i)
                vetor[j] = 0;
        }
    }
    for (i=2; i<=valorMaximo;i++)
        printf("vetor[%d] = %d\n", i, vetor[i]);

    free(vetor);

    return(0);
}
