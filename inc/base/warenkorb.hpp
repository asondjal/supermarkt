#ifndef INC_BASE_WARENKORB_HPP_
#define INC_BASE_WARENKORB_HPP_

#include <iomanip>
#include <vector>
#include <algorithm>
#include <memory>
#include "base/produkt.hpp"
#include "base/kunde.hpp"

class Warenkorb {
 private:
    std::vector<Produkt*> produkte;
    std::shared_ptr<Kunde> kunde_;
    const int warenkorbID_;

 public:
    explicit Warenkorb(std::shared_ptr<Kunde> kunde);
    std::shared_ptr<Kunde> GetKunde() const;
    void AddProdukt(Produkt* produkt);
    void RemoveProdukt(Produkt* produkt);
    float GetGesamtPreis() const;
    std::vector<Produkt*> GetProdukte() const;
    bool operator==(const Warenkorb& other) const;
    int GetWarenkorbID() const;

};

#endif  // INC_BASE_WARENKORB_HPP_
