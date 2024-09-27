/*Película
Crea una estructura llamada Película con los siguientes campons:

Título: nombre de la película
Duración: duración en minutos de la película
Calificación: calificación de la película de 0 a 10
Género: género de la película, puede ser “Acción”, “Comedia”, “Drama”, etc.
Funciones a implementar:
Ingresar Datos de las Películas: Implementa una función que permita ingresar los datos de varias películas (título, duración, calificación y género) y almacenarlos en un arreglo de estructuras.
Calcular Calificación Promedio: Define una función que reciba un arreglo de estructuras y retorne el promedio de la calificación de todas las películas en base a su género, es decir, que muestre el promedio de calificación de las películas de “Acción”, promedio de las películas de “Drama”, etc.
Actualizar Calificación: Define una función que reciba un arreglo de películas y permita actualizar la calificación de cada película según el género. Por ejemplo, las películas de “Acción” pueden ganar un 0.5 en su calificación, o las películas de “Drama” pueden perder todas un 0.2 en su calificación.
Mostrar Datos de las Películas: Define una función que muestre los datos de todas las películas, incluyendo su calificación actualizada después de modificarla.
Buscar una película en específico: Define una función que permita buscar una película por su título y mostrar todos sus datos.*/
#include <iostream>

struct Peliculas
{
    std::string titulo_de_la_pelicula = "";
    std::string duracion_de_la_pelicula_en_minutos = "";
    int calificacion_de_la_pelicula = 0;
    std::string genero_de_la_pelicula = "";
};

struct Promedios
{
    float drama = 0;
    float accion = 0;
    float comedia = 0;
    float otros_generos = 0;
};

void IngresarDatos(Peliculas *pelis, int n);

struct Promedios CalcularPromedio(struct Peliculas *pelis, int n, struct Promedios &promedios);

struct Promedios ActualizarCalificacion(struct Promedios &promedios);

void MostrarPelicula(struct Peliculas *pelis, int n, struct Promedios &promedios);

void BuscarPelicula(struct Peliculas *pelis, int n);

int main(int argc, char *argv[])
{
    Promedios promedios;
    int cantidad_de_peliculas = 0;
    int opcion_en_el_menu = 0;

    std::cout << "----------Bienvenido a Cuevana admin----------" << '\n';
    std::cout << "Coloque la cantidad de peliculas a ingresar: ";
    std::cin >> cantidad_de_peliculas;

    Peliculas arreglo_peliculas[cantidad_de_peliculas];

    do
    {
        std::cout << "-------------MENU----------------" << '\n';
        std::cout << "1. Ingresar datos"<<'\n';
        std::cout << "2. Actualizar calificaion"<<'\n';
        std::cout << "3. Mostrar todas las peliculas"<<'\n';
        std::cout << "4. Buscar peliculas"<<'\n';
        std::cout << "5. Salir"<<'\n';
        std::cout<<"Ingrese su opcion:";
        std::cin>>opcion_en_el_menu;

        switch (opcion_en_el_menu)
        {
        case 1:
            IngresarDatos(arreglo_peliculas, cantidad_de_peliculas);
            promedios = CalcularPromedio(arreglo_peliculas, cantidad_de_peliculas, promedios);

            break;

        case 2:
            promedios = ActualizarCalificacion(promedios);

            break;

        case 3:
            MostrarPelicula(arreglo_peliculas, cantidad_de_peliculas, promedios);

            break;

        case 4:
            BuscarPelicula(arreglo_peliculas, cantidad_de_peliculas);

            break;

        default:

            std::cout << "Escoja una opcion valida.";
            break;
        }

    } while (opcion_en_el_menu != 5);

    return 0;
}

void IngresarDatos(Peliculas *pelis, int n)
{

    std::cout << "Ha escogido la opcion de agregar peliculas." << '\n';
    std::cout << "Ingrese los datos a continuacion: " << '\n';

    for (int i = 0; i < n; i++)
    {
        std::cout << "Ingrese el nombre de la pelicula: ";
        std::cin >> pelis->titulo_de_la_pelicula;
        std::cout << "Ingrese la duracion de la pelicula en minutos: ";
        std::cin >> pelis->duracion_de_la_pelicula_en_minutos;
        std::cout << "Ingrese la calificacion de la pelicula (de 1 a 10): ";
        std::cin >> pelis->calificacion_de_la_pelicula;
        std::cout << "Ingrese el genero de la pelicula: ";
        std::cin >> pelis->genero_de_la_pelicula;
        std::cout << "------------------------------------------------------" << '\n';
    }
}

