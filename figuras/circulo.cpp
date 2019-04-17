#include "circulo.h"
#include <math.h>

void circuloInit(CIRCULO &circ){
circ.radio = 1;
}

void circuloSetRadio(CIRCULO &circ, float radio){
    circ.radio = radio;
}

//2*PI*R
float circuloPerimetro(CIRCULO &circ){
    return 2 * PI * circ.radio;
}
//PI*r∧2
float circuloArea(CIRCULO &circ){
     return PI * pow(circ.radio,2);
}

//r*angulo en radianes. En este caso siempre para PI/4
float circuloLongitudArco(CIRCULO &circ){
     return circ.radio * (PI/4);
}
