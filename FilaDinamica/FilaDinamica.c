#include <stdio.h>
#include "FilaDinamica.h"

/**Implementações das Funções do TAD Fila Dinamica*/

/**
Função para criar a Fila dinamica
Sem Parametros
Retorna um ponteiro para a cabeça da Fila
*/
Fila* criaFila()
{
    Fila* fi =(Fila*)malloc(sizeof(Fila));
    if(fi!=NULL)
    {
        fi->inicio = NULL;
        fi->final = NULL;
    }

    return fi;
}

/**
Função para desalocar a Fila dinamica
Parametros:
Fila* fi: Endereço da cabeça da Fila
Sem retorno
*/
void liberaFila(Fila* fi)
{
    if(fi!=NULL)
    {
         Elem* no;

         while(fi->inicio!=NULL)
         {
             no=fi->inicio;
             fi->inicio = fi->inicio->prox;
             free(no);
         }
         free(fi);
    }

}

/**
Função para descobrirmos o tamanho da fila
Parametros:
Fila* fi: Endereço da cabeça da Fila
Retorna o tamanho da fila
*/
int tamanhoFila(Fila* fi)
{
    if(fi==NULL||fi->inicio==NULL) return 0;

    Elem* no;
    int i = 0;
    no=fi->inicio;

    while(no!=NULL)
    {
        no = no->prox;
        i++;
    }
    return i;
}

/**
Função para sabermos se a Fila está vazia
Parametros:
Fila* fi : Endereço da cabeça da Fila
Retorna 0 caso não esteja vazia
Retorna 1 caso esteja vazia
*/
int filaVazia(Fila* fi)
{
    if(fi==NULL||fi->inicio==NULL) return 1;
    return 0;
}

/**
Função para inserir um novo elemento no final da Fila
Parametros:
Fila* fi : Endereço da cabeça da Fila
Aluno al : Dados a serem guardados dentro do elemento
Retorna 0 caso haja falha na inserçãp
Retorna 1 caso haja sucesso na inserção
*/
int insereFila(Fila* fi,Aluno al)
{
    if(fi==NULL) return 0;

    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no==NULL) return 0;

    no->dados = al;
    no->prox = NULL;

    if(fi->inicio==NULL)
    {
        fi->inicio = no;
        fi->final = no;
        return 1;
    }
    else
    {
        fi->final->prox = no;
        fi->final = no;
        return 1;
    }
}

/**
Função para remover o primeiro item da fila
Parametros:
Fila* fi : Endereço da cabeça da Fila
Retorna 0 caso haja falha na remoção
Retorna 1 caso haja sucesso na remoção
*/
int removeFila(Fila* fi)
{
    if(fi==NULL||fi->inicio==NULL) return 0;
    Elem* no;

    no = fi->inicio;
    fi->inicio = fi->inicio->prox;

    if(fi->inicio==NULL)
        fi->final == NULL;

     free(no);

     return 1;
}

/**
Função para consultarmos o primeiro item da fila
Parametros:
Fila* fi : Endereço da cabeça da Fila
Aluno* al: Endereço para guardamos os dados consultados
Retorna 1 caso haja sucesso na consulta
Retorna 0 caso haja falha na consulta
*/
int consultaFila(Fila* fi,Aluno* al)
{
    if(fi==NULL||fi->inicio==NULL) return 0;
    *al = fi->inicio->dados;
    return 1;
}

