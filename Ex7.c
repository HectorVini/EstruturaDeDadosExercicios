/*7) Faça uma função recursiva que calcule o valor da série S descrita a seguir
para um valor n >0.
S = 1 + 1/2! + 1/3! + ... 1/n!*/
#include <stdio.h>


int fatorial(int fat){
    if(fat>1)
        return fat * fatorial(fat-1);
    
}

float valorSRec(int n){
    if (n == 0) {
        return 0; // Caso base: quando n = 0, a soma é 0
    } else {
        // Soma o termo atual (1/n!) e chama a função para o próximo termo (n-1)
        return (1.0 / fatorial(n)) + valorSRec(n - 1);
    }
}
int main(){
                              //Parâmetro inicia-se com 1
    printf("%.4f",valorSRec(5));
    return 0;
}