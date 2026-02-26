/*Faça uma função recursiva para verificar se uma expressão (string) de
parênteses é bem formada.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ehValido(char *s,int i, int cont){
    //Caso base, final da expressão
    if(s[i]=='\0')
        return cont==0;
    // Se encontramos um parêntese aberto, incrementamos o contador
    if(s[i]=='(')
        return ehValido(s,i+1,cont+1);
    //caso contrário, decrementamos
    else if(s[i]==')'){
        // Se o contador já é zero, temos um parêntese fechado sem aberto correspondente
        if(cont==0)
            return 0;
        return ehValido(s,i+1,cont-1);
    }
    //outros caracteres que não são parênteses
    else
        return ehValido(s,i+1,cont);

}

int main(){
    char expr[]="(32(4)5)";
    int verifica= ehValido(expr,0,0);
    if(verifica)
        printf("Expressao eh valida!!!!\n\n");
    else
        printf("Expressao INCORRETA!!\n\n");
    return 0;
    
}