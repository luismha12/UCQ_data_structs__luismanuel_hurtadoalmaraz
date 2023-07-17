#pragma once

template<typename T>
class LStack {
private:
    struct Node {   // Estructura de nodo para almacenar los elementos de la pila
        T value;    // Valor del nodo
        Node* next; // Puntero al siguiente nodo
    };

    Node* topNode;

public:
    LStack() : topNode(nullptr) {}   // Constructor: inicializa la pila vacía

    ~LStack() {   // Destructor: libera la memoria de todos los nodos de la pila
        while (!isEmpty()) {
            Pop();
        }
    }

    void Push(T value) {   // Agrega un elemento a la pila
        Node* newNode = new Node;   // Crea un nuevo nodo
        newNode->value = value;     // Asigna el valor al nuevo nodo
        newNode->next = topNode;    // Establece el siguiente nodo como el nodo superior actual
        topNode = newNode;          // Actualiza el nodo superior con el nuevo nodo
    }

    void Pop() {   // Elimina el elemento superior de la pila
        if (!isEmpty()) {
            Node* temp = topNode;      // Guarda el nodo superior actual
            topNode = topNode->next;   // Actualiza el nodo superior con el siguiente nodo
            delete temp;               // Libera la memoria del nodo eliminado
        }
    }

    T Top() {   // Obtiene el valor del elemento superior de la pila
        if (!isEmpty()) {
            return topNode->value;
        }
        // Aquí puedes lanzar una excepción o devolver un valor predeterminado en caso de que la pila esté vacía.
        return T();  // Devuelve un valor predeterminado (0 para tipos numéricos, cadena vacía para std::string, etc.)
    }

    bool isEmpty() {   // Verifica si la pila está vacía
        return topNode == nullptr;
    }
};
#pragma once
