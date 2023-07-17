#pragma once

template<typename T>
class LQueue {
private:
    struct Node {   // Estructura de nodo para almacenar los elementos de la cola
        T value;    // Valor del nodo
        Node* next; // Puntero al siguiente nodo
    };

    Node* frontNode;  // Puntero al nodo del frente de la cola
    Node* backNode;   // Puntero al nodo de la parte posterior de la cola

public:
    LQueue() : frontNode(nullptr), backNode(nullptr) {}   // Constructor: inicializa la cola vacía

    ~LQueue() {   // Destructor: libera la memoria de todos los nodos de la cola
        while (!isEmpty()) {
            Dequeue();
        }
    }

    void Enqueue(T value) {   // Agrega un elemento al final de la cola
        Node* newNode = new Node;  // Crea un nuevo nodo
        newNode->value = value;    // Asigna el valor al nuevo nodo
        newNode->next = nullptr;

        if (isEmpty()) {            // Si la cola está vacía, el nuevo nodo se convierte en el frente y la parte posterior
            frontNode = newNode;
            backNode = newNode;
        }
        else {                    // Si la cola no está vacía, se agrega el nuevo nodo después del último nodo
            backNode->next = newNode;
            backNode = newNode;
        }
    }

    void Dequeue() {   // Elimina el elemento del frente de la cola
        if (!isEmpty()) {
            Node* temp = frontNode;    // Guarda el nodo del frente actual
            frontNode = frontNode->next;  // Actualiza el frente con el siguiente nodo
            delete temp;               // Libera la memoria del nodo eliminado

            if (frontNode == nullptr) {   // Si el frente se convierte en nullptr, la cola está vacía
                backNode = nullptr;     // Por lo tanto, la parte posterior también se establece en nullptr
            }
        }
    }

    T Front() {   // Obtiene el valor del elemento del frente de la cola
        if (!isEmpty()) {
            return frontNode->value;
        }
        // Para simplificar, devolveré un valor predeterminado (puede ser modificado según las necesidades).
        return T();  // Devuelve un valor predeterminado (0 para tipos numéricos, cadena vacía para std::string, etc.)
    }

    T Back() {   // Obtiene el valor del elemento de la parte posterior de la cola
        if (!isEmpty()) {
            return backNode->value;
        }
        return T();
    }

    bool isEmpty() {   // Verifica si la cola está vacía
        return frontNode == nullptr;
    }
};
#pragma once
