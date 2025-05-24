#ifndef SUPERMARKT_HPP_
#define SUPERMARKT_HPP_

#include "kunde.hpp"
#include "produkt.hpp"
#include "warenkorb.hpp"
#include "haendler.hpp"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <mutex>
#include <memory>

class Supermarkt {

    private:
        const std::string name_;
        const std::string adresse_;
        std::vector<Produkt*> produkte_;
        std::vector<std::shared_ptr<Kunde>> kunden_;
        std::vector<Warenkorb*> warenkoerbe_;
        std::vector<Haendler*> haendler_;
        const uint32_t supermarkt_ID_;
        mutable std::mutex supermarktMutex_;

    public:
        Supermarkt(std::string name, std::string adresse);
        void AddProdukt(Produkt& produkt);
        void RemoveProdukt(Produkt& produkt);
        void AddKunde(std::shared_ptr<Kunde> kunde);
        void RemoveKunde(std::shared_ptr<Kunde> kunde);
        void AddWarenkorb(Warenkorb& warenkorb);
        void RemoveWarenkorb(Warenkorb& warenkorb);
        void AddHaendler(Haendler& haendler);
        void RemoveHaendler(Haendler& haendler);
        std::string CreateProduktDatabase() const;
        std::string CreateKundeDatabase() const;
        std::string CreateWarenkorbDatabase() const;
        std::string CreateHaendlerDatabase() const;
        float GetGesamtWert() const;
        uint32_t GetSupermarktID() const;
        bool operator==(Supermarkt& other) const;
};

#endif /* SUPERMARKT_HPP_ */