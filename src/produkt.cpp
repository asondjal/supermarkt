#include "produkt.hpp"

static int produkt_counter = 0;

Produkt::Produkt(std::string name, float menge, float preis, Datum haltbarkeit, std::string abteilung) :
    name_{name}, menge_{menge}, preis_{preis}, haltbarkeit_{haltbarkeit}, id_{produkt_counter++}, abteilung_{abteilung} {}

bool Produkt::operator==(Produkt& other) const {
    return id_ == other.GetID();
}

/**
 * @brief Ausgabe vom Namen des Produktes 
 * @return Name einer Person 
 */
std::string Produkt::GetName() const {
    return name_;
}

/**
 * @brief Ausgabe von der Menge an Produkten 
 * @return Menge an Produkten 
 */
float Produkt::GetMenge() const {
    return menge_;
}

/**
 * @brief Ausgabe vom Preis des Produktes
 * @return Preis vom Produkt in €
 */
float Produkt::GetPreis() const {
    return preis_;
}

/**
 * @brief Ausgabe von der ID vom Produkt 
 * @return ID vom Produkt 
 */
int Produkt::GetID() const {
    return id_;
}

/**
 * @brief Ausgabe vom Gesamtpreis eines Produktes 
 * @return Gesamtpreis eines Produktes 
 */
float Produkt::GetGesamtPreis() const {
    std::cout << std::fixed << std::setprecision(2);
    return menge_ * preis_;
}

/**
 * @brief Ausgabe vom Haltbarkeitsdatum eines Produktes 
 * @return Haltbarkeitsdatum eines Produktes
 */
Datum Produkt::GetHaltbarkeit() const {
    return haltbarkeit_;
}

/**
 * @brief Ausgabe von der Abteilung eines Produktes 
 * @return Abteilung eines Produktes
 */
std::string Produkt::GetAbteilung() const {
    return abteilung_;
}

/**
 * @brief Anzeige aller Informationen fürs Produkt
 */
void Produkt::Display() const {
    std::cout << "Name: " << name_ <<  "\n"
            << "Menge: " << menge_ << " kg\n"
            << "Preis: " << preis_ << " €\n"
            << "Ablaufdatum: " << haltbarkeit_.GetTag() << "." << haltbarkeit_.GetMonat() << "." << haltbarkeit_.GetJahr() << "\n"
            << "Abteilung: " << abteilung_ << "\n"
            << std::endl;
}
