#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED
//Este tipo representa um ponto em R*R
struct TPonto{
    double v[2];
};

typedef struct TPonto *Ponto;
/* Essa função.... bla bla bla...
o parâmetro ponto
*/
//
Ponto cria(double ax,double ay);
void translada(Ponto ponto,double aumento);
double getX(Ponto ponto);
double getY(Ponto ponto);
void setX(Ponto ponto,double ax);
void setY(Ponto ponto,double ay);
void destroi(Ponto p);
#endif // PONTO_H_INCLUDED