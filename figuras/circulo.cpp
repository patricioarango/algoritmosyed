#include <iostream>
#include "circulo.h"
using namespace std;
float radio;

int circuloInit(circ &circulo){
    cout << "PARA OBTENER TODOS LOS DATOS SOBRE EL CÍRCULO, INGRESE SU RADIO: " << endl;
    cin >> radio;
    return circuitoSetRadio(radio);

}

int circuitoSetRadio(float radio){
    return (int) radio;
}
