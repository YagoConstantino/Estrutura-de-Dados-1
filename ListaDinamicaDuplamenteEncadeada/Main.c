#include <stdio.h>
#include "ListaDinamicaDuplamenteEncadeada.h"

// Função para exibir os dados de um aluno
void exibeAluno(Aluno al) {
    printf("Matrícula: %d\n", al.matricula);
    printf("Nome: %s\n", al.nome);
    printf("Notas: %.2f, %.2f, %.2f\n", al.n1, al.n2, al.n3);
    printf("-----------------\n");
}

int main() {
    Lista* lista = criaListaDupla();  // Cria uma lista duplamente encadeada

    // Verifica se a lista foi criada corretamente
    if (lista == NULL) {
        printf("Erro ao criar a lista!\n");
        return 1;  // Termina o programa com erro
    }

    // Verifica se a lista está vazia
    if (listaVazia(lista)) {
        printf("Lista vazia!\n");
    } else {
        printf("Lista não está vazia!\n");
    }

    // Insere alguns elementos na lista
    Aluno a1 = {111, "Alice", 8.5, 7.5, 9.0};
    Aluno a2 = {222, "Bob", 7.0, 6.5, 8.0};
    Aluno a3 = {333, "Carol", 9.0, 8.5, 7.5};

    insereInicio(lista, a1);
    insereInicio(lista, a2);
    insereFinal(lista, a3);

    // Mostra o tamanho da lista
    printf("Tamanho da lista: %d\n", tamanhoLista(lista));

    // Mostra os elementos da lista
    printf("Elementos da lista:\n");
    struct elemento* atual = *lista;
    while (atual != NULL) {
        exibeAluno(atual->dados);
        atual = atual->prox;
    }

    // Remove o primeiro e o último elemento da lista
    if (!listaVazia(lista)) {
        removeInicio(lista);
        removeFinal(lista);
    }

    // Mostra o tamanho da lista após remoções
    printf("Tamanho da lista após remoções: %d\n", tamanhoLista(lista));

    // Consulta elemento por posição
    Aluno consultaPos;
    if (consultaListaPos(lista, 1, &consultaPos)) {
        printf("Elemento na posição 1:\n");
        exibeAluno(consultaPos);
    } else {
        printf("Não foi possível consultar o elemento na posição 1.\n");
    }

    // Consulta elemento por matrícula
    int matriculaConsulta = 222;
    Aluno consultaMat;
    if (consultaListaMat(lista, matriculaConsulta, &consultaMat)) {
        printf("Elemento com matrícula %d:\n", matriculaConsulta);
        exibeAluno(consultaMat);
    } else {
        printf("Não foi possível consultar o elemento com matrícula %d.\n", matriculaConsulta);
    }

    // Libera a memória alocada pela lista
    liberaListaDupla(lista);
    lista = NULL;  // Após liberar, é boa prática apontar o ponteiro para NULL

    return 0;
}
