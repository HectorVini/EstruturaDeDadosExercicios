#include <stdio.h>
#include <stdlib.h>

#define NP 3 // Constante de aumento do vetor


int aumentaVetorRealloc(int *v,int *tamanho){
   int *vAux;
   vAux=(int*)realloc(v,(*tamanho)*sizeof(int));
   if(vAux){//if(vAux!=NULL)
      //*tamanho = *tamanho + acrescimo;
      //v=vAux;
      return 1;
   }
   return 0;
}

int main(){
   int *vetor,tam=NP,i=0,sair,k;
   vetor= (int*)malloc(sizeof(int)*tam);
   if(vetor){
      do{
         printf("Forneça um número inteiro:");
         scanf("%d",&vetor[i]);
         i++;
          // Verifica se o vetor está cheio
            if (i == tam) {
                printf("\nVetor cheio. Aumentando tamanho...\n");
                if (!aumentaVetorRealloc(vetor, &tam)) {
                    printf("\nErro ao aumentar o tamanho do vetor!\n");
                    break;
                } else {
                    tam += NP; // Atualiza o tamanho do vetor
                    printf("Tamanho do vetor aumentado para %d\n", tam);
                }
            }
         printf("\nDesja sair? 1-Sim  2-Não:");
         scanf("%d",&sair);
      }while(sair!=1);
      printf("\nElementos do Vetor\n");
      for(k=0;k<i;k++)
         printf("\n%d",vetor[k]);
      free(vetor);
   }
   else
      printf("\nErro na Alocação!!!!");
   return 0;
}