#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Estudiante {
    int id;
    string nombre;
    int edad;
};

Estudiante estudiantes[10];
int total = 0;

// Agrega un estudiante al arreglo
void agregar() {
    if (total >= 10) {
        cout << "Limite de estudiantes alcanzado.\n";
        return;
    }

    cout << "ID: ";
    cin >> estudiantes[total].id;

    cin.ignore(); 
    cout << "Nombre: ";
    getline(cin, estudiantes[total].nombre); 

    cout << "Edad: ";
    cin >> estudiantes[total].edad;

    total++;
    cout << "Agregado!\n";
}

// Muestra todos los estudiantes registrados
void mostrar() {
    cout << "\n--- ESTUDIANTES ---\n";
    for (int i = 0; i < total; i++) {
        cout << estudiantes[i].id << " - "
             << estudiantes[i].nombre << " - "
             << estudiantes[i].edad << " años\n";
    }
}

// Busca un estudiante por ID
void buscar() {
    int idBuscar;
    cout << "Ingrese el ID a buscar: ";
    cin >> idBuscar;

    bool encontrado = false;
    for (int i = 0; i < total; i++) {
        if (estudiantes[i].id == idBuscar) {
            cout << "Estudiante encontrado:\n";
            cout << "ID: " << estudiantes[i].id << endl;
            cout << "Nombre: " << estudiantes[i].nombre << endl;
            cout << "Edad: " << estudiantes[i].edad << " años" << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No encontrado\n";
    }
}

// Guarda los estudiantes en un archivo
void guardar() {
    ofstream archivo("estudiantes.txt");
    archivo << total << endl;
    for (int i = 0; i < total; i++) {
        archivo << estudiantes[i].id << " "
                << estudiantes[i].nombre << " "
                << estudiantes[i].edad << endl;
    }
    archivo.close();
}

// Carga los estudiantes desde un archivo
void cargar() {
    ifstream archivo("estudiantes.txt");
    if (archivo.is_open()) {
        archivo >> total;
        for (int i = 0; i < total; i++) {
            archivo >> estudiantes[i].id
                    >> estudiantes[i].nombre
                    >> estudiantes[i].edad;
        }
        archivo.close();
    }
}

// Programa principal
int main() {
    cargar();
    int op;

    do {
        cout << "\n1. Agregar  2. Mostrar  3. Buscar  4. Salir\n";
        cout << "Opción: ";
        cin >> op;

        if (op == 1) agregar();
        else if (op == 2) mostrar();
        else if (op == 3) buscar();
        else if (op == 4) {
            guardar();
            break;
        }
        else {
            cout << "Opción no válida.\n";
        }

    } while (true);

    return 0;
}
