#include "konto.hpp"

static int kontoCounter = 0;

Konto::Konto(const Kunde& user, std::string bank) : user_{user}, bank_{bank}, kontostand_{0.00}, kontoID_{kontoCounter++} {}

void Konto::Einzahlen(float betrag) {
    kontostand_ += betrag;
}

void Konto::Auszahlen(float betrag) {
    kontostand_ -= betrag;
}

float Konto::GetKontostand() const {
    std::cout << std::fixed << std::setprecision(2);
    return kontostand_;
}

std::string Konto::GetBank() const {
    return bank_;
}

const Kunde& Konto::GetUser() const {
    return user_;
}

int Konto::GetKontoID() const {
    return kontoID_;
}