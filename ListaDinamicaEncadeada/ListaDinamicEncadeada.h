#ifndef __LISTADINAMICAENCADEADA_H
#define __LISTADINAMICAENCADEADA_H

/**Cabe�alhos das Fun��es do TAD Lista Dinamica Encadeada*/

/**Structs utilizadas:*/

typedef struct
{
    int matricula;
    char nome[100];
    float n1,n2,n3;

}Aluno;

typedef struct elem Elem;
typedef Elem* Lista;

/**Fun��es*/

Lista* criaLista();
void liberaLista(Lista* li);
int tamanhoLista(Lista* li);
int listaVazia(Lista* li);
int insereInicio(Lista* li,Aluno al);
int insereFinal(Lista* li,Aluno al);
int insereOrdenado(Lista* li,Aluno al);
int removeInicio(Lista* li);
int removeFinal(Lista* li);
int removeOrdenado(Lista* li,int mat);
int consultaPosicao(Lista* li,int pos,Aluno* al);
int consultaMatricula(Lista*li,int mat,Aluno* al);

#endif
