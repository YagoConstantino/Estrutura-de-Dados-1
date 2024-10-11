#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 40

/**
    QuickSort

    --Ideia Básica: Dividir e conquistar
    --Um elemento é escolhido como pivô
    --Particionar: elementos menores que o pivô são colocados antes dele e maiores depois
    --Recursivamente reorganiza as partições novas(antes e depois)

    Performance
    --Melhor caso: O(N log N)
    --Pior caso: (raro) O(N^2)
    --Estável: não altera a ordem de elementos iguais
    --Desvantagens: Como escolher o pivô??????
    */
int particiona(int* vetor, int inicio, int fim)
{
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = vetor[inicio];

    while (esq <= dir)
    {
        while (vetor[esq] <= pivo && esq <= fim)
            esq++;

        while (vetor[dir] > pivo && dir >= inicio)
            dir--;

        if (esq < dir)
        {
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
    }
    vetor[inicio] = vetor[dir];
    vetor[dir] = pivo;
    return dir;
}

void quickSort(int* vetor, int inicio, int fim)
{
    int pivo;
    if (fim > inicio)
    {
        pivo = particiona(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo - 1);
        quickSort(vetor, pivo + 1, fim);
    }
}

int main()
{
    srand(time(NULL));

    int vetor[N];
    int i;
    for (i = 0; i < N; i++)
    {
        vetor[i] = rand() % 101;
    }

    printf("Vetor original:\n");
    for (i = 0; i < N; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n\n");

    quickSort(vetor, 0, N - 1);

    printf("Vetor ordenado:\n");
    for (i = 0; i < N; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
