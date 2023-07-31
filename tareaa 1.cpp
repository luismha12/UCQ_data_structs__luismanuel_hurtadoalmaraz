#pragma once

#include <iostream>
#include <stack>

template<typename T>
class BinaryTree
{
private:
    // Estructura de Nodo para representar cada elemento en el árbol binario
    template <typename U>
    struct Nodo
    {
    public:
        Nodo(U in_data, Nodo<U>* in_parent, Nodo<U>* in_left = nullptr, Nodo<U>* in_right = nullptr) :
            data(in_data), parent(in_parent), left(in_left), right(in_right)
        {
        }

        ~Nodo()
        {
        }

        U data;
        Nodo<U>* parent;
        Nodo<U>* left;
        Nodo<U>* right;
    };

    Nodo<T>* root; // Puntero a la raíz del árbol binario

public:
    BinaryTree() : root(nullptr)
    {
    }

    // Destructor para liberar la memoria ocupada por el árbol
    ~BinaryTree()
    {
        while (root != nullptr)
        {
            EliminarNodo(root);
        }
    }

    // Función que devuelve un puntero al nodo raíz del árbol
    Nodo<T>* ObtenerRaiz()
    {
        return root;
    }

    // Función para encontrar el nodo con el valor mínimo a partir de un nodo dado
    Nodo<T>* MinimoDesdeNodo(Nodo<T>* in_root)
    {
        Nodo<T>* temp = in_root;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        return temp;
    }

    // Función que devuelve el nodo con el valor mínimo en el árbol
    Nodo<T>* Minimo()
    {
        return MinimoDesdeNodo(root);
    }

    // Función que devuelve el valor mínimo en el árbol
    T ValorMinimo()
    {
        Nodo<T>* temp = Minimo();
        if (temp != nullptr)
        {
            return temp->data;
        }
        // En caso de que el árbol esté vacío, se debe manejar este caso también (por ejemplo, lanzando una excepción o devolviendo un valor predeterminado)
    }

