#include <stdio.h>
#include <stdlib.h>
#include "hora.h"
int main()
{
   THora* Horario,*Horario2;
   Horario = atribuiHora(23,59,59);
   printf("\nHorário 1 Inicial Atribuído:\n");
   imprimeHora(&Horario);
   avancaTempo(Horario,1);
   printf("\nHorário 1 Alterado:\n");
   imprimeHora(&Horario);
   Horario2 = atribuiHora(23,59,59);
   printf("\nHorário 2 Inicial Atribuído:\n");
   imprimeHora(&Horario2);
   avancaTempo(Horario2,1);
   printf("\nHorário 2 Alterado:\n");
   imprimeHora(&Horario2);
   
   
   return 0;
}
