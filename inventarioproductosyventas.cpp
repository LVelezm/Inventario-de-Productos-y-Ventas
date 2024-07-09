#include <iostream>
using namespace std;

struct Producto {
    string nombre;
    float precio;
};

struct Venta {
    int idVenta;
    string producto;
    int cantidad;
    float precioTotal;
};

Producto productos[100];
int cantidadProductos = 0;

Venta ventas[100];
int cantidadVentas = 0;

void registrarProducto(){
    cout<<"Ingrese el nombre del producto: ";
    cin.ignore();
    getline(cin, productos[cantidadProductos].nombre);
    cout<<"Ingrese el precio del producto: ";
    cin>>productos[cantidadProductos].precio;
    cantidadProductos++;
    cout<<endl;
    cout<<"Producto registrado"<<endl;
}
int main(){
    char opcion;
    do{
    	cout<<endl;
        cout<<"Menu de opciones:"<<endl;
        cout<<"A: Registrar un nuevo producto."<<endl;
        cout<<"B: Listar los productos registrados."<<endl;
        cout<<"C: Buscar un producto por nombre."<<endl;
        cout<<"D: Actualizar los datos de un producto."<<endl;
        cout<<"E: Eliminar un producto."<<endl;
        cout<<"F: Registrar una venta."<<endl;
        cout<<"G: Listar las ventas realizadas."<<endl;
        cout<<"H: Calcular el total de ventas realizadas."<<endl;
        cout<<"S: Salir del programa."<<endl;
        cout<<"Ingrese su opcion: ";
        cin >> opcion;
        switch (opcion){
            case 'A':
                registrarProducto();
                break;
            case 'S':
                cout<<"Saliendo...."<<endl;
                break;
            default:
                cout<<"Opcion invalida. Intente de nuevo."<<endl;
        }
    } while(opcion != 'S');
    return 0;
}
