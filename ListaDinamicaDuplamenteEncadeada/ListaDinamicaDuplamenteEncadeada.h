#ifndef __LISTADINAMICADUPLAMENTEENCADEADA_H
#define __LISTADINAMICADUPLAMENTEENCADEADA_H

/**
Lista Dinamica Duplamente Encadeada:

*Lista em que cada elemento aponta para seu sucessor e seu antecessor
*Usa um ponteiro especial para indicar o começo da lista e uma indicação de final nos dois sentidos
*Permite que se navegue tanto para frente como para tras da lista
*Não precisa mudar os antecessores ou sucessores em uma alteração(como a Lista Dinamica Encadeada simples ja permitia
*Necessidade de percorrer a lista para acessar um elemento(a estatica permite acessar sem percorrer)

Usar quando houver muita Inserção/Remoção
*/
//-----------------------------------------//
/**Dado guardado no elemento:*/
typedef struct
{
    int matricula;
    char nome[30];
    float n1,n2,n3;
}Aluno;
struct elemento
{
    struct elemento *prox;
    struct elemento *ant;
    Aluno dados;
};
typedef struct elemento* Lista;
/** Cabeçalhos das funções do TAD Lista Dinamica Duplamente Encadeada*/

Lista* criaListaDupla();
void liberaListaDupla(Lista* li);
int tamanhoLista(Lista* li);
int listaVazia(Lista* li);
int insereInicio(Lista* li,Aluno al);
int insereFinal(Lista* li,Aluno al);
int insereOrdenado(Lista* li,Aluno al);
int removeInicio(Lista* li);
int removeFinal(Lista* li);
int removeOrdenado(Lista* li,int mat);
int consultaListaPos(Lista*li,int pos,Aluno* al);
int consultaListaMat(Lista*li,int mat,Aluno* al);
#endif
