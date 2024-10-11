#include <stdio.h>
#include "ListaDeNoDescritor.h"

// Função auxiliar para imprimir os dados de um aluno
void imprimeAluno(Aluno al) {
    printf("Matricula: %d\n", al.mat);
    printf("Nome: %s\n", al.nome);
    printf("Notas: %.1f %.1f %.1f\n", al.n1, al.n2, al.n3);
    printf("\n");
}

int main() {
    Lista* lista = criaListaNo(); // Criando a lista encadeada com nó descritor

    // Exemplo de inserção no início da lista
    Aluno aluno1 = {"Alice", 123, 8.5, 7.5, 9.0};
    if (insereListaInicio(lista, aluno1))
        printf("Inserção no início realizada com sucesso!\n");
    else
        printf("Falha ao inserir no início da lista.\n");

    // Exemplo de inserção no final da lista
    Aluno aluno2 = {"Bob", 456, 7.0, 6.5, 8.0};
    if (insereListaFinal(lista, aluno2))
        printf("Inserção no final realizada com sucesso!\n");
    else
        printf("Falha ao inserir no final da lista.\n");

    // Exemplo de inserção ordenada na lista
    Aluno aluno3 = {"Carol", 789, 9.0, 8.0, 7.5};
    if (insereOrdenada(lista, aluno3.mat, aluno3))
        printf("Inserção ordenada realizada com sucesso!\n");
    else
        printf("Falha ao inserir ordenadamente na lista.\n");

    // Exemplo de consulta por matrícula
    Aluno alunoConsulta;
    int matriculaConsulta = 456;
    if (consultaMat(lista, matriculaConsulta, &alunoConsulta)) {
        printf("Aluno encontrado por matrícula:\n");
        imprimeAluno(alunoConsulta);
    } else {
        printf("Aluno com matrícula %d não encontrado.\n", matriculaConsulta);
    }

    // Exemplo de remoção
    int matriculaRemocao = 123;
    if (removeMat(lista, matriculaRemocao))
        printf("Remoção do aluno com matrícula %d realizada com sucesso!\n", matriculaRemocao);
    else
        printf("Falha ao remover aluno com matrícula %d.\n", matriculaRemocao);

    // Exemplo de consulta por posição
    int posicaoConsulta = 2;
    if (consultaPosicao(lista, posicaoConsulta, &alunoConsulta)) {
        printf("Aluno encontrado na posição %d:\n", posicaoConsulta);
        imprimeAluno(alunoConsulta);
    } else {
        printf("Posição %d inválida ou não existe na lista.\n", posicaoConsulta);
    }

    // Liberando a memória alocada pela lista
    liberaLista(lista);

    return 0;
}
