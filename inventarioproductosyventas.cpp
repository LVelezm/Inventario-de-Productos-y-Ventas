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
void listarProductos(){
    if(cantidadProductos==0){
    	cout<<endl;
        cout<<"No hay productos registrados."<<endl;
        return;
    }
    for(int i = 0; i < cantidadProductos; i++){
    	cout<<endl;
        cout<<"Producto "<< i + 1 <<": "<<productos[i].nombre <<endl;
        cout<<"------------------------"<<endl;
        cout<<endl;
    }
}
void buscarProducto() {
    string nombreBuscar;
    cout << "Ingrese el nombre del producto a buscar: ";
    cin.ignore();
    getline(cin, nombreBuscar);
    bool encontrado = false;
    for (int i = 0; i < cantidadProductos; i++) {
        if (productos[i].nombre == nombreBuscar) {
            cout << "Producto encontrado: " << productos[i].nombre << ", Precio: " << productos[i].precio << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Producto no encontrado." << endl;
    }
}
void actualizarProducto(){
    string nombreActualizar;
    cout << "Ingrese el nombre del producto a actualizar: ";
    cin.ignore();
    getline(cin, nombreActualizar);
    bool encontrado = false;
    for (int i = 0; i < cantidadProductos; i++) {
        if (productos[i].nombre == nombreActualizar) {
            cout << "Ingrese el nuevo precio del producto: ";
            cin >> productos[i].precio;
            cout<<endl;
            cout << "Producto actualizado con éxito!" << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Producto no encontrado." << endl;
    }
}
void eliminarProducto() {
    string nombreEliminar;
    cout << "Ingrese el nombre del producto a eliminar: ";
    cin.ignore();
	getline(cin, nombreEliminar);
    bool encontrado = false;
    for (int i = 0; i < cantidadProductos; i++) {
        if (productos[i].nombre == nombreEliminar) {
            for (int j = i; j < cantidadProductos - 1; j++) {
                productos[j] = productos[j + 1];
            }
            cantidadProductos--;
            cout<<endl;
            cout << "Producto eliminado" << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
    	cout<<endl;
        cout << "Producto no encontrado." << endl;
    }
}
void registrarVenta() {
    Venta nuevaVenta;
    cout << "Ingrese el nombre del producto vendido: ";
    cin.ignore();
    getline(cin, nuevaVenta.producto);
    cout << "Ingrese la cantidad vendida: ";
    cin >> nuevaVenta.cantidad;
    float precioProducto = 0;
    for (int i = 0; i < cantidadProductos; i++) {
        if (productos[i].nombre == nuevaVenta.producto) {
            precioProducto = productos[i].precio;
            break;
        }
    }
    if (precioProducto == 0) {
    	cout<<endl;
        cout << "Producto no encontrado." << endl;
        return;
    }
    nuevaVenta.precioTotal = precioProducto * nuevaVenta.cantidad;
    ventas[cantidadVentas] = nuevaVenta;
    cantidadVentas++;
    cout << "Venta registrada" << endl;
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
            case 'B':
                listarProductos();
                break;
            case 'C':
                buscarProducto();
                break;
            case 'D':
                actualizarProducto();
                break;
            case 'E':
                eliminarProducto();
                break;
            case 'F':
                registrarVenta();
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
