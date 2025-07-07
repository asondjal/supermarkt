#include "tests/test_warenkorb.hpp"

void TestWarenkorb() {
    Datum datum{1, 1, 2025};
    Produkt apfel{"Apfel", 1.99f, 3.0f, datum, "Obst"};
    Produkt birne{"Birne", 2.52f, 4.49f, datum, "Obst" };
    std::shared_ptr<Kunde> kunde = std::make_shared<Kunde>("LeBron James", "male", 30, "lebron.james@gmail.com", "Los Angeles, USA");
    Warenkorb warenkorb{kunde};

    warenkorb.AddProdukt(&apfel);
    auto produkte = warenkorb.GetProdukte();
    assert(produkte.size() == 1);
    assert(produkte[0] == &apfel);
    assert(std::abs(warenkorb.GetGesamtPreis() - (1.99f * 3.0f)) < 0.001f);

    warenkorb.AddProdukt(&birne);
    produkte = warenkorb.GetProdukte();
    assert(produkte.size() == 2);
    assert(produkte[1] == &birne);
    assert(warenkorb.GetProdukte().size() == 2);
    assert(std::abs(warenkorb.GetGesamtPreis() - ((1.99f * 3.0f) + (2.52f * 4.49f))) < 0.001f);

    warenkorb.RemoveProdukt(&apfel);
    assert(warenkorb.GetProdukte().size() == 1);
    assert(std::abs(warenkorb.GetGesamtPreis() - (2.52f * 4.49f)) < 0.001f);

    warenkorb.RemoveProdukt(&apfel);
    assert(warenkorb.GetProdukte().size() == 1);
    assert(std::abs(warenkorb.GetGesamtPreis() - (2.52f * 4.49f)) < 0.001f);

    std::cout << "Alle Tests für Warenkorb waren erfolgreich!" << std::endl;
}