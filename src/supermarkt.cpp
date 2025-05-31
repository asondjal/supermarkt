#include "base/supermarkt.hpp"

#include <iostream>
#include <memory>
#include <string>

#include "utils/utilities.hpp"

static uint32_t supermarkt_counter = 0;

Supermarkt::Supermarkt(std::string name, std::string adresse)
    : name_(name), adresse_(adresse), supermarkt_ID_{supermarkt_counter++} {}

/**
 * @brief Wiedergabe vom Namen vom Supermarkt
 * @return Name vom Supermarkt
 */
std::string Supermarkt::GetSupermarktName() const { return name_; }

/**
 * @brief Wiedergabe von der Adresse vom Supermarkt
 * @return Adresse vom Supermarkt
 */
std::string Supermarkt::GetSupermarktAdress() const { return adresse_; }

/**
 * @brief Aufruf der ID vom Supermarkt
 * @return ID vom Supermarkt
 */
uint32_t Supermarkt::GetSupermarktID() const { return supermarkt_ID_; }

/**
 * @brief Vergleichsoperator für Supermärkte
 * @param other: anderer Supermarkt
 * @return true, wenn die Supermärkte gleich sind, false sonst
 */
bool Supermarkt::operator==(Supermarkt& other) const {
  return supermarkt_ID_ == other.GetSupermarktID();
}

/**
 * @brief Hinzufügen eines Produktes ins Sortiment
 */
void Supermarkt::AddProdukt(Produkt& produkt) { produkte_.push_back(&produkt); }

/**
 * @brief Entfernen eines Produktes ins Sortiment
 */
void Supermarkt::RemoveProdukt(Produkt& produkt) {
  RemoveFromVector(produkte_, produkt, [](Produkt* a, const Produkt& b) {
    return a->GetID() == b.GetID();  // Vergleichsstrategie
  });
}

/**
 * @brief Erzeugen eines Kassenzettels und Speicherung im Ordner Kassenzettel
 * @return absoluter Pfad zur Datei
 */
std::string Supermarkt::CreateProduktDatabase() const {
  std::lock_guard<std::mutex> lock(supermarktMutex_);
  // Anlegen der Produkt-Datei
  std::filesystem::create_directories("./data");
  std::filesystem::create_directories("./data/supermarkt_" +
                                      std::to_string(supermarkt_ID_));
  std::string filename =
      "./data/supermarkt_" + std::to_string(supermarkt_ID_) + "/produkte.txt";
  std::ofstream file(filename, std::ios::out | std::ios::trunc);
  if (!file) {
    return "Fehler beim Erstellen der Datei!";
  }

  file << "========================== PRODUKT DATABASE "
          "==========================\n";
  file << "Supermarkt: " << name_ << "\n";
  file << "Adresse: " << adresse_ << "\n\n";

  std::ostringstream oss;

  oss << std::left << std::setw(20) << "Produkt" << std::setw(15) << "ID"
      << std::setw(20) << "Preis [€]" << std::setw(15) << "Menge" << "\n";
  oss << std::string(70, '-') << "\n";

  for (const auto& produkt : produkte_) {
    oss << std::fixed << std::setprecision(2) << std::left << std::setw(20)
        << produkt->GetName() << std::setw(15) << produkt->GetID()
        << std::setw(20) << produkt->GetPreis() << std::setw(15)
        << produkt->GetMenge() << "\n";
  }
  oss << std::string(70, '-') << "\n";
  oss << std::left << std::setw(35) << "Umsatz: " << std::fixed
      << std::setprecision(2) << std::setw(14) << GetGesamtWert() << "\n";
  oss << "====================================================================="
         "=\n";

  file << oss.str();
  file.close();

  return filename;
}

/**
 * @brief Hinzufügen eines Kunden
 */
void Supermarkt::AddKunde(std::shared_ptr<Kunde> kunde) {
  kunden_.push_back(kunde);
}

/**
 * @brief Erzeugen einer Textdatei mit allen Kunden
 * @return absoluter Pfad zur Datei
 */
std::string Supermarkt::CreateKundeDatabase() const {
  std::lock_guard<std::mutex> lock(supermarktMutex_);
  // Anlegen der Kunden-Datei
  std::filesystem::create_directories("./data");
  std::filesystem::create_directories("./data/supermarkt_" +
                                      std::to_string(supermarkt_ID_));
  std::string kundendatabase_path =
      "./data/supermarkt_" + std::to_string(supermarkt_ID_) + "/kunden.txt";
  std::ofstream file(kundendatabase_path, std::ios::out | std::ios::trunc);
  if (!file) {
    return "Fehler beim Erstellen der Datei!";
  }
  file << "============================ KUNDEN DATABASE "
          "==============================\n";
  file << "Supermarkt: " << name_ << "\n";
  file << "Adresse: " << adresse_ << "\n\n";
  std::ostringstream oss;
  oss << std::left << std::setw(20) << "Kunde" << std::setw(15) << "ID"
      << std::setw(20) << "Alter" << std::setw(15) << "Geschlecht" << "\n";
  oss << std::string(70, '-') << "\n";
  for (const auto& kunde : kunden_) {
    oss << std::left << std::setw(20) << kunde->GetName() << std::setw(15)
        << kunde->GetKundeID() << std::setw(20) << kunde->GetAge()
        << std::setw(15) << kunde->GetGender() << "\n";
  }
  oss << std::string(70, '-') << "\n";
  oss << std::left << std::setw(35) << "Anzahl Kunden: " << std::setw(14)
      << kunden_.size() << "\n";
  oss << "====================================================================="
         "======\n";
  file << oss.str();
  file.close();
  return kundendatabase_path;
}

