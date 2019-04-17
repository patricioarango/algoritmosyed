#include "cilindro.h"
#include "circulo.h"
#include <math.h>

void cilindroSetRadio(CILINDRO &cili, float radio){
    cili.radio = radio;
}
void cilindroSetAltura(CILINDRO &cili, float altura){
    cili.altura = altura;
}

float cilindroPerimetro(CILINDRO &cili){
    return 2 * PI * cili.radio * cili.altura;
}

float cilindroArea(CILINDRO &cili){
    return 2 * PI * cili.radio * (cili.altura + cili.radio);
}

float cilindroVolumen(CILINDRO &cili){
    return PI * pow(cili.radio,2) * cili.altura;
}
