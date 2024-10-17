#include <iostream>
#include <algorithm>
#include <array>
struct Libro {
    std::string titulo;
    std::string autor;
    std::string genero;
    int veces_solicitado;
};

void AgregarLibro(Libro libros[], int& cantidad) {
    if (cantidad >= 100) {
        std::cout << "No se pueden agregar mas libros. Limite alcanzado.\n";
        return;
    }
    
    Libro nuevo_libro;
    std::cout << "Ingrese el titulo del libro: ";
    std::getline(std::cin, nuevo_libro.titulo);
    std::cout << "Ingrese el autor del libro: ";
    std::getline(std::cin, nuevo_libro.autor);
    std::cout << "Ingrese el genero del libro: ";
    std::getline(std::cin, nuevo_libro.genero);
    std::cout << "Ingrese la cantidad de veces que ha sido solicitado: ";
    std::cin >> nuevo_libro.veces_solicitado;
    std::cin.ignore();

    libros[cantidad] = nuevo_libro;
    cantidad++;
    std::cout << "Libro agregado exitosamente.\n";
}

void OrdenarLibrosPorPopularidad(Libro libros[], int cantidad) {
    std::sort(libros, libros + cantidad, [](const Libro& a, const Libro& b) {
        return a.veces_solicitado > b.veces_solicitado;
    });

    std::cout << "Libros ordenados por popularidad:\n";
    for (int i = 0; i < cantidad; ++i) {
        std::cout << "Titulo: " << libros[i].titulo
                  << ", Autor: " << libros[i].autor
                  << ", Genero: " << libros[i].genero
                  << ", Veces solicitado: " << libros[i].veces_solicitado << "\n";
    }
}
bool CompararAutores(const Libro& a, const Libro& b){
  return a.autor < b.autor;
}
void BinarySearch(Libro libros[], int cantidad){
 std::sort(libros, libros + cantidad, CompararAutores);
int inicio=0, mitad=0, final=0, libro_encontrado=-1, indice =0;
    std::string nombre;
    std::cout << "Ingrese el nombre del autor que desea buscar: ";
    std::getline(std::cin, nombre);
  final = cantidad -1;
    while (inicio <= final) {
        mitad = inicio + (final - inicio) / 2;

        if (libros[mitad].autor == nombre) {
            libro_encontrado = mitad;
            break;
        } else if (libros[mitad].autor < nombre) {
            inicio = mitad + 1;
        } else {
            final = mitad - 1;
        }
    }
    if (libro_encontrado != -1) {
        std::cout << "Libros del autor son: " << nombre << ":\n";
        indice = libro_encontrado;
        while (indice >= 0 && libros[indice].autor == nombre) {
            --indice;
        }
        ++indice;
        while (indice < cantidad && libros[indice].autor == nombre) {
            std::cout <<indice<<" "<<libros[indice].titulo << "\n";
            ++indice;
        }
    } else {
        std::cout << "No se encontraron libros del autor " << nombre << ".\n";
    }
}

int main() {
    Libro libros[100];
    int cantidad = 0;

    int opcion = 0;
    while (true) {
        std::cout << "\nMENU:\n";
        std::cout << "1. Agregar libro\n";
        std::cout << "2. Ordenar libros por popularidad\n";
        std::cout << "3. Buscar por autor\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore();

         if (opcion == 1) {
            AgregarLibro(libros, cantidad);
        } else if (opcion == 2) {
            OrdenarLibrosPorPopularidad(libros, cantidad);
        } 
          else if (opcion==3){
            BinarySearch(libros, cantidad);
          }
        else if (opcion == 4) {
            break;
        } else {
            std::cout << "Opcion invalida. Intentelo de nuevo.\n";
        }
    }

    return 0;
}
