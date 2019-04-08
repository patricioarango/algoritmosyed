#include <iostream>
#include <string>
using namespace std;

//para menu
int menu_elegido, menuSwitch(int menu_elegido), salir(), SUC_SIZE = 25;
enum zns { NORTE,SUR,ESTE,OESTE,CENTRO };

//para sucursales
struct ssal {
    int id;
    string direccion;
    int zona;
    int ocupado = 0;
} sucursal[25];

int i,j,pos_suc, id_suc, altaSucursal(), validarIdSuc(int pos_suc), getPosicionSucursalVacia(), validarIdSucExistente(int id_suc);
int RangoIdSucursalValido(int id_suc),getSucursalPosicionPorId(int id_suc);
void generarFakeData(), listarSucursales();
std::string getZonabyName(int zona);

//facturacion
int FACT_SIZE = 50;
struct fact {
    ssal sucu_facturacion;
    float monto;
    int ocupado = 0;
} factura[50];
int altaFacturacion(), getPosicionFacturacionVacia(), listarFacturacionPorZonas(), listarFacturacionPorSucursal(), getFacturacionPorIdSucursal(int id_suc);
void listarFacturacion();
float totalzonas[4];

//PROGRAMA
int main()
{
    cout << " " << endl;
    cout << "1. Alta Sucursal" << endl;
    cout << "2. Ingreso de Facturación" << endl;
    cout << "3. Listar Sucursales" << endl;
    cout << "4. Total facturación por Zona" << endl;
    cout << "5. Listar Facturación" << endl;
    cout << "6. Listar Sucursal por Max. / Min. de facturación" << endl;
    cout << "98. Generar Fake Data" << endl;
    cout << "99. Salir" << endl;
    cout << " " << endl;
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
            altaSucursal();
            break;

        case 2:
            altaFacturacion();
            break;

        case 3:
            listarSucursales();
            break;

        case 4:
            listarFacturacionPorZonas();
            break;

        case 5:
            listarFacturacion();
            break;

        case 6:
            listarFacturacionPorSucursal();
            break;

        case 98:
            generarFakeData();
            break;

        case 99:
            salir();
            break;
    }

    main();
}

int salir()
{
    cout << "elegiste salir" << endl;
    exit(EXIT_SUCCESS);
    return 0;
}

void generarFakeData()
{
    for (i=0;i < SUC_SIZE;i++)
    {
       sucursal[i].id = 100 + i;
       sucursal[i].direccion = "SUCURSAL " + std::to_string(i + 1);
       sucursal[i].zona = (i % 5);
       sucursal[i].ocupado = 1;
    }
    cout << " " << endl;
    cout << "SUCURSALES" << endl;
    listarSucursales();

    for (i=0;i < SUC_SIZE;i++)
    {
        factura[i].sucu_facturacion = sucursal[i];
        factura[i].monto = rand() % 100;
        factura[i].ocupado = 1;
    }

    for (i=0;i < SUC_SIZE;i++)
    {
        factura[i+25].sucu_facturacion = sucursal[i];
        factura[i+25].monto = rand() % 100;
        factura[i].ocupado = 1;
    }
    cout << " " << endl;
    cout << "FACTURAS" << endl;
    listarFacturacion();
    main();
}

void listarSucursales()
{
    for(i=0;i < SUC_SIZE;i++)
    {
        cout << (i+1) <<") " << "id: " << sucursal[i].id << " dirección: " << sucursal[i].direccion << " zona: " << getZonabyName(sucursal[i].zona) << " ocupado: " << sucursal[i].ocupado << endl;
    }
}

int altaSucursal()
{
    pos_suc = getPosicionSucursalVacia();
    cout << "Vas a escribir la posición de sucursal: " << pos_suc << endl;
    cout << "Elegir un id Sucursal entre 100 y 999. 1000 = exit" << endl;
    cin >> id_suc;
        validarIdSuc(id_suc);
        sucursal[pos_suc].id = id_suc;
    cout << "Direccion Sucursal (SIN ESPACIOS POR FAVOR)" << endl;
    cin >> sucursal[pos_suc].direccion;
    cout << "Localidad 0: NORTE; 1: SUR; 2: ESTE; 3: OESTE; 4: CENTRO " << endl;
    cin >> sucursal[pos_suc].zona;
    sucursal[pos_suc].ocupado = 1;
    listarSucursales();
    main();
    return 0;
}

int validarIdSuc(int id_suc)
{
    if (validarIdSucExistente(id_suc) == 1){
     cout << "El id ya Existe. Ingresá otro" << endl;
      altaSucursal();
      return 0;
    }

    if (RangoIdSucursalValido(id_suc) == 0)
    {
        cout << "Numero Invalido" << endl;
        altaSucursal();
    }
    if (id_suc == 1000)
    {
        salir();
    }
    return 0;
}

int RangoIdSucursalValido(int id_suc)
{
    if (id_suc >= 99 || id_suc <= 1000 )
    {
        return 1;
    }
    return 0;
}

int validarIdSucExistente(int id_suc)
{
    for (i=0;i < SUC_SIZE;i++)
    {
        if (sucursal[i].id == id_suc)
        {
            return 1;
        }
    }
    return 0;
}
std::string getZonabyName(int zona)
{
    string zonaS;
    switch(zona)
    {
        case NORTE:
        zonaS = "NORTE";
        break;

        case SUR:
        zonaS = "SUR";
        break;

        case ESTE:
        zonaS = "ESTE";
        break;

        case CENTRO:
        zonaS = "CENTRO";
        break;

        case OESTE:
        zonaS = "OESTE";
        break;
    }

    return std::string(zonaS);
}

