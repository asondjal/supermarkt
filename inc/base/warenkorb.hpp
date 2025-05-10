#ifndef WARENKORB_HPP_
#define WARENKORB_HPP_

#include <iomanip>
#include <vector>
#include <algorithm>
#include "produkt.hpp"
#include "kunde.hpp"

class Warenkorb {

    private:
    std::vector<Produkt*> produkte;
    const Kunde& kunde_;
    const int warenkorbID_;

    public:
    Warenkorb(const Kunde& kunde);
    const Kunde& GetKunde() const;
    void AddProdukt(Produkt* produkt);
    void RemoveProdukt(Produkt* produkt);
    float GetGesamtPreis() const;
    std::vector<Produkt*> GetProdukte() const;
    bool operator==(const Warenkorb& other) const;
    int GetWarenkorbID() const;

};

#endif /* WARENKORB_HPP_ */