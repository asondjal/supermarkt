#include "tests/test_datum.hpp"

void TestDatum() {
  Datum datum1{1, 1, 2025};
  assert(datum1.GetTag() == 1);
  assert(datum1.GetMonat() == 1);
  assert(datum1.GetJahr() == 2025);
  assert(datum1.Print() == "01.01.2025");

  Datum datum2{2, 2, 2024};
  assert(datum2.GetTag() == 2);
  assert(datum2.GetMonat() == 2);
  assert(datum2.GetJahr() == 2024);
  assert(datum2.Print() == "02.02.2024");

  assert(datum1.operator==(datum2) == false);

  std::cout << "Alle Tests für Datum waren erfolgreich!" << std::endl;
}