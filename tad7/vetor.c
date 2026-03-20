#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

typedef struct {
    int *elementos;   // Ponteiro para o vetor de elementos
    int n;            // Número de elementos no conjunto
    int capacidade;   // Tamanho atual do vetor
} Conjunto;

// a) Criar um conjunto vazio
Conjunto* criarConjunto() {
    Conjunto *c = (Conjunto*)malloc(sizeof(Conjunto));
    if (c == NULL) 
      return NULL; // Falha na alocação
    c->elementos = (int*)malloc(3 * sizeof(int));
    if (c->elementos == NULL) {
        free(c);
        return NULL; // Falha na alocação
    }
    c->n = 0;
    c->capacidade = 3;
    return c;
}

// b) Destruir o conjunto
void destruirConjunto(Conjunto *c) {
    if (c != NULL) {
        free(c->elementos);
        free(c);
    }
}

// c) Inserir um elemento no conjunto, retornando 1 se possível e 0 senão
int inserirElemento(Conjunto *c, int elemento) {
    if (c == NULL) return 0;

    // Verificar se o elemento já está no conjunto
    for (int i = 0; i < c->n; i++) {
        if (c->elementos[i] == elemento) {
            return 0; // Elemento já existe
        }
    }

    // Verificar se é necessário aumentar a capacidade do vetor
    if (c->n == c->capacidade) {
        int novaCapacidade = c->capacidade + 3;
        int *novoArray = (int*)realloc(c->elementos, novaCapacidade * sizeof(int));
        if (novoArray == NULL) return 0; // Falha ao realocar memória
        c->elementos = novoArray;
        c->capacidade = novaCapacidade;
    }

    // Inserir o elemento no conjunto
    c->elementos[c->n] = elemento;
    c->n++;
    return 1;
}

// Função para exibir o conjunto (apenas para debug)
void exibirConjunto(Conjunto *c) {
    if (c == NULL) return;
    printf("{ ");
    for (int i = 0; i < c->n; i++) {
        printf("%d ", c->elementos[i]);
    }
    printf("}\n");
}