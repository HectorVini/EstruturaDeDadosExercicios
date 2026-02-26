/*Escreva um programa que leia do usuário uma palavra (sem espaços). Após a leitura, aloque
dinamicamente uma área de memória com o tamanho exato necessário para armazenar a palavra,
incluindo o caractere terminador '\0'. Copie o conteúdo da string para essa nova área e exiba a
palavra copiada. Libere a memória ao final.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
         // Declara um array para armazenar o nome
    char nome[100],*vetPalavra; /*Vetor a ser alocado para armazenamento necessário 
                                de uma string*/
    int tam; 
insira_nome: //etiqueta a ser requerida pelo programa
    printf("Digite seu nome: ");
    if (fgets(nome, sizeof(nome), stdin) != NULL) {
        // fgets inclui o \n
        
        //Armazenando o tamanho da string
        tam=strlen(nome);
        //Verificando a existência de espaços
        for(int i=0;i<tam;i++){
            if(nome[i]==' '){
                //Condição caso satisfeita volta para inicio da inserção do usuário
                printf("String fornecida por usuario contem espaço\n");
                goto insira_nome;
            }
        }
        printf("Olá, %s\n", nome);
        vetPalavra=(char*)malloc(sizeof(char)*tam);
        if(vetPalavra!=NULL){
            strcpy(vetPalavra,nome);
            printf("\r%s tem %d letras",vetPalavra,tam);
        }
        else
            printf("Erro ao alocar memoria");
    } else {
        printf("Erro ao ler a entrada.\n");
    }

    return 0;
}