void MostrarPelicula(struct Peliculas *pelis, int n, struct Promedios &promedios)
{

    std::cout << "--A continuacion vera las peliculas guardadas en el sistema--" << '\n';

    for (int i = 0; i < n; i++)
    {
        std::cout << "Titulo de la pelicula: " << pelis->titulo_de_la_pelicula << '\n';
        std::cout << "Duracion de la pelicula en minutos: " << pelis->duracion_de_la_pelicula_en_minutos << '\n';
        std::cout << "Calificacion de la pelicula: " << pelis->calificacion_de_la_pelicula << '\n';
        std::cout << "Genero de la pelicula: " << pelis->genero_de_la_pelicula << '\n';
        std::cout << "------------------------------------------------------" << '\n';
    }
    std::cout << "Calificacion promedio por generos: " << '\n';
    std::cout << "Peliculas de accion: " << promedios.accion << '\n';
    std::cout << "Peliculas de comedia: " << promedios.comedia << '\n';
    std::cout << "Peliculas de drama: " << promedios.drama;
}

struct Promedios CalcularPromedio(struct Peliculas *pelis, int n, struct Promedios &promedios)
{
    int contador_comedia = 0;
    int contador_drama = 0;
    int contador_accion = 0;
    int contador_otros_generos = 0;

    for (int i = 0; i < n; i++)
    {
        if ((pelis->genero_de_la_pelicula == "Drama") || (pelis->genero_de_la_pelicula == "drama"))
        {
            promedios.drama += pelis->calificacion_de_la_pelicula;
            contador_drama++;
        }
        else if ((pelis->genero_de_la_pelicula == "Accion") || (pelis->genero_de_la_pelicula == "accion"))
        {

            promedios.accion += pelis->calificacion_de_la_pelicula;
            contador_accion++;
        }
        else if ((pelis->genero_de_la_pelicula == "Comedia") || (pelis->genero_de_la_pelicula == "comedia"))
        {

            promedios.comedia += pelis->calificacion_de_la_pelicula;
            contador_comedia++;
        }

        else
        {
            promedios.otros_generos += pelis->calificacion_de_la_pelicula;
            contador_otros_generos++;
        }
    }
    promedios.accion = promedios.accion / contador_accion;
    promedios.drama = promedios.drama / contador_drama;
    promedios.comedia = promedios.comedia / contador_comedia;
    promedios.otros_generos = promedios.otros_generos / contador_otros_generos;

    return promedios;
}

struct Promedios ActualizarCalificacion(struct Promedios &promedios)
{

    std::cout << "Ha escogido la opcion de actualizar la calificacion." << '\n';
    std::cout << "Ingrese el nuevo promedio para las peliculas de comedia: ";
    std::cin >> promedios.comedia;
    std::cout << "Ingrese el nuevo promedio para las peliculas de accion: ";
    std::cin >> promedios.accion;
    std::cout << "Ingrese el nuevo promedio para las peliculas de drama: ";
    std::cin >> promedios.drama;
    std::cout << "Ingrese el nuevo promedio para las peliculas de otros generos: ";
    std::cin >> promedios.otros_generos;

    return promedios;
}

void BuscarPelicula(struct Peliculas *pelis, int n)
{
    std::string nombre_de_la_peli = "";

    std::cout << "-------Buscador de peliculas------" << '\n';
    std::cout << "Ingrese el nombre de la pelicula a buscar: ";
    std::cin >> nombre_de_la_peli;

    for (int i = 0; i < n; i++)
    {
        if (nombre_de_la_peli == pelis->titulo_de_la_pelicula)
        {
            std::cout << "Titulo de la pelicula: " << pelis->titulo_de_la_pelicula << '\n';
            std::cout << "Duracion de la pelicula en minutos: " << pelis->duracion_de_la_pelicula_en_minutos << '\n';
            std::cout << "Calificacion de la pelicula: " << pelis->calificacion_de_la_pelicula << '\n';
            std::cout << "Genero de la pelicula: " << pelis->genero_de_la_pelicula << '\n';
            std::cout << "------------------------------------------------------" << '\n';
        }
    }
    

}