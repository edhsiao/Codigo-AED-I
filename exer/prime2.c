#include <stdio.h>
#include <stdbool.h>
int ehprimo(n) {
   int i;
   for (i=2; (i<n) && (n%i != 0);i++)
   ;
   return (n>1 && i>=n);
}

int main() {
   long n, i=1, cont=0;
   printf("Informe o numero de ordem do primo: ");
   scanf("%d", &n);
   while (cont < n) {
      i++;
      if (ehprimo(i))
         cont++;
   }
   printf("\nO %d numero primo eh: %d\n", n, i);
   return 0;
}
