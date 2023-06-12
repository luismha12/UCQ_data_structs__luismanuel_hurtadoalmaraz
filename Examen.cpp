#include <iostream>

class RawArray {
private:
    int* array; // Puntero para almacenar el arreglo dinámico
    int size; // Tamaño del arreglo

public:
    // Constructor de la clase RawArray
    RawArray(int size) {
        this->size = size;
        array = new int[size]; // Asigna memoria dinámica al arreglo
    }

    // Destructor de la clase RawArray
    ~RawArray() {
        delete[] array; // Libera la memoria asignada al arreglo
    }

    // Inicializa todos los elementos del arreglo con un valor específico
    void init(int value) {
        for (int i = 0; i < size; i++) {
            array[i] = value;
        }
    }

    // Imprime los elementos del arreglo
    void print() {
        std::cout << "[";
        for (int i = 0; i < size; i++) {
            std::cout << array[i];
            if (i != size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    // Asigna un valor a uno de cada X elementos del arreglo
    void assignEveryXElements(int v, int x) {
        for (int i = 0; i < size; i += x) {
            array[i] = v;
        }
    }

    // Ordena los elementos del arreglo de menor a mayor
    void sortFunction() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    // Obtiene el índice de la primera aparición de un valor en el arreglo
    int getIndexOf(int x) {
        for (int i = 0; i < size; i++) {
            if (array[i] == x) {
                return i;
            }
        }
        return -1; // Si no se encuentra el valor, retorna -1
    }

    // Obtiene el índice de la última aparición de un valor en el arreglo
    int getLastOf(int x) {
        for (int i = size - 1; i >= 0; i--) {
            if (array[i] == x) {
                return i;
            }
        }
        return -1; // Si no se encuentra el valor, retorna -1
    }

    // Obtiene los índices de todas las apariciones de un valor en el arreglo
    RawArray getIndicesOf(int x) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (array[i] == x) {
                count++;
            }
        }

        RawArray indices(count); // Crea un objeto RawArray para almacenar los índices
        int currentIndex = 0;
        for (int i = 0; i < size; i++) {
            if (array[i] == x) {
                indices.array[currentIndex] = i;
                currentIndex++;
            }
        }

        return indices; // Retorna el objeto RawArray con los índices
    }

    // Agrega los elementos de otro RawArray al final del arreglo actual
    void appendArray(const RawArray& arrayToAppend) {
        int newSize = size + arrayToAppend.size;
        int* newArray = new int[newSize];

        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }

        for (int i = 0; i < arrayToAppend.size; i++) {
            newArray[size + i] = arrayToAppend.array[i];
        }

        delete[] array;
        array = newArray;
        size = newSize;
    }

    // Modifica el tamaño del arreglo
    void setSize(int newSize) {
        if (newSize == size) {
            return; // Si el nuevo tamaño es igual al tamaño actual, no se realiza ningún cambio
        }

        int* newArray = new int[newSize];

        if (newSize > size) {
            // Si el nuevo tamaño es mayor al tamaño actual, se copian los elementos actuales
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
        }
        else {
            // Si el nuevo tamaño es menor al tamaño actual, se copian los primeros elementos hasta el nuevo tamaño
            for (int i = 0; i < newSize; i++) {
                newArray[i] = array[i];
            }
        }

        delete[] array;
        array = newArray; // Asigna el nuevo arreglo al puntero
        size = newSize; // Actualiza el tamaño del arreglo
    }

    // Inserta los elementos de otro RawArray en el arreglo actual a partir de un índice dado
    void insert(const RawArray& arrayToInsert, int startIndex) {
        int newSize = size + arrayToInsert.size;
        int* newArray = new int[newSize]; // Crea un nuevo arreglo con el tamaño adecuado

        for (int i = 0; i < startIndex; i++) {
            newArray[i] = array[i];
        }

        for (int i = 0; i < arrayToInsert.size; i++) {
            newArray[startIndex + i] = arrayToInsert.array[i];
        }

        for (int i = startIndex; i < size; i++) {
            newArray[arrayToInsert.size + i] = array[i];
        }

        delete[] array;
        array = newArray; // Asigna el nuevo arreglo al puntero
        size = newSize; // Actualiza el tamaño 
    }

    // Suma elemento por elemento los elementos de otro RawArray con los del arreglo actual
    RawArray sumArrays(const RawArray& A) {
        RawArray result(size); // Crea un nuevo RawArray para almacenar el resultado de la suma

        for (int i = 0; i < size; i++) {
            result.array[i] = array[i] + A.array[i];
        }

        return result; // Retorna el objeto RawArray con el resultado de la suma
    }
};

int main() {
    RawArray myArray(5);
    myArray.init(0);

    RawArray toBeInserted(3);
    toBeInserted.init(1);

    int currentStartIndex = 3;
    myArray.insert(toBeInserted, currentStartIndex);
    myArray.print();
    // Debería imprimir [0, 0, 0, 1, 1, 1, 0, 0]

    return 0;
}