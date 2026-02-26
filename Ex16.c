#include <stdio.h>
/*Escreva uma função recursiva que determine quantas vezes um dígito K ocorre
em um número natural N. Por exemplo, o dígito 2 ocorre 3 vezes em 762021192.*/
int digitoKRec(char K,char *num,int i,int occur){
    if(num[i]=='\0')
        return occur;
    else
        if(K==num[i]){
            //Quando o dígito é achado em um N  
            occur++;
            //Retorna um algarismo do N a cada chamada
            return digitoKRec(K,num,i+1,occur);   
        }
        else
            //digito ainda não foi achado
            digitoKRec(K,num,i+1,occur);

}

int main(){
    //Valor passado em string
    char N[]="762021192",k;
    int ocorrencia;
    printf("Informe o dígito desejado para o número %s: ",N);
    scanf("%c",&k);           //algarismo inicial e ocorrência zerada
    ocorrencia=digitoKRec(k,N,0,0);
    printf("O número de vezes que %c aparece em %s é de %d vezes(vez)\n\n",
    k,N,ocorrencia);
    return 0;

}