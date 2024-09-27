/*Un grupo de jugadores de juegos de rol quiere un creador de personajes que les permita definir las caracterósticas de sus personajes antes de iniciar una aventura. Cada jugador puede personalizar su personaje eligiendo su nombre, clase y atributos como fuerza. agilidad y magia.

Descripcion del programa:
1. Permite crear un personaje de rol. Cada personaje debe tener un nombre, clase (guerrero, mago, arquero) y tres atributos: fuerza, agilidad y magia.

2. El programa muestra el personaje creado con todos sus atributos.

3. Ofrece la opción de modificar los atributos del persomaje si el jugador desea hacer ajustes.

Usar punteros para manejar los atributos del personaje, estructuras para almacenar los datos y funciones para modificar sus valores y mostrar la información.

*/

#include <iostream>

struct Personaje
{

    std::string nombre = "";
    std::string clase[3] = {"mago", "guerrero", "arquero"};
    int atributos[3];
};

int nuevo_personaje_contador = 0;

void CrearPersonaje(struct Personaje *personaje, int *cantidad_de_personajes);
void MostrarPersonajesTodos(Personaje *personaje, int *cantidad_de_personajes);
void ModificarPersonaje(Personaje *personaje, int *cantidad_de_personajes);

int main(int argc, char *argv[])
{

    int opcion_del_usuario_en_el_menu = 0, cantidad_de_personajes = 0;

    int *ptr_cantidad_de_personajes = &cantidad_de_personajes;

std::cout<<"Ingrese la cantidad de personajes a ingresar: ";
std::cin>>cantidad_de_personajes;
Personaje personajes [cantidad_de_personajes];
std::cout<<std::endl;

    do
    {
std::cout<<"----------MENU----------"<<'\n';
std::cout<<"1. Crear Personajes"<<'\n';
std::cout<<"2. Mostrar Personajes creados"<<'\n';
std::cout<<"3. Modificar los atributos del personaje"<<'\n';
std::cout<<"4. Salir"<<'\n';

std::cout<<"Ingrese su opcion aqui: ";
std::cin>>opcion_del_usuario_en_el_menu;

switch (opcion_del_usuario_en_el_menu)
{
case 1:

    CrearPersonaje(personajes, ptr_cantidad_de_personajes);
    break;

case 2: 

MostrarPersonajesTodos(personajes, ptr_cantidad_de_personajes);
    break; 

case 3: 

ModificarPersonaje(personajes, ptr_cantidad_de_personajes);
    break; 

case 4: 
std::cout<<"Ha salido del programa, :DDD";
break;

default:
std::cout<<"Ingrese una opcion valida"<<'\n';
    break;
}

    } while (opcion_del_usuario_en_el_menu != 4);
    



    return 0;
}

void CrearPersonaje(struct Personaje *personaje, int *cantidad_de_personajes)
{
    for (int i = 0; i < *cantidad_de_personajes; i++)
    {
        std::string personaje_temporal = "";

        std::cout << "Ingrese el nombre de su personaje: ";
        std::cin >> (personaje + i)->nombre;
        do
        {
            std::cout << "Ingrese la calse de su personaje (mago, guerrero o arquero): ";
            std::cin >> personaje_temporal;
            if ((personaje_temporal == "mago") || (personaje_temporal == "Mago"))
            {
                personaje_temporal = (personaje + i)->clase[0];
            }
            else if ((personaje_temporal == "guerrero") || (personaje_temporal == "Guerrero"))
            {
                personaje_temporal = (personaje + i)->clase[1];
            }
            else if ((personaje_temporal == "Arquero") || (personaje_temporal == "arquero"))
            {
                personaje_temporal == (personaje + i)->clase[2];
            }

            else
            {
                std::cout << "Por favor escoja una opcion valida" << '\n';
            }
        } while ((personaje_temporal != "guerrero") && (personaje_temporal != "mago") && (personaje_temporal != "arquero") && (personaje_temporal != "Guerrero") && (personaje_temporal != "Mago") && (personaje_temporal != "Arquero"));

        std::cout << "Ingrese el valor de la fuerza: ";
        std::cin >> (personaje + i)->atributos[0];
        std::cout << "Ingrese el valor de la agilidad: ";
        std::cin >> (personaje + i)->atributos[1];
        std::cout << "Ingrese el valor de la magia: ";
        std::cin >> (personaje + i)->atributos[2];
        nuevo_personaje_contador++;
    }
}

void MostrarPersonajesTodos(Personaje *personaje, int *cantidad_de_personajes)
{
    for (int i = 0; i < *cantidad_de_personajes; i++)
    {
        std::cout << "------------Datos del personaje creado----------------" << '\n';
        std::cout << "Nombre del personaje: " << (personaje + i)->nombre << '\n';

        std::cout << "Clase: " << *(personaje + i)->clase << '\n';
        std::cout << "\tAtributos: " << '\n';

        std::cout << "Fuerza: " << (personaje + i)->atributos[0]<<'\n';
        std::cout << "Agilidad: " << (personaje + i)->atributos[1]<<'\n';
        std::cout << "Magia: " << (personaje + i)->atributos[2]<<'\n';
    }
}

void ModificarPersonaje(Personaje *personaje, int *cantidad_de_personajes)
{
bool personaje_encontrado = false;
do
{
    std::string nombre_personaje_temporal = "";
    std::cout<<"Ingresa el nombre del personaje al cual modificar datos: ";
    std::cin>>nombre_personaje_temporal;

    for (int i = 0; i < *cantidad_de_personajes; i++)
    {
        if (nombre_personaje_temporal == (personaje + i)->nombre)
        {
            std::cout<<"-----Personaje "<<(personaje + i)->nombre<<" Encontrado.-----"<<'\n';
            std::cout<<"Clase: "<<*(personaje + i)->clase<<'\n';
            std::cout << "Ingrese el valor de la fuerza: ";
            std::cin >> (personaje + i)->atributos[0];
            std::cout << "Ingrese el valor de la agilidad: ";
            std::cin >> (personaje + i)->atributos[1];
            std::cout << "Ingrese el valor de la magia: ";
            std::cin >> (personaje + i)->atributos[2];
            nuevo_personaje_contador++;

            personaje_encontrado = true;
        }

        
    }
    if (personaje_encontrado==false)
    {
        std::cout<<"No se pudo encontrar al personaje, intente denuevo"<<'\n';
    }
} while (personaje_encontrado ==false);


    
}
