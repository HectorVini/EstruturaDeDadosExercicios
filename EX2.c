/*2) Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos e passe esse
vetor para uma função que vai ler os elementos desse vetor. Depois, no programa principal, o vetor
preenchido deve ser impresso. Além disso, antes de finalizar o programa, deve-se liberar a área de
memória alocada.*/

#include <stdio.h>
#include <stdlib.h>

//Lendo os Elementos
int lerElemento(int valor){
    scanf("%d",&valor);
    return valor;
}

int main()
{
    int n,*vetor,v;
    printf("Informe o valor n para n elementos");
    scanf("%d",&n);
    //Criando o vetor
    vetor= (int*)malloc(sizeof(int)*n);
    printf("\n\nLendo elementos:\n");
    for(int i=0; i<n;i++)
        vetor[i] = lerElemento(v);

    //Imprimindo o vetor já preenchido;
    printf("\n\nValores do Vetor = ");
    for(int i=0; i<n;i++)
        printf(" %d ",vetor[i]);

    free(vetor);
    
    return 0;
}
