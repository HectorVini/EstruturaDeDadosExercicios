/*Implemente um programa que funcione como um editor de texto básico.
O usuário poderá digitar várias linhas de texto, uma após a outra. Cada linha deve ser armazenada em
uma área de memória alocada dinamicamente. Os endereços das linhas devem ser guardados em um
vetor de ponteiros, que será expandido sempre que necessário com a função realloc.
Ao final da digitação (quando o usuário informar algum comando de parada, como "fim"), exiba o texto
completo e libere toda a memória alocada.*/

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
    char **linhaTexto=NULL,texto[10000];
    int tam,//tamanho de cada texto
    pos=0;//Indice dentro do loop
    int capacidade= 2; //Capacidade inicial de um vetor
    linhaTexto = (char**)malloc(capacidade * sizeof(char*));
    if (linhaTexto == NULL) {
        printf("Erro na alocação inicial!\n");
        return 1;
    }
    //Adiciona mais capacidade ao vetor de ponteiros
    int acrescimo=0;
    printf("\n");
    while(texto){
        printf("%d|",pos+1);
        fgets(texto,sizeof(texto),stdin);
        //Verificando se o usuário quer sair do editor
        if(strcmp(texto,"fim\n")==0)
            break;
            //Tamanho adequado da string fornecida  
        //Verifica se precisa expandir o vetor
        if(pos>=capacidade){
            acrescimo=tam*2;
            if(!realocaEspaco(&linhaTexto,&tam,acrescimo))
            break;
        }
        tam=strlen(texto)+1;
        linhaTexto[pos]=(char*)malloc(sizeof(char)*tam);
        if(!linhaTexto[pos]){
            printf("Erro de alocacao");
            break;
        }
        strcpy(linhaTexto[pos],texto);
        pos++;
        
    }
    printf("\n\n");
    //Exibe e libera memória
    for(int i=0;i<pos;i++){ 
        printf("%s",linhaTexto[i]);
    }
    //Libera memoria
    desalocaEspaco(linhaTexto,pos);
    return 0;
}