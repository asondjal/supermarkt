#ifndef KONTO_HPP_
#define KONTO_HPP_

#include "kunde.hpp"
#include <string>
#include <iomanip>
#include <memory>

class Konto{

    private:
    std::shared_ptr<Kunde> user_;
    const std::string bank_;
    float kontostand_;
    const int kontoID_;

    public:
    explicit Konto(std::shared_ptr<Kunde> user, std::string bank);
    void Einzahlen(float betrag);
    void Auszahlen(float betrag);
    std::string GetBank() const;
    float GetKontostand() const;
    std::shared_ptr<Kunde> GetUser() const;
    int GetKontoID() const;
    bool operator==(const Konto& other) const;

};

#endif /* KONTO_HPP_ */