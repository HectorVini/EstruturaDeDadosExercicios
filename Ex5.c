/*Faça uma função recursiva soma que, dados dois números inteiros não
negativos a e b, retorne a + b, usando apenas as operações mais simples de
incrementar 1.*/
#include <stdio.h>

int somaAeB(int a, int b){
    if(a<0 || b<0)
        return -1;
    else
        if(b>0)
            return somaAeB(a+1,b-1);
        return a;
}

int main(){
    int valor;
    valor=somaAeB(12,1);
    printf("Resultado A+B é de = %d\n\n",valor);
    return 0;
}