int getPosicionSucursalVacia()
{
    for (i=0;i < SUC_SIZE;i++)
    {
        if (sucursal[i].ocupado == 0)
        {
            return i;
        }
    }
    return 0;
}

int getPosicionFacturacionVacia()
{
    for (i=0;i < FACT_SIZE;i++)
    {
        if (factura[i].ocupado == 0)
        {
            return i;
        }
    }
    return 0;
}

int altaFacturacion()
{
    int pos_fact = getPosicionFacturacionVacia();
    listarSucursales();
    cout << "Vas a escribir la posición de factura: " << pos_fact << endl;
    cout << "Ingrese el ID de la Sucursal deseada: " << endl;
    cin >> id_suc;
        if (id_suc == 1000)
        {
            salir();
        }

        if (RangoIdSucursalValido(id_suc) == 0){
            cout << "El Rango del ID no es correcto" << endl;
            altaFacturacion();
        }

        if (validarIdSucExistente(id_suc) == 0)
        {
            cout << "El ID no existe" << endl;
            altaFacturacion();
        }
    factura[pos_fact].sucu_facturacion = sucursal[getSucursalPosicionPorId(id_suc)];
    cout << "Ingrese El Monto " << endl;
    cin >> factura[pos_fact].monto;
    factura[pos_fact].ocupado = 1;
    listarFacturacion();
    return 0;
}

void listarFacturacion()
{
    for(i=0;i < FACT_SIZE;i++)
    {
        cout << (i+1) <<") " << "id: " << factura[i].sucu_facturacion.id << " Monto: " << factura[i].monto << " Zona: " << factura[i].sucu_facturacion.zona << endl;
    }
}

int listarFacturacionPorZonas()
{
    for(i=0;i < FACT_SIZE; i++)
    {
        if (factura[i].sucu_facturacion.zona == 0){
            totalzonas[0] += factura[i].monto;
        }

        if (factura[i].sucu_facturacion.zona == 1){
            totalzonas[1] += factura[i].monto;
        }

        if (factura[i].sucu_facturacion.zona == 2){
            totalzonas[2] += factura[i].monto;
        }

        if (factura[i].sucu_facturacion.zona == 3){
            totalzonas[3] += factura[i].monto;
        }

        if (factura[i].sucu_facturacion.zona == 4){
            totalzonas[4] += factura[i].monto;
        }
    }
    cout << " " << endl;
    for(i=0;i < 5;i++)
    {
        cout << "TOTAL " << getZonabyName(i) << ": " << totalzonas[i] << endl;
    }
    cout << " " << endl;
    return 0;
}

int listarFacturacionPorSucursal()
{
    id_suc = 0;
    float monto_max = 0;
    int id_suc_max,id_suc_min;
    float monto_min = 99999;
    for(i=0;i < SUC_SIZE; i++)
    {
        float monto = 0;
        id_suc = sucursal[i].id;

        for(j=0;j < FACT_SIZE; j++){
            if (id_suc == factura[j].sucu_facturacion.id)
            {
                monto += factura[j].monto;
            }
        }
        cout << (i+1) << ") " << "id: " << sucursal[i].id << " Facturación: " <<  monto << endl;

        if (monto > monto_max)
        {
            monto_max = monto;
            id_suc_max = sucursal[i].id;
        }
        if (monto < monto_min)
        {
            monto_min = monto;
            id_suc_min = sucursal[i].id;
        }
    }
    cout << " " << endl;
    cout <<  "Facturación Máxima: " <<  monto_max << " | id Sucursal: " << id_suc_max << endl;
    cout << "Sucursal Dirección: " << sucursal[getSucursalPosicionPorId(id_suc_max)].direccion << ". Zona: " << getZonabyName(sucursal[getSucursalPosicionPorId(id_suc_max)].zona) << endl;
    cout << " " << endl;
    cout <<  "Facturación Mínima: " <<  monto_min << " | id Sucursal: " << id_suc_min << endl;
    cout << "Sucursal Dirección: " << sucursal[getSucursalPosicionPorId(id_suc_min)].direccion << ". Zona: " << getZonabyName(sucursal[getSucursalPosicionPorId(id_suc_min)].zona) << endl;
    cout << " " << endl;
    return 0;
}

int getSucursalPosicionPorId(int id_suc)
{
    for (i=0;i < SUC_SIZE;i++)
    {
        if (sucursal[i].id == id_suc)
        {
            return i;
        }
    }
}

/** ERRORES
El alta de sucursales no soporta espacios. Prob varias formas, no encontré solución.
Tanto en alta de sucursales como de facturación, si todas las posiciones están ocupadas, se continuará ingresando siempre la posición 0 del array.
A veces hay que ingresar 99 varias veces para poder salir.
No me dejó inicializar los array de struct con el valor declarado en los int Constantes.
No encontré la manera de contar el length del enum

Ver main.cpp disponible en
https://drive.google.com/file/d/1wzaJu9lX8eNSO7qZxxxTOpzGv4GimXFx/view?usp=sharing
*/
