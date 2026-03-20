#include <stdio.h>
#include <stdlib.h>
#include "hora.h"



THora* atribuiHora(int h,int m,int s){
   THora* p = (THora*)malloc(sizeof(THora));
   if(h<=24){
      p->hora=h;
      if(m<=59){
         p->minuto = m;
         if(s<=59){
            p->seg = s;
            return p;
         }
         else
            return 0;
      }
      else
         return 0;
   }
   else
      return 0;
}
void avancaTempo(THora* p, int aumentoSeg){
   p->seg = p->seg + aumentoSeg;
   if(aumentoSeg<=86400 && aumentoSeg>=1){
      //Corrige os segundos
      while(p->seg>=60){
         p->seg-=60;
         p->minuto++;
         
      }
      //Corrige os minutos
      while(p->minuto>=60){
         p->minuto-=60;
         p->hora++;    
      }
      //Corrige as horas
      if(p->hora>=24)
         p->hora-=24;
   }
}
int comparaHora(THora** h1,THora** h2){
   if(((*h1)->hora==(*h2)->hora) && ((*h1)->minuto==(*h2)->minuto)
      && (*h1)->seg==(*h2)->seg)
      return 1;
   return 0;
}

void imprimeHora(THora** h){
   printf("\n\t%02d:%02d:%02d",(*h)->hora,(*h)->minuto,(*h)->seg);
}