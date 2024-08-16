#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

struct Estudiante {
    long long id;
    bool genero;
    std::string nombre;
    std::string email;
    long long telefono;
    int edad;
    float calculoII;
    float logica;
    float fundamentosProgramacion;
    float principiosDesarrolloSoftware;
    float promedio;
};

// Generar un nombre basado en el género
std::string generarNombre(bool genero) {
    std::string nombresMujer[] = {"Ana", "Maria", "Lucia", "Carmen", "Josefa"};
    std::string nombresHombre[] = {"Jose", "Juan", "Pedro", "Luis", "Miguel"};

    if (genero) {
        return nombresMujer[rand() % 5];
    } else {
        return nombresHombre[rand() % 5];
    }
}

// Función para generar data dummies
void generarEstudiantes(Estudiante* estudiantes, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        estudiantes[i].id = rand() % 1000000000 + 1000000000;
        estudiantes[i].genero = rand() % 2;
        estudiantes[i].nombre = generarNombre(estudiantes[i].genero);
        estudiantes[i].email = estudiantes[i].nombre + std::to_string(rand() % 100) + "@eafit.edu.co";
        estudiantes[i].telefono = rand() % 239999999 + 3000000000;
        estudiantes[i].edad = rand() % 106 + 5;
        estudiantes[i].calculoII = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 5.0;
        estudiantes[i].logica = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 5.0;
        estudiantes[i].fundamentosProgramacion = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 5.0;
        estudiantes[i].principiosDesarrolloSoftware = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 5.0;
        estudiantes[i].promedio = (estudiantes[i].calculoII + estudiantes[i].logica +
                                   estudiantes[i].fundamentosProgramacion + estudiantes[i].principiosDesarrolloSoftware) / 4;
    }
}

// Comparador para ordenar por promedio
bool compararPromedio(Estudiante a, Estudiante b) {
    return a.promedio > b.promedio;
}

// Imprimir información de un estudiante
void imprimirEstudiante(Estudiante estudiante) {
    std::cout << "ID: " << estudiante.id << "\n";
    std::cout << "Genero: " << (estudiante.genero ? "Mujer" : "Hombre") << "\n";
    std::cout << "Nombre: " << estudiante.nombre << "\n";
    std::cout << "Email: " << estudiante.email << "\n";
    std::cout << "Telefono: " << estudiante.telefono << "\n";
    std::cout << "Edad: " << estudiante.edad << "\n";
    std::cout << "Calculo II: " << estudiante.calculoII << "\n";
    std::cout << "Logica: " << estudiante.logica << "\n";
    std::cout << "Fundamentos de Programacion: " << estudiante.fundamentosProgramacion << "\n";
    std::cout << "Principios de Desarrollo de Software: " << estudiante.principiosDesarrolloSoftware << "\n";
    std::cout << "Promedio: " << estudiante.promedio << "\n\n";
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    int cantidad;
    std::cout << "Ingrese la cantidad de estudiantes: ";
    std::cin >> cantidad;

    Estudiante* estudiantes = new Estudiante[cantidad];

    generarEstudiantes(estudiantes, cantidad);

    std::sort(estudiantes, estudiantes + cantidad, compararPromedio);

    std::cout << "Top 10 estudiantes:\n";
    for (int i = 0; i < std::min(10, cantidad); i++) {
        imprimirEstudiante(estudiantes[i]);
    }

    std::cout << "\nLos 5 estudiantes con los promedios mas bajos:\n";
    for (int i = std::max(0, cantidad - 5); i < cantidad; i++) {
        imprimirEstudiante(estudiantes[i]);
    }

    delete[] estudiantes;
    return 0;
}
