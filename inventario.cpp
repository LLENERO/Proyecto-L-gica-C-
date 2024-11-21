#include <iostream>
#include <string>
#include <vector>
using namespace std;

void mensaje() {
    cout << "***************************" << endl;
    cout << "   CONTROL DE INVENTARIO" << endl;
    cout << "***************************" << endl;
}

struct Producto {
    string nombre;
    int cantidad;
    double precio;
};

void mostrarMenuInventario();
void agregarProducto(vector<Producto>& inventario);
void mostrarInventario(const vector<Producto>& inventario);
void actualizarProducto(vector<Producto>& inventario);

int main() {
    mensaje();

    vector<Producto> inventario;
    int opcion;

    do {cout << "\n--- SISTEMA DE GESTION ---\n";
        cout << "1. Gestion de inventarios\n";
        cout << "2. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int opcionInventario;
                do {
                    mostrarMenuInventario();
                    cout << "Seleccione una opcion: ";
                    cin >> opcionInventario;

                    switch (opcionInventario) {
                        case 1:
                            agregarProducto(inventario);
                            break;
                        case 2:
                            mostrarInventario(inventario);
                            break;
                        case 3:
                            actualizarProducto(inventario);
                            break;
                        case 4:
                            cout << "Regresando al menu principal...\n";
                            break;
                        default:
                            cout << "Opcion no valida.\n";
                    }
                } while (opcionInventario != 4);
                break;
            }
            case 2:
                cout << "Saliendo del sistema... ¡Hasta luego!\n";
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while (opcion != 2);

    return 0;
}
void mostrarMenuInventario() {
    cout << "\n--- Gestion de Inventarios ---\n";
    cout << "1. Agregar producto\n";
    cout << "2. Mostrar inventario\n";
    cout << "3. Actualizar producto\n";
    cout << "4. Regresar al menu principal\n";
}

void agregarProducto(vector<Producto>& inventario) {
    Producto nuevoProducto;
    cout << "Ingrese el nombre del producto: ";
    cin.ignore();
    getline(cin, nuevoProducto.nombre);
    cout << "Ingrese la cantidad: ";
    cin >> nuevoProducto.cantidad;
    cout << "Ingrese el precio: ";
    cin >> nuevoProducto.precio;

    inventario.push_back(nuevoProducto);
    cout << "Producto agregado exitosamente.\n";
}

void mostrarInventario(const vector<Producto>& inventario) {
    if (inventario.empty()) {
        cout << "El inventario esta vacio.\n";
        return;
    }

    cout << "\n--- Inventario ---\n";
    for (size_t i = 0; i < inventario.size(); ++i) {
        cout << i + 1 << ". Nombre: " << inventario[i].nombre
             << ", Cantidad: " << inventario[i].cantidad
             << ", Precio: $" << inventario[i].precio << endl;
    }
}

void actualizarProducto(vector<Producto>& inventario) {
    if (inventario.empty()) {
        cout << "El inventario está vacío. No se puede actualizar.\n";
        return;
    }

    int indice;
    cout << "Ingrese el número del producto que desea actualizar: ";
    cin >> indice;

    if (indice < 1 || indice > inventario.size()) {
        cout << "Numero de producto no valido.\n";
        return;
    }

    Producto& producto = inventario[indice - 1];
    cout << "Actualizando el producto: " << producto.nombre << endl;
    cout << "Ingrese la nueva cantidad: ";
    cin >> producto.cantidad;
    cout << "Ingrese el nuevo precio: ";
    cin >> producto.precio;
    cout << "Producto actualizado correctamente.\n";
}