#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaCirculares.h"

// Função para imprimir os dados de um aluno
void imprimeAluno(Aluno al) {
    printf("Matricula: %d\n", al.mat);
    printf("Nome: %s\n", al.nome);
    printf("Nota 1: %.2f\n", al.n1);
    printf("Nota 2: %.2f\n", al.n2);
    printf("Nota 3: %.2f\n", al.n3);
    printf("\n");
}

int main() {
    Lista* li = criaLista(); // Cria uma lista circular

    // Inserindo alguns alunos para teste
    Aluno aluno1 = {"Ana", 1, 7.5, 8.0, 6.5};
    Aluno aluno2 = {"Bruno", 2, 6.0, 7.0, 8.0};
    Aluno aluno3 = {"Carlos", 3, 5.5, 6.5, 7.5};
    Aluno aluno4 = {"Daniela", 4, 8.0, 9.0, 7.0};

    printf("Inserindo alunos no início da lista:\n");
    insercaoInicio(li, aluno1);
    insercaoInicio(li, aluno2);
    insercaoInicio(li, aluno3);

    // Consultando um aluno pelo número de matrícula
    Aluno consulta;
    int matriculaConsulta = 2;
    if (consultaMat(li, matriculaConsulta, &consulta)) {
        printf("Aluno encontrado com matrícula %d:\n", matriculaConsulta);
        imprimeAluno(consulta);
    } else {
        printf("Aluno com matrícula %d não encontrado.\n", matriculaConsulta);
    }

    // Inserindo um aluno no final da lista
    printf("\nInserindo aluno no final da lista:\n");
    insercaoFinal(li, aluno4);

    // Consultando um aluno pela posição na lista
    int posicaoConsulta = 2;
    if (consultaPosicao(li, posicaoConsulta, &consulta)) {
        printf("Aluno encontrado na posição %d:\n", posicaoConsulta);
        imprimeAluno(consulta);
    } else {
        printf("Posição %d inválida ou não encontrada.\n", posicaoConsulta);
    }

    // Removendo um aluno da lista
    printf("\nRemovendo aluno com matrícula %d:\n", 3);
    removeMat(li, 3);

    // Verificando o tamanho da lista


    // Imprimindo todos os alunos na lista
    printf("\nLista de alunos:\n");
    Elem* no = *li;
    if (no != NULL) {
        Elem* primeiro = no;
        do {
            imprimeAluno(no->dados);
            no = no->prox;
        } while (no != primeiro);
    } else {
        printf("Lista vazia.\n");
    }

    // Liberando a lista da memória
    liberaLista(li);

    return 0;
}
