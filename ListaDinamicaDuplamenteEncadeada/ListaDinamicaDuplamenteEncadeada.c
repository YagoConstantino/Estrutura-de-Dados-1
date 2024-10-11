#include "ListaDinamicaDuplamenteEncadeada.h"
#include <stdio.h>
/*struct elemento
{
    struct elemento *prox;
    struct elemento *ant;
    Aluno dados;
};*/

typedef struct elemento Elem;

/**Implementação das funções do TAD Lista Dinamica Duplamente Encadeada*/

/**
Função para alocar uma Lista dupla
Sem parametros
Retorna um pónteiro para a Lista alocada
*/
Lista* criaListaDupla()
{
    Lista* li;

    li=(Lista*)malloc(sizeof(Lista));
    if(li!=NULL)
        *li = NULL;

    return li;
}

/**
Função para desalocar uma Lista dupla
Parametros:
Lista* li: Ponteiro para o endereço do começo da lista
Sem retorno
*/
void liberaListaDupla(Lista* li)
{
    if(*li!= NULL)
    {
        Elem* no;
        while((*li)!=NULL)
        {
            no= (*li);
            *li =(*li)->prox;
            free(no);

        }
        free(li);
    }
}

/**
Função para descobrirmos o tamanho da lista
Parametros:
Lista* li:Ponteiro para o endereço do começo da lista
Retorna o Tamanho da lista.
*/
int tamanhoLista(Lista* li)
{
    if(li==NULL)return 0; // Verificamos se a lista existe

    else //Caso exista
    {
        int i =0; // Criamos um contador
        Elem* no; // Um no auxiliar para percorrermos a lista
        no = (*li); // Damos ao auxiliar o endereço do primeiro item da lista

        while(no!=NULL) // Enquanto não chegarmos ao item final
        {
            i++; // Aumentamos o contador
            no = no->prox; // E vamos para o proximo item
        }
        return i; // Retornamos quantos itens tem na lista,caso ela aponte para NULL,não entra no loop e retornamos i=0
    }
}

/**
Função para dizer se a Lista está Vazia
Parametros:
Lista* li:Ponteiro para o endereço do começo da lista
Retorna 0 caso ela tenha elementos
Retorna 1 caso ela esteja vazia
*/
int listaVazia(Lista* li)
{
    if(li==NULL) return 1; //Se a lista não existe (vazia)
    if((*li)==NULL) return 1;// Se a lista existe mas não tem nenhum elemento(vazia)
    return 0;
}

/**
Função para inserir um novo elemento no começo da lista
Parametros:
Lista* li:Ponteiro para o endereço do começo da lista
Aluno al: Copia dos dados a serem guardados na lista
Retorna 0 caso falhe em inserir o novo elemento
Retorna 1 caso tenha sucesso em inserir o novo elemento

*/
int insereInicio(Lista* li,Aluno al)
{
    if(li==NULL) return 0; //Verificamos se a lista existe

    Elem* no = (Elem*)malloc(sizeof(Elem));//Criamos um novo nó e o alocamos
    if(no==NULL) return 0;//Verificamos se a alocação funcionou
    no->dados = al;//Copiamos os dados a serem guardados
    no->ant = NULL;//Ele não tem elemento(nó) anterior(so existe o ponteiro para o começo da lista)
    no->prox = (*li);//Colocamos o proximo para apontar para o que era o conteudo de li(NULL pois estava vazia)

    if((*li)!=NULL)
        (*li)->ant = no; //Se ela não estiver vazia conectamos o proximo elemento com o endereço do no criado

    (*li) = no;//Agora a cabeça da lista aponta para o no que criamos

    return 1;
}

/**
Função para inserir um novo elemento no final da lista
Parametros:
Lista* li:Ponteiro para o endereço do começo da lista
Aluno al: Copia dos dados a serem guardados na lista
Retorna 0 caso falhe em inserir o novo elemento
Retorna 1 caso tenha sucesso em inserir o novo elemento
*/

