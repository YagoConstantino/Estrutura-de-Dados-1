#include <stdio.h>
#include "PilhaDinamica.h"

/**Implementação das Funções do TAD Pilha Dinamica*/

/**
Função para criar a Pilha dinamica
Sem Parametros
Retorna um ponteiro para a cabeça da pilha
*/
Pilha* criaPilha()
{
    Pilha* pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi!=NULL)
        *pi = NULL;

    return pi;
}

/**
Função para desalocar a Pilha dinamica
Parametros:
Pilha* pi: Endereço da cabeça da pilha;
Sem retorno
*/
void liberaPilha(Pilha* pi)
{
    Elem* no,*ant;
    no = (*pi);

    while(no!=NULL)
    {
        ant = no;
        no= no->prox;
        free(ant);
    }
    free(no);
    free(pi);
}

/**
Função para verificar se a pilha está vazia
Parametros:
Pilha* pi: Endereço da cabeça da pilha;
Retorna 1 se estiver vazia
Retorna 0 caso contenha algo
*/
int pilhaVazia(Pilha* pi)
{
    if(pi==NULL||(*pi)==NULL) return 1;
    return 0;
}

/**
Função para verificar quantos itens tem na pilha
Parametros:
Pilha* pi: Endereço da cabeça da pilha;
Retorna 0 caso esteja vazia ou não exista
Retotna  a quantidade de itens caso exista e não esteja vazia
 */
int tamanhoPilha(Pilha* pi)
{
    int i=0;
    if(pi==NULL|| (*pi)==NULL) return 0;
    else
    {
        Elem* no;

        no= (*pi);
        while(no!=NULL)
        {
            i++;
            no=no->prox;
        }
        return i;
    }
}

/**
Função para inserir um novo elemento na pilha
Parametros:
Pilha* pi: Endereço da cabeça da pilha
Aluno al: Dados a serem guardados no novo elemento
Retorna 1 caso haja sucesso na inserção
Retorna 0 caso haja falha na inserção
*/
int inserePilha(Pilha* pi,Aluno al)
{
    if(pi==NULL) return 0;
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no==NULL) return 0;
    no->dados = al;
    no->prox = (*pi);
    (*pi) = no;
    return 1;
}

/**
Função para remover um elemento na pilha
Parametros:
Pilha* pi: Endereço da cabeça da pilha
Aluno al: Dados a serem guardados no novo elemento
Retorna 1 caso haja sucesso na remoção
Retorna 0 caso haja falha na remoção
*/
int removePilha(Pilha* pi,Aluno al)
{
    if(pi==NULL)return 0;
    if((*pi)==NULL) return 0;
    Elem* no=(*pi);

    (*pi) = no->prox;
    free(no);
    return 1;
}

/**
Função para consultar um elemento na pilha
Parametros:
Pilha* pi: Endereço da cabeça da pilha
Aluno* al: Endereço de uma variavel que guaradará os dados consultados
Retorna 1 caso haja sucesso na consulta
Retorna 0 caso haja falha na consulta
*/
int consultaPilha(Pilha* pi,Aluno* al)
{
    if(pi==NULL) return 0;
    if((*pi)==NULL) return 0;
    *al = (*pi)->dados;
    return 1;
}
