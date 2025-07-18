#include "base/konto.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <utility>

static int kontoCounter = 0;

Konto::Konto(std::shared_ptr<Kunde> user, std::string bank)
    : user_(std::move(user)), bank_(bank), kontostand_(0.00), kontoID_(kontoCounter++) {}

/**
 * @brief Vergleichsoperator für Konten
 * @param other: anderes Konto
 * @return true, wenn die Konten gleich sind, false sonst
 */
bool Konto::operator==(const Konto& other) const { return kontoID_ == other.GetKontoID(); }

/**
 * @brief Einzahlung auf das Konto
 * @param betrag: Geldbetrag, der aufs Konto eingezahlt bzw. überwiesen wird
 */
void Konto::Einzahlen(float betrag) { kontostand_ += betrag; }

/**
 * @brief Auszahlung vom Konto
 * @param betrag: Geldbetrag, der vom Konto abgerechnet wird
 */
void Konto::Auszahlen(float betrag) {
  if (betrag > kontostand_) {
    throw std::invalid_argument("Auszahlung übersteigt Kontostand!");
  }
  kontostand_ -= betrag;
}

/**
 * @brief Aufruf vom Kontostand
 * @return Kontostand bei einer Genauigkeit von 2 Dezimalstellen
 */
float Konto::GetKontostand() const {
  std::cout << std::fixed << std::setprecision(2);
  return kontostand_;
}

/**
 * @brief Aufruf vom Institut
 * @return Bankinformationen als String
 */
std::string Konto::GetBank() const { return bank_; }

/**
 * @brief Aufruf vom Kontoinhaber
 * @return Kontoinhaber
 */
std::shared_ptr<Kunde> Konto::GetUser() const { return user_; }

/**
 * @brief Aufruf vom der ID vom Kontoinhaber
 * @return ID vom Kontoinhaber
 */
int Konto::GetKontoID() const { return kontoID_; }
