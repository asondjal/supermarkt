#ifndef INC_BASE_SUPERMARKT_HPP_
#define INC_BASE_SUPERMARKT_HPP_

#include <filesystem>
#include <fstream>
#include <iomanip>
#include <memory>
#include <mutex>
#include <set>
#include <sstream>
#include <string>

#include "base/haendler.hpp"
#include "base/kunde.hpp"
#include "base/produkt.hpp"
#include "base/warenkorb.hpp"

class Supermarkt {
 private:
  const std::string name_;
  const std::string adresse_;
  std::set<Produkt*> produkte_;
  std::set<std::shared_ptr<Kunde>> kunden_;
  std::set<Warenkorb*> warenkoerbe_;
  std::set<Haendler*> haendler_;
  const uint32_t supermarkt_ID_;
  mutable std::mutex supermarktMutex_;

 public:
  Supermarkt(std::string name, std::string adresse);
  std::string GetSupermarktAdress() const;
  std::string GetSupermarktName() const;
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

#endif  // INC_BASE_SUPERMARKT_HPP_
