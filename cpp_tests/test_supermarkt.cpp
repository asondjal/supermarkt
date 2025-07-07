#include "tests/test_supermarkt.hpp"

void TestSupermarkt () {
    Produkt produkt1{"Apfel", 1.170, 1.230, Datum{1, 1, 2022}, "Lebensmittel"};
	Produkt produkt2{"Birne", 5.20, 2.420, Datum{1, 1, 2022}, "Lebensmittel"};

	std::shared_ptr<Kunde> kunde1 = std::make_shared<Kunde>("Kujo Jotaro", "male", 30, "jotaro.kujo@gmail.com", "Tokyo, Japan");
	std::shared_ptr<Kunde> kunde2 = std::make_shared<Kunde>("Josuke Higashikata", "male", 16, "josuke.higashikata@yahoo.com", "Morioh, Japan");

	Haendler haendler1{"Jonathan Joestar", "male", 76, "jonathan.joestar@gmx.net", "London, England"};
    Haendler haendler2{"Girono Giovanna", "male", 19, "giorno.giovanna@gmail.com", "Rom, Italien"};
	
	Warenkorb warenkorb1(kunde1);
	warenkorb1.AddProdukt(&produkt1);
	warenkorb1.AddProdukt(&produkt2);
	warenkorb1.GetProdukte();

	Warenkorb warenkorb2{kunde2};
	warenkorb2.AddProdukt(&produkt1);
	warenkorb2.AddProdukt(&produkt2);

	Konto konto1{kunde1,"Bank of America"};
	konto1.Einzahlen(100.0f);
	Konto konto2{kunde2,"Deutsche Bank"};
	konto2.Einzahlen(50.0f);

	Datum datum1{1, 1, 2022};
	Datum datum2{12, 11, 2009};

	auto shared_konto1 = std::make_shared<Konto>(kunde1, "Bank of America");
    shared_konto1->Einzahlen(100.0f);
	Kassenzettel kassenzettel1{datum1, kunde1, haendler1, warenkorb1, shared_konto1};
	kassenzettel1.CreateKassenzettel();

	auto shared_konto2 = std::make_shared<Konto>(kunde2, "Deutsche Bank");
    shared_konto2->Einzahlen(50.0f);
	Kassenzettel kassenzettel2{datum2, kunde2, haendler1, warenkorb2, shared_konto2};
	kassenzettel2.CreateKassenzettel();

	Supermarkt supermarkt1{"REAL", "Muenchen, Deutschland"};
	supermarkt1.AddProdukt(produkt1);
	supermarkt1.AddProdukt(produkt2);
    supermarkt1.CreateProduktDatabase();
	supermarkt1.AddKunde(kunde1);
	supermarkt1.AddKunde(kunde2);
	supermarkt1.AddHaendler(haendler1);
	supermarkt1.AddWarenkorb(warenkorb1);
	supermarkt1.AddWarenkorb(warenkorb2);

    supermarkt1.CreateProduktDatabase();
    assert(supermarkt1.CreateProduktDatabase() == "./data/supermarkt_0/produkte.txt");
	assert(std::filesystem::exists(supermarkt1.CreateProduktDatabase()));

    supermarkt1.CreateKundeDatabase();
    assert(supermarkt1.CreateKundeDatabase() == "./data/supermarkt_0/kunden.txt");
	assert(std::filesystem::exists(supermarkt1.CreateKundeDatabase()));

    supermarkt1.CreateHaendlerDatabase();
    assert(supermarkt1.CreateHaendlerDatabase() == "./data/supermarkt_0/haendler.txt");
	assert(std::filesystem::exists(supermarkt1.CreateHaendlerDatabase()));

    supermarkt1.CreateWarenkorbDatabase();
    assert(supermarkt1.CreateWarenkorbDatabase() == "./data/supermarkt_0/warenkoerbe.txt");
	assert(std::filesystem::exists(supermarkt1.CreateWarenkorbDatabase()));

    Supermarkt supermarkt2{"DM", "Prag, Tschechien"};
    supermarkt2.AddProdukt(produkt1);
	supermarkt2.AddProdukt(produkt2);
	supermarkt2.AddKunde(kunde1);
	supermarkt2.AddKunde(kunde2);
	supermarkt2.AddHaendler(haendler1);
	supermarkt2.AddWarenkorb(warenkorb1);
	supermarkt2.AddWarenkorb(warenkorb2);

	supermarkt2.CreateProduktDatabase();
    assert(supermarkt2.CreateProduktDatabase() == "./data/supermarkt_1/produkte.txt");
	assert(std::filesystem::exists(supermarkt2.CreateProduktDatabase()));
    supermarkt2.CreateKundeDatabase();
    assert(supermarkt2.CreateKundeDatabase() == "./data/supermarkt_1/kunden.txt");
	assert(std::filesystem::exists(supermarkt2.CreateKundeDatabase()));
    supermarkt2.CreateHaendlerDatabase();
    assert(supermarkt2.CreateHaendlerDatabase() == "./data/supermarkt_1/haendler.txt");
	assert(std::filesystem::exists(supermarkt2.CreateHaendlerDatabase()));
    supermarkt2.CreateWarenkorbDatabase();
    assert(supermarkt2.CreateWarenkorbDatabase() == "./data/supermarkt_1/warenkoerbe.txt");
	assert(std::filesystem::exists(supermarkt2.CreateWarenkorbDatabase()));

    std::cout << "Alle Test für Supermarkt waren erfolgreich!" << std::endl;
}