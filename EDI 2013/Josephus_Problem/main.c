#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    struct elemento {
    int pessoa;
    struct elemento *proximo };
    struct elemento *p, *q;
    int i, cont;

    scanf("%d", &n);
    scanf("%d", &k);


    p = q = malloc(sizeof(struct elemento));

    p->pessoa = 1;

    for (i = 2; i <= n; ++i) {
        p->proximo = malloc(sizeof(struct elemento));
        p = p->proximo;
        p->pessoa= i;
    }

    p->proximo = q;

    for (cont = n; cont > 1; --cont) {
       for (i = 0; i < k - 1; ++i)
          p = p->proximo;

       p->proximo = p->proximo->proximo;
    }

    printf("%d\n.", p->pessoa);

    return 0;
}
