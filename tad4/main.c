#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main()
{
    Data pData;
    criaData(&pData,2019,12,31);
    if(pData){
        DiminuiDia(&pData,1);
        getData(pData);
        printf("\nteste\n");
    }
    else if(!pData){
        printf("Data inválida\n\n");
    }
    return 0;
}
