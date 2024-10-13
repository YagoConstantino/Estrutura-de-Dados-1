#include <stdio.h>

int buscaBinaria(int *vetor,int tamanho,int elem)
{
    int inicio,final,meio;
    inicio = 0;
    final = tamanho-1;
    while(inicio<=final)
    {
        meio = (inicio + final)/2;
        if(vetor[meio]==elem) return meio;
        else
        {
            if(elem<vetor[meio])
                final = meio-1;
            if(elem>vetor[meio])
                inicio = meio+1;
        }
    }
    return -1;
}

int main()
{
    int vetor[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int local;
    local = buscaBinaria(vetor,13,5);
    printf("%d",local);

    return 0;
}
