#include "tests/test_haendler.hpp"

void TestHaendler() {
    Haendler haendler{"Leonidas Arkona", "male", 28, "leonidas.arkona@esn.com", "Protein 1, 82617, Proteinos"};

    assert(haendler.GetName() == "Leonidas Arkona");
    assert(haendler.GetAge() == 28);
    assert(haendler.GetAdresse() == "Protein 1, 82617, Proteinos");
    assert(haendler.GetGender() == "male");
    assert(haendler.GetEmail() ==  "leonidas.arkona@esn.com");
    assert(haendler.GetHaendlerID() == 0);

    std::cout << "Alle Tests für Haendler waren erfolgreich!" << std::endl;
}