#include <stdio.h>


int main (void)
{
  int i, nb, contar, teste;
  teste = contar = 0;
  printf ("Entre um n�mero inteiro : ");
  if (scanf ("%d", &nb) != 1)
    return -1;

  for (i = 2; i < nb; i++, contar++)
    if (nb % i == 0)
      teste = 1;
  if (!teste)
    printf ("%d n�mero primo, n�mero itera��es = %d\n", nb, contar);
  else
    printf ("%d n�o � um n�mero primo, n�mero itera��es = %d\n", nb,contar);
  return 0;
}
