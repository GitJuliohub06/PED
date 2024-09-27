#include <iostream>

// Estructura para el equipo (arma y armadura)
struct Equipo {
    char nombre[50];
    int bonoFuerza;
    int bonoAgilidad;
    int bonoMagia;
};

// Estructura del personaje de rol
struct Personaje {
    char nombre[50];
    char clase[20]; // guerrero, mago, arquero
    int fuerza;
    int agilidad;
    int magia;
    Equipo* arma;
    Equipo* armadura;
};

// Función para crear un personaje
void crearPersonaje(Personaje* p) {
    std::cout << "Ingrese el nombre del personaje: ";
    std::cin >> p->nombre;
    
    std::cout << "Ingrese la clase del personaje (guerrero/mago/arquero): ";
    std::cin >> p->clase;

    std::cout << "Ingrese los puntos de fuerza, agilidad y magia:\n";
    std::cin >> p->fuerza >> p->agilidad >> p->magia;
}

// Función para asignar equipo al personaje
void asignarEquipo(Personaje* p, Equipo* arma, Equipo* armadura) {
    p->arma = arma;
    p->armadura = armadura;
}

// Función para mostrar el personaje y sus atributos totales
void mostrarPersonaje(const Personaje* p) {
    std::cout << "\nPersonaje: " << p->nombre << "\n";
    std::cout << "Clase: " << p->clase << "\n";
    std::cout << "Fuerza: " << p->fuerza + p->arma->bonoFuerza + p->armadura->bonoFuerza << "\n";
    std::cout << "Agilidad: " << p->agilidad + p->arma->bonoAgilidad + p->armadura->bonoAgilidad << "\n";
    std::cout << "Magia: " << p->magia + p->arma->bonoMagia + p->armadura->bonoMagia << "\n";
    std::cout << "Arma: " << p->arma->nombre << "\n";
    std::cout << "Armadura: " << p->armadura->nombre << "\n";
}

// Función para modificar los atributos del personaje
void modificarPersonaje(Personaje* p) {
    std::cout << "\nModificar personaje...\n";
    std::cout << "Ingrese los nuevos puntos de fuerza, agilidad y magia:\n";
    std::cin >> p->fuerza >> p->agilidad >> p->magia;
}

// Función para modificar el equipo
void modificarEquipo(Equipo* e) {
    std::cout << "\nModificar equipo...\n";
    std::cout << "Ingrese el nombre del equipo: ";
    std::cin >> e->nombre;
    
    std::cout << "Ingrese los bonos de fuerza, agilidad y magia del equipo:\n";
    std::cin >> e->bonoFuerza >> e->bonoAgilidad >> e->bonoMagia;
}

int main() {
    // Crear un personaje
    Personaje personaje;
    crearPersonaje(&personaje);

    // Crear un arma y armadura
    Equipo arma = {"Espada", 5, 2, 0};
    Equipo armadura = {"Cota de malla", 3, 1, 0};

    // Asignar equipo al personaje
    asignarEquipo(&personaje, &arma, &armadura);

    // Mostrar el personaje
    mostrarPersonaje(&personaje);

    // Modificar el personaje y su equipo
    modificarPersonaje(&personaje);
    modificarEquipo(&arma);
    modificarEquipo(&armadura);

    // Mostrar el personaje actualizado
    mostrarPersonaje(&personaje);

    return 0;
}
