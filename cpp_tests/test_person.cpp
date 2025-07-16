#include "tests/test_person.hpp"

void TestPerson() {
  Person person{"Max Mustermann", "male", 30, "max.mustermann@gmx.net",
                "Musterstraße 1, 12345, Musterstadt"};

  assert(person.GetName() == "Max Mustermann");
  assert(person.GetAge() == 30);
  assert(person.GetAdresse() == "Musterstraße 1, 12345, Musterstadt");
  assert(person.GetGender() == "male");
  assert(person.GetEmail() == "max.mustermann@gmx.net");

  try {
    Person promi{"Thomas Bryant", "unidentified", 202, "not.yourmail@hotmail.com",
                 "Irgendwo in Berlin"};
    promi.GetGender();
    assert(false && "Nicht vorhandenes Geschlecht!");
  } catch (const std::invalid_argument& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << "Alle Tests für Person waren erfolgreich!" << std::endl;
}