#include "tests/test_kunde.hpp"

void TestKunde() {
  Kunde kunde{"LeBron James", "male", 40, "lebron.james@gmail.com", "Los Angeles, USA"};

  assert(kunde.GetName() == "LeBron James");
  assert(kunde.GetAge() == 40);
  assert(kunde.GetAdresse() == "Los Angeles, USA");
  assert(kunde.GetGender() == "male");
  assert(kunde.GetEmail() == "lebron.james@gmail.com");
  assert(kunde.GetKundeID() == 0);

  std::cout << "Alle Tests für Kunde waren erfolgreich!" << std::endl;
}