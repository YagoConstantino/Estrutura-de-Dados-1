#include "ListaDinamicEncadeada.h"
#include <stdio.h>

typedef struct elem
{
    Aluno dados;
    struct Elem* proximo;

}Elem;

/**Implementa��o para as Fun��es do TAD Lista Dinamca Encadeada

Fun��o para alocar mem�ria para o primeiro elemento da Lista
Retorna um ponteiro para Lista(Que � um ponteiro para ponteiro de Elem)
*/
Lista* criaLista()
{
    Lista* li;
    li =(Lista*)malloc(sizeof(Lista)); //Aloca��o da nova Lista;

    if(li!=NULL)
    {
        *li = NULL;
    }

    return li;
}

/**
Fun��o para desalocar a Lista
Parametros:
Lista* li: Ponteiro para ponteiro do come�o da lista
Sem retorno
*/
void liberaLista(Lista* li)
{
    if(li!=NULL)
    {
        Elem* no;
        while(*li!=NULL)
        {
            no = *li;
            *li = (*li)->proximo;
            free(no);
        }
        free(li);
    }
}

/**
Fun��o para descobrirmos o tamanho da Lista
Parametros:
Lista* li;Ponteiro para ponteiro do come�o da lista
Retorna a quantidade de itens;
*/
int tamanhoLista(Lista* li)
{
    int cont = 0;

    if(li==NULL) return 0;
    Elem* no = *li;

    while(no!=NULL)
    {
        cont++;
        no=no->proximo;
    }

    return cont;
}

/**
Fun��o para verificar se a lista est� vazia
Paramentros:
Lista* li;Ponteiro para ponteiro do come�o da lista
Retorna 1 Caso esteja vazia ou n�o exista
Retorna 0 Caso n�o esteja vazia
*/
int listaVazia(Lista* li)
{
    if(*li==NULL) return 1;
    return 0;
}

/**
Fun��o para inserir um novo elemento no inicio da Lista
Parametros:
Lista* li:Ponteiro para ponteiro do come�o da lista
Aluno al: Copia da struct a ser guardada no novo no da Lista.
Retorna 0 caso de erro
Retorna 1 caso haja sucesso na inser��o
*/
int insereInicio(Lista* li,Aluno al)
{
    if(li==NULL) return 0; // Verifica se a Lista existe

    Elem* no;
    no = (Elem*)malloc(sizeof(Elem));

    if(no==NULL) return 0;//Verifica se o novo no foi alocado corretamente

    no->dados = al;//Insere uma copia da struct aqui
    no->proximo = (*li); // Se houver mais Elementos na lista,ent�o o proximo apontara para eles
    *li = no; // o novo proximo do inicio ser� o endere�o do no que criamos;

    return 1; //Retorna 1 para sinalizar sucesso

}

/**
Fun��o para inserir um novo elemento no final da Lista
Parametros:
Lista* li:Ponteiro para ponteiro do come�o da lista
Aluno al: Copia da struct a ser guardada no novo no da Lista.
Retorna 0 caso de erro
Retorna 1 caso haja sucesso na inser��o
*/
int insereFinal(Lista* li,Aluno al)
{
    if(li==NULL) return 0;

    Elem* no;
    no = (Elem*)malloc(sizeof(Elem));


    if(no==NULL) return 0;

    Elem* atual;
    atual = (*li);

    while(atual->proximo!=NULL)
    {
        atual=(atual->proximo);
    }

    atual->proximo = no;
    no->dados = al;
    no->proximo = NULL;

    return 1;

}

/**
Fun��o para inserir um novo elemento de forma ordenada na Lista
Parametros:
Lista* li:Ponteiro para ponteiro do come�o da lista
Aluno al: Copia da struct a ser guardada no novo no da Lista.
Retorna 0 caso de erro
Retorna 1 caso haja sucesso na inser��o
*/
int insereOrdenado(Lista* li,Aluno al)
{
    if(*li==NULL) return 0;

    Elem* no;
    no = (Elem*)malloc(sizeof(Elem));

    if(no==NULL) return 0;

    no->dados = al;

    if(listaVazia(li))
    {
        no->proximo = (*li);

        *li = no;
        return 1;
    }
    else
    {
        Elem* atual,*ant;
        atual = (*li);
        ant = (*li);

        /**La�o para achar aonde o novo item se encaixa baseado na matricula do aluno*/
        while(atual!=NULL&&atual->dados.matricula<al.matricula)
        {
            ant = atual;
            atual = atual->proximo;
        }
        if(atual==(*li))/**Caso seja o primeiro item ap�s o inicio da lista,o proximo ser� o conteudo apontado pela lista
                           Anteriormente(1),depois atualizamos o conteudo para apontar para o elemento que colocamos(2) */
        {
            no->proximo = (*li);/**(1)*/
            *li = no;/**(2)*/
        }
        else/**Se n�o for o elemento seguinte do inicio da lista,pegamos o antigo proximo e colocamos ele para ser apontado no
               Proximo do nosso novo elemento(1) depois atualizamos o conteudo do anterior para apontarmos para o elemento que
               colocamos(2)*/
        {
            no->proximo = ant->proximo;/**(1)*/
            ant->proximo = no;/**(2)*/

        }
        return 1;
    }
}

