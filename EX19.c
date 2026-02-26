/*Faça um programa que leia um inteiro n e aloque dinamicamente um vetor de n elementos.
Após o preenchimento com valores fornecidos pelo usuário, leia também um inteiro k.
O programa deve rotacionar o vetor para a direita em k posições, de forma circular (os últimos
elementos “voltam” para o início do vetor). O desafio está em realizar a rotação sem criar uma cópia
auxiliar completa do vetor. Exiba o vetor final após a rotação e libere a memória utilizada.*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Informe os valores para:\n");
    printf("n:");
    scanf("%d",&n);
    printf("Leia um valor para k:\n");
    int k;
    printf("n:");
    scanf("%d",&k);
    int* vetor=(int*)malloc(n*sizeof(int));
    if(!vetor)
        return 0;

    //Inserindo os valores em Vetor
    printf("Inserindo os valores em Vetor:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&vetor[i]);
    }

    printf("Imprimindo o vetor :\n");
    for(int i=0;i<n;i++){
        printf("%d\n",vetor[i]);
    }
    //O vetor rotaciona K vezes
    printf("Imprimindo o vetor %d vezes rotacionado:\n",k);
    while(k!=0){
        int numAux=vetor[n-1];              
        for(int i=n;i>0;i--){                 
            vetor[i]=vetor[i-1];
        }
        vetor[0]=numAux;
        k--;
    }
    
    for(int i=0;i<n;i++){
        printf("%d\n",vetor[i]);
    }

    free(vetor);
    return 1;
}