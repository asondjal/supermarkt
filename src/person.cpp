#include "person.hpp"

static int personen_counter = 0;

Person::Person(std::string name, std::string gender, int age, std::string email, std::string adresse) :
    name_{name}, gender_{gender}, age_{age}, email_{email}, adresse_{adresse}, personID_{personen_counter++} {}

std::string Person::GetName() const {
    return name_;
}

std::string Person::GetGender() const {
    return gender_;
}

int Person::GetAge() const {
    return age_;
}

std::string Person::GetEmail() const {
    return email_;
}

std::string Person::GetAdresse() const {
    return adresse_;
}

void Person::Print() const {
    std::cout << "Name: " << name_ << "\n"
        << "Alter: " << age_ << "\n" 
        << "Geschlecht: " << gender_ << "\n"
        << "Email: " << email_ << "\n"
        << "Adresse: " << adresse_ << std::endl;
}