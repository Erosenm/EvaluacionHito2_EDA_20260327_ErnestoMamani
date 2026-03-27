#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    string codigo;
    Estudiante* siguiente;
};

class ListaEstudiantes {
private:
    Estudiante* inicio;
    Estudiante* fin;
public:
    ListaEstudiantes() {
        inicio = nullptr;
        fin = nullptr;
    }
    

    void registrar(string nombre, string codigo) {
        Estudiante* nuevo = new Estudiante;
        nuevo->nombre = nombre;
        nuevo->codigo = codigo;
        nuevo->siguiente = nullptr;

        if (inicio == nullptr) {
            inicio = nuevo;
            fin = nuevo;
        } else {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
    }

    void atender() {
        if (inicio == nullptr) {
            cout << "No hay estudiantes en espera\n";
            return;
        }
        Estudiante* atendido = inicio;
        cout << "Atendiendo estudiante:\n";
        cout << "Nombre: " << atendido->nombre << "\n";
        cout << "Codigo: " << atendido->codigo << "\n";
        inicio = inicio->siguiente;
        delete atendido;
        if (inicio == nullptr) fin = nullptr;
    }

    void mostrar() {
        if (inicio == nullptr) {
            cout << "No hay estudiantes en espera\n";
            return;
        }
        cout << "Lista de estudiantes en espera:\n\n";
        Estudiante* actual = inicio;
        int pos = 1;
        while (actual != nullptr) {
            cout << pos << ". " << actual->nombre << " (" << actual->codigo << ")\n";
            actual = actual->siguiente;
            pos++;
        }
    }

    void buscar(string nombre) {
        if (inicio == nullptr) {
            cout << "No hay estudiantes en espera\n";
            return;
        }
        Estudiante* actual = inicio;
        int pos = 1;
        while (actual != nullptr) {
            if (actual->nombre == nombre) {
                cout << "Estudiante encontrado en la posicion " << pos << ":\n";
                cout << "nombre: " << actual->nombre << "\n";
                cout << "codigo: " << actual->codigo << "\n";
                return;
            }
            actual = actual->siguiente;
            pos++;
        }
        cout << "estudiante no encontrado \n";
    }
};

int main() {
    ListaEstudiantes lista;
    int opcion;
    string nombre, codigo;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Registrar estudiante\n";
        cout << "2. Atender estudiante\n";
        cout << "3. Mostrar estudiantes en espera\n";
        cout << "4. Buscar estudiante por nombre\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Ingrese nombre: ";
                getline(cin, nombre);
                cout << "Ingrese codigo: ";
                getline(cin, codigo);
                lista.registrar(nombre, codigo);
                break;
            case 2:
                lista.atender();
                break;
            case 3:
                lista.mostrar();
                break;
            case 4:
                cout << "Ingrese nombre a buscar: ";
                getline(cin, nombre);
                lista.buscar(nombre);
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 5);

    return 0;
}