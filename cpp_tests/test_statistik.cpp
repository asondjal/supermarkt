#include "tests/test_statistik.hpp"

void TestStatistik() {
  ReadData inventur{"./data/supermarkt_1/produkte.txt"};
  std::string data = inventur.ReadTxt();

  ReadData kunden{"./data/supermarkt_0/kunden.txt"};
  std::string kundenData = kunden.ReadTxt();

  ReadData verkaeufer{"./data/supermarkt_0/haendler.txt"};
  std::string verkaeuferData = verkaeufer.ReadTxt();

  ReadData warenkoerbe{"./data/supermarkt_1/warenkoerbe.txt"};
  std::string warenkoerbeData = warenkoerbe.ReadTxt();

  ReadData settings{"./.vscode/settings.json"};
  std::string settingsData = settings.ReadJSON();

  ReadData numbers{"./data/numbers.csv"};
  std::string numbersData = numbers.ReadCSV();

  ReadData pdf{"README.pdf"};
  std::string pdfData = pdf.ReadPDF();

  Statistik statistik;
  statistik.LadeDaten(warenkoerbe);
  assert(statistik.ZaehleEintraege() == 1);
  assert(statistik.ZaehleVariable("DATABASE") == 1);
  statistik.EntferneDaten(warenkoerbeData);
  assert(statistik.ZaehleEintraege() == 0);
  statistik.EntferneDaten(warenkoerbeData);
  assert(statistik.ZaehleEintraege() == 0);
  statistik.LadeDaten(inventur);
  assert(statistik.ZaehleEintraege() == 1);
  assert(statistik.ZaehleLinien() == 11);
  assert(statistik.ZaehleWorte() == 14);
  statistik.LadeDaten(numbers);
  assert(statistik.ZaehleEintraege() == 2);
  assert(statistik.ZaehleLinien() == 54);
  assert(statistik.ZaehleWorte() == 14);
  assert(statistik.ZaehleZeichen() == 2084);
  assert(std::fabs(statistik.Mittelwert() - 197.14f) < 0.01f);
  assert(std::fabs(statistik.Median() - 1042.00f) < 0.01f);
  assert(std::fabs(statistik.Erwartungswert() - 197.14f) < 0.01f);
  assert(std::fabs(statistik.Standardabweichung() - 117.26f) < 0.01f);

  std::cout << "Alle Statistik-Tests waren erfolgreich!" << std::endl;
}