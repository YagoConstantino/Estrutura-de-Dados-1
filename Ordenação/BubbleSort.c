#include <stdio.h>
#define MAX 10
int main()
{
    /**
    Implementação do método BubbleSort para Ordenação de vetores.
    BubbleSort compara pares de elementos adjacentes e troca de lugar
    caso estejam na ordem errada.

    Esse processo se repete até que não seja mais necessário trocas

    Performance:
    Melhor caso : O(N)
    Pior caso : O(N^2)
    Não é eficiente para um grande número de dados
    */

    /** Minha implementação */
    int vetor[MAX]={3,2,4,7,9,10,12,5,44,18};
    int i,j;
    int aux;

    for(i=0;i<MAX;i++)
        for(j=i+1;j<MAX;j++) /**Nesse primeiro laço vamos pegar cada elemento do vetor*/
        {

           if(vetor[i]>vetor[j])/**E testar com todos  os elementos restantes,
                                caso o elemento em [i] seja maior que [j] trocamos os valores com j usando um aux*/
           {
               aux = vetor[i];
               vetor[i] = vetor[j];
               vetor[j] = aux;
           }
        }
    for(i=0;i<MAX;i++)
    {
        printf("%d\n",vetor[i]);
    }
/**Não implementei uma forma de parar caso ja esteja ordenado, como no video,logo não está otimizado*/
    return 0;
}
/** Implementação do Video 48 da playlist*/

void bubbleSort(int* vetor,int tamanho)
{
    int i,continua,aux,fim=tamanho;

    do{
        continua = 0; // flag para caso ja esteja ordenado nao continuarmos o loop
        for(i=0;i<fim-1;i++)
        {
            if(vetor[i]>vetor[i+1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                continua = i; // se houvel alguma mudança mudamos o continua para algum valor,se não houve ja esta ordenado
            }
        }
        fim--;
    }while(continua!=0);//Caso ja esteja ordenado finalizamos o loop para otmizar
}
