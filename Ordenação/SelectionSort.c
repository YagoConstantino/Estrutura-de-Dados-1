#include <stdio.h>

/**
SelectionSort
--A cada passo procura o menor valor do array e coloca ele na posição atual(começando do 0)
--Isso é feito para todas as posições do array

Performance
--Melhor caso O(N^2)
--Pior caso O(N^2)
--Ineficiente para grandes conjuntos de dados
--Estável(não muda a ordem de elementos iguais)
*/

void selectionSort(int* vetor,int tamanho)
{
    int i,j,menor,aux;

    for(i=0;i<tamanho-1;i++)
    {
        menor = i;/**Armazenamos a posição que vamos testar*/
        for(j=i+1;j<tamanho;j++)
        {
            if(vetor[j]<vetor[menor]) /**Testamos se ha algum item no array que seja menor que o item na posição menor*/
                menor = j; //Se sim trocamos a posição do atual menor do array
        }
        if(menor != i) //Caso haja alguma troca de posição trocamos o conteudo da posição do menor item na posição i,assim ordenando o array
        {
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }

}

int main()
{
    int teste[12] = {2,5,4,36,7,9,121,5,65,45,8,31};

    int i;
    for(i=0;i<12;i++)
    {
        printf("%d ",teste[i]);
    }
    printf("\n\n");

    selectionSort(teste,12);

    for(i=0;i<12;i++)
    {
        printf("%d ",teste[i]);
    }
    printf("\n\n");

    return 0;

}
