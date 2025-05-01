#include "tests.hpp"

Tests::Tests() {}

void Tests::test_Produkt() {
    Datum datum(1, 1, 2025);
    Produkt produkt("Apfel", 1.99f, 3.0f, datum, "Obst");

    assert(std::abs(produkt.GetMenge() - 1.99f) < 0.001f);  
    assert(std::abs(produkt.GetPreis() - 3.0f) < 0.001f);      
    assert(produkt.GetName() == "Apfel");
    assert(produkt.GetAbteilung() == "Obst");
    assert(std::abs(produkt.GetGesamtPreis() - (1.99f * 3.0f)) < 0.001f); 
    std::cout << "Produkt Test erfolgreich!" << std::endl;
}

void Tests::test_Person() {
    Person person("Max Mustermann", "M", 30, "max.mustermann@gmx.net", "Musterstraße 1, 12345, Musterstadt");
    assert(person.GetName() == "Max Mustermann");
    assert(person.GetAge() == 30);
    assert(person.GetAdresse() == "Musterstraße 1, 12345, Musterstadt");
    assert(person.GetGender() == "M");
    assert(person.GetEmail() ==  "max.mustermann@gmx.net");
    std::cout << "Person Test erfolgreich!" << std::endl;
}

void Tests::test_Kunde() {
    Kunde kunde("LeBron James", "M", 30, "lebron.james@gmail.com", "Los Angeles, USA");
    assert(kunde.GetKundeID()== 0);
    std::cout << "Kunde Test erfolgreich!" << std::endl;
}

// void Tests::test_Haendler() {
//     Datum datum(1, 1, 2025);
//     Produkt produkt("Apfel", 1.99f, 3.0f, datum, "Obst");
//     Haendler haendler("Hans", "Müller", 40, "Händlerstraße 2", "54321", "Händlerstadt");
//     haendler.AddProdukt(produkt);

//     assert(haendler.GetProdukte().size() == 1);
//     assert(haendler.GetProdukte()[0].GetName() == "Apfel");
//     std::cout << "Haendler Test erfolgreich!" << std::endl;
// }

// void Tests::test_Warenkorb() {
//     Datum datum(1, 1, 2025);
//     Produkt produkt("Apfel", 1.99f, 3.0f, datum, "Obst");
//     Warenkorb warenkorb;
//     warenkorb.AddProdukt(produkt);

//     assert(warenkorb.GetProdukte().size() == 1);
//     assert(warenkorb.GetProdukte()[0].GetName() == "Apfel");
//     std::cout << "Warenkorb Test erfolgreich!" << std::endl;
// }

// void Tests::test_Konto() {
//     Konto konto("Max", "Mustermann", 30, "Musterstraße 1", "12345", "Musterstadt");
//     konto.Einzahlen(100.0f);
//     konto.Auszahlen(50.0f);

//     assert(std::abs(konto.GetKontostand() - 50.0f) < 0.001f);
//     std::cout << "Konto Test erfolgreich!" << std::endl;
// }
