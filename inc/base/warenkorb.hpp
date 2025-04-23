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
    Kunde& kunde_;

    public:
    Warenkorb(Kunde& kunde);
    Kunde& GetKunde() const;
    void AddProdukt(Produkt* produkt);
    void RemoveProdukt(Produkt* produkt);
    float GetGesamtPreis() const;
    std::vector<Produkt*> GetProdukte() const;

};

#endif /* WARENKORB_HPP_ */