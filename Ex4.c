#include <stdio.h>

int A(int m,int n){
    if(m<0 || n<0)
        return 0;
    else
        if(m==0)
            return n+1;
        else if(m>0 && n==0)
            return A(m-1,1);
        else if(m>0 && n>0)
            return A(m-1,A(m,n-1));
}
int main()
{
    int valor;
    valor=A(0,8);
    printf("Resultado M,N é de = %d\n\n",valor);
    return 0;
}
