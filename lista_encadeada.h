#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *cabeca;
    int tamanho;
} ListaEncadeada;

ListaEncadeada* criar_lista();
int esta_vazia(ListaEncadeada *lista);
int obter_tamanho(ListaEncadeada *lista);
int obter_elemento(ListaEncadeada *lista, int posicao);
void modificar_elemento(ListaEncadeada *lista, int posicao, int valor);
void inserir_elemento(ListaEncadeada *lista, int posicao, int valor);
void retirar_elemento(ListaEncadeada *lista, int posicao);
void imprimir_lista(ListaEncadeada *lista);
void liberar_lista(ListaEncadeada *lista);

#endif // LISTA_ENCADEADA_H
