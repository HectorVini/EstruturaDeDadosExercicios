/*Escreva um programa que leia n números inteiros e os armazene em um vetor alocado dinamicamente.
Em seguida, crie um novo vetor comprimido, armazenando cada número junto com a quantidade de
vezes consecutivas em que ele aparece. Exemplo:
Entrada → 5 5 5 2 2 7 7 7 7
Saída → [5,3, 2,2, 7,4]
O vetor comprimido deve crescer dinamicamente usando realloc, de acordo com os dados
processados. Exiba o vetor comprimido e libere a memória ao final.*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;
    printf("Informe o tamanho do vetor:\n");
    scanf("%d", &tamanho);
    
    // Alocando o vetor de entrada
    int* vetor = (int*)malloc(tamanho * sizeof(int));
    if(!vetor) {
        printf("Erro na alocação!\n");
        return 0;
    }

    // Inserindo os valores
    printf("Inserindo os valores:\n");
    for(int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
    
    // Vetor comprimido (inicia vazio)
    int* vetComp = NULL;
    int tamComp = 0;
    
    if(tamanho > 0) {
        int valorAtual = vetor[0];
        int contador = 1;
        
        for(int i=1;i <=tamanho;i++) {
            // Se for o último elemento ou se o próximo for diferente
            if(i == tamanho || vetor[i] != valorAtual) {
                // Adiciona o valor atual e sua frequência ao vetor comprimido
                int* temp = (int*)realloc(vetComp, (tamComp + 2) * sizeof(int));
                if(!temp) {
                    printf("Falha ao realocar memória!\n");
                    free(vetComp);
                    free(vetor);
                    return 0;
                }
                vetComp = temp;
                
                vetComp[tamComp] = valorAtual;
                vetComp[tamComp + 1] = contador;
                tamComp += 2;
                
                // Prepara para o próximo valor (se não for o último)
                if(i < tamanho) {
                    valorAtual = vetor[i];
                    contador = 1;
                }
            } else {
                // Se for igual, incrementa contador
                contador++;
            }
        }
    }
    
    // Exibição
    printf("\nEntrada → ");
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    
    printf("\nSaída → [");
    for(int i = 0; i < tamComp; i += 2) {
        printf("%d,%d", vetComp[i], vetComp[i + 1]);
        if(i < tamComp - 2) {
            printf(", ");
        }
    }
    printf("]\n");
    
    // Liberação de memória
    free(vetComp);
    free(vetor);
    
    return 1;
}