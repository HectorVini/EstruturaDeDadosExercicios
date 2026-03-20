typedef struct TNComplexo *NComplexo;

NComplexo criaNumero(double,double);
void destroi(NComplexo);
//setters
void setNumeroR(NComplexo,double);
void setNumeroIm(NComplexo,double);

//getters
double getNumeroR(NComplexo);
double getNumeroR(NComplexo);

//Operações
//-------------
// Soma: (a + bi) + (c + di) = (a + c) + (b + d)i
NComplexo somarN(NComplexo,NComplexo);
// Subtração: (a + bi) - (c + di) = (a - c) + (b - d)
NComplexo subtrairN(NComplexo,NComplexo);
// Multiplicação: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
NComplexo multiplicaN(NComplexo,NComplexo);
// Divisão: (a + bi) / (c + di) = [(ac + bd) + (bc - ad)i] / (c² + d²)
NComplexo dividirN(NComplexo,NComplexo);