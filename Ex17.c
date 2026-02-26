#include <stdio.h>
/*A multiplicação de dois números inteiros pode ser feita atravé de somas
sucessivas. Escreva uma função recursiva multiplica(n1,n2) que calcule a
multiplicação de dois inteiros.*/
int multiplica(int n1,int n2){
   
    if(n1==1)
        return n2;
    return n2+multiplica(n1-1,n2);
}

int main(){

    printf("= %d",multiplica(10,32));
    return 0;
}