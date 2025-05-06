#include "../inc/base/warenkorb.hpp"

Warenkorb::Warenkorb(Kunde& kunde) : kunde_(kunde) {}

void Warenkorb::AddProdukt(Produkt* produkt) {
    produkte.push_back(produkt); 
}

void Warenkorb::RemoveProdukt(Produkt* produkt) {
    auto it = std::find(produkte.begin(), produkte.end(), produkt);
    if (it != produkte.end()) {
        produkte.erase(it);
    }
}

float Warenkorb::GetGesamtPreis() const {
    std::cout << std::fixed << std::setprecision(2);
    float gesamtPreis = 0.0;
    for (const auto& produkt : produkte) {
        gesamtPreis += produkt->GetGesamtPreis();
    }
    return gesamtPreis;
}

std::vector<Produkt*> Warenkorb::GetProdukte() const {
    return produkte;
}

Kunde& Warenkorb::GetKunde() const {
    return kunde_;
}