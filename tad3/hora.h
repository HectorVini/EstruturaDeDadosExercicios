
typedef struct THora{
   int hora, minuto, seg;
}THora;


THora* atribuiHora(int,int,int);
void avancaTempo(THora*,int); //Avança os segundos
int comparaHora(THora**,THora**);
void imprimeHora(THora**);


