#ifndef KONTO_HPP_
#define KONTO_HPP_

#include "kunde.hpp"
#include <string>
#include <iomanip>

class Konto{

    private:
    const Kunde& user_;
    const std::string bank_;
    float kontostand_;
    const int kontoID_;

    public:
    Konto(const Kunde& user, std::string bank);
    void Einzahlen(float betrag);
    void Auszahlen(float betrag);
    std::string GetBank() const;
    float GetKontostand() const;
    const Kunde& GetUser() const;
    int GetKontoID() const;

};

#endif /* KONTO_HPP_ */