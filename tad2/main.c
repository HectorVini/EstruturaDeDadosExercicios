#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"
#include "triangulo.h"

int main(){
    Ponto coord1,coord2,coord3;
    double areaTriangulo;
    int ehTriangulo;
    coord1= cria(5,1);
    coord2= cria(10,2);
    coord3= cria(3,4);
    areaTriangulo = calculaArea(coord1,coord2,coord3);
    ehTriangulo= verificaTriangulo(areaTriangulo);
    if(ehTriangulo!=0){
         printf("\nOs pontos são colineares e não formam um triângulo\n");
    }
    else if(ehTriangulo==0){
        printf("\n\tÁrea do triangulo após verificação é de = %.3f\n\n",areaTriangulo);
    }
    destroi(coord1);
    destroi(coord2);
    destroi(coord3);
}
