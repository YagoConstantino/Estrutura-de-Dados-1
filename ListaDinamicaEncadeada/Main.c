#include <stdio.h>
#include "ListaDinamicEncadeada.h"

int main() {
    Lista* li = criaLista(); // Testando criaLista()

    // Testando insereInicio()
    Aluno aluno1 = {1, "Joao", 7.5, 8.3, 9.1};
    Aluno aluno2 = {2, "Maria", 6.8, 7.5, 8.2};
    Aluno aluno3 = {3, "Pedro", 5.5, 6.7, 7.3};

    printf("Inserindo elementos no inicio da lista:\n");
    insereInicio(li, aluno1);
    insereInicio(li, aluno2);
    insereInicio(li, aluno3);

    // Testando tamanhoLista()
    printf("Tamanho da lista: %d\n", tamanhoLista(li));

    // Testando consultaPosicao()
    Aluno consulta;
    int posicao = 2;
    if (consultaPosicao(li, posicao, &consulta)) {
        printf("Conteudo da posicao %d: Matricula: %d, Nome: %s, Notas: %.1f %.1f %.1f\n",
               posicao, consulta.matricula, consulta.nome, consulta.n1, consulta.n2, consulta.n3);
    } else {
        printf("Posicao invalida ou lista vazia.\n");
    }

    // Testando consultaMatricula()
    int matricula = 1;
    if (consultaMatricula(li, matricula, &consulta)) {
        printf("Aluno com matricula %d encontrado: Nome: %s, Notas: %.1f %.1f %.1f\n",
               matricula, consulta.nome, consulta.n1, consulta.n2, consulta.n3);
    } else {
        printf("Matricula nao encontrada.\n");
    }

    // Testando insereFinal()
    Aluno aluno4 = {4, "Ana", 8.0, 8.5, 9.0};
    printf("Inserindo elemento no final da lista:\n");
    insereFinal(li, aluno4);

    // Testando removeInicio()
    printf("Removendo elemento do inicio da lista:\n");
    removeInicio(li);
    printf("Novo tamanho da lista: %d\n", tamanhoLista(li));

    // Testando removeFinal()
    printf("Removendo elemento do final da lista:\n");
    removeFinal(li);
    printf("Novo tamanho da lista: %d\n", tamanhoLista(li));

    // Testando removeOrdenado()
    int matriculaRemover = 2;
    printf("Removendo aluno com matricula %d da lista:\n", matriculaRemover);
    removeOrdenado(li, matriculaRemover);
    printf("Novo tamanho da lista: %d\n", tamanhoLista(li));

    // Liberando lista
    liberaLista(li);

    return 0;
}
