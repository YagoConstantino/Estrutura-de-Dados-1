#ifndef __LISTACIRCULARES_H
#define __LISTACIRCULARES_H

/**
TAD Lista Dinamica Encadeada Circular
Lista onde cada elemento aponta para o seu sucessor,porém o ultimo elemento aponta para o começo da lista
*/
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

typedef Elem* Lista;

/**Cabeçalho de Funções do TAD Lista Circular*/

Lista* criaLista();
void liberaLista(Lista* li);
int tamanhoLista(Lista* li);
int listaVazia(Lista* li);
int insercaoInicio(Lista* li,Aluno al);
int insercaoFinal(Lista* li,Aluno al);
int insercaoOrdenada(Lista* li,Aluno al);
int removeInicio(Lista* li);
int removeFinal(Lista* li);
int removeMat(Lista* li,int mat);
int consultaPosicao(Lista* li,int pos,Aluno* al);
int consultaMat(Lista* li,int mat,Aluno* al);
#endif

