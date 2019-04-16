#include <iostream>
#include "circulo.h"



using namespace std;



int main()
{
    int menu_elegido;
    CIRCULO circulo;
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
                break;

            case 2:

                break;

            case 99:
                break;
        }

    }
    return 0;
}