/**
 * @brief Entfernen eines Kunden
 */
void Supermarkt::RemoveKunde(std::shared_ptr<Kunde> kunde) {
  RemoveFromVector(
      kunden_, kunde,
      [](const std::shared_ptr<Kunde>& a, const std::shared_ptr<Kunde>& b) {
        return a->GetKundeID() == b->GetKundeID();
      });
}

/**
 * @brief Hinzufügen eines Warenkorbs
 */
void Supermarkt::AddWarenkorb(Warenkorb& warenkorb) {
  warenkoerbe_.push_back(&warenkorb);
}

/**
 * @brief Erzeugen einer Textdatei mit allen Warenkörben und Speicherung im
 * Ordner data
 * @return absoluter Pfad zur Datei
 */
std::string Supermarkt::CreateWarenkorbDatabase() const {
  std::lock_guard<std::mutex> lock(supermarktMutex_);
  // Anlegen der Warenkorb-Datei
  std::filesystem::create_directories("./data");
  std::filesystem::create_directories("./data/supermarkt_" +
                                      std::to_string(supermarkt_ID_));
  std::string warenkorbdatabase_path = "./data/supermarkt_" +
                                       std::to_string(supermarkt_ID_) +
                                       "/warenkoerbe.txt";
  std::ofstream file(warenkorbdatabase_path, std::ios::out | std::ios::trunc);
  if (!file) {
    return "Fehler beim Erstellen der Datei!";
  }
  file << "=========================== WARENKORB DATABASE "
          "=======================\n";
  file << "Supermarkt: " << name_ << "\n";
  file << "Adresse: " << adresse_ << "\n\n";
  std::ostringstream oss;
  oss << std::left << std::setw(20) << "Kunde" << std::setw(15) << "ID"
      << std::setw(20) << "Gesamtpreis [€]" << "\n";
  oss << std::string(70, '-') << "\n";
  for (const auto& warenkorb : warenkoerbe_) {
    oss << std::fixed << std::setprecision(2) << std::left << std::setw(20)
        << warenkorb->GetKunde()->GetName() << std::setw(15)
        << warenkorb->GetKunde()->GetKundeID() << std::setw(20)
        << warenkorb->GetGesamtPreis() << "\n";
  }
  oss << std::string(70, '-') << "\n";
  oss << std::left << std::setw(35) << "Anzahl Warenkoerbe: " << std::setw(14)
      << warenkoerbe_.size() << "\n";
  oss << "====================================================================="
         "=\n";
  file << oss.str();
  file.close();
  return warenkorbdatabase_path;
}

/**
 * @brief Entfernen eines Warenkorbes
 */
void Supermarkt::RemoveWarenkorb(Warenkorb& warenkorb) {
  RemoveFromVector(
      warenkoerbe_, warenkorb, [](Warenkorb* a, const Warenkorb& b) {
        return a->GetKunde()->GetKundeID() == b.GetKunde()->GetKundeID();
      });
}

/**
 * @brief Hinzufügen eines Händlers
 */
void Supermarkt::AddHaendler(Haendler& haendler) {
  haendler_.push_back(&haendler);
}

/**
 * @brief Erzeugen eines Textdatei mit allen Händlern und Speicherung im Ordner
 * data
 * @return absoluter Pfad zur Datei
 */
std::string Supermarkt::CreateHaendlerDatabase() const {
  std::lock_guard<std::mutex> lock(supermarktMutex_);
  // Anlegen der Kunden-Datei
  std::filesystem::create_directories("./data");
  std::filesystem::create_directories("./data/supermarkt_" +
                                      std::to_string(supermarkt_ID_));
  std::string haendlerdatabase_path =
      "./data/supermarkt_" + std::to_string(supermarkt_ID_) + "/haendler.txt";
  std::ofstream file(haendlerdatabase_path, std::ios::out | std::ios::trunc);
  if (!file) {
    return "Fehler beim Erstellen der Datei!";
  }
  file << "============================ HAENDLER DATABASE "
          "============================\n";
  file << "Supermarkt: " << name_ << "\n";
  file << "Adresse: " << adresse_ << "\n\n";
  std::ostringstream oss;
  oss << std::left << std::setw(20) << "Haendler" << std::setw(15) << "ID"
      << std::setw(20) << "Alter" << std::setw(15) << "Geschlecht" << "\n";
  oss << std::string(70, '-') << "\n";
  for (const auto& haendler : haendler_) {
    oss << std::left << std::setw(20) << haendler->GetName() << std::setw(15)
        << haendler->GetHaendlerID() << std::setw(20) << haendler->GetAge()
        << std::setw(15) << haendler->GetGender() << "\n";
  }
  oss << std::string(70, '-') << "\n";
  oss << std::left << std::setw(35) << "Anzahl Haendler: " << std::setw(14)
      << haendler_.size() << "\n";
  oss << "====================================================================="
         "======\n";
  file << oss.str();
  file.close();
  return haendlerdatabase_path;
}

/**
 * @brief Entfernen eines Händlers aus dem System
 */
void Supermarkt::RemoveHaendler(Haendler& haendler) {
  RemoveFromVector(haendler_, haendler, [](Haendler* a, const Haendler& b) {
    return a->GetHaendlerID() == b.GetHaendlerID();
  });
}

/**
 * @brief Berechnung vom generierten Umsatz
 * @return generierter Umsatz in €
 */
float Supermarkt::GetGesamtWert() const {
  float gesamtwert = 0.0f;
  std::cout << std::fixed << std::setprecision(2);
  for (const auto& produkt : produkte_) {
    gesamtwert += produkt->GetPreis() * produkt->GetMenge();
  }
  return gesamtwert;
}
