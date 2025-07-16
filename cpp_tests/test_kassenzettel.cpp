#include "tests/test_kassenzettel.hpp"

void TestKassenzettel() {
  Produkt produkt1{"Apfel", 1.170, 1.230, Datum{1, 1, 2022}, "Lebensmittel"};
  Produkt produkt2{"Birne", 5.20, 2.420, Datum{1, 1, 2022}, "Lebensmittel"};

  std::shared_ptr<Kunde> kunde1 =
      std::make_shared<Kunde>("Kujo Jotaro", "male", 30, "jotaro.kujo@gmail.com", "Tokyo, Japan");
  std::shared_ptr<Kunde> kunde2 = std::make_shared<Kunde>(
      "Josuke Higashikata", "male", 16, "josuke.higashikata@yahoo.com", "Morioh, Japan");

  Haendler haendler1{"Jonathan Joestar", "male", 76, "jonathan.joestar@gmx.net", "London, England"};
  Haendler haendler2{"Girono Giovanna", "male", 19, "giorno.giovanna@gmail.com", "Rom, Italien"};

  auto shared_konto1 = std::make_shared<Konto>(kunde1, "Bank of America");
  shared_konto1->Einzahlen(100.0f);
  auto shared_konto2 = std::make_shared<Konto>(kunde2, "Deutsche Bank");
  shared_konto2->Einzahlen(50.0f);

  Datum datum1{1, 1, 2022};
  Datum datum2{12, 11, 2009};

  Warenkorb warenkorb1(kunde1);
  warenkorb1.AddProdukt(&produkt1);
  warenkorb1.AddProdukt(&produkt2);

  Warenkorb warenkorb2{kunde2};
  warenkorb2.AddProdukt(&produkt1);
  warenkorb2.AddProdukt(&produkt2);

  Kassenzettel kassenzettel1{datum1, kunde1, haendler1, warenkorb1, shared_konto1};
  kassenzettel1.CreateKassenzettel();
  assert(shared_konto1->GetKontostand() == 100.0f - warenkorb1.GetGesamtPreis());

  Kassenzettel kassenzettel2{datum2, kunde2, haendler1, warenkorb1, shared_konto2};
  kassenzettel2.CreateKassenzettel();
  assert(shared_konto2->GetKontostand() == 50.0f - warenkorb1.GetGesamtPreis());

  std::cout << "Alle Test für Kassenzettel waren erfolgreich!" << std::endl;
}