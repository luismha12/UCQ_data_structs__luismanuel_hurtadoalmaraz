#include <iostream>
#include <string>
#include <vector>

// Definición de la clase Email para representar un correo electrónico
struct Email {
    std::string from;
    std::string subject;
    std::string content;
    bool isRead;
    bool isStarred;

    // Constructor para crear un correo electrónico
    Email(const std::string& _from, const std::string& _subject, const std::string& _content)
        : from(_from), subject(_subject), content(_content), isRead(false), isStarred(false) {
    }
};

// Definición de la clase Inbox para manejar los correos electrónicos
class Inbox {
private:
    std::vector<Email> emails;

public:
    // Agregar un nuevo correo electrónico a la bandeja de entrada
    void AddEmail(const Email& email) {
        emails.push_back(email);
    }

    // Borrar un correo electrónico de la bandeja de entrada
    void DeleteEmail(size_t index) {
        if (index < emails.size()) {
            emails.erase(emails.begin() + index);
        }
    }

    // Filtrar correos electrónicos según la opción seleccionada
    std::vector<Email> FilterEmails(bool read, bool starred) {
        std::vector<Email> filteredEmails;
        for (const Email& email : emails) {
            if ((read && email.isRead) || (!read && !email.isRead)) {
                if ((starred && email.isStarred) || (!starred && !email.isStarred)) {
                    filteredEmails.push_back(email);
                }
            }
        }
        return filteredEmails;
    }
};

int main() {
    // Crear la bandeja de entrada
    Inbox inbox;

    // Agregar algunos correos electrónicos de ejemplo
    inbox.AddEmail(Email("antoniogarza18@hotmail.com", "Hola hermano"));
    inbox.AddEmail(Email("luisquintana@gmail.com", "¿Cómo estás?"));
    inbox.AddEmail(Email("eduardoperez@hotmail.com", "¿Irás a la escuela?"));

    // Marcar correos como leídos y destacados
    inbox.FilterEmails(false, false)[0].isRead = true;
    inbox.FilterEmails(false, false)[1].isStarred = true;

    // Filtrar correos electrónicos leídos y no destacados
    std::vector<Email> readUnstarredEmails = inbox.FilterEmails(true, false);
    std::cout << "Correos electrónicos leídos y no destacados:\n";
    for (const Email& email : readUnstarredEmails) {
        std::cout << "De: " << email.from << " - Asunto: " << email.subject << "\n";
    }

    // Filtrar todos los correos electrónicos
    std::vector<Email> allEmails = inbox.FilterEmails(false, false);
    std::cout << "\nTodos los correos electrónicos:\n";
    for (const Email& email : allEmails) {
        std::cout << "De: " << email.from << " - Asunto: " << email.subject << "\n";
    }

    return 0;
}