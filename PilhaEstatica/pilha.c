    #include "pilha.h"
    #include <stdio.h>

    /**Implementação das funções */
    struct pilha{
        int top;
        int size;
        int *array;
    };

    /**Função para criar uma pilha usando alocação dinâmica*/
    Pilha* cria_pilha(int size)
    {
        Pilha *p;
        p=(Pilha*)malloc(sizeof(Pilha)); // aloco a pilha

        //Coloco os valores nos atributos da struct
        p->top = 0;
        p->size = size;
        p->array = (int*)malloc(sizeof(int)*size);

        return p; //retorno o ponteiro

    }

    /**Função para desalocar a pilha*/
    void libera_pilha(Pilha* p)
    {
        free(p->array);
        free(p);
    }

    /**Função para colocar um novo elemento na pilha */
    void push(Pilha* p,int elem)
    {
        if(full(p))
        {
            printf("Capacidade esgotada \n");
            exit(1);
        }

        p->array[p->top] = elem;
        p->top++;
    }

    /**Função para retirar o elemento no topo da pilha*/
    int pop(Pilha* p)
    {
        if(empty(p))
        {
            printf("Sem elementos na pilha\n");
            exit(1);
        }
        p->top--;

        return p->array[p->top];

    }
    /**Função para verificar se a pilha está vazia*/
    int empty(Pilha* p)
    {
        return (p->top==0);
    }

    /**Função para verificar se a pilha está cheia*/
    int full(Pilha* p)
    {
        return (p->top == p->size);
    }
