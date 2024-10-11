#include "ListaEstatica.h"
#include <stdio.h>

/** Implementação das Funções do TAD Lista Estática


Função para criar uma Lista
Retorna um ponteiro para a Lista criada
*/
Lista* criaLista()
{
    Lista *novaLista;

    novaLista =(Lista*)malloc(sizeof(Lista));

    if(!novaLista)
    {
        printf("Não pude alocar a Lista\n");
        exit(1);
    }
    novaLista->qtd=0;

    return novaLista;
}

/**
Função para desalocar a Lista
Parametros:Lista* li:Ponteiro para o endereço da lista a ser desalocada
Sem retorno
*/
void liberaLista(Lista* li)
{
    free(li->dados);
    free(li);
}

/**
Função para saber quantos itens tem na lista
Parametros:Lista* li : Ponteiro para o endereço da Lista
Retorna um inteiro com a quantidade de itens da Lista
Caso retorne -1 a Lista não existe
Caso retorne 0 a Lista está vazia
*/
int tamanhoLista(Lista* li)
{
    if(li == NULL)
    {
        return -1;
    }
     return li->qtd;
}

/**
Função para verificar se a Lista está cheia
Parametros:Lista* li : Ponteiro para o endereço da Lista
Retorna 0 caso ainda haja espaço na Lista
Retorna 1 caso a Lista esteja cheia
Retorna -1 caso a Lista não exista
*/
int listaCheia(Lista* li)
{
    if(li==NULL)
    {
        return -1;
    }

    return (li->qtd == MAX);
}

/**
Função para inserir um item no final da Lista
Parametros:
Lista* li:Ponteiro para o endereço da Lista
Aluno al: Copia da struct a ser inserida na lista
Retorna 0 caso não seja possivel inserir o novo item
Retorna 1 caso o novo item seja inserido
*/
int insereFinalLista(Lista* li,Aluno al)
{
    if(li==NULL)
        return 0;
    if(listaCheia(li))
        return 0;

    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}


/**
Função para inserir um item no começo da Lista
Parametros:
Lista* li:Ponteiro para o endereço da Lista
Aluno al: Copia da struct a ser inserida na lista
Retorna 0 caso não seja possivel inserir o novo item
Retorna 1 caso o novo item seja inserido
*/
int insereInicioLista(Lista* li,Aluno al)
{
    int i;

    if(li==NULL) return 0;

    if(listaCheia(li)) return 0;

    for(i=li->qtd-1;i>=0;i--)
    {
        li->dados[i+1]=li->dados[i];
    }
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

/**
Função para inserir um numero de forma Ordenada
Parametros:
Lista* li:Ponteiro para o endereço da Lista
Aluno al: Copia da struct a ser inserida na lista
Retorna 0 caso não seja possivel inserir o novo item
Retorna 1 caso o novo item seja inserido
*/

int insereListaOrdenada(Lista* li,Aluno al)
{
    int i=0,j;
    if(li==NULL) return 0;
    if(listaCheia(li)) return 0;

    /** Acho a posição que o novo item deve ficar baseado na matricula do
        aluno e guardo na variável i */

    while(i<li->qtd && li->dados[i].matricula<al.matricula)
        i++;

    /**Todos os itens depois da posição i que achamos vai uma casa pra frente*/
    for(j=li->qtd-1;j>=i;j--)
        li->dados[j+1] = li->dados[j];

    /**Colocamos o novo item na posição correta*/
    li->dados[i] = al;
    li->qtd++;
    return 1;
}

/**
Função para remover um item do final da Lista
Parametros:
Lista* li:Ponteiro para o endereço da Lista
Retorna 0 caso não seja possivel remover o novo item
Retorna 1 caso o novo item seja removido
*/
int removeFinalLista(Lista* li)
{
    if(li==NULL) return 0;
    if(li->qtd==0) return 0;

    li->qtd--;

    return 1;
}

/**
Função para remover um item do inicio da Lista
Parametros:
Lista* li:Ponteiro para o endereço da Lista
Retorna 0 caso não seja possivel remover o novo item
Retorna 1 caso o novo item seja removido
*/
int removeInicioLista(Lista* li)
{
    int i;

    if(li == NULL) return 0;
    if(li->qtd == 0) return 0;

    for(i = 0; i < li->qtd ; i++)
        li->dados[i] = li->dados[i + 1];

    li->qtd--;
    return 1;
}


/**
Função para remover um elemento baseado na sua matricula
Parametros
Lista* li : Ponteiro que aponta para o endereço da Lista
Int mat : matricula do aluno a ser removido
Retorna 0 caso não possa ser removido
Retorna 1 caso seja removido
*/

int removeElemento(Lista* li,int mat)
{
    int i=0,j;

    if(li==NULL) return 0;
    if(li->qtd==0) return 0;

    /**Acho na Lista aonde está o elemento a ser removido*/
    while(i<li->qtd && li->dados[i].matricula!= mat)
        i++;


    /**
    Copio todos os elementos uma casa pra tras a partir
    do elemento a ser removido,assim substituindo ele pelo próximo
    */
    for(j=i;j<li->qtd-1;j++)
    {
        li->dados[j]=li->dados[j+1];;
    }

    li->qtd--; //Diminuo o numero total de itens

    return 1;

}

/**
Função para consultar um item da Lista baseado na sua posição
Parametros:
Lista* li: Ponteiro para o endereço da lista;
int pos; Posição do item a ser consultado
Aluno* al: Ponteiro para a struct aluno na qual passarei os dados consultados da lista;
Retorna 0 caso não achemos o item;
Retorna 1 caso achemos o item
*/
int consultaListaPosicao(Lista* li,int pos,Aluno* al)
{
    if(pos>li->qtd||li==NULL||pos<=0) return 0;

    *al = li->dados[pos-1]; //Pos deve ir de 1 a 100,logo diminuimos um e passamos a struct armazenada para o conteudo apontado por al

    return 1;

}

/**
Função para consultar um item da Lista baseado na sua matricula
Parametros:
Lista* li: Ponteiro para o endereço da lista;
int mat: Matricula do item a ser consultado
Aluno* al: Ponteiro para a struct aluno na qual passarei os dados consultados da lista;
Retorna 0 caso não achemos o item;
Retorna 1 caso achemos o item
*/
int consultaListaMatricula(Lista* li,int mat,Aluno* al)
{
    if(li==NULL||mat<=0) return 0;
    int i=0;

    while(i<li->qtd&& li->dados[i].matricula!=mat)
        i++;
    if(i==li->qtd) return 0;

    *al = li->dados[i];
    return 1;
}
