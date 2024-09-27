#include <iostream>

void sumarArreglos(int arr1[], int arr2[], int resultado[], int n) {
    for (int i = 0; i < n; ++i) {
        resultado[i] = arr1[i] + arr2[i];
    }
}

int main() {
    int arreglo1[5] = {1, 2, 3, 4, 5};
    int arreglo2[5] = {6, 7, 8, 9, 10};
    int suma[5];

    sumarArreglos(arreglo1, arreglo2, suma, 5);

    std::cout << "La suma de los arreglos es: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << suma[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
