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

class Kassenzettel {
    private:
    const Datum& datum_;
    const Kunde& kunde_;
    const Haendler& haendler_;
    const Warenkorb& warenkorb_;
    const uint32_t kassenzettelID_;
    const Konto& konto_;
    std::string filename_;

    public:
    Kassenzettel(Datum& datum, const Kunde& kunde, Haendler& haendler, Warenkorb& warenkorb, const Konto& konto);
    uint32_t GetKassenzettelID() const;
    std::string CreateKassenzettel() const;

};

#endif /* KASSENZETTEL_HPP */