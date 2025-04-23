#include "supermarkt.hpp"

Supermarkt::Supermarkt(std::string name, std::string adresse) : name_(name), adresse_(adresse) {}

void Supermarkt::AddProdukt(Produkt& produkt) {
    produkte_.push_back(&produkt);
}

void Supermarkt::RemoveProdukt(Produkt& produkt) {
    RemoveFromVector(produkte_, produkt, 
        [](Produkt* a, const Produkt& b) {
            return a->GetID() == b.GetID(); // Vergleichsstrategie
        }
    );
}

std::string Supermarkt::CreateProduktDatabase() const {
    // Anlegen der Produkt-Datei
    std::string filename = "./data/inventur.txt";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (!file) {
        return "Fehler beim Erstellen der Datei!";
    }

    file << "================== PRODUKT DATABASE ==================\n";
    file << "Supermarkt: " << name_ << "\n";
    file << "Adresse: " << adresse_ << "\n\n";

    std::ostringstream oss;

    oss << std::left << std::setw(20) << "Produkt"
        << std::setw(15) << "ID"
        << std::setw(20) << "Preis [€]" 
        << std::setw(15) << "Menge" 
        << "\n";
    oss << std::string(70, '-') << "\n";

    for (const auto& produkt : produkte_) {
        oss << std::fixed << std::setprecision(2)
            << std::left
            << std::setw(20) << produkt->GetName()
            << std::setw(15) << produkt->GetID()
            << std::setw(20) << produkt->GetPreis()
            << std::setw(15) << produkt->GetMenge()
            << "\n";
    }
    oss << std::string(70, '-') << "\n";
    oss << std::left << std::setw(35) << "Umsatz: "
        << std::fixed << std::setprecision(2)
        << std::setw(14) << GetGesamtWert() << "\n";
    oss << "=======================================================\n";

    file << oss.str();
    file.close();

    return oss.str();
}

void Supermarkt::AddKunde(Kunde& kunde) {
    kunden_.push_back(&kunde);
}

std::string Supermarkt::CreateKundeDatabase() const {
    // Anlegen der Kunden-Datei
    std::string filename = "./data/kunden.txt";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (!file) {
        return "Fehler beim Erstellen der Datei!";
    }
    file << "============================ KUNDEN DATABASE ==============================\n";
    file << "Supermarkt: " << name_ << "\n";
    file << "Adresse: " << adresse_ << "\n\n";
    std::ostringstream oss;
    oss << std::left << std::setw(20) << "Kunde"
        << std::setw(15) << "ID"
        << std::setw(20) << "Alter" 
        << std::setw(15) << "Geschlecht" 
        << "\n";
    oss << std::string(70, '-') << "\n";
    for (const auto& kunde : kunden_) {
        oss << std::left
            << std::setw(20) << kunde->GetName()
            << std::setw(15) << kunde->GetKundeID()
            << std::setw(20) << kunde->GetAge()
            << std::setw(15) << kunde->GetGender()
            << "\n";
    }
    oss << std::string(70, '-') << "\n";
    oss << std::left << std::setw(35) << "Anzahl Kunden: "
        << std::setw(14) << kunden_.size() << "\n";
    oss << "===========================================================================\n";
    file << oss.str();
    file.close();
    return oss.str();
}

void Supermarkt::RemoveKunde(Kunde& kunde) {
    RemoveFromVector(kunden_, kunde, 
        [](Kunde* a, const Kunde& b) {
            return a->GetKundeID() == b.GetKundeID(); 
        }
    );
}

void Supermarkt::AddWarenkorb(Warenkorb& warenkorb) {
    warenkoerbe_.push_back(&warenkorb);
}

std::string Supermarkt::CreateWarenkorbDatabase() const {
    // Anlegen der Warenkorb-Datei
    std::string filename = "./data/warenkoerbe.txt";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (!file) {
        return "Fehler beim Erstellen der Datei!";
    }
    file << "============================ WARENKORB DATABASE ===========================\n";
    file << "Supermarkt: " << name_ << "\n";
    file << "Adresse: " << adresse_ << "\n\n";
    std::ostringstream oss;
    oss << std::left << std::setw(20) << "Kunde"
        << std::setw(15) << "ID"
        << std::setw(20) << "Gesamtpreis [€]" 
        << "\n";
    oss << std::string(70, '-') << "\n";
    for (const auto& warenkorb : warenkoerbe_) {
        oss << std::fixed << std::setprecision(2)
            << std::left
            << std::setw(20) << warenkorb->GetKunde().GetName()
            << std::setw(15) << warenkorb->GetKunde().GetKundeID()
            << std::setw(20) << warenkorb->GetGesamtPreis()
            << "\n";
    }
    oss << std::string(70, '-') << "\n";
    oss << std::left << std::setw(35) << "Anzahl Warenkoerbe: "
        << std::setw(14) << warenkoerbe_.size() << "\n";
    oss << "===========================================================================\n";
    file << oss.str();
    file.close();
    return oss.str();
}

void Supermarkt::RemoveWarenkorb(Warenkorb& warenkorb) {
    RemoveFromVector(warenkoerbe_, warenkorb, 
        [](Warenkorb* a, const Warenkorb& b) {
            return a->GetKunde().GetKundeID() == b.GetKunde().GetKundeID();
        }
    );
}

void Supermarkt::AddHaendler(Haendler& haendler) {
    haendler_.push_back(&haendler);
}

std::string Supermarkt::CreateHaendlerDatabase() const {
    // Anlegen der Kunden-Datei
    std::string filename = "./data/haendler.txt";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (!file) {
        return "Fehler beim Erstellen der Datei!";
    }
    file << "============================ KUNDEN DATABASE ==============================\n";
    file << "Supermarkt: " << name_ << "\n";
    file << "Adresse: " << adresse_ << "\n\n";
    std::ostringstream oss;
    oss << std::left << std::setw(20) << "Haendler"
        << std::setw(15) << "ID"
        << std::setw(20) << "Alter" 
        << std::setw(15) << "Geschlecht" 
        << "\n";
    oss << std::string(70, '-') << "\n";
    for (const auto& haendler : haendler_) {
        oss << std::left
            << std::setw(20) << haendler->GetName()
            << std::setw(15) << haendler->GetHaendlerID()
            << std::setw(20) << haendler->GetAge()
            << std::setw(15) << haendler->GetGender()
            << "\n";
    }
    oss << std::string(70, '-') << "\n";
    oss << std::left << std::setw(35) << "Anzahl Haendler: "
        << std::setw(14) << haendler_.size() << "\n";
    oss << "===========================================================================\n";
    file << oss.str();
    file.close();
    return oss.str();
}


void Supermarkt::RemoveHaendler(Haendler& haendler) {
    RemoveFromVector(haendler_, haendler, 
        [](Haendler* a, const Haendler& b) {
            return a->GetHaendlerID() == b.GetHaendlerID(); 
        }
    );
}

float Supermarkt::GetGesamtWert() const {
    float gesamtwert = 0.0f;
    for (const auto& produkt : produkte_) {
        gesamtwert += produkt->GetPreis() * produkt->GetMenge();
    }
    return gesamtwert;
}