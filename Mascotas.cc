/*Mascotas
Crea un programa que almacene mascotas. Cada registro de mascota deberá contener los siguientes campos:

Nombre: nombre de la mascota
Edad: edad de la mascota
Vacunada: indicador de si ha sido o no vacunada.

Funciones a implementar:

Ingresar Datos de las Mascotas: Implementa una función que permita ingresar los datos de varias mascotas (nombre, edad y si han sido vacunadas o no) y almacenarlos en un arreglo de estructuras.

Mostrar Todos los Registros: Implementa una función que muestre los datos de todas las mascotas ingresadas.

Editar Estado de Vacunación: Define una función que permita editar el estado de vacunación de una mascota existente, actualizando el valor de vacunada cuando corresponda.

Filtrar Mascotas por Estado de Vacunación: Implementa una función que permita filtrar y mostrar solo las mascotas que no han sido vacunadas, para poder identificarlas fácilmente.

Contar Mascotas por Estado de Vacunación: Implementa una función que cuente cuántas mascotas han sido vacunadas y cuántas no.

Buscar Mascota por Nombre: Añade una función que permita buscar una mascota por su nombre y mostrar su información (nombre, edad y estado de vacunación). Si no se encuentra la mascota, debe mostrar un mensaje de error.*/

#include <iostream>

struct Mascotas
{
    std::string nombre = "";
    int edad = 0;
    int vacunacion;
};

void IngresarDatos(struct Mascotas mascotas[], int cantidad);

void MostrarRegistros(struct Mascotas mascotas[], int cantidad);

void ModificarEstadoDeVacunacion(struct Mascotas mascotas[], int cantidad);

void FiltrarMascotasPorEstadoDeVacunacion(struct Mascotas mascotas[], int cantidad);

void ContarMascotasPorEstadoDeVacunacion(struct Mascotas mascotas[], int cantidad);

void BuscarMascotasPorNombre(struct Mascotas mascotas[], int cantidad);

int main(int argc, char *argv[])
{

    int cantidad_de_mascotas = 0, opcion_del_usuario_en_el_menu = 0;
    std::cout << "Ingrese la cantidad de mascotas con las que trabajara:";
    std::cin >> cantidad_de_mascotas;
    Mascotas mascotas[cantidad_de_mascotas];

    do
    {
        std::cout << "-----------Bienvenido a Chivo Pets app doc---------" << '\n';
        std::cout << '\t' << "Opciones" << '\n';
        std::cout << "1. Ingresar datos de las mascotas" << '\n';
        std::cout << "2. Mostrar registros de las mascotas" << '\n';
        std::cout << "3. Modificar estado de vacunacion de las mascotas" << '\n';
        std::cout << "4. Mostrar mascotas no vacunadas" << '\n';
        std::cout << "5. Mostrar cantidad de mascotas vacunadas y no vacunadas" << '\n';
        std::cout << "6. Busqueda de mascota en la base de datos" << '\n';
        std::cout << "7. Salir" << '\n';
        std::cout<<"Ingrese su opcion aqui: ";
        std::cin >> opcion_del_usuario_en_el_menu;
        std::cout<<std::endl;

        switch (opcion_del_usuario_en_el_menu)
        {
        case 1:

            IngresarDatos(mascotas, cantidad_de_mascotas);
            break;

        case 2:
            MostrarRegistros(mascotas, cantidad_de_mascotas);
            break;
        case 3:
            ModificarEstadoDeVacunacion(mascotas, cantidad_de_mascotas);
            break;
        case 4:
            FiltrarMascotasPorEstadoDeVacunacion(mascotas, cantidad_de_mascotas);
            break;
        case 5:
            ContarMascotasPorEstadoDeVacunacion(mascotas, cantidad_de_mascotas);
            break;
        case 6:
            BuscarMascotasPorNombre(mascotas, cantidad_de_mascotas);
            break;
        case 7:
            std::cout << "Ha salido del programa";
            break;

        default:
            std::cout << "Por favor escoja una opcion valida";
            break;
        }

    } while (opcion_del_usuario_en_el_menu != 7);

    return 0;
}

