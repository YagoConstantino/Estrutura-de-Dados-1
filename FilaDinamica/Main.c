#include <stdio.h>
#include <stdlib.h>
#include "FilaDinamica.h"

void imprimeFila(Fila* fi) {
    if (fi == NULL || fi->inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }
    Elem* no = fi->inicio;
    while (no != NULL) {
        printf("Nome: %s, Mat: %d, Notas: %.2f, %.2f, %.2f\n", no->dados.nome, no->dados.mat, no->dados.n1, no->dados.n2, no->dados.n3);
        no = no->prox;
    }
}

int main() {
    Fila* fi = criaFila();
    if (fi == NULL) {
        printf("Erro ao criar a fila!\n");
        return 1;
    }

    Aluno al1 = {"Alice", 123, 7.5, 8.0, 9.0};
    Aluno al2 = {"Bob", 456, 6.5, 7.0, 8.5};
    Aluno al3 = {"Carol", 789, 9.0, 8.5, 9.5};

    printf("Inserindo Alunos na Fila...\n");
    insereFila(fi, al1);
    insereFila(fi, al2);
    insereFila(fi, al3);

    printf("\nFila atual:\n");
    imprimeFila(fi);

    printf("\nTamanho da fila: %d\n", tamanhoFila(fi));

    Aluno alConsultado;
    if (consultaFila(fi, &alConsultado)) {
        printf("\nPrimeiro aluno da fila: Nome: %s, Mat: %d, Notas: %.2f, %.2f, %.2f\n", alConsultado.nome, alConsultado.mat, alConsultado.n1, alConsultado.n2, alConsultado.n3);
    } else {
        printf("Falha ao consultar o primeiro aluno da fila.\n");
    }

    printf("\nRemovendo um aluno da fila...\n");
    if (removeFila(fi)) {
        printf("Aluno removido com sucesso!\n");
    } else {
        printf("Falha ao remover o aluno da fila.\n");
    }

    printf("\nFila atual:\n");
    imprimeFila(fi);

    printf("\nTamanho da fila: %d\n", tamanhoFila(fi));

    liberaFila(fi);
    printf("\nFila liberada e memória desalocada.\n");

    return 0;
}
