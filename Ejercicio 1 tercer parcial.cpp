#include <iostream>

// Definición de la clase RawArray con un tamaño de arreglo fijo.
template<size_t Size>
class RawArray {
private:
    int elements[Size]; // Arreglo para almacenar los elementos.

public:
    // Constructor que inicializa el arreglo con valores del 1 al Size.
    RawArray() {
        for (size_t i = 0; i < Size; ++i) {
            elements[i] = i + 1;
        }
    }

    // Función para acceder a los elementos con índices negativos.
    int& MyFunction(int index) {
        if (index >= 0) {
            return elements[index]; // Acceso a elementos con índice positivo.
        }
        else {
            return elements[Size + index]; // Acceso a elementos con índice negativo.
        }
    }
};

int main() {
    RawArray<5> myArray; // Creación de un objeto RawArray con un tamaño de 5.
    std::cout << myArray.MyFunction(-1) << std::endl; // Imprimirá '5', accediendo al último elemento.

    return 0;
}