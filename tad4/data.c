#include <stdio.h>
#include <stdlib.h>
#include "data.h"

 struct TData{
    int dia;
    int mes;
    int ano;
};

Data criaData(Data* date,int a, int m, int d)
{
    *date= (Data)malloc(sizeof(struct TData));
    if(*date){
        if(a % 4 == 0){
            if(m==2 && d>29){
                return 0;
            }
        }
        else{
            if(m==2 && d>28){
                return 0;
            }
        }
        if(m==1 && d>31){
            return 0;
        }

        if(m==3 && d>31){
            return 0;
        }

        if(m==4 && d>30){
            return 0;
        }

        if(m==5 && d>31){
            return 0;
        }

        if(m==6 && d>30){
            return 0;
        }

        if(m==7 && d>31){
            return 0;
        }

        if(m==8 && d>31){
            return 0;
        }

        if(m==9 && d>30){
            return 0;
        }

        if(m==10 && d>31){
            return 0;
        }

        if(m==11 && d>30){
            return 0;
        }

        if(m==12 && d>31){
            return 0;
        }

        if(m>12){
            return 0;
        }
        (*date)->ano=a;
        (*date)->mes=m;
        (*date)->dia=d;
        return *date;
    }
    return 0;
}

Data AumentaDia(Data* d, int umDia)
{
    if(umDia==1){
        (*d)->dia+=umDia;
        if((*d)->ano % 4 == 0){
            if((*d)->mes==2 && (*d)->dia>29){
                (*d)->dia-=29;
                (*d)->mes++;
            }
        }
        else{
            if((*d)->mes==2 && (*d)->dia>28){
                (*d)->dia-=28;
                (*d)->mes++;
            }
        }
        if((*d)->mes==4 || (*d)->mes==6 ||
        (*d)->mes==9 || (*d)->mes==11){
            if((*d)->dia>30){
                (*d)->dia-=30;
                (*d)->mes++;
            }
        }
        else{
            if((*d)->dia>31){
                (*d)->dia-=31;
                (*d)->mes++;
            }
            if((*d)->mes>12){
                (*d)->mes-=12;
                (*d)->ano++;
            }
        }
        return *d;
    }
    return 0;
}

Data DiminuiDia(Data* d, int umDia)
{
    if(umDia==1){
        (*d)->dia-=umDia;
        if((*d)->ano % 4 == 0){
            if((*d)->mes==3 && (*d)->dia<1){
                (*d)->dia+=29;
                (*d)->mes--;
            }
        }
        else{
            if((*d)->mes==3 && (*d)->dia<1){
                (*d)->dia+=28;
                (*d)->mes--;
            }
        }
        if((*d)->mes==5 || (*d)->mes==7 ||
        (*d)->mes==10 || (*d)->mes==12){
            if((*d)->dia<1){
                (*d)->dia+=30;
                (*d)->mes--;
            }
        }
        else{
            if((*d)->dia<1){
                (*d)->dia+=31;
                (*d)->mes--;
            }
            if((*d)->mes<1){
                (*d)->mes+=12;
                (*d)->ano--;
            }
        }
        return *d;
    }
    return 0;
}

void getData(Data d){
    
    printf("\n%02d/%02d/%02d\n",d->dia,d->mes,d->ano);
    
}