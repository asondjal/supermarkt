#include "kunde.hpp"

static int kunden_counter = 0;

Kunde::Kunde(std::string name, std::string gender, int age, std::string email, std::string adresse) :
    Person(name, gender, age, email, adresse), kundeID_{kunden_counter++} {}


/**
 * @brief Rückgabewert ist die ID eines Kunden
 * @return kundeID_: ID eines Kunden
 */
int Kunde::GetKundeID() const {
    return kundeID_;
}

/**
 * @brief Darstellung der wichtigsten Informationen eines Kunden
 */
void Kunde::Print() const {
    Person::Print();
    std::cout << "Kunden-ID: " << kundeID_ << std::endl;
}
    