void IngresarDatos(struct Mascotas mascotas[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        std::cout << "Ingresa el nombre de la mascota: ";
        std::cin >> mascotas[i].nombre;
        std::cout << "Ingresa la edad de la mascota ";
        std::cin >> mascotas[i].edad;
        std::cout << "Si la mascota esta vacunada ingrese 1, si la mascota no esta vacunada ingrese 0: ";
        std::cin >> mascotas[i].vacunacion;
    }
}

void MostrarRegistros(struct Mascotas mascotas[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        std::cout<<"-------------------------------------------------------"<<'\n';
        std::cout << "Nombre de la mascota: " << mascotas[i].nombre<<'\n';
        std::cout << "Edad de la mascota " << mascotas[i].edad<<'\n';
        std::cout << "Estado de vacunacion: ";
        if (mascotas[i].vacunacion == 1)
        {
            std::cout << "Mascota vacunada"<<'\n';
        }

        else if (mascotas[i].vacunacion == 0)
        {
            std::cout << "Mascota no vacunada"<<'\n';
        }
        std::cout<<"-------------------------------------------------------"<<'\n';
    }
}

void ModificarEstadoDeVacunacion(struct Mascotas mascotas[], int cantidad)
{

    std::string busqueda = "";
    std::cout<<"Ingrese el nombre de la mascota a modificar su estado de vacunacion: ";
    std::cin>>busqueda;
    for (int i = 0; i < cantidad; i++)
    {
        if (busqueda == mascotas[i].nombre)
        {
            std::cout << "Estado de vacunacion de " << mascotas[i].nombre << ": ";

            if (mascotas[i].vacunacion == 1)
            {
                std::cout << "Mascota vacunada";
            }

            else if (mascotas[i].vacunacion == 0)
            {
                std::cout << "Mascota no vacunada";
            }

            std::cout << "Ingrese el nuevo estado de vacunacion (1 para mascota vacunada, 0 para mascota no vacunada): ";
            std::cin >> mascotas[i].vacunacion;
        }
    }
}

void FiltrarMascotasPorEstadoDeVacunacion(struct Mascotas mascotas[], int cantidad)
{

    std::cout << "Listado de mascotas que no han sido vacunadas";

    for (int i = 0; i < cantidad; i++)
    {
        if (mascotas[i].vacunacion == 0)
        {
            std::cout << "-------------------------------------------------------------"<<'\n';
            std::cout << "Nombre de la mascota: " << mascotas[i].nombre << '\n';
            std::cout << "Edad de la mascota: " << mascotas[i].edad << '\n';
            std::cout << "-------------------------------------------------------------" << '\n';
        }
    }
}

void ContarMascotasPorEstadoDeVacunacion(struct Mascotas mascotas[], int cantidad)
{
    int mascotas_vacunadas = 0;
    int mascotas_no_vacunadas = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if (mascotas[i].vacunacion == 1)
        {
            mascotas_vacunadas++;
        }

        else if (mascotas[i].vacunacion == 0)
        {
            mascotas_no_vacunadas++;
        }
    }
    std::cout << "Total de mascotas vacunadas: " << mascotas_vacunadas << '\n';
    std::cout << "Total de mascotas no vacunadas: " << mascotas_no_vacunadas << '\n';
}

void BuscarMascotasPorNombre(struct Mascotas mascotas[], int cantidad)
{

    std::string busqueda = "";
    std::cout<<"Ingrese el nombre de la mascota: ";
    std::cin>>busqueda;

    bool mensaje_error=true;

    for (int i = 0; i < cantidad; i++)
    {
        if (busqueda == mascotas[i].nombre)
        {

            std::cout << "Nombre de la mascota: " << mascotas[i].nombre << '\n';
            std::cout << "Edad de la mascota: " << mascotas[i].edad << '\n';
            std::cout << "Estado de vacunacion de " << mascotas[i].nombre << ": ";

            if (mascotas[i].vacunacion == 1)
            {
                std::cout << "Mascota vacunada";
            }

            else if (mascotas[i].vacunacion == 0)
            {
                std::cout << "Mascota no vacunada";
            }
            mensaje_error = true;
        }

    }
    if (mensaje_error ==false)
    {
        std::cout<<"No se pudo encontrar a la mascota";
    }
    
}