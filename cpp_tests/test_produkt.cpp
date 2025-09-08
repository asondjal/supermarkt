#include "tests/test_produkt.hpp"

void TestProdukt() {
  Datum datum{1, 1, 2025};
  Produkt produkt{"Apfel", 1.99f, 3.0f, datum, "Obst"};
  Datum event{2, 2, 2022};

  assert(produkt.GetMenge() == 1.99f);
  assert(produkt.GetPreis() == 3.0f);
  assert(produkt.GetName() == "Apfel");
  assert(produkt.GetAbteilung() == "Obst");
  assert(std::abs(produkt.GetGesamtPreis() - (1.99f * 3.0f)) < 0.001f);
  assert(produkt.GetHaltbarkeit().Print() == "01.01.2025");
  assert(event.operator==(datum) == false);

  std::cout << "Alle Tests für Produkt waren erfolgreich!" << std::endl;
}