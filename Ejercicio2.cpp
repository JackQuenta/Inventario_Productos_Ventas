/*2. Inventario de Productos y Ventas
Objetivo: Desarrollar un programa que permita registrar, listar, buscar, actualizar y eliminar productos, as� como gestionar las ventas.
Requisitos:
� Define una estructura Producto con los campos: nombre (cadena), precio (flotante).
� Define una estructura Venta con los campos: idVenta (entero), producto (cadena), cantidad (entero), precioTotal (flotante).
� Implementa un men� con las siguientes opciones:
	A: Registrar un nuevo producto.
	B: Listar los productos registrados.
	C: Buscar un producto por nombre.
	D: Actualizar los datos de un producto.
	E: Eliminar un producto.
	F: Registrar una venta.
	G: Listar las ventas realizadas.
	H: Calcular el total de ventas realizadas.
	S: Salir del programa.
� El men� debe estar ciclado y permitir volver al men� principal despu�s de cada opci�n.
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
Venta ventas[100];
int numProductos=0;
int numVentas=0;

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

void eliminarProducto() {
    string nombreBuscar;
    cout << "\n=== ELIMINAR PRODUCTO ===" << endl;
    cout << "Ingrese el nombre del producto a eliminar: ";
    cin.ignore();
	getline(cin, nombreBuscar);
	
    bool encontrado = false;
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].nombre == nombreBuscar) {
            for (int j = i; j < numProductos - 1; j++) {
                productos[j] = productos[j + 1];
            }
            numProductos--;
            encontrado = true;
            break;
        }
    }
   if (encontrado == true) {
    	cout << "Contacto Eliminado" << endl;
	} else {
    	cout << "Contacto no encontrado." << endl;
	}
}


int contadorVentas=1;
void registrarVenta() {
    string nombreProducto;
    float precioProducto = 0;
    
    cout << "\n=== REGISTRAR VENTA ===" << endl;
    cout << "Nombre del producto vendido: ";
    cin.ignore();
	getline(cin, nombreProducto);
	
	bool productoEncontrado = false;
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].nombre == nombreProducto) {
            precioProducto = productos[i].precio;
            productoEncontrado = true;
            break;
        }
    }
    
    if (productoEncontrado = false) {
        cout << "Producto no encontrado en el inventario." << endl;
    }
    
    ventas[numVentas].idVenta = contadorVentas++;
    ventas[numVentas].producto = nombreProducto;
    
    cout << "Cantidad vendida: ";
    cin >> ventas[numVentas].cantidad;
    
    ventas[numVentas].precioTotal = precioProducto * ventas[numVentas].cantidad;
    
    numVentas++;
    cout << "Venta registrada exitosamente!" << endl;
    cout << "Total de la venta: " << ventas[numVentas-1].precioTotal << endl;
}

void listarVentas() {
    cout << "\n=== LISTADO DE VENTAS ===" << endl;
    for (int i = 0; i < numVentas; i++) {
        cout << "ID: " << ventas[i].idVenta << endl;
		cout << "PRODUCTO: " << ventas[i].producto << endl;
		cout << "CANTIDAD: " << ventas[i].cantidad << endl;
		cout << "TOTAL: " << ventas[i].precioTotal << endl;
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
                eliminarProducto();
                break;
            case 'F':
                registrarVenta();
                break;
            case 'G':
                listarVentas();
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