int insereFinal(Lista* li,Aluno al)
{
    if(li==NULL) return 0; // Verificamos se a lista existe

    Elem* no =(Elem*)malloc(sizeof(Elem)); // Criamos e alocamos o novo no

    if(no==NULL) return 0; // Verificamos se a alocação deu certo

    no->dados = al; // Copiamos os dados a ser guardados
    no->prox = NULL; //Como ele vai ficar no final podemos colocar o proximo como NULL

    if((*li)==NULL) // Caso a lista esteja vazia
    {
        no->ant = NULL; // O anterior dele aponta para vazio
        *li=no; // A cabeça da lista ponta para o no novo
    }

    else //Caso a lista não esteja vazia
    {
        Elem* atual;// Auxiliar para percorrer a lista
        atual = *li; // Passamos o começo da lista para nosso auxiliar
        while(atual->prox!= NULL) // Enquanto o auxiliar não chegar ao final
        {
            atual = atual->prox; // Vamos para o proximo elemento
        }
        atual->prox = no;// Quando chegamos no final colocamos nosso novo no como proximo do auxiliar
        no->ant = atual; // E colocamos o endereço do auxilar como anterior
    }
    return 1; // Retorna um para sinalizar sucesso
}

/**
Função para inserir um elemento de forma ordenada baseada nos dados guardados nela(Nesse caso Matricula do aluno)
Parametros:
Lista* li:Ponteiro para o endereço do começo da lista
Aluno al: Copia dos dados a serem guardados na lista
Retorna 0 caso falhe em inserir o novo elemento
Retorna 1 caso tenha sucesso em inserir o novo elemento
*/

int insereOrdenado(Lista* li,Aluno al)
{
    if(li==NULL) return 0; // Verificamos se a lista existe

    Elem* no =(Elem*)malloc(sizeof(Elem)); // Criamos e alocamos o novo no
    if(no==NULL) return 0; // Verificamos se a alocação deu certo

    no->dados = al; // Copiamos os dados a ser guardados

    if((*li)==NULL) //Caso a lista esteja vazia
    {
        no->ant= NULL; // O anterior é vazio
        no->prox = NULL;// Não existe proximo logo NULL, pois é o primeiro item da lista
        (*li) = no;// A cabeça da lista aponta para o nó
        return 1; // Sinalizamos o sucesso da nova inserção
    }

    else // Caso a lista não esteja vazia
    {
        Elem* atual,*anterior;// Auxiliares para percorrer a lista
        atual = (*li); // Colocamos a cabeça da lista em nosso auxiliar


        while(atual!=NULL&&atual->dados.matricula<al.matricula) // Percorremos a lista até acharmaos a posição baseada na matricula
        {
            anterior = atual; // Guardamos o anterior para que ele aponte para o novo nó
            atual = atual->prox; // Usamos o atual para achar a posição certa baseada na maticula
        }

        no->ant = anterior; // O anterior é apontado pelo ant do novo nó
        anterior->prox = no;// O prox do anterior aponta para o novo nó
        no->prox = atual; // O prox do nosso novo no aponta para o atual
        if(atual!=NULL) atual->ant = no; // O anterior do atual aponta para o novo nó
        return 1; // Sinaliza o sucesso na inserção
    }
}

/**
Função para remover um item do inicio da Lista
Lista* li:Ponteiro para o endereço do começo da lista
Retorna 0 caso falhe em remover o elemento
Retorna 1 caso tenha sucesso em remover o elemento
*/
int removeInicio(Lista* li)
{
    if(li==NULL) return 0; // Verifica se a lista existe
    if((*li)==NULL) return 0;// Verifica se ela esta vazia

    Elem* no; // Crio um elemento para auxiliar

    no=(*li); // Vinculo ele ao primeiro item

    (*li) = no->prox; //Faço a cabeça aponta para o proximo elemento

    if(no->prox!=NULL) //Caso o proximo não seja NULL
        no->prox->ant == NULL; /**Fazemos o anterior do proximo item apontar para NULL(Como é comum do primeiro item da Lista,coisa que ele
                                 Coisa que ele se tornou agora*/

    free(no); // Liberamos o antigo primeiro item;
    return 1; // Sinalizamos o sucesso na remoção
}

