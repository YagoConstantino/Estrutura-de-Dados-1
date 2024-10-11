#include <stdio.h>
#include"ListaEstatica.h"

void imprimeAluno(Aluno al) {
    printf("Matrícula: %d\n", al.matricula);
    printf("Nome: %s\n", al.nome);
    printf("Notas: %.2f, %.2f, %.2f\n", al.n1, al.n2, al.n3);
    printf("\n");
}

int main() {
    Lista* minhaLista = criaLista(); // Criando uma lista

    // Inserindo alguns alunos na lista
    Aluno aluno1 = {1, "Joao", 7.5, 8.0, 6.5};
    Aluno aluno2 = {2, "Maria", 8.0, 9.0, 7.5};
    Aluno aluno3 = {3, "Pedro", 6.0, 7.0, 8.0};

    insereFinalLista(minhaLista, aluno1);
    insereFinalLista(minhaLista, aluno2);
    insereFinalLista(minhaLista, aluno3);

    // Verificando o tamanho da lista e imprimindo seus elementos
    printf("Tamanho da lista: %d\n", tamanhoLista(minhaLista));
    printf("Elementos da lista:\n");

    Aluno alunoConsulta;

    // Consultando e imprimindo os elementos da lista
    for (int i = 1; i <= tamanhoLista(minhaLista); i++) {
        consultaListaPosicao(minhaLista, i, &alunoConsulta);
        imprimeAluno(alunoConsulta);
    }

    // Testando a remoção de um elemento pelo início
    printf("Removendo o primeiro elemento da lista...\n");
    removeInicioLista(minhaLista);

    printf("Tamanho da lista após remoção: %d\n", tamanhoLista(minhaLista));

    // Testando a remoção de um elemento pelo final
    printf("Removendo o último elemento da lista...\n");
    removeFinalLista(minhaLista);

    printf("Tamanho da lista após remoção: %d\n", tamanhoLista(minhaLista));

    // Consultando novamente e imprimindo os elementos da lista após remoção
    printf("Elementos da lista após remoção:\n");
    for (int i = 1; i <= tamanhoLista(minhaLista); i++) {
        consultaListaPosicao(minhaLista, i, &alunoConsulta);
        imprimeAluno(alunoConsulta);
    }

    // Liberando a memória alocada pela lista
    liberaLista(minhaLista);

    return 0;
}
