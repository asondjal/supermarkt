#ifndef KUNDE_HPP_
#define KUNDE_HPP_

#include "person.hpp"

class Kunde : public Person {

    private:
    const int kundeID_;

    public:
    Kunde(std::string name, std::string gender, int age, std::string email, std::string adresse);
    int GetKundeID() const;
    void Print() const final;
    bool operator==(const Kunde& other) const;

};

#endif /* KUNDE_HPP_ */