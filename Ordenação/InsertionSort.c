#include <stdio.h>

/**
    InsertionSort:
    Similar a ordenação de cartas de baralho com as mãos
    Pega-se uma carta de cada vez,e a coloca em seu devido lugar, sempre deixando as cartas da mão em ordem

    Performance:
    -Melhor caso O(N)
    -Pior caso O(N^2)
    -Eficiente para conjuntos pequenos de dados
    -Estável: Não altera a ordem de dados iguais
    -Capaz de ordenar os dados a medida que os recebe(Em tempo real);
    */


void insertionSort(int* vetor,int tamanho)
{
    int i,j,aux;

    for(i=1;i<tamanho;i++)
    {
        aux = vetor[i];/**Guardo um elemento que vou testar com todos os anteriores*/
        for(j=i;(j>0)&& (vetor[j-1]>aux);j--)/**Se o anterior for maior que o aux*/
        {
            vetor[j] = vetor[j-1];/**Passamos o anterior para frente e continuamos testando ate achar um elemento que é menor que aux*/
        }
        vetor[j] = aux;/**A posição desse elemento fica guaardada em j,colocamos o valor testado nessa posição,assim sabemos que ele é menor
        do que todos os que foram testados */


        /**Aqui termina o codigo o resto é so visualização-----------------------------------*/
        printf("atual v[i]: %d atualVetor atual: ",aux);
        for(j=0;j<tamanho;j++)
        {
            printf("%d ",vetor[j]);
        }
        printf("\n\n");
    }
}

int main()
{
    int vetor[11] = {10,25,34,7,9,52,3,4,36,45,36};

    int i;
    for(i=0;i<11;i++)
    {
        printf("%d ",vetor[i]);
    }
    printf("\n");

    insertionSort(vetor,11);

    for(i=0;i<11;i++)
    {
        printf("%d ",vetor[i]);
    }
    printf("\n");
    return 0;
}
