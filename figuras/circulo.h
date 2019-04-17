#ifndef _CIRCULO_H_
#define _CIRCULO_H_

typedef struct{
    float radio;
}CIRCULO;

const float PI = 3.1416;
void circuloInit(CIRCULO &circ);

void circuloSetRadio(CIRCULO &circ, float radio);

//2*PI*R
float circuloPerimetro(CIRCULO &circ);
//PI*r∧2
float circuloArea(CIRCULO &circ);

//r*angulo en radianes. En este caso siempre para PI/4
float circuloLongitudArco(CIRCULO &circ);
#endif // _CIRCULO_H_
