#ifndef CILINDRO_H_INCLUDED
#define CILINDRO_H_INCLUDED

typedef struct{
    float radio;
    float altura;
}CILINDRO;

void cilindroSetRadio(CILINDRO &cili, float radio);

void cilindroSetAltura(CILINDRO &cili, float altura);

float cilindroPerimetro(CILINDRO &cili);

//ciculoArea * Altura
float cilindroVolumen(CILINDRO &cili);

//circuloPerimetro * (Altura + radio)
float cilindroArea(CILINDRO &cili);
#endif // CILINDRO_H_INCLUDED
