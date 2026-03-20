#ifndef RETAGULO_H_INCLUDED
#define RETAGULO_H_INCLUDED
typedef struct{
   float alt;
   float l;
}ret;
/*Função de Inicialiazação de atributos = init */
void init(ret*,float,float);
/*Calcular Área do retângulo*/
float getArea(ret);
/*Calcular Perḿetro do retângulo*/
float getPerimeter(ret);
/*Informações de um retângulo*/
void infoRet(ret);

#endif // RETAGULO_H_INCLUDED
