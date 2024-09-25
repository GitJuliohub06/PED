/*Suma de los Elementos de un Arreglo: Crea una función recursiva que sume todos los elementos de un arreglo de enteros.

Entrada: [2, 4, 6, 8]
Salida: 20*/

#include <iostream>

int SumaElementosArreglo(int[], int, int);

int main(int argc, char *argv[])
{

    int entrada[6] = {2, 4, 6, 8,8,8};

    std::cout<<SumaElementosArreglo(entrada, 6, 0);

    return 0;
}

int SumaElementosArreglo(int n[], int tamanio, int suma)
{
    int suma_total = suma;
    int tamanio_arreglo = tamanio;
    if (tamanio == 0)
    {
        return suma_total;
    }
    else
    {
        return n[tamanio-1] + SumaElementosArreglo(n, tamanio - 1, suma);
    }
}