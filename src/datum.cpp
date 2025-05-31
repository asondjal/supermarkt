#include "base/datum.hpp"

Datum::Datum(uint32_t tag, uint32_t monat, uint32_t jahr)
    : tag_(tag), monat_(monat), jahr_(jahr) {}

/**
 * @brief Aufruf vom aktuellen Tag
 * @return aktueller Tag
 */
uint32_t Datum::GetTag() const { return tag_; }

/**
 * @brief Aufruf vom aktuellen Monat
 * @return aktueller Monat
 */
uint32_t Datum::GetMonat() const { return monat_; }

/**
 * @brief Aufruf vom aktuellen Jahr
 * @return aktuelles Jahr
 */
uint32_t Datum::GetJahr() const { return jahr_; }

/**
 * @brief Darstellung vom Tag im Format DD.MM.JJ
 */
std::string Datum::Print() const {
  std::string datum;
  std::ostringstream oss;
  oss << std::setfill('0') << std::setw(2) << tag_ << "." << std::setfill('0')
      << std::setw(2) << monat_ << "." << jahr_;
  datum = oss.str();
  return datum;
}

/**
 * @brief Vergleich von zwei Daten
 * @param other anderes Datum
 * @return true wenn gleich, false wenn ungleich
 */
bool Datum::operator==(const Datum& other) const {
  return (tag_ == other.tag_) && (monat_ == other.monat_) &&
         (jahr_ == other.jahr_);
}
