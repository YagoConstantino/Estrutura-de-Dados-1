#ifndef __LISTAESTATICA_H
#define __LISTAESTATICA_H
#define MAX 100

/**
Lista é uma sequência de elementos do mesmo tipo ligados
Uma Lista pode N elementos,caso N=0 dizemos que a lista
está vazia
Operações:

-Criação de lista
-Inserção de elemento
-Exclusão de elemento
-Acesso de elemento
-Exclusão de lista

Cabeçalho das Funções do TAD Lista Estática
*/

typedef struct{
    int matricula;
    char nome[30];
    float n1,n2,n3;
}Aluno;

typedef struct
{
    int qtd;
    Aluno dados[MAX];

}Lista;

Lista* criaLista();
void liberaLista(Lista* li);
int tamanhoLista(Lista* li);
int listaCheia(Lista* li);
int insereFinalLista(Lista* li,Aluno al);
int insereInicioLista(Lista* li,Aluno al);
int insereListaOrdenada(Lista* li,Aluno al);
int removeFinalLista(Lista* li);
int removeInicioLista(Lista* li);
int removeElemento(Lista* li,int mat);
int consultaListaPosicao(Lista* li,int pos,Aluno* al);
int consultaListaMatricula(Lista* li,int mat,Aluno* al);


#endif
