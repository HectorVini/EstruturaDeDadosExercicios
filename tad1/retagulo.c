#include "retagulo.h"
#include <stdio.h>

void init(ret *p, float altura, float largura){
   p->alt = altura;
   p->l = largura;
}
void infoRet(ret p){
   printf("**Informações recebidas do Retângulo**\nAltura: %.2f\nLargura: %.2f",p.alt,p.l);
   printf("\nPerímetro : %.2f\nÁrea: %.2f",getArea(p),getPerimeter(p));
}
float getArea(ret p){
   return p.alt*p.l;
}
float getPerimeter(ret p){
   return 2*(p.alt*p.l);
}
