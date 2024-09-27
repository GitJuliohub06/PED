#include <iostream>

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

void mostrarMejorEstudiante(Estudiante estudiantes[], int n) {
    int indiceMejor = 0;
    for (int i = 1; i < n; ++i) {
        if (estudiantes[i].promedio > estudiantes[indiceMejor].promedio) {
            indiceMejor = i;
        }
    }
    std::cout << "El mejor estudiante es: " << estudiantes[indiceMejor].nombre 
              << " con un promedio de " << estudiantes[indiceMejor].promedio << "\n";
}

int main() {
    Estudiante estudiantes[5] = {
        {"Juan", 20, 8.5},
        {"Ana", 19, 9.0},
        {"Luis", 22, 7.8},
        {"Maria", 21, 9.5},
        {"Pedro", 23, 8.0}
    };

    mostrarMejorEstudiante(estudiantes, 5);

    return 0;
}
