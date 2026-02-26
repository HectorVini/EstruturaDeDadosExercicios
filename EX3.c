/*3)Faça uma função que receba um valor n e crie dinamicamente um vetor de n elementos e retorne
um ponteiro. Crie uma função que receba um ponteiro para um vetor e um valor n e imprima os n
elementos desse vetor. Construa também uma função que receba um ponteiro para um vetor e
libere esta área de memória. Ao final, crie uma função principal que leia um valor n e chame a
função criada acima. Depois, a função principal deve ler os n elementos desse vetor. Então, a
função principal deve chamar a função de impressão dos n elementos do vetor criado e, finalmente,
liberara memória alocada através da função criada para liberação.*/

#include <stdio.h>
#include <stdlib.h>


void liberaVetor(int *vet,int n){
    free(vet);
}

void imprimaVetor(int *vet, int n){
    for (size_t i = 0; i < n; i++)
        printf(" %d ",vet[i]);
    
}

int* alocaVentor(int n){
    int *v=(int*)malloc(sizeof(int)*n);
    return v;
}

int main()
{
    int*vetor=NULL,n;
    printf("Informe o valor n para n elementos;");
    scanf("%d",&n);
    vetor =alocaVentor(n);
    for(int i=0;i<n;i++){ 
        printf("[%d]",i);
        scanf("%d",&vetor[i]);
    }
    printf("\n\n");
    imprimaVetor(vetor,n);
    liberaVetor(vetor,n);
    
    return 0;
}
