#include <stdio.h>
#include "ListaDeNoDescritor.h"

/**Implementação das Funções do TAD Lista De Nó Descritor*/

/**
Função para criar uma lista de nó descritor
Sem Parametros
Retorna um ponteiro para o endereço do começo da lista
*/
Lista* criaListaNo()
{
    Lista* li = (Lista*)malloc(sizeof(Lista));

    if(li!=NULL)
    {
        li->final = NULL;
        li->inicio = NULL;
        li->qtd = 0;
    }
    return li;

}

/**
Função para desalocar a lista
Parametros:
Lista* li: Endereço do Nó Descritor da lista
Sem retorno
*/
void liberaLista(Lista* li)
{
    Elem * no;
    while(no!=li->final)
    {
        no = li->inicio;
        li->inicio = li->inicio->prox;
        free(no);
    }
    free(li);
}

/**
Função para descobrirmos o tamanho da lista
Parametros:
Lista* li: Endereço do Nó Descritor da lista
Retorna a quantidade de itens da lista
*/
int tamanhoLista(Lista*li)
{
    if(li==NULL) return 0;
    return li->qtd;
}

/**
Função para Inserirmos um novo elemento no inicio da lista
Parametros:
Lista* li: Lista* li: Endereço do Nó Descritor da lista
Aluno al: Dados a serem guardados no novo elemento
Retorna 1 caso haja sucesso na inserção
Retorna 0 caso haja falha na inserção
*/
int insereListaInicio(Lista* li,Aluno al)
{
    if(li==NULL) return 0;
    Elem* no = (Elem*)malloc(sizeof(Elem));

    if(no==NULL) return 0;

    no->dados = al;
    no->prox = li->inicio;
    if(li->inicio == NULL) // Caso a lista esteja vazia temos que atualizar o final tbm
        li->final = no;

    li->inicio = no; // Atualizamos o inicio
    li->qtd++;// Atualizamos a quantidade de itens
    return 1;

}

/**
Função para Inserirmos um novo elemento no final da lista
Parametros:
Lista* li: Lista* li: Endereço do Nó Descritor da lista
Aluno al: Dados a serem guardados no novo elemento
Retorna 1 caso haja sucesso na inserção
Retorna 0 caso haja falha na inserção
*/
int insereListaFinal(Lista*li,Aluno al)
{
    if(li==NULL) return 0;
    Elem* no = (Elem*)malloc(sizeof(Elem));

    if(no==NULL) return 0;

    no->dados = al;
    no->prox = NULL;

    if(li->inicio = NULL) // Caso a lista esteja vazia temos que atualizar o inicio tbm
        li->inicio = no;
    else
        li->final ->prox = no; // Se não está vazia o ultimo item que apontar para o novo nó
    li->final = no; // Atualizamos o final com o endereço do novo elemento
    li->qtd++; // Atualizamos a quantidade de itens

    return 1;

}


/**
Função para Inserirmos um novo elemento ordenado da lista
Parametros:
Lista* li: Lista* li: Endereço do Nó Descritor da lista
Aluno al: Dados a serem guardados no novo elemento
Retorna 1 caso haja sucesso na inserção
Retorna 0 caso haja falha na inserção
*/
int insereOrdenada(Lista* li,int mat,Aluno al)
{
    if(li==NULL) return 0;
    Elem* no = (Elem*)malloc(sizeof(Elem));

    if(no==NULL) return 0;
    no->dados = al;

    Elem* atual = li->inicio;
    Elem* ant;

    while(atual!=NULL && atual->dados.mat<mat)
    {
        ant = atual;
        atual = atual->prox;
    }

    if(li->inicio==NULL)
    {
        li->inicio = no;
        li->final = no;
        no->prox = NULL;
        li->qtd++;
        return 1;
    }
    if(atual==li->inicio)
    {
        no->prox = atual;
        li->inicio = no;
        li->qtd++;
        return 1;
    }
    if(atual==NULL)
    {
        li->final = no;
        li->final->prox = no;
        no->prox = NULL;
        li->qtd++;
        return 1;
    }
    else
    {
        ant->prox = no;
        no->prox = atual;
        li->qtd++;
        return 1;
    }
}

/**
Função para Removermos um elemento no inicio da lista
Parametros:
Lista* li: Lista* li: Endereço do Nó Descritor da lista
Retorna 1 caso haja sucesso na remoção
Retorna 0 caso haja falha na remoção
*/

int removeInicio(Lista*li)
{
    if(li==NULL||li->inicio==NULL) return 0;

    Elem* no = li->inicio;
    li->inicio = li->inicio->prox;
    free(no);
    if(li->inicio==NULL)
        li->final==NULL;

    li->qtd--;
    return 1;

}

