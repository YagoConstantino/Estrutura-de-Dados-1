#ifndef __PILHA_H
#define __PILHA_H

/** Arquivo com cabeçalhos da pilha*/

//redefinição do nome da struct//
typedef struct pilha Pilha;

/** Funções exportadas*/

Pilha* cria_pilha(int size);
void libera_pilha(Pilha* p);
void push(Pilha* p,int elem);
int pop(Pilha* p);
int empty(Pilha* p);
int full(Pilha* p);
#endif

