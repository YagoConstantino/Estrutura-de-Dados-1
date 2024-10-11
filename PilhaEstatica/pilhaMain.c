#include <stdio.h>
#include "pilha.h"

int main()
{
    Pilha *p = cria_pilha(10);

    push(p,1);
    push(p,2);
    push(p,4);
    push(p,7);
    push(p,2);
    push(p,36);
    push(p,8);
    push(p,45);
    push(p,21);
    push(p,9);

    while(!empty(p))
        printf("%d\n",pop(p));

     libera_pilha(p);
    return 0;
}
