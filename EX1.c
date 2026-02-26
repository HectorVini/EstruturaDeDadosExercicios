#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
int a,b,c; int vetor[3];
int *pti;
int *pti1, *pti2;
a=10;
b=20;
c=30;
pti1 = &a;
pti2 = &b;
*pti1 = c;
*pti2 = c;
pti = vetor;
*pti = 1;
*(pti+1) = 2;
*(pti+2) = 3;
printf (">> Teste de Mesa (1) << \n");
printf ("A: %d, B: %d, C: %d\n",a,b,c);
printf ("Vetor: %d, %d, %d\n",vetor[0],vetor[1],vetor[2]);
a=99;
vetor[0] = *pti1;
vetor[1] = *pti2;
*(vetor+2)= *pti;
printf (">> Teste de Mesa (2) << \n"); printf ("A: %d, B: %d,"
": %d\n",a,b,c);
printf ("Vetor: %d, %d, %d\n",vetor[0],vetor[1],vetor[2]);
return 0;
}
