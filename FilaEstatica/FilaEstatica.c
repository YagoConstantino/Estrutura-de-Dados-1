#include <stdio.h>
#include "FilaEstatica.h"

/**Implementação das Funções do TAD Fila Estática*/

/**
Função para criar uma Fila;
Sem parametros
Retorna um ponteiro para o endereço da Fila
*/
Fila* criaFila()
{
    Fila* fi = (Fila*)malloc(sizeof(Fila));
    if(fi!=NULL)
    {
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd =0;
    }
    return fi;
}

/**
Função para desalocar a fila
Parametros:
Fila* fi: Endereço da struct que contém a Fila
Sem retorno
*/
void liberaFila(Fila* fi)
{
    free(fi);
}

/**
Função para sabermos o tamanho da fila
Parametros:
Fila* fi: Endereço da struct que contém a Fila
Retorna -1 caso a fila não exista
Retorna o tamanho da fila caso ela exista
*/
int tamanhoFila(Fila* fi)
{
    if(fi==NULL) return -1;

    return fi->qtd;
}

/**
Função para sabermos se a fila está vazia
Parametros:
Fila* fi: Endereço da struct que contém a Fila
Retorna -1 caso a fila não exista
Retorna 1 caso a fila esteja vazia
Retorna 0 caos a fila não esteja vazia
*/
int filaVazia(Fila*fi)
{
    if(fi== NULL) return -1;
    if(fi->qtd==0) return 1;
    else return 0;
}

/**
Função para sabermos se a fila está cheia
Parametros:
Fila* fi: Endereço da struct que contém a Fila
Retorna -1 caso a fila não exista
Retorna 0 caso a fila não esteja cheia
Retorna 1 caso a fila esteja cheia
*/
int filaCheia(Fila* fi)
{
    if(fi==NULL) return -1;
    if(fi->qtd==MAX) return 1;
    else return 0;
}

/**
Função para inserir um novo item no final da fila
Parametros:
Fila* fi:Endereço da struct que contém a Fila
Aluno al:Conteúdo a ser guardado na fila
Retorna 1 caso haja sucesso na inserção
Retorna 0 caso haja falha na inserção
*/
int insereItem(Fila* fi,Aluno al)
{
    if(fi==NULL) return 0;
    if(filaCheia(fi)) return 0;

    fi->dados[fi->final] = al;
    fi->final= (fi->final+1)%MAX; //Caso chege a Max ele reseta para 0 ;
    fi->qtd++;

    return 1;
}

/**
Função para retirarmos um item da Fila
Parametros:
Fila* fi:Endereço da struct que contém a Fila
Retorna 1 caso haja sucesso na remoção
Retorna 0 caso haja falha
*/
int removeFila(Fila* fi)
{
    if(fi==NULL || filaVazia(fi)) return 0;

    fi->inicio = (fi->inicio+1)%MAX; //Reseta em 0 caso caso chega a Max

    fi->qtd--;

    return 1;
}

/**
Função para consultamos o item no inicio da lista;
Parametros:
Fila* fi:Endereço da struct que contém a Fila
Aluno* al: Endereço da variavel que vai receber os dados consultados
Retorna 0 caso haja falha na Consulta
Retorna 1 caso haja sucesso na Consulta
*/
int consultaFila(Fila* fi,Aluno* al)
{
    if(fi==NULL) return 0;

    *al = fi->dados[fi->inicio];
    return 1;
}
