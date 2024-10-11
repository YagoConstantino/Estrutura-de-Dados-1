#ifndef _FILAESTATICA_H
#define _FILAESTATICA_H
#define MAX 100

/**
Fila é uma sequencia de elementos do mesmo tipo
Em que os itens saem do primeiro a ser inserido até o ultimo a ser inserido
inserções e exclusoes são feitas nas extremidades da fila,não há inserção no meio
Bom para controlar fluxo
*/

typedef struct
{
    char nome[50];
    int mat;
    float n1,n2,n3;
}Aluno;

typedef struct
{
    int inicio,final,qtd;
    Aluno dados[MAX];
}Fila;

/**Cabeçalhos das Funções do TAD Fila Estática*/

Fila* criaFila();
void liberaFila(Fila* fi);
int tamanhoFila(Fila* fi);
int filaVazia(Fila* fi);
int filaCheia(Fila* fi);
int insereItem(Fila* fi,Aluno al);
int removeFila(Fila* fi);
int consultaFila(Fila* fi,Aluno* al);


#endif // _FILAESTATICA_H
