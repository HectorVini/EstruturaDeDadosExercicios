/*Escreva um programa que leia um número inteiro n, correspondente ao tamanho de um vetor. Em
seguida, aloque dinamicamente um vetor de n posições e preencha-o com números inteiros fornecidos
pelo usuário. O programa deve então remover todas as ocorrências de valores repetidos, de modo que
cada número apareça apenas uma vez. Para isso, reorganize o vetor e use a função realloc para
reduzir seu tamanho ao mínimo necessário. Por fim, exiba o vetor resultante, contendo apenas os
elementos únicos.*/

#include <stdio.h>
#include <stdlib.h>


//Reajusta o tamanho do vetor em -1 a cada chamada;
int reduzVetor(int *v,int *tamanho){
    int *vAux;
    (*tamanho)--;
    vAux=(int*)realloc(v,(*tamanho)*sizeof(int));
    if(vAux)//if(vAux!=NULL)
        return *vAux;
   
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
            if(!reduzVetor(v,tam)){
                return 0;
            }
            return *v;
            
        }
        else
            indice++;
    }
}

/*Avalia a possibiliade de ocorrência de valores repetidos.Chama a função 
de remover elemento*/
void vetorCheck(int *v,int *tamanho){
    int i=0,j;
    while(i<*tamanho){
        j=i+1;
        while(j<*tamanho){
            //Verificando duplicata
            if(v[i]==v[j]){
                if(!removeElemento(v,tamanho,&j))
                    break;
            }
            else
                j++; //Incrementa quando não acha valor duplicado
        }
        i++;
    }
}

int main(){
    int *vetor, n;
    printf("Informe o tamanho n do vetor:");
    scanf("%d",&n);
    vetor=(int*)malloc(sizeof(int)*n);
    if(vetor){
        printf("\n---------\n");
        printf("Informe os valores para checagem: \n");
        for(int i=0;i<n;i++){
            scanf("%d",&vetor[i]);
        }
        vetorCheck(vetor,&n);
        printf("Vetor com ou sem alteracoes sendo impresso...\n\n");
        //Exibindo o vetor
        for(int i=0;i<n;i++){
            printf(" %d ",vetor[i]);
        }
        printf("\n\n");
        //Liberando o vetor
        free(vetor);
    }
    else
        printf("Erro de alocacao");
    return 0;
}