#ifndef _PILHADINAMICA_H
#define _PILHADINAMICA_H

/**Estruturas*/
typedef struct
{
    char nome;
    int mat;
    float n1,n2,n3;
}Aluno;

typedef struct elemento
{
    struct elemento *prox;
    Aluno dados;
}Elem;

typedef Elem*  Pilha;

/**Cabeçalhos das Funçoes do TAD Pilha Dinamica*/

Pilha* criaPilha();
void liberaPilha(Pilha* pi);
int pilhaVazia(Pilha* pi);
int tamanhoPilha(Pilha* pi);
int inserePilha(Pilha* pi,Aluno al);
int removePilha(Pilha* pi,Aluno al);
int consultaPilha(Pilha* pi,Aluno* al);


#endif
