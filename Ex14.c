#include <stdio.h>

void decBin(int dec){
    if(dec==0){
       printf("0");
    }
    else
        if(dec==1)
           printf("1");
    else{
        decBin(dec/2);
        printf("%d",dec%2);
    }
}
int main(){
    decBin(10);

    return 0;
}