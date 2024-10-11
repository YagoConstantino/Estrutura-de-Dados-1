#include <stdio.h>

/**
Heap Sort

--Heap: vetor que simula uma arvore binária completa(exceção do ultimo nivel)
--Todo elemento pai do vetor possui dois elementos como filhos
--pai(i) ->filhos:(2*i+1) e (2*i+2);
*/
void criaHeap(int* vetor,int inicio,int fim)
{
    int aux = vetor[inicio];
    int j = inicio*2+1;
    while(j<=fim)
    {
        if(j<fim)/**Pai tem dois filhos ? qual o maior?*/
            if(vetor[j]<vetor[j+1])
                j=j+1;

        if(aux<vetor[j])/**Filho maior que o pai ?,filho se torna o Pai,Repetir o processo*/
        {
            vetor[inicio]=vetor[j];
            inicio = j;
            j=2*inicio+1;
        }
        else
            j=fim+1;
    }
    vetor[inicio] = aux;/**Antigo pai ocupa o lugar do ultimo filho*/
}


void heapSort(int* vetor,int N)
{
    int i,aux;
    /**Criar Heap a partir do meio dos dados*/
    for(i=(N-1)/2;i>=0;i--)
    {
        criaHeap(vetor,i,N-1);
    }
    for(i=(N-1);i>=1;i--)
    {
        /**Pegar o maior elemento do Heap e colocar na sua posição correspondente no array*/
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        criaHeap(vetor,0,i-1);/**Reconstruir heap*/
    }
}

int main()
{
    int vetor[10]={12,36,78,4,5,96,3,4,12,25};

    int i;

    for(i=0;i<10;i++)
        printf("%d ",vetor[i]);

    heapSort(vetor,10);
    printf("\n\n");
    for(i=0;i<10;i++)
        printf("%d ",vetor[i]);



    return 0;
}
