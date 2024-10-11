#include <stdio.h>
#include "ListaCirculares.h"

/**Implemetação das Funçoes do TAD Lista Circular*/

/**
Função para criar a Lista Circular
Sem Parametros
Retorna um ponteiro para a Lista recem alocada
*/
Lista* criaLista()
{
    Lista* li;

    li=(Lista*)malloc(sizeof(Lista));

    if(li!=NULL)
        *li = NULL;

    return li;
}

/**
Função para liberar a Lista
Parametros:
Lista* li: Endereço do começo da Lista
Sem retorno
*/
void liberaLista(Lista* li)
{
    if(li!=NULL&&(*li)!=NULL) // Verifico se a Lista existe e não está vazia(se ha algo apontado por ela)
    {
        Elem* ant,*no;// Crio nós auxiliares
        no = (*li);
        while((*li)!=no->prox)// Enquanto o no não voltar para o começo da Lista circular
        {
            ant = no; //Coloco o nó atual como anterior
            no=no->prox; // Percorro a lista e libero o no anterior
            free(ant); // Liberando o anterior
        }
        free(no); // Libero o ultimo item
        free(li); // Libero a Lista
    }
}

/**
Função para sabermos quantos itens tem na lista
Lista* li: Endereço do começo da Lista
Retorna o número de itens da Lista
*/
int tamanhoLista(Lista* li)
{
    if(li==NULL) return 0; // Retorna 0 caso a Lista não exista
    if((*li)==NULL) return 0;// Retorna 0 caso a Lista esteja vazia

    Elem *no=(*li);
    int i = 1;

    while(no!=li)
    {
        no = no->prox;
        i++;
    }

    return i;
}

/**
Função para testar se a lista está vazia
Lista* li: Endereço do começo da Lista
Retorna 1 caso esteja vazia
Retorna 0 caso não esteja vazia
*/
int listaVazia(Lista* li)
{
    if((*li)!=NULL&&li!=NULL) return 1;
    return 0;
}

/**
Função para inserirmos um novo Elemento no começo da lista
Parametros
Lista* li: Endereço do começo da Lista
Aluno al: Conteúdo a ser armazenado no novo elemento
Retorna 1 caso haja sucesso na inserção
Retorna 0 caso falhe na inserção
*/
int insercaoInicio(Lista* li,Aluno al)
{
    if(li==NULL) return 0; //Se a Lista não existir retornamos falha

    Elem* no =(Elem*)malloc(sizeof(Elem)); // Alocamos um novo elemento

    if(no==NULL) return 0; // Testamos se a alocação deu certo

    no->dados = al; // Guardamos os dados nesse novo Elemento

    if((*li)==NULL) // Caso não exista nenhum item na lista
    {
        (*li) = no;// A cabeça da lista passa a apontar para o novo elemento
        no->prox = no;// O proximo do novo elemento aponta para o primeiro da lista (Ele mesmo)
        return 1; // Sinalizamos sucesso na operação de inserção
    }
    else // Caso haja mais itens na lista
    {
        Elem* aux = (*li); // Criamos um auxiliar para percorremos a lista
        while(aux->prox!=(*li)) // Percorremso a lista até o final, ou seja o elemento que o proximo aponta para o começo
            aux = aux->prox;// Guardamos o ultimo como aux

        aux->prox = no; // Fazemos o ultimo elemento apontar para o novo primeiro elemento
        no->prox = *li; // Fazemos o novo elemento seguir a lista apontando para o antigo primeiro elemento(Que era (*li))
        (*li) = no; // Fazemos a cabeça da lista apontar para o novo primeiro elemento
        return 1; // Sinalizamos sucesso na operação de inserção
    }

}


/**
Função para inserirmos um novo Elemento no final da lista
Parametros
Lista* li: Endereço do começo da Lista
Aluno al: Conteúdo a ser armazenado no novo elemento
Retorna 1 caso haja sucesso na inserção
Retorna 0 caso falhe na inserção
*/
int insercaoFinal(Lista* li,Aluno al)
{

    if(li==NULL) return 0; //Se a Lista não existir retornamos falha

    Elem* no =(Elem*)malloc(sizeof(Elem)); // Alocamos um novo elemento

    if(no==NULL) return 0; // Testamos se a alocação deu certo

    no->dados = al; // Guardamos os dados nesse novo Elemento

    if((*li)==NULL) // Caso não exista nenhum item na lista
    {
        (*li) = no;// A cabeça da lista passa a apontar para o novo elemento
        no->prox = no;// O proximo do novo elemento aponta para o primeiro da lista (Ele mesmo)
        return 1; // Sinalizamos sucesso na operação de inserção
    }
    else // Caso haja mais itens na lista
    {
        Elem* aux = (*li); // Criamos um auxiliar para percorremos a lista
        while(aux->prox!=(*li)) // Percorremso a lista até o final, ou seja o elemento que o proximo aponta para o começo
            aux = aux->prox;// Guardamos o ultimo como aux

        aux->prox = no; // Fazemos o ultimo elemento apontar para o novo primeiro elemento
        no->prox = (*li); // Fazemos o novo elemento seguir a lista apontando para o antigo primeiro elemento(Que era (*li))

        return 1; // Sinalizamos sucesso na operação de inserção
    }
}

