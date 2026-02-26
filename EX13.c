/*Faça um programa que permita ao usuário cadastrar vários nomes de pessoas.
Cada nome deve ser armazenado em uma área de memória alocada dinamicamente, de forma que o
espaço utilizado seja exatamente o necessário para guardar o nome. Além disso, mantenha todos os
ponteiros para os nomes em um vetor dinâmico de ponteiros, que também deve crescer conforme novos
nomes forem adicionados. Ao término do cadastro (por exemplo, quando o usuário digitar a palavra
"fim"), exiba todos os nomes cadastrados e, em seguida, libere a memória utilizada.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int realocaEspaco(char ***v,int *tam, int acres){
    char **vAux;
    vAux=(char**)realloc(*v,acres*sizeof(char*));
    if(!v)
        return 0; //Falhou a alocação
    *v=vAux;
    *tam=acres;
    return 1;

}

void desalocaEspaco(char **v,int count){
    for(int i=0;i<count;i++)
        free(v[i]);
    free(v);
}

int main(){
    char **listaNome=NULL,nome[100];
    int tam,//tamanho de cada nome
    pos=0;//Indice dentro do loop
    int capacidade= 2; //Capacidade inicial de um vetor
    listaNome = (char**)malloc(capacidade * sizeof(char*));
    if (listaNome == NULL) {
        printf("Erro na alocação inicial!\n");
        return 1;
    }
    //Adiciona mais capacidade ao vetor de ponteiros
    int acrescimo=0;
    printf("1-Insira nomes, digite \"fim\" para sair\n");
    while(nome){
        printf("Insira um nome: ");
        fgets(nome,sizeof(nome),stdin);
        //Verificando se o usuário quer sair do programa
        if(strcmp(nome,"fim\n")==0)
            break;
            //Tamanho adequado da string fornecida
        //Remove o \n se existir(opcional)
        nome[strcspn(nome, "\n")] = ' ';    
        //Verifica se precisa expandir o vetor
        if(pos>=capacidade){
            acrescimo=tam*2;
            if(!realocaEspaco(&listaNome,&tam,acrescimo))
            break;
        }
        tam=strlen(nome)+1;
        listaNome[pos]=(char*)malloc(sizeof(char)*tam);
        if(!listaNome[pos]){
            printf("Erro de alocacao");
            break;
        }
        strcpy(listaNome[pos],nome);
        pos++;
        
    }
    printf("Programa encerrado\n");
    //Exibe e libera memória
    for(int i=0;i<pos;i++){ 
        printf("%s",listaNome[i]);
    }
    //Libera memoria
    desalocaEspaco(listaNome,pos);
    return 0;
}