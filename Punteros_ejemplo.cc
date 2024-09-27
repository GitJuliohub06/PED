#include <iostream>

void intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    std::cout << "Antes del intercambio: x = " << x << ", y = " << y << "\n";

    intercambiar(&x, &y);

    std::cout << "Después del intercambio: x = " << x << ", y = " << y << "\n";

    return 0;
}
