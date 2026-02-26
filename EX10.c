/*Implemente um programa que permita ao usuário cadastrar quantos números inteiros desejar, sem
que o tamanho do vetor seja previamente conhecido. Para isso, utilize a função realloc para
expandir o vetor a cada nova inserção. O processo de inserção continua indefinidamente até que o
usuário digite o valor -1, que deve ser tratado como sentinela de parada (não deve ser armazenado
no vetor). Ao final, exiba todos os números cadastrados na ordem em que foram inseridos e libere a
memória alocada.*/

#include <stdlib.h>
#include <stdio.h>

int main(){
    int *vet,*novoVet,pos=0;
    vet=(int*)malloc(sizeof(int));
    while(vet){
        printf("Infome o número desejado:");
        scanf("%d",&vet[pos]);
        if(vet[pos]==-1){ 
            //Encerrando o loop 
            printf("Terminando vetor...\n\n");
            break;
        }
        pos++;
        novoVet=realloc(vet,sizeof(int));
        vet[pos]=novoVet[pos];
        
    }
    //Exibindo o vetor
    printf("Elementos do vetor\n");
    for(int i=0;i<pos;i++)
        printf("[%d]",vet[i]);
    printf("\n\n");
    free(vet);
    return 0;
}