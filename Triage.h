#pragma once
#include "LQueue.h"
#include <iostream>

class Triage {
private:
    static const int NUM_LEVELS = 5;  // Número de niveles de urgencia
    LQueue<std::string> PatientQueues[NUM_LEVELS];  // Arreglo de colas para cada nivel de urgencia

public:
    void AddPatient(int urgency, std::string patient_name) {   // Agrega un paciente al nivel de urgencia especificado
        if (urgency >= 1 && urgency <= NUM_LEVELS) {
            PatientQueues[urgency - 1].Enqueue(patient_name);
        }
    }

    void PassPatient() {   // Pasa al siguiente paciente en orden de prioridad
        for (int i = 0; i < NUM_LEVELS; ++i) {
            if (!PatientQueues[i].isEmpty()) {
                PatientQueues[i].Dequeue();
                return;
            }
        }
    }

    void Print() {   // Imprime el estado actual de las colas de pacientes
        for (int i = 0; i < NUM_LEVELS; ++i) {
            std::cout << i + 1 << " -> ";
            if (PatientQueues[i].isEmpty()) {
                std::cout << "\n";
            }
            else {
                LQueue<std::string> tempQueue = PatientQueues[i];
                while (!tempQueue.isEmpty()) {
                    std::cout << tempQueue.Front();
                    tempQueue.Dequeue();
                    if (!tempQueue.isEmpty()) {
                        std::cout << ", ";
                    }
                }
                std::cout << "\n";
            }
        }
    }
};

