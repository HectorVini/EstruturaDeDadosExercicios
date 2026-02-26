/*Implemente uma função, recursiva, para calcular a soma dos elementos
de uma matriz ixj de inteiros.*/

#include <stdio.h>
#include <stdlib.h>

int ** aloca(int nl,int nc){
    int **m,i;
    m=(int**)malloc(sizeof(int*)*nl);
    for(i=0;i<nl;i++)
       m[i]=(int*)malloc(sizeof(int)*nc);
    
    return m;   
}

void desaloca(int **m,int nl,int nc){
    int i;
    for(i=0;i<nl;i++)
       free(m[i]);
    
    free(m);
}

int somaMatrizRec(int **mat,int linha,int coluna,int nl,int nc){
    if(linha==nl)    
       return 0;
    else
        if(coluna<nc)
           return mat[linha][coluna]+somaMatrizRec(mat,linha,coluna+1,nl,nc);
        else
            return somaMatrizRec(mat,linha+1,0,nl,nc);
}


int somaMatriz(int **mat,int nl,int nc){
    return somaMatrizRec(mat,0,0,nl,nc);
}

int main(){
    int **matriz;
    matriz=aloca(2,2);
    matriz[0][0]=10;
    matriz[0][1]=20;
    matriz[1][0]=1;
    matriz[1][1]=4;
    printf("\nSoma = %d\n",somaMatriz(matriz,2,2));
    desaloca(matriz,2,2);
    return 0;
}