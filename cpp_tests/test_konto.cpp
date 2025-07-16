#include "tests/test_konto.hpp"

void TestKonto() {
  std::shared_ptr<Kunde> kunde = std::make_shared<Kunde>(
      "Jonathan Joestar", "male", 35, "jonathan.joestar@yahoo.com", "London, UK");
  Konto konto{kunde, "Barclays"};

  assert(konto.GetUser() == kunde);
  konto.Einzahlen(100.0f);
  assert(konto.GetKontostand() == 100.0f);
  konto.Auszahlen(50.0f);
  assert(konto.GetKontostand() == 50.0f);

  try {
    konto.Auszahlen(100.0f);
    assert(false && "Exception durch Überziehung des Kontos!");
  } catch (const std::invalid_argument& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  assert(konto.GetKontostand() == 50.0f);

  std::cout << "Alle Tests für Konto waren erfolgreich!" << std::endl;
}