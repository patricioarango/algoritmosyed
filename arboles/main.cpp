#include <iostream>

using namespace std;


typedef struct Nodo{
    int balance;
    int dato;
    Nodo *der;
    Nodo *izq;
};

Nodo *crearNodo(int);
Nodo *arbol = NULL;
void insertarNodo(Nodo *&arbol, int numero);
void mostrarArbol(Nodo *&arbol,int espacios);
void imprimirNodo(Nodo *&nodo);
void recorrerPreOrden(Nodo *&arbol);
void recorrerPostOrden(Nodo *&arbol);
void imprimirNodoDato(Nodo *&nodo);

int main()
{
    int menu, seguir = 1, nuevo_dato, espacios = 0;


    while(seguir == 1){
    cout<<"MENU"<<endl;
    cout<<"Ingrese lo que quiera hacer: "<<endl;
    cout<<"1. Insertar Nodo Arbol "<<endl;
    cout<<"2. Recorrer PreOrden "<<endl;
    cout<<"3. Recorrer InOrden "<<endl;
    cout<<"4. Recorrer PostOrden "<<endl;
    cout<<"5. Mostrar Arbol"<<endl;
    cout<<"6. Imprimir raiz "<<endl;
    cout<<"99. Salir"<<endl;
    cin >> menu;

         switch(menu){
            case 1:
                cout << "**********"<<endl;
                cout << "ingresar valor: "<<endl;
                cin >> nuevo_dato;
                insertarNodo(arbol,nuevo_dato);
                break;
            case 2:
                recorrerPreOrden(arbol);
                break;
            case 4:
                recorrerPostOrden(arbol);
                break;
            case 5:
                cout << "**********"<<endl;
                cout << "EL ARBOL"<<endl;
                mostrarArbol(arbol,espacios);
                break;
            case 6:
                cout << "RAIZ"<<endl;
                imprimirNodo(arbol);
                break;
            case 99:
              seguir = 0;
              break;

        }
    }

    return 0;
}

Nodo *crearNodo(int dato){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->balance = 0;
    nuevo_nodo->dato = dato;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int numero){
    if (arbol == NULL){
        Nodo *nuevo_nodo = crearNodo(numero);
        arbol = nuevo_nodo;
    } else {
        int raiz = arbol->dato;
        if (numero < raiz){
            cout << "insertado nodo izq" << endl;
            insertarNodo(arbol->izq,numero);
        } else {
            cout << "insertado nodo der" << endl;
            insertarNodo(arbol->der,numero);
        }
    }
}

void mostrarArbol (Nodo *&arbol,int espacios){
    if (arbol == NULL){
        return;
    } else {
        mostrarArbol(arbol->der,espacios+1);
        for (int i = 0; i<espacios;i++){
            cout << "   ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izq,espacios+1);
    }
}

void imprimirNodo(Nodo *&nodo){
    cout << "**********"<<endl;
    cout << "arbol->balance"<<endl;
    cout << arbol->balance<<endl;
    cout << "arbol->dato"<<endl;
    cout << arbol->dato<<endl;
    cout << "arbol->izq"<<endl;
    cout << arbol->izq<<endl;
    cout << "arbol->der"<<endl;
    cout << arbol->der<<endl;
}

void recorrerPreOrden(Nodo *&nodo){
    if (nodo == NULL){
        return;
    } else {
        cout << nodo->dato << " - ";
        recorrerPreOrden(nodo->izq);
        recorrerPreOrden(nodo->der);
    }
}

void recorrerPostOrden(Nodo *&nodo){
    if (nodo == NULL){
        return;
    } else {
        recorrerPostOrden(nodo->izq);
        recorrerPostOrden(nodo->der);
        cout << nodo->dato << " - ";
    }
}
