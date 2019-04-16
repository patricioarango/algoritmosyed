#ifndef _CIRCULO_H_
#define _CIRCULO_H_

typedef struct{
    float radio;
}CIRCULO;

void circuloInit(CIRCULO &circ);

void circuitoSetRadio(CIRCULO &circ, float radio);

#endif // _CIRCULO_H_
