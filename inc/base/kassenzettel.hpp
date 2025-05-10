#ifndef KASSENZETTEL_HPP
#define KASSENZETTEL_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <filesystem> // C++17 is required for this header
#include "kunde.hpp"
#include "produkt.hpp"
#include "warenkorb.hpp"
#include "datum.hpp"
#include "haendler.hpp"
#include "konto.hpp"
#include <chrono>
#include <ctime>
#include <mutex>
#include <memory>

class Kassenzettel {
    private:
    const Datum& datum_;
    const Kunde& kunde_;
    const Haendler& haendler_;
    const Warenkorb& warenkorb_;
    const uint32_t kassenzettelID_;
    std::shared_ptr<Konto> konto_; // Nicht konstant, da Auszahlungen und Einzahlungen möglich bleiben müssen
    std::string filename_;
    mutable std::mutex kassenzettelMutex_;
    
    public:
    Kassenzettel(const Datum& datum, const Kunde& kunde, const Haendler& haendler, const Warenkorb& warenkorb, const std::shared_ptr<Konto>& konto);
    uint32_t GetKassenzettelID() const;
    std::string CreateKassenzettel() const;
    bool operator==(Kassenzettel& other) const;

};

#endif /* KASSENZETTEL_HPP */