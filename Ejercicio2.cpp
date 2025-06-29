/*2. Inventario de Productos y Ventas
Objetivo: Desarrollar un programa que permita registrar, listar, buscar, actualizar y eliminar productos, así como gestionar las ventas.
Requisitos:
• Define una estructura Producto con los campos: nombre (cadena), precio (flotante).
• Define una estructura Venta con los campos: idVenta (entero), producto (cadena), cantidad (entero), precioTotal (flotante).
• Implementa un menú con las siguientes opciones:
	A: Registrar un nuevo producto.
	B: Listar los productos registrados.
	C: Buscar un producto por nombre.
	D: Actualizar los datos de un producto.
	E: Eliminar un producto.
	F: Registrar una venta.
	G: Listar las ventas realizadas.
	H: Calcular el total de ventas realizadas.
	S: Salir del programa.
• El menú debe estar ciclado y permitir volver al menú principal después de cada opción.
*/
#include <iostream>
#include <string>
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
int numProductos=0;

void registrarProducto() {
    cout << "\n=== REGISTRAR PRODUCTO ===" << endl;
    cout << "Nombre del producto: ";
    cin.ignore();
    getline(cin, productos[numProductos].nombre);
    cout << "Precio del producto: ";
    cin >> productos[numProductos].precio;
    
    numProductos++;
    cout << "Producto registrado exitosamente!" << endl;
}

void listarProductos() {
    cout << "\n=== LISTADO DE PRODUCTOS ===" << endl;
    for (int i = 0; i < numProductos; i++) {
        cout << "\nProducto " << (i+1) << ":" << endl;
        cout << "Nombre: " << productos[i].nombre << endl;
        cout << "Precio: " << productos[i].precio << endl;
	}
}

void buscarProducto() {
    string nombreBuscar;
    cout << "\n=== BUSCAR PRODUCTO ===" << endl;
    cout << "Ingrese el nombre del producto a buscar: ";
    cin.ignore();
	getline(cin, nombreBuscar);
	
    bool encontrado = false;
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].nombre == nombreBuscar) {
            cout << "\nProducto encontrado:" << endl;
            cout << "Nombre: " << productos[i].nombre << endl;
            cout << "Precio: " << productos[i].precio << endl;
            encontrado = true;
            break;
        }
    }
    if (encontrado == false) {
        cout << "Producto no encontrado." << endl;
    }
}

void actualizarProducto() {
    string nombreBuscar;
    cout << "\n=== ACTUALIZAR PRODUCTO ===" << endl;
    cout << "Ingrese el nombre del producto a actualizar: ";
    cin.ignore();
    getline(cin, nombreBuscar);
    
    bool buscado = false;
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].nombre == nombreBuscar) {
            cout << "Producto encontrado. Datos actuales:" << endl;
            cout << "Nombre: " << productos[i].nombre << endl;
            cout << "Precio: " << productos[i].precio << endl;
            
            cout << "\nIngrese los nuevos datos:" << endl;
            cout << "Nuevo nombre: ";
            getline(cin, productos[i].nombre);
            cout << "Nuevo precio: ";
            cin >> productos[i].precio;
            cout << "Producto actualizado exitosamente!" << endl;
       		buscado = true;
       		break;
	    }
         if (buscado == false) {
    	cout << "Contacto no encontrado." << endl;
		}
	}
}

int main() {
	int salir = 0;
    do {
        cout << "\n=== INVENTARIO DE PRODUCTOS Y VENTAS ===" << endl;
        cout << "*Indique una opcion: " << endl;
        cout << "A: Registrar un nuevo producto." << endl;
        cout << "B: Listar los productos registrados." << endl;
        cout << "C: Buscar un producto por nombre." << endl;
        cout << "D: Actualizar los datos de un producto." << endl;
        cout << "E: Eliminar un producto." << endl;
        cout << "F: Registrar una venta." << endl;
        cout << "G: Listar las ventas realizadas." << endl;
        cout << "H: Calcular el total de ventas realizadas." << endl;
        cout << "S: Salir del programa." << endl;
		char op;
        cin >> op;
        
        switch(op) {
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
               
                break;
            case 'F':
                
                break;
            case 'G':
               
                break;  
			case 'H':
                ;
                break; 
            case 'S':
                salir = 1;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while(salir == 0);
    
    return 0;
}
