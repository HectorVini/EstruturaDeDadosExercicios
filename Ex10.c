#include <stdio.h>
/*10) Localize o(s) erro(s) na seguinte função recursiva e explique como
corrigi-lo(s). Essa função deve calcular a soma dos valores de 0 a n.*/

int soma(const int n)
{
    if (n == 0)
        return 0;

    else
        /*Erro identificado; o valor dentro da função não estava
        sendo decrementado, fazendo com que ela fosse chamada infinitas 
        vezes sem atingir a condição de parada*/
        return n + soma(n-1);
                   //parte corrigida
}

int main(){
    printf("O número de 0 a %d é igual a = %d",10,soma(10));
}