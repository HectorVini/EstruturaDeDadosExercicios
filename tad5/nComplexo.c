#include "nComplexo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TNComplexo{
    double x;//Campo real
    double y;//Campo imaginário
};

//Cria os campos de valores real e imaginário.
NComplexo criaNumero(double R,double Im){
    NComplexo p=(NComplexo)malloc(sizeof(struct TNComplexo));
    if(!p)
        return NULL;
    p->x=R;
    p->y=Im;
}

//Libera a alocação, portanto destroi os valores
void destroi(NComplexo num) {free(num);}

//setters
int setNumeroR(NComplexo p,double x){
    if(!p)
        return 0;
    p->x=x;
    return 1;
}
int setNumerIm(NComplexo p,double y){
    if(!p)
        return 0;
    p->y=y;
    return 1;
}

//getters
double getNumeroR(NComplexo pR){
    if(!pR)
        return 0;
    return pR->x;
}
double getNumeroR(NComplexo pIm){
    if(!pIm)
        return 0;
    return pIm->y;
}

// Soma: (a + bi) + (c + di) = (a + c) + (b + d)i
NComplexo somarN(NComplexo p1,NComplexo p2){
    if(!p1 || !p2)
        return NULL;
    
    double real = (p1->x) + (p2->x);
    double imag = (p1->y) + (p2->y);

    return criaNumero(real,imag);
}
// Subtração: (a + bi) - (c + di) = (a - c) + (b - d)
NComplexo subtrairN(NComplexo p1,NComplexo p2){
    if(!p1 || !p2)
        return NULL;
    
    double real = (p1->x) - (p2->x);
    double imag = (p1->y) - (p2->y);

    return criaNumero(real,imag);
}
// Multiplicação: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
NComplexo multiplicaN(NComplexo p1,NComplexo p2){
    if(!p1 || !p2)
        return NULL;
    
    double real = (p1->x * p2->x) - (p1->y * p2->y);
    double imag = (p1->x * p2->y) + (p1->y + p2->x);

    return criaNumero(real,imag);
}
// Divisão: (a + bi) / (c + di) = [(ac + bd) + (bc - ad)i] / (c² + d²)
NComplexo dividirN(NComplexo p1, NComplexo p2){
    if(!p1 || !p2)
        return NULL;

    double denominador;
    denominador = (p2->x*p2->x)*(p2->y*p2->y);
    if(denominador==0){
        printf("\nNao existe divisao por 0");
        return NULL;
    }

    double real = (p1->x * p2->x) + (p1->y * p2->y)/denominador;
    double imag = (p2->y * p1->x) - (p2->x * p1->y)/denominador;

    return criaNumero(real,imag);
    
}