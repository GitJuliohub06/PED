#include <iostream>

int main() {
    int numeros[10];

    std::cout << "Ingrese 10 números: \n";
    for (int i = 0; i < 10; ++i) {
        std::cin >> numeros[i];
    }

    std::cout << "Los números en orden inverso son: \n";
    for (int i = 9; i >= 0; --i) {
        std::cout << numeros[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
