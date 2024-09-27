#include <iostream>

// Definir la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

// Función para encontrar el estudiante con mejor promedio
Estudiante* encontrarMejorEstudiante(Estudiante estudiantes[], int n) {
    Estudiante* mejor = &estudiantes[0];
    for (int i = 1; i < n; ++i) {
        if (estudiantes[i].promedio > mejor->promedio) {
            mejor = &estudiantes[i];
        }
    }
    return mejor;
}

// Función para intercambiar los promedios de dos estudiantes usando punteros
void intercambiarPromedios(Estudiante* a, Estudiante* b) {
    float temp = a->promedio;
    a->promedio = b->promedio;
    b->promedio = temp;
}

// Función recursiva para calcular la suma total de promedios
float sumaPromediosRecursiva(Estudiante estudiantes[], int n) {
    if (n == 0) {
        return 0;
    }
    return estudiantes[n-1].promedio + sumaPromediosRecursiva(estudiantes, n-1);
}

// Función para mostrar la información de todos los estudiantes
void mostrarEstudiantes(Estudiante estudiantes[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "Estudiante: " << estudiantes[i].nombre 
                  << ", Edad: " << estudiantes[i].edad 
                  << ", Promedio: " << estudiantes[i].promedio << "\n";
    }
}

int main() {
    // Arreglo estático de 5 estudiantes
    Estudiante estudiantes[5] = {
        {"Juan", 20, 8.5},
        {"Ana", 19, 9.0},
        {"Luis", 22, 7.8},
        {"Maria", 21, 9.5},
        {"Pedro", 23, 8.0}
    };

    // Mostrar todos los estudiantes
    std::cout << "Lista de estudiantes: \n";
    mostrarEstudiantes(estudiantes, 5);

    // Encontrar el mejor estudiante
    Estudiante* mejorEstudiante = encontrarMejorEstudiante(estudiantes, 5);
    std::cout << "\nEl mejor estudiante es: " << mejorEstudiante->nombre 
              << " con un promedio de " << mejorEstudiante->promedio << "\n";

    // Intercambiar los promedios de los primeros dos estudiantes
    intercambiarPromedios(&estudiantes[0], &estudiantes[1]);
    std::cout << "\nDespués de intercambiar los promedios de " << estudiantes[0].nombre 
              << " y " << estudiantes[1].nombre << ":\n";
    mostrarEstudiantes(estudiantes, 5);

    // Calcular el promedio total usando una función recursiva
    float promedioTotal = sumaPromediosRecursiva(estudiantes, 5) / 5;
    std::cout << "\nEl promedio general de todos los estudiantes es: " << promedioTotal << "\n";

    return 0;
}