    // Función para encontrar el nodo con el valor máximo a partir de un nodo dado
    Nodo<T>* MaximoDesdeNodo(Nodo<T>* in_root)
    {
        Nodo<T>* temp = in_root;
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }
        return temp;
    }

    // Función que devuelve el nodo con el valor máximo en el árbol
    Nodo<T>* Maximo()
    {
        return MaximoDesdeNodo(root);
    }

    // Función que devuelve el valor máximo en el árbol
    T ValorMaximo()
    {
        Nodo<T>* temp = Maximo();
        if (temp != nullptr)
        {
            return temp->data;
        }
        // En caso de que el árbol esté vacío, se debe manejar este caso también (por ejemplo, lanzando una excepción o devolviendo un valor predeterminado)
    }

    // Función para buscar un valor en el árbol y devolver el nodo que lo contiene (si existe)
    Nodo<T>* Buscar(T valor)
    {
        Nodo<T>* temp = root;
        while (temp != nullptr && temp->data != valor)
        {
            if (valor < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return temp;
    }

    // Función para insertar un nuevo valor en el árbol binario
    void Insertar(T valor)
    {
        Nodo<T>* temp = root;
        Nodo<T>* temp_padre = nullptr;
        while (temp != nullptr)
        {
            if (valor < temp->data)
            {
                temp_padre = temp;
                temp = temp->left;
            }
            else
            {
                temp_padre = temp;
                temp = temp->right;
            }
        }

        Nodo<T>* nuevoNodo = new Nodo<T>(valor, temp_padre);
        if (temp_padre == nullptr)
        {
            root = nuevoNodo;
        }
        else if (valor < temp_padre->data)
        {
            temp_padre->left = nuevoNodo;
        }
        else
        {
            temp_padre->right = nuevoNodo;
        }
    }

    // Función que devuelve el sucesor de un nodo dado en el árbol
    Nodo<T>* Sucesor(Nodo<T>* in_x)
    {
        if (in_x->right != nullptr)
        {
            return MinimoDesdeNodo(in_x->right);
        }
        else
        {
            Nodo<T>* actual = in_x;
            Nodo<T>* temp_padre = in_x->parent;
            while (temp_padre != nullptr && temp_padre->right == actual)
            {
                actual = temp_padre;
                temp_padre = actual->parent;
            }
            return temp_padre;
        }
    }

    // Función que devuelve el predecesor de un nodo dado en el árbol
    Nodo<T>* Predecesor(Nodo<T>* in_x)
    {
        if (in_x->left != nullptr)
        {
            return MaximoDesdeNodo(in_x->left);
        }
        else
        {
            Nodo<T>* actual = in_x;
            Nodo<T>* temp_padre = in_x->parent;
            while (temp_padre != nullptr && temp_padre->left == actual)
            {
                actual = temp_padre;
                temp_padre = actual->parent;
            }
            return temp_padre;
        }
    }

    // Función para recorrer el árbol en orden (in-order) y mostrar los valores
    void EnOrden(Nodo<T>* in_x)
    {
        if (in_x != nullptr)
        {
            EnOrden(in_x->left);
            std::cout << in_x->data << ", ";
            EnOrden(in_x->right);
        }
    }

    // Función para recorrer el árbol en preorden (pre-order) y mostrar los valores
    void PreOrden(Nodo<T>* in_x)
    {
        if (in_x != nullptr)
        {
            std::cout << in_x->data << ", ";
            PreOrden(in_x->left);
            PreOrden(in_x->right);
        }
    }

    // Función para recorrer el árbol en postorden (post-order) y mostrar los valores
    void PostOrden(Nodo<T>* in_x)
    {
        if (in_x != nullptr)
        {
            PostOrden(in_x->left);
            PostOrden(in_x->right);
            std::cout << in_x->data << ", ";
        }
    }

    // Función para reemplazar un nodo del árbol con otro nodo
    void Transplant(Nodo<T>* in_u, Nodo<T>* in_v)
    {
        if (in_u->parent == nullptr)
        {
            root = in_v;
        }
        else if (in_u == in_u->parent->left)
        {
            in_u->parent->left = in_v;
        }
        else
        {
            in_u->parent->right = in_v;
        }
        if (in_v != nullptr)
        {
            in_v->parent = in_u->parent;
        }
    }

    // Función para eliminar un nodo del árbol
    void EliminarNodo(Nodo<T>* in_z)
    {
        if (in_z->left == nullptr)
        {
            Transplant(in_z, in_z->right);
        }
        else if (in_z->right == nullptr)
        {
            Transplant(in_z, in_z->left);
        }
        else
        {
            Nodo<T>* Y = MinimoDesdeNodo(in_z->right);
            if (Y != in_z->right)
            {
                Transplant(Y, Y->right);
                Y->right = in_z->right;
                Y->right->parent = Y;
            }
            Transplant(in_z, Y);
            Y->left = in_z->left;
            Y->left->parent = Y;
        }
        delete in_z;
    }

    // Función para realizar el recorrido in-order de manera iterativa
    void EnOrdenIterativo()
    {
        if (root == nullptr)
        {
            return;
        }

        std::stack<Nodo<T>*> pilaNodos;
        Nodo<T>* actual = root;

        while (actual != nullptr || !pilaNodos.empty())
        {
            while (actual != nullptr)
            {
                pilaNodos.push(actual);
                actual = actual->left;
            }

            actual = pilaNodos.top();
            pilaNodos.pop();

            std::cout << actual->data << ", ";

            actual = actual->right;
        }
    }

    // Función para realizar el recorrido pre-order de manera iterativa
    void PreOrdenIterativo()
    {
        if (root == nullptr)
        {
            return;
        }

        std::stack<Nodo<T>*> pilaNodos;
        pilaNodos.push(root);

        while (!pilaNodos.empty())
        {
            Nodo<T>* actual = pilaNodos.top();
            pilaNodos.pop();

            std::cout << actual->data << ", ";

            if (actual->right != nullptr)
            {
                pilaNodos.push(actual->right);
            }

            if (actual->left != nullptr)
            {
                pilaNodos.push(actual->left);
            }
        }
    }

    // Función para realizar el recorrido post-order de manera iterativa
    void PostOrdenIterativo()
    {
        if (root == nullptr)
        {
            return;
        }

        std::stack<Nodo<T>*> pila1, pila2;
        pila1.push(root);

        // Llenar pila2 con el recorrido post-order invertido
        while (!pila1.empty())
        {
            Nodo<T>* actual = pila1.top();
            pila1.pop();
            pila2.push(actual);

            if (actual->left != nullptr)
            {
                pila1.push(actual->left);
            }

            if (actual->right != nullptr)
            {
                pila1.push(actual->right);
            }
        }

        // Mostrar los valores del recorrido post-order
        while (!pila2.empty())
        {
            Nodo<T>* actual = pila2.top();
            pila2.pop();
            std::cout << actual->data << ", ";
        }
    }
};