
/*Implemente a pesquisa binária de forma recursiva. Considere um vetor de
inteiros como conjunto de busca. */
#define TM 9
#include <stdio.h>

int buscaBinRec(int *vet,int inicio,int fim,int* busca){
    if(fim>=inicio){
        int meio=(inicio+fim)/2;
        //Elemento mais a direita
        if(*busca>=vet[meio]){
            
            if(*busca==vet[meio])
                return 1;
            return buscaBinRec(vet,meio+1,fim,busca);
        }
        //Elemento mais a esquerda
        else if(*busca<=vet[meio]){
            if(*busca==vet[meio])
                return 1;
            return buscaBinRec(vet,inicio,meio-1,busca);
        }
    }
    //Elemento não está no vetor
    return -1;
 
}


int main(){
    //Considerando um vetor já ordenado
    int v[TM]={1,2,3,5,6,15,25,99,200},achou,num;
    printf("\nQual numero desejas procurar?");
    scanf("%d",&num);
    achou=buscaBinRec(v,0,TM-1,&num);
    if(achou==1)
        printf("\n\tVALOR ENCONTRADO!!!");
    else if(achou!=1)
        printf("\n\tVALOR INDISPONÍVEL!!");

    return 0;
}