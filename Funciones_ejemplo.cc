#include <iostream>

int encontrarMaximo(int arr[], int n) {
    int maximo = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maximo) {
            maximo = arr[i];
        }
    }
    return maximo;
}

int main() {
    int numeros[10] = {1, 2, 5, 9, 3, 8, 4, 7, 6, 10};

    int maximo = encontrarMaximo(numeros, 10);

    std::cout << "El valor máximo es: " << maximo << "\n";

    return 0;
}
