#ifndef PRODUKT_HPP_
#define PRODUKT_HPP_

#include <string>
#include <iostream>
#include <iomanip>
#include "datum.hpp"

class Produkt {

    private:
    const std::string name_;
    const float menge_; // in kg
    const float preis_; // in €
    const Datum haltbarkeit_; // im Format TT.MM.JJJJ
    const int id_;
    const std::string abteilung_;

    public:
    Produkt(std::string name, float menge, float preis, Datum haltbarkeit, std::string abteilung);
    std::string GetName() const;
    float GetMenge() const;
    float GetPreis() const;
    float GetGesamtPreis() const;
    Datum GetHaltbarkeit() const;
    int GetID() const;
    std::string GetAbteilung() const;
    void Display() const;

};

#endif /* PRODUKT_HPP_ */