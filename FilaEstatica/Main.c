#include <stdio.h>
#include "FilaEstatica.h"

void printAluno(Aluno al) {
    printf("Nome: %s\n", al.nome);
    printf("Matricula: %d\n", al.mat);
    printf("Nota 1: %.2f\n", al.n1);
    printf("Nota 2: %.2f\n", al.n2);
    printf("Nota 3: %.2f\n", al.n3);
}

int main() {
    Fila* fi = criaFila();
    if (fi == NULL) {
        printf("Erro ao criar a fila.\n");
        return 1;
    }

    Aluno a1 = {"Joao", 123, 7.5, 8.0, 6.0};
    Aluno a2 = {"Maria", 456, 9.0, 8.5, 7.0};
    Aluno a3 = {"Pedro", 789, 5.5, 6.0, 7.5};

    insereItem(fi, a1);
    insereItem(fi, a2);
    insereItem(fi, a3);

    printf("Tamanho da fila: %d\n", tamanhoFila(fi));

    Aluno al;
    if (consultaFila(fi, &al)) {
        printf("Primeiro aluno da fila:\n");
        printAluno(al);
    }

    removeFila(fi);
    printf("Tamanho da fila após remoção: %d\n", tamanhoFila(fi));

    if (consultaFila(fi, &al)) {
        printf("Novo primeiro aluno da fila:\n");
        printAluno(al);
    }

    liberaFila(fi);
    return 0;
}
