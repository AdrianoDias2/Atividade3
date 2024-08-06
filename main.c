#include <stdio.h>
#include "lista_encadeada.h"

int main() {
    ListaEncadeada *lista = criar_lista();

    
    inserir_elemento(lista, 1, 10); 
    inserir_elemento(lista, 2, 20); 
    inserir_elemento(lista, 3, 30); 

    printf("Elemento na posicao 2: %d\n", obter_elemento(lista, 2));

    modificar_elemento(lista, 2, 25);
    printf("Elemento na posicao 2 apos modificacao: %d\n", obter_elemento(lista, 2));

    retirar_elemento(lista, 2);
    printf("Elemento na posicao 2 apos remocao: %d\n", obter_elemento(lista, 2));

    printf("Elementos da lista: ");
    imprimir_lista(lista);

    liberar_lista(lista);
    return 0;
}
