#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NC 3
#define NL 10

void desalocaMatriz(int **mat,int nLinhas, int nColunas){
    int i;
    for( i=0;i<nLinhas;i++){
        free(mat[i]);
    }
    mat[i];
}


int** alocaMatriz(int nLinhas, int nColunas){
    int **mat= (int**)malloc(sizeof(int*)*nLinhas);
    if(mat){//mat!=NULL
        for(int i=0;i<nLinhas;i++){ 
            mat[i]=(int*)malloc(sizeof(int)*nColunas);
        }
        return mat;
    }
    return 0;
}

int main(){
    int **matriz,nl=NL,nc=NC;
    //Alocando a matriz
    matriz=alocaMatriz(nl,nc);
    //Informando dados para a a matriz já alocada
    for(nl=0;nl<NL;nl++){
        for(nc=0;nc<NC;nc++){
            matriz[nl][nc]= rand()%100;
        }
    }
    //Imprimindo a matriz
    for(nl=0;nl<NL;nl++){
        printf("\n");
        for(nc=0;nc<NC;nc++){
            printf(" %d ",matriz[nl][nc]);
        }
    }

}