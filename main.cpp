#include <iostream>
#include "LStack.h"
#include "LQueue.h"
#include "Triage.h"

int main() {
    LStack<int> stack;
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    std::cout << "Top: " << stack.Top() << std::endl;  // Salida: 30
    stack.Pop();
    std::cout << "Top: " << stack.Top() << std::endl;  // Salida: 20

    LQueue<std::string> queue;
    queue.Enqueue("PATRICIO");
    queue.Enqueue("BOB ESPONJA");
    std::cout << "Front: " << queue.Front() << std::endl;  // Salida: PATRICIO
    std::cout << "Back: " << queue.Back() << std::endl;    // Salida: BOB ESPONJA
    queue.Dequeue();
    std::cout << "Front: " << queue.Front() << std::endl;  // Salida: BOB ESPONJA

    Triage myTriage;
    myTriage.AddPatient(1, "luis");
    myTriage.AddPatient(5, "sorriana");
    myTriage.AddPatient(3, "LALA");
    myTriage.AddPatient(2, "Sofia");
    myTriage.AddPatient(1, "chaparro");
    myTriage.AddPatient(4, "Olivia");
    myTriage.AddPatient(5, "guero");
    myTriage.AddPatient(1, "Emiliano");

    myTriage.PassPatient();
    myTriage.PassPatient();

    myTriage.Print();

    return 0;
}
