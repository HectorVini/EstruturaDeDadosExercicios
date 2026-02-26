/*Faça um programa que leia um número inteiro n, representando a quantidade de elementos que
serão armazenados. Em seguida, aloque dinamicamente um vetor capaz de armazenar n inteiros.
O programa deve solicitar que o usuário digite os valores um a um, preenchendo todo o vetor. Após
a leitura, exiba todos os elementos armazenados na tela, na mesma ordem em que foram digitados.
Por fim, libere corretamente a memória alocada.*/
#include <stdlib.h>
#include <stdio.h>



int main(){
    int n; //Quantidade n elementos a ser r6armazenada
    printf("Informe a quantidade a ser armazenada: ");
    scanf("%d",&n);

    int *vet,i;
    vet=(int*)malloc(sizeof(int)*n);
    //Lendo o vetor alocado caso for possível
    if(vet!=NULL){
        printf("Forneça os elementos:\n");
        for( i=0;i<n;i++)
            scanf("%d",&vet[i]);
    }
    else
        printf("Alocacao nao foi possivel ser realizada");
    //Exibindo o vetor impresso
    printf("Elementos do vetor\n\n");
    for(i=0;i<n;i++)
        printf("[%d]",vet[i]);
    printf("\n\n");
    free(vet);
    return 0;
}