/**
Função para Removermos um elemento no Final da lista
Parametros:
Lista* li: Lista* li: Endereço do Nó Descritor da lista
Retorna 1 caso haja sucesso na remoção
Retorna 0 caso haja falha na remoção
*/
int removeFinal(Lista*li)
{
    if(li==NULL||li->inicio==NULL) return 0;

    Elem* ant,*no = li->inicio;

    while(no->prox!=NULL)
    {
        ant = no;
        no= no->prox;
    }
    if(no==li->inicio)
    {
        li->inicio = NULL;
        li->final = NULL;
    }
    else
    {
        ant -> prox = NULL;
        li->final = ant;
    }
    free(no);
    li->qtd--;
    return 1;

}

/**
Função para removermos um Elemento da lista baseado na sua matricula
Parametros
Lista* li: Endereço do começo da Lista
int mat: Numero de matricula do elemento a ser removido
Retorna 1 caso haja sucesso na remoção
Retorna 0 caso falhe na remoção
*/

int removeMat(Lista* li, int mat)
{
    // Verifica se a lista ou o ponteiro para a lista são nulos
    if (li == NULL || li->inicio== NULL) return 0; // Caso a lista não exista ou esteja vazia, retorna 0

    Elem* no = li->inicio; // Inicializa o ponteiro 'no' para apontar para o primeiro elemento da lista


    if (no->dados.mat == mat) // Verifica se o primeiro elemento da lista tem a matrícula mat
    {
        li->inicio = no->prox; // Atualiza o início da lista para o próximo elemento
        free(no); // Libera a memória do nó removido
        return 1; // Retorna 1 indicando que a remoção foi bem sucedida
    }

    Elem* ant; // Ponteiro para o nó anterior
    no = no->prox; // Avança para o próximo nó da lista

    while (no != NULL && no->dados.mat != mat)// Percorre a lista enquanto não volta ao início e não encontra o elemento com a matrícula mat
    {
        ant = no; // ant guarda o nó atual
        no = no->prox; // Avança para o próximo nó
    }

    // Verifica se o nó com a matrícula mat foi encontrado
    if (no->dados.mat == mat)
    {
        ant->prox = no->prox; // Remove no ajustando o ponteiro prox do nó anterior
        free(no); // Libera a memória do nó removido
        return 1; // Retorna 1 indicando que a remoção foi bem sucedida
    }

    return 0; // Retorna 0 se não encontrou o elemento com a matrícula mat
}

/**
Função para consultar um elemento da lista baseado em sua posicao
Parametros:
Lista* li: Endereço do começo da Lista
int pos: posição do elemento a ser consultado
Aluno* al: Ponteiro do endereço aonde guardaremos o elemento consultado
Retorna 1 caso haja sucesso na consulta
Retorna 0 caso falhe na cunsulta
*/

int consultaPosicao(Lista* li,int pos,Aluno* al)
{
    if(li==NULL||li->inicio==NULL) return 0; // Caso a lista não exista ou esteja vazia retornamos 0;
    if(pos<=0) return 0; //Caso recebamos uma posiçao invalida retornamos 0;

    int i = 1;
    Elem* no = li->inicio;
    while(no->prox!=NULL&& i< pos) // Percorremos a lista em busca da posicao
    {
        i++;
        no = no->prox;
    }
    if(i!=pos) return 0;// Caso percorramos toda a lista e não chegamos a pos retornamos 0(se a pos for maior que a lista por exemplo)
    else
    {
        *al = no->dados; // Copiamos os dados para o ponteiro
        return 1;// Sinalizamos sucesso
    }
}

/**
Função para consultar um elemento da lista baseado em sua matricula
Parametros:
Lista* li: Endereço do começo da Lista
int mat: matricula do elemento a ser consultado
Aluno* al: Ponteiro do endereço aonde guardaremos o elemento consultado
Retorna 1 caso haja sucesso na consulta
Retorna 0 caso falhe na cunsulta
*/

int consultaMat(Lista* li,int mat,Aluno* al)
{
    if(li==NULL||li->inicio==NULL) return 0; // Caso a lista não exista ou esteja vazia retornamos 0;

    Elem* no = li->inicio;
    while(no->prox!=NULL&& no->dados.mat!=mat) // Percorremos a lista em busca da matricula
    {
        no = no->prox;
    }
    if(no->dados.mat!=mat) return 0;// Caso percorramos toda a lista e não chegamos a matricula dada retornamos 0;
    else
    {
        *al = no->dados; // Copiamos os dados para o ponteiro
        return 1;// Sinalizamos sucesso
    }
}
