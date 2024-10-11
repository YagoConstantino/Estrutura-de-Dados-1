#ifndef _LISTANODESCRITOR_H
#define _LISTANODESCRITOR_H

/**
Lista Encadeada com Nó Descritor
Trata-se de uma variação de lista Dinâmica,podendo ser simples,duplamente encadeada ou ainda circular
Usa um nó especial para armazenar diversas informações  sobre a lista
*/

/**Estruturas armazenadas e Nó Descritor*/
typedef struct
{
    char nome[30];
    int mat;
    float n1,n2,n3;
}Aluno;

typedef struct elemento
{
    Aluno dados;
    struct elemento* prox;

}Elem;

typedef struct descritor
{
    Elem* inicio;
    Elem* final;
    int qtd;
}Lista;

/**Cabeçalhos das Funções do TAD Lista Encadeada com Nò Descritor*/

Lista* criaListaNo();
void liberaLista(Lista* li);
int tamanhoLista(Lista*li);
int insereListaInicio(Lista* li,Aluno al);
int insereListaFinal(Lista* li,Aluno al);
int insereOrdenada(Lista* li,int mat,Aluno al);
int removeInicio(Lista*li);
int removeMat(Lista* li, int mat);
int consultaMat(Lista* li,int mat,Aluno* al);
int consultaPosicao(Lista* li,int pos,Aluno* al);
#endif
