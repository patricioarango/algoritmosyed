#include <iostream>
 #include "circulo.h"
#ifndef _CIRCULO_H
    #define _CIRCULO_H

#endif

#ifndef _CILINDRO_H
    #define _CILINDRO_H
    #include "cilindro.h"
#endif

using namespace std;

int menu_elegido;

int main()
{
    circ circulo;
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
                circuloInit(circ &circulo);
                break;

            case 2:

                break;

            case 99:
                break;
                return 0;
        }

    }
    return 0;
}
