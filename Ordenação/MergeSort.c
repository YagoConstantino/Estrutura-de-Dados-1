#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**Merge Sort

    --Ideia Básica : Dividir para conquistar
    --Divide,recursivamente,o conjunto de dados até que cada subconjunto tenha um elemento
    --Combina 2 subconjuntos de forma a obter um subconjunto maior e ordenado
    --Esse processo continua até que tenha só um conjunto

    Performance:
    --Melhor caso : O(N log N)
    --Pior caso :  O(N log N)
    --Estável : Não altera a ordem de dados iguais
    --Desvantagens : Usa um auxiliar durante a ordenação e é recursivo

    */


/**Função para combinamos dois vetores que foram separados*/

void merge(int* vetor,int inicio,int meio,int fim)
{
    int *vetorTemporario,p1,p2,tamanho,i,j,k;
    int fim1=0,fim2=0; // Duas flags para sinalizar se ja foi todos os itens de uma das partes

    tamanho = fim-inicio+1;// Tamanho do vetor sera o fim menos começo +1(0,9[9-0+1 = 10]  10 itens no total por exemplo)

    p1 = inicio;// Inicio da parte 1 que vai do inicio até o meio
    p2 = meio+1;// Inicio da parte 2 que vai do meio+1 até o fim

    vetorTemporario = (int*)malloc(sizeof(int)*tamanho); // Alocamos um vetor temporário com o mesmo tamamnho para receber os valores ordenados

    if(vetorTemporario!=NULL) // Verificamso se a alocação deu certo
    {
        for(i=0;i<tamanho;i++) // Para cada espaço do vetor temporário
        {
            if(!fim1&&!fim2) //Enquanto nenhuma das duas partes estiver vazias
            {
                if(vetor[p1]<vetor[p2]) // Se o elemento na parte 1 for menor que da parte 2
                  {
                     vetorTemporario[i] = vetor[p1]; // O vetor temporario recebe o elemento e incrementamos o p1 para ele ir pro proximo
                     p1++;
                  }

                else// Se o elemento na parte 2 for menor que da parte 1
                    {
                        vetorTemporario[i] = vetor[p2];// O vetor temporario recebe o elemento e incrementamos o p2 para ele ir pro proximo
                        p2++;
                    }
                if(p1>meio) fim1 = 1; // Verificamos se todos os elementos de alguma das partes ja foi colocado no vetor temporário
                if(p2>fim)  fim2 = 1;// Se sim acionamos a flag e vamos para o else seguinte
            }
            else // Caso alguma das partes ja tenha acabado
            {
                if(!fim1)
                {       // Testamos se é a segunda parte, se for
                    vetorTemporario[i] = vetor[p1];//O vetor temporário recebe o restante da parte 1
                    p1++;
                }
                else// Se não
                {
                    vetorTemporario[i] = vetor[p2];//O vetor temporário recebe o restante da parte 2
                    p2++;
                }
            }
        }
        for(j=0,k=inicio;j<tamanho;j++,k++)
        {
            vetor[k] = vetorTemporario[j]; // Passamos os elementos do vetor temporário para o passado por referencia
        }
        free(vetorTemporario); // Desalocamos o vetor temporario
    }
}

void mergeSort(int* vetor,int inicio,int fim)
{
    int meio;
    if(inicio<fim) //Se o inicio for menor que o fim
    {
        meio = floor((inicio+fim)/2);//Calculamos o meio, que a soma do inicio e fim dividido por 2

        mergeSort(vetor,inicio,meio);//Chamamos o mergesort para o vetor entre o inicio e meio

        mergeSort(vetor,meio+1,fim);//Chamamos o mergesort para o vetor entre o meio+1 e o fim

        merge(vetor,inicio,meio,fim);//Combinamos 2 metades de forma ordenada
    }
}

int main()
{

    int vetor[10] ={22,31,54,77,99,122,46,6789,120,81};
    int i;

    for(i=0;i<10;i++)
    {
        printf("%d ",vetor[i]);
    }

    printf("\n\n");

    mergeSort(vetor,0,9);

     for(i=0;i<10;i++)
    {
        printf("%d ",vetor[i]);
    }

    printf("\n\n");
    return 0;
}
