#ifndef _FILADINAMICA_H
#define _FILADINAMICA_H

/**
Fila é uma sequencia de elementos do mesmo tipo
Em que os itens saem do primeiro a ser inserido até o ultimo a ser inserido
inserções e exclusoes são feitas nas extremidades da fila,não há inserção no meio
Bom para controlar fluxo de dados e a ordem de saida
Usamos um nó descritor na cabeça da Fila
*/
typedef struct
{
    char nome[30];
    int mat;
    float n1,n2,n3;

}Aluno;

typedef struct elem
{
    Aluno dados;
    struct elem* prox;
}Elem;

typedef struct fila
{
    Elem* inicio;
    Elem* final;
}Fila;

/**Cabeçalhos das Funções do TAD Fila Dinamica*/

Fila* criaFila();
void liberaFila(Fila* fi);
int tamanhoFila(Fila* fi);
int filaVazia(Fila* fi);
int insereFila(Fila* fi,Aluno al);
int removeFila(Fila* fi);
int consultaFila(Fila* fi,Aluno* al);

#endif
