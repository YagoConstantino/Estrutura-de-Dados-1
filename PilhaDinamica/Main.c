#include <stdio.h>
#include <stdlib.h> // Para usar malloc e free
#include "PilhaDinamica.h"

// Função para exibir os dados de um aluno
void exibeAluno(Aluno al) {
    printf("Nome: %c\n", al.nome);
    printf("Matrícula: %d\n", al.mat);
    printf("Notas: %.2f, %.2f, %.2f\n", al.n1, al.n2, al.n3);
    printf("\n");
}

int main() {
    // Criando uma pilha dinâmica
    Pilha* pi = criaPilha();

    // Verificando se a pilha foi criada corretamente
    if (pi == NULL) {
        printf("Erro ao criar a pilha!\n");
        return 1;
    }

    // Inserindo alguns alunos na pilha
    Aluno aluno1 = {'A', 123, 7.5, 8.0, 6.5};
    Aluno aluno2 = {'B', 456, 5.0, 6.0, 7.0};
    Aluno aluno3 = {'C', 789, 9.0, 8.5, 9.5};

    inserePilha(pi, aluno1);
    inserePilha(pi, aluno2);
    inserePilha(pi, aluno3);

    // Verificando o tamanho da pilha
    printf("Tamanho da pilha: %d\n", tamanhoPilha(pi));

    // Consultando e exibindo o topo da pilha
    Aluno topo;
    if (consultaPilha(pi, &topo)) {
        printf("Topo da pilha:\n");
        exibeAluno(topo);
    } else {
        printf("Erro ao consultar o topo da pilha!\n");
    }

    // Removendo um elemento da pilha
    removePilha(pi, topo);

    // Verificando o tamanho da pilha após remoção
    printf("Tamanho da pilha após remoção: %d\n", tamanhoPilha(pi));

    // Liberando a pilha da memória
    liberaPilha(pi);

    return 0;
}
