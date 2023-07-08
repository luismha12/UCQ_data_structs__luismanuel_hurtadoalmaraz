// Tarea ParCial 2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void PushBack(const T& value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            // Si la lista está vacía, el nuevo nodo será tanto el primero como el último.
            head = newNode;
            tail = newNode;
        }
        else {
            // Si la lista no está vacía, agregamos el nuevo nodo al final y actualizamos el puntero al último nodo.
            tail->next = newNode;
            tail = newNode;
        }
    }

    void Print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    LinkedList(const std::vector<T>& in_data) : head(nullptr), tail(nullptr) {
        for (const T& value : in_data) {
            // Agregamos cada elemento del vector a la lista.
            PushBack(value);
        }
    }

    void Reverse() {
        if (head == nullptr || head->next == nullptr) {

            return;
        }

        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }


        tail = head;
        head = prev;
    }

    void Unique() {
        if (head == nullptr || head->next == nullptr) {
            // Si la lista está vacía o tiene solo un elemento, no hay duplicados para eliminar.
            return;
        }

        Node* current = head;

        while (current != nullptr) {
            Node* runner = current;

            while (runner->next != nullptr) {
                if (runner->next->data == current->data) {
                    Node* duplicate = runner->next;
                    runner->next = runner->next->next;
                    delete duplicate;
                }
                else {
                    runner = runner->next;
                }
            }

            current = current->next;
        }
    }
};

int main() {