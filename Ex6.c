/*Faça uma função recursiva para calcular o mdc de dois inteiros positivos.
Sabe-se que:
mdc(x,y) = y se y<=x e x%y igual a zero

mdc(x,y) = mdc(y,x) se x<y
mdc(x,y) = mdc(x, x % y)*/
#include <stdio.h>

int mdc(int x, int y){
    if(x<0 || y<0)
        return -1;
    else if(y<=x && (x%y)==0)
        return y;
    else if(x<y)
        return mdc(y,x);
    return mdc(y,x%y);
}

int main(){
    printf("MDC(30,10) = %d ",mdc(30,10));
    return 0;
}