#include <iostream>

#include "tests/test_datum.hpp"
#include "tests/test_haendler.hpp"
#include "tests/test_kassenzettel.hpp"
#include "tests/test_konto.hpp"
#include "tests/test_kunde.hpp"
#include "tests/test_logging.hpp"
#include "tests/test_person.hpp"
#include "tests/test_produkt.hpp"
#include "tests/test_read_data.hpp"
#include "tests/test_statistik.hpp"
#include "tests/test_supermarkt.hpp"
#include "tests/test_warenkorb.hpp"

int main() {
  TestDatum();
  TestProdukt();
  TestPerson();
  TestKunde();
  TestHaendler();
  TestWarenkorb();
  TestKonto();
  TestKassenzettel();
  TestSupermarkt();

  TestReadData();
  TestStatistik();
  TestLogging();

  return 0;
}