/**
Função para inserirmos um novo Elemento Baseado na matricula
Parametros
Lista* li: Endereço do começo da Lista
Aluno al: Conteúdo a ser armazenado no novo elemento
Retorna 1 caso haja sucesso na inserção
Retorna 0 caso falhe na inserção
*/
int insercaoFinaloOrdenada(Lista* li,Aluno al)
{
    if(li==NULL) return 0; // Caso a lista não exista retornamos falha na inserção

    Elem* no = (Elem*)malloc(sizeof(Elem)); // Criamos um novo elemento

    if(no==NULL) return 0; // Caso haja falha na alocação de memória retornamos falha

    no->dados = al; // Guardamos os dados do aluno no novo elemento

    if((*li)==NULL) // Caso a lista esteja vazia
    {
        (*li) = no; // Fazemos a cabeça apontar para o novo elemento
        no->prox = no;// Fazemos o novo elemento apontar para o primeiro elemento da lista (Ele próprio)
        return 1; // Sinalizamos sucesso na inserção
    }
    else
    {
        if((*li)->dados.mat>al.mat) // Caso o primeiro item tenha uma maticula maior,o item deve ser inserido no começo
        {
            Elem* atual = (*li); // Criamos um auxiliar para percorrer a lista
            while(atual->prox!=(*li))
                atual = atual->prox; //Percorremos até o final
            no->prox = (*li); // Fazemos o novo elemento apontar para o antigo primeiro elemento da lista
            atual->prox = no; // Fazemos o ultimo elemnto apontar para o novo Nó
            *li = no;// E por fim fazemos a cabeça da lista apontar para o novo Nó
            return 1;// Sinalizamos sucesso
        }
        Elem* ant = *li;
        Elem* atual = (*li)->prox;  /* Caso não seja colocado no começo da lista, criamos dois auxiliares para percorrer a lista
                                       e colocarmos  o novo Nó entre eles*/

        while(atual!=(*li)&& atual->dados.mat<al.mat)// Percorrermos a lista até acharmos o lugar ideal (baseado na matricuila)
        {
            ant = atual; // Guardamos o anterior pois vamos ter que mudar o proximo dele
            atual = atual->prox;// Percorremos a lista
        }
        ant->prox = no;// Colocamos o nó entre o ant e atual
        no->prox = atual;
        return 1;// Sinalizamos sucesso na inserção
    }
}

/**
Função para removermos um Elemento no começo da lista
Parametros
Lista* li: Endereço do começo da Lista
Retorna 1 caso haja sucesso na remoção
Retorna 0 caso falhe na remoção
*/
int removeInicio(Lista* li)
{
    if(li==NULL||(*li)==NULL) return 0; // Caso a lista não exista ou esteja vazia retornamos 0

    if((*li)==(*li)->prox)// Caso so tenha um item na lista
    {
        free(*li);// Lisberamos esse item
        *li = NULL; // Fazemos a cabeça apontar para NULL
        return 1;// Sinalizamos sucesso na remoção
    }

    Elem* atual = (*li); // Criamos um auxiliar para percorrermos a lista
    while(atual->prox!=(*li))
        atual = atual->prox;
    Elem* no = *li;// Usamos esse no para ser o primeiro elemento(Aquele que será removido)
    atual->prox = no->prox;// Fazemos o ultimo elemento apontar para o proximo da lista
    *li = no->prox; // Fazemos a cabeça da lista apontar para o proximo elemento
    free(no);// Removemos o primeiro elemento
    return 1;// Sinalizamos o sucesso na remoção
}

