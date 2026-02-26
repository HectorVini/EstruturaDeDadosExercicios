/*Escreva um programa que leia dois inteiros n e m, que representam os tamanhos de dois vetores
distintos. Aloque dinamicamente o vetor A de tamanho n e o vetor B de tamanho m, preenchendo-os
com valores informados pelo usuário.Em seguida, crie dois novos vetores:
◦ União (U): deve conter todos os elementos de A e B, sem repetição.
◦ Interseção (I): deve conter apenas os elementos que aparecem em ambos os vetores.
Os vetores U e I devem ser realocados dinamicamente com realloc para ocupar exatamente o
espaço necessário. Ao final, exiba os dois vetores resultantes e libere toda a memória.*/
#include <stdio.h>
#include <stdlib.h>



int buscarElemento(int *v,int tam,int el){
    for(int i=0;i<tam;i++){
        if(v[i]==el)
            return 1;
    }
    return 0;
}

int main(){
    int n,m,tamanho;
    printf("Informe os valores para:\n");
    printf("n:");
    scanf("%d",&n);
    printf("m:");
    scanf("%d",&m);
    int *vetA,*vetB,*vetU;
    vetA=(int*)malloc(n*sizeof(int));
    if(!vetA)
        return 0;
    vetB=(int*)malloc(m*sizeof(int));
    if(!vetB)
        return 0;
    
    //Vet U
    tamanho=n;
    //Alocando vet U
    vetU=(int*)malloc(tamanho*sizeof(int));
    if (!vetU) {
        printf("Falha ao realocar memória!\n");
        free(vetA);
        free(vetB);
        return 0;
    }
    //Inserindo os valores em VetA
    printf("Inserindo os valores em VetA:\n");
    for(int i=0;i<tamanho;i++){
        scanf("%d",&vetA[i]);
    }
     //Inserindo os valores em VetB
    printf("Inserindo os valores em VetB:\n");
    for(int i=0;i<m;i++){
        scanf("%d",&vetB[i]);
    }
    //Inserindo A em U
    for(int i=0;i<n;i++){
        vetU[i]=vetA[i];
    }
    //Realocando o vetor União com os elementos de A adicionando B
    for(int i=0;i<m;i++){
        if(!buscarElemento(vetA,tamanho,vetB[i])){ 
            int *temp_vetor = (int *)realloc(vetU, (tamanho+1)* sizeof(int));
            if (temp_vetor == NULL) {
                printf("Falha ao realocar memória!\n");
                free(vetU); // Libera o bloco antigo se realloc falhar
                return 0;
            }
            else
                vetU = temp_vetor;
                vetU[tamanho]=vetB[i];
                tamanho++;
        }
    }
    //Vetor interseção
    int *vetI,tamI=0;
    vetI=(int*)malloc(sizeof(int));
    if(!vetI){
        free(vetA);
        free(vetU);
        free(vetB);
        return 1;
    }
    //Conferindo se um dos vetores possui elemento repetido e atribuindo
    for(int i=0;i<m;i++){
        if(buscarElemento(vetA,n,vetB[i])){
            int *temp = (int *)realloc(vetI, (tamI+1)* sizeof(int));
            if (temp == NULL) {
                printf("Falha ao realocar memória!\n");
                free(vetI); // Libera o bloco antigo se realloc falhar
                return 0;
            }
            else
                vetI = temp;
                vetI[tamI]=vetB[i];
                tamI++;
        }
    }
    
    printf("Imprimindo o vetor inter:\n");
    int cont=tamI;
    if(!vetI[0]){ 
        printf("\nNão há elementos para interseção\n");
    }
    for(int i=0;i<tamI;i++){
        printf("%d\n",vetI[i]);
    }
    printf("Imprimindo o vetor união:\n");
    for(int i=0;i<tamanho;i++){
        printf("%d\n",vetU[i]);
    }

    free(vetU);
    free(vetA);
    free(vetB);
    return 1;
}