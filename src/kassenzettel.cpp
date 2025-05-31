#include "base/kassenzettel.hpp"

#include <memory>
#include <string>
#include <utility>

static uint32_t kassenzettelCounter_ = 0;

Kassenzettel::Kassenzettel(const Datum& datum, std::shared_ptr<Kunde> kunde,
                           const Haendler& haendler, const Warenkorb& warenkorb,
                           std::shared_ptr<Konto> konto)
    : datum_(datum),
      kunde_(std::move(kunde)),
      haendler_(haendler),
      warenkorb_(warenkorb),
      kassenzettelID_(kassenzettelCounter_++),
      konto_(std::move(konto)),
      filename_("./data/kassenzettel/kunde_" + std::to_string(kassenzettelID_) +
                ".txt") {}

/**
 * @brief Vergleichsoperator für Kassenzettel
 * @param other: anderer Kassenzettel
 * @return true, wenn die Kassenzettel gleich sind, false sonst
 */
bool Kassenzettel::operator==(Kassenzettel& other) const {
  return kassenzettelID_ == other.GetKassenzettelID();
}

/**
 * @brief Aufruf vom KassenzettelID
 * @return ID vom Kassenzettel
 */
uint32_t Kassenzettel::GetKassenzettelID() const { return kassenzettelID_; }

/**
 * @brief Erzeugen eines Kassenzettels und Speicherung im Ordner Kassenzettel
 * @return absoluter Pfad zur Datei
 */
std::string Kassenzettel::CreateKassenzettel() const {
  std::lock_guard<std::mutex> lock(kassenzettelMutex_);
  // Anlegen des Kassenzettel-Ordners
  std::filesystem::create_directories("./data/kassenzettel");

  // Datei im Schreibmodus öffnen
  std::ofstream file(filename_, std::ios::out | std::ios::trunc);

  if (!file) {
    return "Fehler beim Erstellen der Datei!";
  }

  file << "================== KASSENZETTEL ==================\n";
  file << "Kunde: " << kunde_->GetName()
       << ", Kunde-ID: " << kunde_->GetKundeID() << "\n";
  file << "Haendler: " << haendler_.GetName()
       << ", Haendler-ID: " << haendler_.GetHaendlerID() << "\n";

  std::ostringstream oss;

  oss << "\n";

  oss << std::left << std::setw(20) << "Produkt" << std::setw(15) << "Menge "
      << std::setw(20) << "Preis [€]" << "\n";

  oss << std::string(50, '-') << "\n";

  for (const auto& produkt : warenkorb_.GetProdukte()) {
    oss << std::fixed << std::setprecision(2) << std::left << std::setw(20)
        << produkt->GetName() << std::setw(15) << produkt->GetMenge()
        << std::setw(20) << produkt->GetPreis() << "\n";
  }

  oss << std::string(50, '-') << "\n";
  oss << std::left << std::setw(35) << "Gesamtpreis:" << std::fixed
      << std::setprecision(2) << std::setw(14) << warenkorb_.GetGesamtPreis()
      << "\n\n";

  file << oss.str();
  konto_->Auszahlen(warenkorb_.GetGesamtPreis());
  file << "Institut: " << konto_->GetBank() << "\n";
  file << "Konto-ID: " << konto_->GetKontoID() << "\n";
  file << "Abrechnungsdatum: " << datum_.Print() << "\n";

  file << "================== KASSENZETTEL ==================\n";
  file.close();

  return filename_;
}
