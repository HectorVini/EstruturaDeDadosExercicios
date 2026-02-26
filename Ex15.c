#include <stdio.h>

void calculaMaiorMenor(int *v,int tamanho,int *maior,int *menor){
    if(tamanho==1){
        *maior=v[0];
        *menor=v[0];
    }
    else{
         calculaMaiorMenor(v,tamanho-1,maior,menor);      
        //posição corente, ou seja, a ser avaliada é a tamanho-1
        if(v[tamanho-1]>*maior)
            *maior=v[tamanho-1];
        else
           if(v[tamanho-1]<*menor)
              *menor=v[tamanho-1];
        
    }
   
}

int main(){
    int vetor[5]={10,0,5,30,2},maiorValor,menorValor;
    
    
    calculaMaiorMenor(vetor,5,&maiorValor,&menorValor);
    printf("\nMaior = %d  e Menor = %d\n",maiorValor,menorValor);
    return 0;
}