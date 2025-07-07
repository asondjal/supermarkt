#include "tests/test_person.hpp"

void TestPerson() {
    Person person{"Max Mustermann", "male", 30, "max.mustermann@gmx.net", "Musterstraße 1, 12345, Musterstadt"};

    assert(person.GetName() == "Max Mustermann");
    assert(person.GetAge() == 30);
    assert(person.GetAdresse() == "Musterstraße 1, 12345, Musterstadt");
    assert(person.GetGender() == "male");
    assert(person.GetEmail() ==  "max.mustermann@gmx.net");

    std::cout << "Alle Tests für Person waren erfolgreich!" << std::endl;
}