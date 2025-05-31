#ifndef INC_BASE_KASSENZETTEL_HPP_
#define INC_BASE_KASSENZETTEL_HPP_

#include <chrono>
#include <ctime>
#include <filesystem>  // C++17 is required for this header
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>

#include "base/datum.hpp"
#include "base/haendler.hpp"
#include "base/konto.hpp"
#include "base/kunde.hpp"
#include "base/produkt.hpp"
#include "base/warenkorb.hpp"

class Kassenzettel{
 private:
  const Datum& datum_;
  std::shared_ptr<Kunde> kunde_;
  const Haendler& haendler_;
  const Warenkorb& warenkorb_;
  const uint32_t kassenzettelID_;
  std::shared_ptr<Konto> konto_;  // Nicht konstant, da Auszahlungen und
                                  // Einzahlungen möglich bleiben müssen
  std::string filename_;
  mutable std::mutex kassenzettelMutex_;

 public:
  Kassenzettel(const Datum& datum, std::shared_ptr<Kunde> kunde,
               const Haendler& haendler, const Warenkorb& warenkorb,
               std::shared_ptr<Konto> konto);
  uint32_t GetKassenzettelID() const;
  std::string CreateKassenzettel() const;
  bool operator==(Kassenzettel& other) const;
};

#endif  // INC_BASE_KASSENZETTEL_HPP_
