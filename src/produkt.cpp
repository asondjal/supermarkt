#include "produkt.hpp"

static int produkt_counter = 0;

Produkt::Produkt(std::string name, float menge, float preis, Datum haltbarkeit, std::string abteilung) :
    name_{name}, menge_{menge}, preis_{preis}, haltbarkeit_{haltbarkeit}, id_{produkt_counter++}, abteilung_{abteilung} {}

std::string Produkt::GetName() const {
    return name_;
}

float Produkt::GetMenge() const {
    return menge_;
}

float Produkt::GetPreis() const {
    return preis_;
}

int Produkt::GetID() const {
    return id_;
}

float Produkt::GetGesamtPreis() const {
    std::cout << std::fixed << std::setprecision(2);
    return menge_ * preis_;
}

Datum Produkt::GetHaltbarkeit() const {
    return haltbarkeit_;
}

std::string Produkt::GetAbteilung() const {
    return abteilung_;
}

void Produkt::Display() const {
    std::cout << "Name: " << name_ <<  "\n"
            << "Menge: " << menge_ << " kg\n"
            << "Preis: " << preis_ << " €\n"
            << "Ablaufdatum: " << haltbarkeit_.GetTag() << "." << haltbarkeit_.GetMonat() << "." << haltbarkeit_.GetJahr() << "\n"
            << "Abteilung: " << abteilung_ << "\n"
            << std::endl;
}