/**
Função para removermos um Elemento no final da lista
Parametros
Lista* li: Endereço do começo da Lista
Retorna 1 caso haja sucesso na remoção
Retorna 0 caso falhe na remoção
*/
int removeFinal(Lista* li)
{
    if(li==NULL||(*li)==NULL) return 0; // Caso a lista não exista ou esteja vazia retornamos 0

    if((*li)==(*li)->prox)// Caso so tenha um item na lista
    {
        free(*li);// Lisberamos esse item
        *li = NULL; // Fazemos a cabeça apontar para NULL
        return 1;// Sinalizamos sucesso na remoção
    }

    Elem* atual = (*li)->prox; // Criamos um auxiliar para percorrermos a lista(Até o ultimo que será removido)
    Elem* ant = (*li);// Criamos o ant para guardamos o penultimo item
    while(atual->prox!=(*li))
    {
        ant = atual;
        atual = atual->prox;
    }
    ant->prox = atual->prox; // Fazemos o penultimo item apontar para o primeiro da lista
    free(atual);// Liberamos o ultimo item
    return 1;// Sinalizamos sucesso na remoção

}

/**
Função para removermos um Elemento da lista baseado na sua matricula
Parametros
Lista* li: Endereço do começo da Lista
int mat: Numero de matricula do elemento a ser removido
Retorna 1 caso haja sucesso na remoção
Retorna 0 caso falhe na remoção
*/
int removeMat(Lista* li, int mat)
{
    // Verifica se a lista ou o ponteiro para a lista são nulos
    if (li == NULL || (*li) == NULL) return 0; // Caso a lista não exista ou esteja vazia, retorna 0

    Elem* no = *li; // Inicializa o ponteiro 'no' para apontar para o primeiro elemento da lista


    if (no->dados.mat == mat) // Verifica se o primeiro elemento da lista tem a matrícula mat
    {
        *li = no->prox; // Atualiza o início da lista para o próximo elemento
        free(no); // Libera a memória do nó removido
        return 1; // Retorna 1 indicando que a remoção foi bem sucedida
    }

    Elem* ant; // Ponteiro para o nó anterior
    no = no->prox; // Avança para o próximo nó da lista

    while (no != (*li) && no->dados.mat != mat)// Percorre a lista enquanto não volta ao início e não encontra o elemento com a matrícula mat
    {
        ant = no; // ant guarda o nó atual
        no = no->prox; // Avança para o próximo nó
    }

    // Verifica se o nó com a matrícula mat foi encontrado
    if (no->dados.mat == mat)
    {
        ant->prox = no->prox; // Remove no ajustando o ponteiro prox do nó anterior
        free(no); // Libera a memória do nó removido
        return 1; // Retorna 1 indicando que a remoção foi bem sucedida
    }

    return 0; // Retorna 0 se não encontrou o elemento com a matrícula mat
}

/**
Função para consultar um elemento da lista baseado em sua posicao
Parametros:
Lista* li: Endereço do começo da Lista
int pos: posição do elemento a ser consultado
Aluno* al: Ponteiro do endereço aonde guardaremos o elemento consultado
Retorna 1 caso haja sucesso na consulta
Retorna 0 caso falhe na cunsulta
*/
int consultaPosicao(Lista* li,int pos,Aluno* al)
{
    if(li==NULL||(*li)==NULL) return 0; // Caso a lista não exista ou esteja vazia retornamos 0;
    if(pos<=0) return 0; //Caso recebamos uma posiçao invalida retornamos 0;

    int i = 1;
    Elem* no = (*li);
    while(no->prox!=(*li)&& i< pos) // Percorremos a lista em busca da posicao
    {
        i++;
        no = no->prox;
    }
    if(i!=pos) return 0;// Caso percorramos toda a lista e não chegamos a pos retornamos 0(se a pos for maior que a lista por exemplo)
    else
    {
        *al = no->dados; // Copiamos os dados para o ponteiro
        return 1;// Sinalizamos sucesso
    }
}

/**
Função para consultar um elemento da lista baseado em sua matricula
Parametros:
Lista* li: Endereço do começo da Lista
int mat: matricula do elemento a ser consultado
Aluno* al: Ponteiro do endereço aonde guardaremos o elemento consultado
Retorna 1 caso haja sucesso na consulta
Retorna 0 caso falhe na cunsulta
*/
int consultaMat(Lista* li,int mat,Aluno* al)
{
    if(li==NULL||(*li)==NULL) return 0; // Caso a lista não exista ou esteja vazia retornamos 0;

    Elem* no = (*li);
    while(no->prox!=(*li)&& no->dados.mat!=mat) // Percorremos a lista em busca da matricula
    {
        no = no->prox;
    }
    if(no->dados.mat!=mat) return 0;// Caso percorramos toda a lista e não chegamos a matricula dada retornamos 0;
    else
    {
        *al = no->dados; // Copiamos os dados para o ponteiro
        return 1;// Sinalizamos sucesso
    }
}
