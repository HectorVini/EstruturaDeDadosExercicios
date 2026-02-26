
//Implemente o método de ordenação as seleção direta de forma recursiva.
#include <stdio.h>

#define TAM 5

int ehMenor(int *v,int indice,int j,int tamanho){
    if(tamanho==1)
        return indice;
    else
        if(v[j]<=v[indice])
            indice=j;
        return ehMenor(v,indice,j+1,tamanho-1);
}

void selectionSortRec(int *v,int inicio, int fim){
    int troca;
    if(inicio<=fim-1){
        int menor = ehMenor(v,inicio,inicio,fim);
        if(inicio!=menor){ 
            troca=v[inicio];
            v[inicio]=v[menor];
            v[menor]=troca;
        }
        selectionSortRec(v,inicio+1,fim);
    }
}

int main(){
    int vet[]={5,1,1,9,8,2};
    int me,i=0;

    int tamanho = sizeof(vet) / sizeof(vet[0]);
    printf("\nAntes da inversão %d\n", i);
    for(int i=0;i<tamanho;i++)
        printf(" %d ",vet[i]);
    selectionSortRec(vet,0,tamanho-1);
    printf("\nApós a função\n");
    for(int i=0;i<tamanho;i++)
        printf(" %d ",vet[i]);
}
