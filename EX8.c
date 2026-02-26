#include <stdio.h>
#include <stdlib.h>


typedef struct registro{
    char nome[100];
    char data[15];
    char cpf[20];

}TRegistro; 


void imprimePonteiro(TRegistro **info){
    printf("\n\n\tNome = %s",(*info)->nome);
    printf("\tData = %s",(*info)->data);
    printf("\tCPF = %s",(*info)->cpf);
    free(*info);
}

void recebePonteiro (TRegistro **info){ 
    printf("Forneça um nome:");
    fgets((*info)->nome,100,stdin);
    setbuf(stdin,NULL);
    printf("Informe uma data:");
    fgets((*info)->data,15,stdin);
    setbuf(stdin,NULL);
    printf("Digite o cpf:");
    fgets((*info)->cpf,20,stdin);
    setbuf(stdin,NULL);
}

int main(){
    TRegistro *p;
    p=(TRegistro*)malloc(sizeof(TRegistro));
    recebePonteiro(&p);
    imprimePonteiro(&p);
}