/**
Fun��o para remover o primeiro elemento da Lista
Parametros:
Lista* li:Ponteiro para ponteiro do come�o da lista
Retorna 0 caso de erro
Retorna 1 caso haja sucesso na remo��o
*/

int removeInicio(Lista* li)
{
    if(*li==NULL) return 0;

    Elem* no;
    no = (Elem*)malloc(sizeof(Elem));

    if(no==NULL) return 0;

    no = (*li);

    *li=no->proximo;

    free(no);

    return 1;
}

/**
Fun��o para remover o ultimo elemento da Lista
Parametros:
Lista* li:Ponteiro para ponteiro do come�o da lista
Retorna 0 caso de erro
Retorna 1 caso haja sucesso na remo��o
*/

int removeFinal(Lista* li)
{
    if(*li==NULL) return 0;
    if(li==NULL) return 0;

    Elem* ant = (*li);
    Elem* atual=(*li);

    if(ant==NULL||atual==NULL) return 0;

    while(atual->proximo!=NULL)
    {
        ant = atual;
        atual = atual->proximo;

    }

    if(atual==(*li))
    {
        *li=atual->proximo;
    }
    else
    {

    }
    ant->proximo=NULL;

    free(atual);

    return 1;
}

/**
Fun��o para remover um elemento baseado na matricula
Parametros:
Lista* li:Ponteiro para ponteiro do come�o da lista
int mat: numero da matriculo do elemento que ser� removido
Retorna 1 caso de certo a remo��o
Retorna 0 caso a remo��o de errado
*/
int removeOrdenado(Lista* li,int mat)
{
    if(*li==NULL) return 0;
    if(li=NULL) return 0;

    Elem* ant,*atual;

    atual=(*li);

    while(atual!=NULL&&atual->dados.matricula!=mat)
    {
        ant = atual;
        atual = atual->proximo;
    }
    if(atual==NULL) return 0;

    if(atual==(*li))
        *li=(*li)->proximo;

    else
        ant->proximo = atual->proximo;

    free(atual);
    return 1;
}

/**
Fun��o para consultar a lista em busca de uma posi��o e copiar o conteudo dessa posi��o na lista em al
Parametros:
Lista* li:Ponteiro para ponteiro do come�o da lista
int pos: posi��o na lista do elemento a ser copiado
Aluno* al: endere�o aonde mandaremos a copia
Retorna 1 caso de certo
Retorna 0 caso de erro
*/
int consultaPosicao(Lista* li,int pos,Aluno* al)
{
    if(*li==NULL|| pos<=0) return 0;

    Elem* no = (*li);
    int i =1;

    while(no!=NULL && i<pos)
    {
        no=no->proximo;
        i++;
    }

    if(no==NULL) return 0;

    else
    {
        *al = no->dados;
        return 1;
    }
}

/**
Fun��o para consultar a lista em busca de uma posi��o e copiar o conteudo dessa posi��o na lista em al
Parametros:
Lista* li:Ponteiro para ponteiro do come�o da lista
int pos: posi��o na lista do elemento a ser copiado
Aluno* al: endere�o aonde mandaremos a copia
Retorna 1 caso de certo
Retorna 0 caso de erro
*/
int consultaMatricula(Lista*li,int mat,Aluno* al)
{
    if(*li==NULL) return 0;

    Elem* no = (*li);

    while(no!=NULL&& no->dados.matricula!=mat)
    {
        no = no->proximo;
    }

    if(no==NULL)return 0;
    else
    {
        *al = no->dados;
        return 1;
    }
}
