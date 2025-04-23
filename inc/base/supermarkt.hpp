#ifndef SUPERMARKT_HPP_
#define SUPERMARKT_HPP_

#include "kunde.hpp"
#include "produkt.hpp"
#include "warenkorb.hpp"
#include "haendler.hpp"
#include "utilities.hpp"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

class Supermarkt {

    private:
        std::string name_;
        std::string adresse_;
        std::vector<Produkt*> produkte_;
        std::vector<Kunde*> kunden_;
        std::vector<Warenkorb*> warenkoerbe_;
        std::vector<Haendler*> haendler_;

    public:
        Supermarkt(std::string name, std::string adresse);
        void AddProdukt(Produkt& produkt);
        void RemoveProdukt(Produkt& produkt);
        void AddKunde(Kunde& kunde);
        void RemoveKunde(Kunde& kunde);
        void AddWarenkorb(Warenkorb& warenkorb);
        void RemoveWarenkorb(Warenkorb& warenkorb);
        void AddHaendler(Haendler& haendler);
        void RemoveHaendler(Haendler& haendler);
        std::string CreateProduktDatabase() const;
        std::string CreateKundeDatabase() const;
        std::string CreateWarenkorbDatabase() const;
        std::string CreateHaendlerDatabase() const;
        float GetGesamtWert() const;
};

#endif /* SUPERMARKT_HPP_ */