/**
Função para remover um item do final da Lista
Lista* li:Ponteiro para o endereço do começo da lista
Retorna 0 caso falhe em remover o elemento
Retorna 1 caso tenha sucesso em remover o elemento
*/

int removeFinal(Lista* li)
{
    if(li==NULL) return 0; // Verifica se a lista existe
    if((*li)==NULL) return 0;// Verifica se ela esta vazia

    Elem* no;
    no=(*li);

    while(no->prox!=NULL) // Percorro a lista até chegar ao final
        no = no->prox;

    if(no->ant==NULL) // Se o anterio for NULL então só há um item na Lista e fazemos a cabeça aponta para o prox(NULL tambem)
        *li=no->prox;
    else
        no->ant->prox = NULL; // Se não mudamos o proximo do item anterior para não apontar para o item que estamos removendo

    free(no); // Liberamos o item
    return 1; // Sinalizamos sucesso na remoção
}

/**
Função para remover um item  da Lista baseada na matricula do aluno
Lista* li:Ponteiro para o endereço do começo da lista
int mat: matricula do elemento a ser removido
Retorna 0 caso falhe em remover o elemento
Retorna 1 caso tenha sucesso em remover o elemento
*/

int removeOrdenado(Lista* li,int mat)
{
    if(li==NULL) return 0; // Verifica se a lista existe
    if((*li)==NULL) return 0;// Verifica se ela esta vazia

    Elem* no;
    no=(*li);

    while(no->prox!=NULL&&no->dados.matricula!=mat) // Percorro a lista até chegar ao item que tem a matricula igual mat
        no = no->prox;

    if(no==NULL) return 0;

    if(no->ant==NULL) // Caso seja o primeiro item da lista
        *li = no->prox; // Apontamos para o proximo (NULL);

    else
        no->ant->prox = no->prox; // Fazemos o proximo do anterior apontar para o proximo do item escolhido

    if(no->prox!=NULL) // Caso o proximo não seja nulo
        no->prox->ant = no->ant; // Fazemos o anterior do proximo apontar para o proximo do excluido

    free(no); // Liberamos o elemento
    return 1; // Sinalizamos o sucesso da exclusão
}

/**
Função para consultarmos um elemento da lista baseado na sua posição
Parametros:
Lista* li:Ponteiro para o endereço do começo da lista
int pos: posicao do elemento a ser consultado
Aluno* li: Endereço aonde vamos guardar as informações do elemento acessado
Retorna 0 caso falhe em acessar o elemento
Retorna 1 caso tenha sucesso em acessar o elemento
*/
int consultaListaPos(Lista*li,int pos,Aluno* al)
{
    if(li==NULL) return 0; // Verifica se a lista existe
    if((*li)==NULL||pos<=0) return 0;// Verifica se ela esta vazia

    Elem* no;
    no=(*li); // Acessa o começo da lista
    int i = 1;
    while(no!=NULL&&i<pos) // Percorro a lista até chegar ao item na posicao pos;
    {
        i++;
        no = no->prox;
    }
    if(no==NULL) return 0;// Não achamos o item na posicao
    else
    {
        *al = no->dados;
        return 1;
    }
}

/**
Função para consultarmos um elemento da lista baseado na sua matricula
Parametros:
Lista* li:Ponteiro para o endereço do começo da lista
int mat: matricula do elemento a ser consultado
Aluno* li: Endereço aonde vamos guardar as informações do elemento acessado
Retorna 0 caso falhe em acessar o elemento
Retorna 1 caso tenha sucesso em acessar o elemento
*/

int consultaListaMat(Lista*li,int mat,Aluno* al)
{
    if(li==NULL) return 0; // Verifica se a lista existe
    if((*li)==NULL) return 0;// Verifica se ela esta vazia

    Elem* no;
    no=(*li);

    while(no!=NULL&&no->dados.matricula!=mat) // Percorro a lista até chegar ao item que tem a matricula igual mat
        no = no->prox;

    if(no==NULL) return 0;
    else
    {
        *al = no->dados;
        return 1;
    }
}
