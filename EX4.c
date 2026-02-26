#include <stdio.h>
#include <stdlib.h>

#define NP 10 // Constante de aumento do vetor

// Função para aumentar o vetor
int aumentaVetor(int **v, int tamanho, int acrescimo) {
    int *vAux;

    // Aloca memória para o vetor aumentado
    vAux = (int *)malloc(sizeof(int) * (tamanho + acrescimo));
    if (vAux) { // Verifica se a alocação foi bem-sucedida
        // Copiar os elementos do vetor original para o novo
        for (int i = 0; i < tamanho; i++)
            vAux[i] = (*v)[i];
        free(*v); // Libera a memória antiga
        *v = vAux; // Atualiza o ponteiro original para o novo vetor
        return 1;  // Retorna sucesso
    }
    return 0; // Retorna falha
}

int main() {
    int i = 0, *vetor = NULL, tam = NP, sair, k;

    // Inicializa o vetor
    vetor = (int *)malloc(sizeof(int) * tam);
    if (vetor) { // Verifica se a alocação foi bem-sucedida
        do {
            // Leitura de um número inteiro
            printf("Forneça um número inteiro: ");
            scanf("%d", &vetor[i]);
            i++;

            // Verifica se o vetor está cheio
            if (i == tam) {
                printf("\nVetor cheio. Aumentando tamanho...\n");
                if (!aumentaVetor(&vetor, tam, NP)) {
                    printf("\nErro ao aumentar o tamanho do vetor!\n");
                    break;
                } else {
                    tam += NP; // Atualiza o tamanho do vetor
                    printf("Tamanho do vetor aumentado para %d\n", tam);
                }
            }

            // Pergunta ao usuário se deseja sair
            printf("\nDeseja sair? 1-Sim  2-Não: ");
            scanf("%d", &sair);
        } while (sair != 1);

        // Exibe os elementos do vetor
        printf("\nElementos do vetor:\n");
        for (k = 0; k < i; k++)
            printf("%d ", vetor[k]);

        // Libera a memória do vetor
        free(vetor);
    } else {
        printf("\nErro na alocação de memória!\n");
    }

    return 0;
}
