#include <iostream>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int numero = 5;
    std::cout << "El factorial de " << numero << " es: " << factorial(numero) << "\n";

    return 0;
}
