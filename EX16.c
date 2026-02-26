/*Faça um programa que leia duas palavras fornecidas pelo usuário. Aloque dinamicamente uma nova
área de memória com tamanho suficiente para armazenar a concatenação das duas strings (incluindo o
caractere '\0'). Construa a string resultante, exiba-a na tela e libere a memória.*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(){
    char word[100],
    **strResult;
    const int tam=2;
    int i=0,wordLenght;
    strResult= (char**)malloc(sizeof(char*)*tam);
    if(strResult){
        while(i<tam){
            printf("Insira uma palavra: ");
            fgets(word,sizeof(word),stdin);
            //Remove o \n se existir(opcional)
            word[strcspn(word, "\n")] = '\0'; 
            //Tamando de cada string
            wordLenght=strlen(word);
            strResult[i]=(char*)malloc(sizeof(char)*wordLenght);
            //Concatenando as strings
            strcpy(strResult[i],word);
            //Verificando se as duas palavras já foram informadas
            i++;
        }
        printf("\n\n");
        printf("--------\n");
        for(int k=0;k<i;k++){ 
            printf("%s",strResult[k]);
        }
        printf("\n");
        printf("--------");
        printf("\n");
    }
    else
        printf("Erro na alocacao de memoria!!");
    return 0;
}