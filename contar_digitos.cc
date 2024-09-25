/*Contar Dígitos de un Número: Crea una función recursiva que cuente cuántos dígitos tiene un número entero positivo.

Ejemplo: 12345 tiene 5 dígitos.*/
#include <iostream>

int ContarDigitos(int, int);

int main(int argc, char *argv[])
{

    std::cout << ContarDigitos(10000325, 0);

    return 0;
}

int ContarDigitos(int n, int conta)
{
    int contador = 0;
    contador = conta;

    if (n < 1)
    {
        return contador;
    }

    else
    {
        contador++;
        return ContarDigitos(n / 10, contador);
    }

    return contador;
}