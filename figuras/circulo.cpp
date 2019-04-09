#include "circulo.h"
#include <iostream>
using namespace std;
float radio;

int circuloInit(CIRCULO &circulo){
    cout << "PARA OBTENER TODOS LOS DATOS SOBRE EL CÍRCULO, INGRESE SU RADIO: " << endl;
    cin >> radio;
    return circuitoSetRadio(radio);

}

int circuitoSetRadio(float radio){
    return (int) radio;
}
