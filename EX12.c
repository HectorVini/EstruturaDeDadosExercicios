/*Implemente um programa que leia dois números inteiros, m e n, representando, respectivamente, o
número de linhas e de colunas de uma matriz. Em seguida, aloque dinamicamente uma matriz de
inteiros com m linhas e n colunas. Solicite que o usuário preencha todos os elementos da matriz. Após o
preenchimento, exiba o conteúdo em formato tabular (semelhante a uma tabela).
Ao final, libere corretamente toda a memória alocada.*/

#include <stdio.h>
#include <stdlib.h>                                       
                                                           
void desalocaMatriz(int **mat,int nLinha){
    for(int i=0;i<nLinha;i++)
        free(mat[i]);
    free(mat);
}

void matrizDinamica(int ***mat,int *m, int *n){
    *mat=(int**)malloc(sizeof(int*)*(*m));
    for (int i = 0; i < *m; i++)
    {
        (*mat)[i]=(int*)malloc(sizeof(int)*(*n));
    }
    
}

int main(){
    int m;//n° de linhas
    int n;//n° de colunas
    int **matriz;
    printf("Insira número de linhas:");
    scanf("%d",&m);
    printf("Insira número de colunas:");
    scanf("%d",&n);
    matrizDinamica(&matriz,&m,&n);
    printf("Inserindo na matriz:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matriz[i][j]);
        }
    }
    printf("Exibindo a matriz:\n\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("  [%d]  ",matriz[i][j]);
        }
        printf("\t\t\n\n");
    }
    desalocaMatriz(matriz,m);
    return 0;
}

