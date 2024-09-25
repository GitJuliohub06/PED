/*Ejercicios de Recursividad:
Convertir Decimal a Binario: Escribe un programa que imprima el binario de un número decimal. Determina el caso base y el proceso que realizará la función.*/

#include <iostream>

float DecimalABinario(int);

int main(int argc, char *argv[])
{

    DecimalABinario(100);

    return 0;
}

float DecimalABinario(int n)
{

    if (n == 0)
    {
        return n;
    }
    else
    {
        
        DecimalABinario(n / 2);
        std::cout << n % 2;
    }
}