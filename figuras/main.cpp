#include <iostream>

#ifndef _CIRCULO_H
    #define _CIRCULO_H
    #include "circulo.h"
#endif

#ifndef _CILINDRO_H
    #define _CILINDRO_H
    #include "cilindro.h"
#endif

using namespace std;


struct CIRCULO{
    float radio;
}circulo;

struct Cilindro{
    float radio;
    float altura;
}cilindro;

int menu_elegido,menuSwitch(int menu_elegido);

int main()
{

    cout << "Elija con qué figura trabajar:" << endl;
    cout << "1. CIRCULO" << endl;
    cout << "2. CILINDRO" << endl;
    cout << "99. Salir" << endl;
    cin >> menu_elegido;

    while(menu_elegido != 99)
    {
        menuSwitch(menu_elegido);
    }
    return 0;
}

int menuSwitch(int menu_elegido)
{
    switch(menu_elegido)
    {
        case 1:
            circuloInit(circulo);
            break;

        case 2:

            break;

        case 99:
            break;
            return 0;
    }

    main();
}
