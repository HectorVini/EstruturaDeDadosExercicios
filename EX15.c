/*Escreva um programa que aloque dinamicamente um vetor de n inteiros. Após o preenchimento do
vetor, permita que o usuário escolha uma posição para remover um elemento.
Após a remoção, reorganize os elementos para que não fiquem “buracos” no vetor, e utilize realloc
para ajustar o tamanho da área de memória.Exiba o vetor resultante e, ao final, libere a memória.*/

#define TAM 7

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Reajusta o tamanho do vetor em -1 a cada chamada;
Retira a última posição onde o elemento foi 
transferido*/
int manipulaVetor(int *v,int *tamanho){
   int *vAux;
   (*tamanho)--;
   vAux=(int*)realloc(v,(*tamanho)*sizeof(int));
   if(vAux)//if(vAux!=NULL)
      return 1;
   
   return 0;
}

/*Função remove o elemento localizando sua posição e movendo para a última.
Obs: Chamará outra função para reajustar tamanho*/
int removeElemento(int *v,int *tam,int *pos){
    int indice=0,aux;
    for(int i=0;i<*tam;i++){
        if(indice==(*pos)){                         
            for(int j=indice;j<*tam-1;j++){
                //Passo 1-Levando o elemento para a última posição
                aux=v[j+1];
                v[j+1]=v[j];
                v[j]=aux; 
            }
            //Passo 2- Chamando a função         
            if(!manipulaVetor(v,tam)){
                return 0;
            }
            return *v;
            
        }
        else
            indice++;
    }
}

int main(){
    int *vetor,capacidade=TAM,i=0,pos;
    vetor = (int*)malloc(sizeof(int)*capacidade);
    if(vetor){
        while(1){ 
            //Informando os números
            printf("%d° posicao =",i);
            scanf("%d",&vetor[i]);
            i++;
            if(i>=capacidade){
                printf("\n");
                //Vetor antes da remoção
                for(int k=0;k<capacidade;k++)
                    printf("%d\n",vetor[k]);
                printf("Qual elemento pela posicao deseja excluir?\n");
                scanf("%d",&pos);
                if(pos>capacidade-1)
                    printf("posicao invalida!!!\n");
                else
                    if(!removeElemento(vetor,&capacidade,&pos)){
                        printf("\nOperacao nao foi possivel\n");
                    }
                    else{
                        printf("\n");
                        //Vetor após a remoção
                        for(int l=0;l<capacidade;l++){
                            printf(" %d ",vetor[l]);
                        }
                        //Liberando o vetor
                        free(vetor);
                    }
                break;
            }  
        }
    }
    else
        printf("Erro ao alocar memoria");
    return 0;
}