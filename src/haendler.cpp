#include "../inc/base/haendler.hpp"

static int haendlerCounter_ = 0;

Haendler::Haendler(std::string name, std::string gender, int alter, std::string email, std::string adresse)
    : Person(name, gender, alter, email, adresse), haendlerID_(haendlerCounter_++) {
}


/**
 * @brief Überladung des Vergleichsoperators für die Klasse Haendler
 */
bool Haendler::operator==(const Haendler& other) const {
    return haendlerID_ == other.GetHaendlerID();
}

/**
 * @brief Funktion zur Wiedergabe der ID eines Händlers
 */
int Haendler::GetHaendlerID() const {
    return haendlerID_;
}

/**
 * @brief Funktion zur Präsentation der Informationen über einen Händler
 */
void Haendler::Print() const {
    Person::Print();
    std::cout << "Haendler ID: " << haendlerID_ << std::endl;
}