#include "lista_encadeada.h"
#include <stdio.h>
#include <stdlib.h>

// Função para criar uma lista vazia
ListaEncadeada* criar_lista() {
    ListaEncadeada *lista = (ListaEncadeada*)malloc(sizeof(ListaEncadeada));
    lista->cabeca = NULL;
    lista->tamanho = 0;
    return lista;
}

// Função para verificar se a lista está vazia
int esta_vazia(ListaEncadeada *lista) {
    return lista->tamanho == 0;
}

// Função para obter o tamanho da lista
int obter_tamanho(ListaEncadeada *lista) {
    return lista->tamanho;
}

// Função para obter o valor de um elemento em uma determinada posição
int obter_elemento(ListaEncadeada *lista, int posicao) {
    if (posicao < 1 || posicao > lista->tamanho) {
        printf("posicao invalida.\n");
        exit(1);
    }
    No *atual = lista->cabeca;
    for (int i = 1; i < posicao; i++) {
        atual = atual->proximo;
    }
    return atual->valor;
}

// Função para modificar o valor de um elemento em uma determinada posição
void modificar_elemento(ListaEncadeada *lista, int posicao, int valor) {
    if (posicao < 1 || posicao > lista->tamanho) {
        printf("posicao invalida.\n");
        exit(1);
    }
    No *atual = lista->cabeca;
    for (int i = 1; i < posicao; i++) {
        atual = atual->proximo;
    }
    atual->valor = valor;
}

// Função para inserir um elemento em uma determinada posição
void inserir_elemento(ListaEncadeada *lista, int posicao, int valor) {
    if (posicao < 1 || posicao > lista->tamanho + 1) {
        printf("posicao invalida.\n");
        exit(1);
    }
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    if (posicao == 1) {
        novo->proximo = lista->cabeca;
        lista->cabeca = novo;
    } else {
        No *atual = lista->cabeca;
        for (int i = 1; i < posicao - 1; i++) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
    lista->tamanho++;
}

// Função para retirar um elemento de uma determinada posição
void retirar_elemento(ListaEncadeada *lista, int posicao) {
    if (posicao < 1 || posicao > lista->tamanho) {
        printf("posicao invalida.\n");
        exit(1);
    }
    No *remover;
    if (posicao == 1) {
        remover = lista->cabeca;
        lista->cabeca = lista->cabeca->proximo;
    } else {
        No *atual = lista->cabeca;
        for (int i = 1; i < posicao - 1; i++) {
            atual = atual->proximo;
        }
        remover = atual->proximo;
        atual->proximo = remover->proximo;
    }
    free(remover);
    lista->tamanho--;
}

// Função para imprimir os elementos da lista
void imprimir_lista(ListaEncadeada *lista) {
    No *atual = lista->cabeca;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

// Função para liberar a memória alocada pela lista
void liberar_lista(ListaEncadeada *lista) {
    No *atual = lista->cabeca;
    while (atual != NULL) {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(lista);
}
