#include <iostream>
#include <cstring>

template <typename T>
class RawArray
{
private:
    T* array;
    int length;

public:
    RawArray(int len) : length(len)
    {
        array = new T[length];
    }

    ~RawArray()
    {
        delete[] array;
    }

    int Length() const
    {
        return length;
    }

    T& operator[](int index)
    {
        return array[index];
    }

    const T& operator[](int index) const
    {
        return array[index]; // constante para los elementos
    }

    void Copy(const RawArray<T>& otherArray)
    {
        int copyLength = otherArray.Length() < length ? otherArray.Length() : length;
        for (int i = 0; i < copyLength; i++)
        {
            array[i] = otherArray[i]; // Copia los elemnetos desde otro RawArray al RawArray actual
        }
    }

    void Copy(const T sourceArray[], int sourceLength)
    {
        int copyLength = sourceLength < length ? sourceLength : length;
        for (int i = 0; i < copyLength; i++)
        {
            array[i] = sourceArray[i];
        }
    }
};

int main()
{
    RawArray<char> prueba(5); //crea una array con una longitud de 5
    RawArray<char> aCopiar(5);
    char miArray[5] = { 'L', 'U', 'I', 'S', 'A' }; //array de los elemenstos necesarios

    aCopiar.Copy(prueba); //copia los elementos d copia
    prueba.Copy(miArray, 5); //copia los elementos de miArray

    std::cout << "Elementos en el RawArray después de copiar otro RawArray:" << std::endl;
    for (int i = 0; i < prueba.Length(); i++)
    {
        std::cout << prueba[i] << std::endl;
    }

    std::cout << "Elementos en el RawArray después de copiar un array de caracteres:" << std::endl;
    for (int i = 0; i < prueba.Length(); i++)
    {
        std::cout << prueba[i] << std::endl;
    }

    return 0;
}