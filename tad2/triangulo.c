#include "triangulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculaArea(Ponto a,Ponto b,Ponto c){

    double vert1,vert2,vert3,area=0;

     vert1=a->v[0]*(b->v[1]-c->v[1]);
     vert2=b->v[0]*(c->v[1]-a->v[1]);
     vert3=c->v[0]*(a->v[1]-b->v[1]);
    
    area= (0.5)*(vert1+vert2+vert3);
    return area;

}
int verificaTriangulo(double area){
    //Verificando se os pontos são colineares
    if(area==0)
        return 1;
    return 0;
}