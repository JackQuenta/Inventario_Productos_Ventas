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
                agregarContacto();
                break;
            case 'B':
                agregarContacto();
                break;
            case 'C':
                agregarContacto();
                break;
            case 'D':
                agregarContacto();
                break;
            case 'E':
                agregarContacto();
                break;
            case 'F':
                agregarContacto();
                break;
            case 'G':
                eliminarContacto();
                break;  
			case 'H':
                mostrarContactos();
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
