#include <iostream>
#include "circulo.h"
#include "cilindro.h"
using namespace std;

int main()
{
    int menu_elegido;
    float radio;
    float altura;
    CIRCULO circulo;
    CILINDRO cilindro;
    cout << "Elija con qué figura trabajar:" << endl;
    cout << "1. CIRCULO" << endl;
    cout << "2. CILINDRO" << endl;
    cout << "99. Salir" << endl;
    cin >> menu_elegido;

    while(menu_elegido != 99)
    {
        switch(menu_elegido)
        {
            case 1:
                circuloInit(circulo);
                cout << "Ingrese el Radio del Circulo:" << endl;
                cin >> radio;
                    circuloSetRadio(circulo, radio);
                    cout << "El Perímetro es: " << circuloPerimetro(circulo)<< endl;
                    cout << "El Área es: " << circuloArea(circulo)<< endl;
                    cout << "La Longitud del Arco para 45° es: " << circuloLongitudArco(circulo)<< endl;
                    cout << " " << endl;
                    main();
                break;

            case 2:
                cout << "Ingrese el Radio del Cilindro:" << endl;
                cin >> radio;
                    cilindroSetRadio(cilindro,radio);
                cout << "Ingrese la Altura del Cilindro:" << endl;
                cin >> altura;
                    cilindroSetAltura(cilindro,altura);
                    cout << "El Perimetro es: " << cilindroPerimetro(cilindro)<< endl;
                    cout << "El Área es: " << cilindroArea(cilindro)<< endl;
                    cout << "El Volumen es: " << cilindroVolumen(cilindro)<< endl;
                    main();
                break;

            case 99:
                break;
        }

    }
    return 0;
}
