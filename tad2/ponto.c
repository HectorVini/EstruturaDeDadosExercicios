#include "ponto.h"
#include <math.h>
#include <stdlib.h>




Ponto cria(double ax,double ay){
    Ponto p =(Ponto)malloc(sizeof(struct TPonto));
    p->v[0]=ax;
    p->v[1]=ay;
    return p;

}

void translada(Ponto ponto,double aumento){
    ponto->v[0]+=aumento;
    ponto->v[1]+=aumento;
}

double getX(Ponto ponto){
    return ponto->v[0];
}
double getY(Ponto ponto){
    return ponto->v[1];
}
void setX(Ponto ponto,double ax){
    ponto->v[0]=ax;
}
void setY(Ponto ponto,double ay){
    ponto->v[1]=ay;
}
void destroi(Ponto p){
    free(p);
    //realloc(p,0);
}