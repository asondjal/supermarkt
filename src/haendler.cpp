#include "haendler.hpp"

static int haendlerCounter_ = 0;

Haendler::Haendler(std::string name, std::string gender, int alter, std::string email, std::string adresse)
    : Person(name, gender, alter, email, adresse), haendlerID_(haendlerCounter_++) {
}

int Haendler::GetHaendlerID() const {
    return haendlerID_;
}

void Haendler::Print() const {
    Person::Print();
    std::cout << "Haendler ID: " << haendlerID_ << std::endl;
}