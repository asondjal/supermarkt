#include "../inc/utils/tests.hpp"
#include "../inc/base/datum.hpp"
#include "../inc/base/produkt.hpp"
#include "../inc/base/person.hpp"
#include "../inc/base/kunde.hpp"
#include "../inc/base/warenkorb.hpp"
#include "../inc/base/konto.hpp"
#include "../inc/base/haendler.hpp"
#include "../inc/base/kassenzettel.hpp"
#include "../inc/base/supermarkt.hpp"

Tests::Tests() {}

void Tests::test_Datum() {
    Datum datum{11, 11, 2011};

    assert(datum.GetTag() == 11);
    assert(datum.GetMonat() == 11);
    assert(datum.GetJahr() == 2011);
    assert(datum.Print() == "11.11.2011");

    std::cout << "Erfolgreiche Tests für Datum!" << std::endl;
}

void Tests::test_Produkt() {
    Datum datum{1, 1, 2025};
    Produkt produkt{"Apfel", 1.99f, 3.0f, datum, "Obst"};

    assert(produkt.GetMenge() == 1.99f);  
    assert(produkt.GetPreis() ==  3.0f);      
    assert(produkt.GetName() == "Apfel");
    assert(produkt.GetAbteilung() == "Obst");
    assert(std::abs(produkt.GetGesamtPreis() - (1.99f * 3.0f)) < 0.001f); 
    auto test_produkt = produkt.GetHaltbarkeit();
    assert(test_produkt == datum);

    std::cout << "Produkt Test erfolgreich!" << std::endl;
}

void Tests::test_Person() {
    Person person{"Max Mustermann", "M", 30, "max.mustermann@gmx.net", "Musterstraße 1, 12345, Musterstadt"};

    assert(person.GetName() == "Max Mustermann");
    assert(person.GetAge() == 30);
    assert(person.GetAdresse() == "Musterstraße 1, 12345, Musterstadt");
    assert(person.GetGender() == "M");
    assert(person.GetEmail() ==  "max.mustermann@gmx.net");

    std::cout << "Person Test erfolgreich!" << std::endl;
}

void Tests::test_Kunde() {
    Kunde kunde{"LeBron James", "M", 40, "lebron.james@gmail.com", "Los Angeles, USA"};

    assert(kunde.GetName() == "LeBron James");
    assert(kunde.GetAge() == 40);
    assert(kunde.GetAdresse() == "Los Angeles, USA");
    assert(kunde.GetGender() == "M");
    assert(kunde.GetEmail() ==  "lebron.james@gmail.com");
    assert(kunde.GetKundeID()== 0);

    std::cout << "Kunde Test erfolgreich!" << std::endl;
}

void Tests::test_Haendler() {
    Haendler haendler{"Leonidas Arkona", "M", 28, "leonidas.arkona@esn.com", "Protein 1, 82617, Proteinos"};

    assert(haendler.GetName() == "Leonidas Arkona");
    assert(haendler.GetAge() == 28);
    assert(haendler.GetAdresse() == "Protein 1, 82617, Proteinos");
    assert(haendler.GetGender() == "M");
    assert(haendler.GetEmail() ==  "leonidas.arkona@esn.com");
    assert(haendler.GetHaendlerID() == 0);

    std::cout << "Haendler Test erfolgreich!" << std::endl;
}

void Tests::test_Warenkorb() {
    Datum datum{1, 1, 2025};
    Produkt apfel{"Apfel", 1.99f, 3.0f, datum, "Obst"};
    Produkt birne{"Birne", 2.52f, 4.49f, datum, "Obst" };
    Kunde kunde{"LeBron James", "M", 30, "lebron.james@gmail.com", "Los Angeles, USA"};
    Warenkorb warenkorb{kunde};

    warenkorb.AddProdukt(&apfel);
    auto produkte = warenkorb.GetProdukte();
    assert(produkte.size() == 1);
    assert(produkte[0] == &apfel);
    assert(std::abs(warenkorb.GetGesamtPreis() - (1.99f * 3.0f)) < 0.001f);

    warenkorb.AddProdukt(&birne);
    produkte = warenkorb.GetProdukte();
    assert(produkte.size() == 2);
    assert(produkte[1] == &birne);
    assert(warenkorb.GetProdukte().size() == 2);
    assert(std::abs(warenkorb.GetGesamtPreis() - ((1.99f * 3.0f) + (2.52f * 4.49f))) < 0.001f);

    warenkorb.RemoveProdukt(&apfel);
    assert(warenkorb.GetProdukte().size() == 1);
    assert(std::abs(warenkorb.GetGesamtPreis() - (2.52f * 4.49f)) < 0.001f);

    warenkorb.RemoveProdukt(&apfel);
    assert(warenkorb.GetProdukte().size() == 1);
    assert(std::abs(warenkorb.GetGesamtPreis() - (2.52f * 4.49f)) < 0.001f);

    std::cout << "Warenkorb Test erfolgreich!" << std::endl;
}

void Tests::test_Konto() {
    const Kunde kunde{"Jonathan Joestar", "M", 35, "jonathan.joestar@yahoo.com", "London, UK"};
    Konto konto{kunde, "Barclays"};

    assert(konto.GetUser() == kunde);
    konto.Einzahlen(100.0f);
    assert(konto.GetKontostand() == 100.0f);
    konto.Auszahlen(50.0f);
    assert(konto.GetKontostand() == 50.0f);

    std::cout << "Konto Test erfolgreich!" << std::endl;
}

void Tests::test_Kassenzettel() {
    Produkt produkt1{"Apfel", 1.170, 1.230, Datum{1, 1, 2022}, "Lebensmittel"};
	Produkt produkt2{"Birne", 5.20, 2.420, Datum{1, 1, 2022}, "Lebensmittel"};

	Kunde kunde1{"Kujo Jotaro", "maennlich", 30, "jotaro.kujo@gmail.com", "Tokyo, Japan"};
	Kunde kunde2{"Josuke Higashikata", "maennlich", 16, "josuke.higashikata@yahoo.com", "Morioh, Japan"};

	Haendler haendler1{"Jonathan Joestar", "maennlich", 76, "jonathan.joestar@gmx.net", "London, England"};
    Haendler haendler2{"Girono Giovanna", "maennlich", 19, "giorno.giovanna@gmail.com", "Rom, Italien"};
	
	Konto konto1{kunde1,"Bank of America"};
	konto1.Einzahlen(100.0f);
	Konto konto2{kunde2,"Deutsche Bank"};
	konto2.Einzahlen(50.0f);

	Datum datum1{1, 1, 2022};
	Datum datum2{12, 11, 2009};

	Warenkorb warenkorb1(kunde1);
	warenkorb1.AddProdukt(&produkt1);
	warenkorb1.AddProdukt(&produkt2);

	Warenkorb warenkorb2{kunde2};
	warenkorb2.AddProdukt(&produkt1);
	warenkorb2.AddProdukt(&produkt2);

	auto shared_konto1 = std::make_shared<Konto>(kunde1, "Bank of America");
	Kassenzettel kassenzettel1{datum1, kunde1, haendler1, warenkorb1, shared_konto1};
	kassenzettel1.CreateKassenzettel();
	assert(konto1.GetKontostand() == 100.0f - warenkorb1.GetGesamtPreis());

	auto shared_konto2 = std::make_shared<Konto>(kunde2, "Deutsche Bank");
	Kassenzettel kassenzettel2{datum2, kunde2, haendler1, warenkorb1, shared_konto2};
	kassenzettel2.CreateKassenzettel();
	assert(konto2.GetKontostand() == 50.0f - warenkorb1.GetGesamtPreis());

    std::cout << "Test für Kassenzettel alle erfolgreich!" << std::endl;
}

void Tests::test_Supermarkt() {
    Produkt produkt1{"Apfel", 1.170, 1.230, Datum{1, 1, 2022}, "Lebensmittel"};
	Produkt produkt2{"Birne", 5.20, 2.420, Datum{1, 1, 2022}, "Lebensmittel"};

	Kunde kunde1{"Kujo Jotaro", "M", 30, "jotaro.kujo@gmail.com", "Tokyo, Japan"};
	Kunde kunde2{"Josuke Higashikata", "M", 16, "josuke.higashikata@yahoo.com", "Morioh, Japan"};

	Haendler haendler1{"Jonathan Joestar", "M", 76, "jonathan.joestar@gmx.net", "London, England"};
    Haendler haendler2{"Girono Giovanna", "M", 19, "giorno.giovanna@gmail.com", "Rom, Italien"};
	
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
	Kassenzettel kassenzettel1{datum1, kunde1, haendler1, warenkorb1, shared_konto1};
	kassenzettel1.CreateKassenzettel();

	auto shared_konto2 = std::make_shared<Konto>(kunde2, "Deutsche Bank");
	Kassenzettel kassenzettel2{datum2, kunde2, haendler1, warenkorb1, shared_konto2};
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

void Tests::test_ReadData() {

	ReadData inventur{"./data/supermarkt_1/produkte.txt"};
	std::string data = inventur.ReadTxt();
	std::ifstream produkt_file("./data/supermarkt_1/produkte.txt");
	std::string data_content((std::istreambuf_iterator<char>(produkt_file)), std::istreambuf_iterator<char>());
	assert(data == data_content);

	ReadData kunden{"./data/supermarkt_0/kunden.txt"};
	std::string kundenData = kunden.ReadTxt();
	std::ifstream kunden_file("./data/supermarkt_0/kunden.txt");
	std::string kunden_content((std::istreambuf_iterator<char>(kunden_file)), std::istreambuf_iterator<char>());
	assert(kundenData == kunden_content);

	ReadData verkaeufer{"./data/supermarkt_0/haendler.txt"};
	std::string verkaeuferData = verkaeufer.ReadTxt();
	std::ifstream verkaeufer_file("./data/supermarkt_0/haendler.txt");
	std::string verkaeufer_content((std::istreambuf_iterator<char>(verkaeufer_file)), std::istreambuf_iterator<char>());
	assert(verkaeuferData == verkaeufer_content);

	ReadData warenkoerbe{"./data/supermarkt_1/warenkoerbe.txt"};
	std::string warenkoerbeData = warenkoerbe.ReadTxt();
	std::ifstream warenkoerbe_file("./data/supermarkt_1/warenkoerbe.txt");
	std::string warenkoerbe_content((std::istreambuf_iterator<char>(warenkoerbe_file)), std::istreambuf_iterator<char>());
	assert(warenkoerbeData == warenkoerbe_content);

	ReadData settings{"./.vscode/settings.json"};
	std::string settingsData = settings.ReadJSON();
	std::ifstream settings_file("./.vscode/settings.json");
	std::string settings_content((std::istreambuf_iterator<char>(settings_file)), std::istreambuf_iterator<char>());
	assert(settingsData == settings_content);

	ReadData numbers{"./data/numbers.csv"};
	std::string numbersData = numbers.ReadCSV();
	std::ifstream numbers_file("./data/numbers.csv");
	std::string numbers_content((std::istreambuf_iterator<char>(numbers_file)), std::istreambuf_iterator<char>());
	assert(numbersData == numbers_content);

	ReadData pdf{"README.pdf"};
	std::string pdfData = pdf.ReadPDF();
	std::ifstream pdf_file("README.pdf");
	std::string pdf_content;
	poppler::document* doc = poppler::document::load_from_file("README.pdf");
	if (!doc) {
		throw std::runtime_error("Could not open PDF file: README.pdf");
	}
	for (int i = 0; i < doc->pages(); ++i) {
		poppler::page* p = doc->create_page(i);
		if (p) {
			pdf_content += p->text().to_latin1();
			delete p;
		}
	}
	delete doc;

	assert(pdfData == pdf_content);

	ReadData autoFile{"CMakeLists.txt"};
	std::string autoData = autoFile.ReadAuto();
	std::ifstream automatic_file("CMakeLists.txt");
	std::string automated_content((std::istreambuf_iterator<char>(automatic_file)), std::istreambuf_iterator<char>());
	assert(autoData == automated_content);

	std::cout << "Alle Tests für ReadData waren erfolgreich!" << std::endl;

}

void Tests::test_Statistik() {
	
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
	assert(std::fabs(statistik.Varianz() - 13750.23f) < 0.01f);

	std::cout << "Alle Statistik-Tests waren erfolgreich!" << std::endl;
}

void Tests::test_Logging() {

    Logging logger("logfile.txt", LogLevel::DEBUG);
	assert(std::filesystem::exists("logfile.txt"));
	assert(logger.getLevel() == "DEBUG");
    logger.log("System initialized.", LogLevel::INFO);
    logger.log("Reading configuration...", LogLevel::DEBUG);
    logger.log("File not found!", LogLevel::WARNING);
    logger.log("Critical error!", LogLevel::ERROR);

	std::cout << "Alle Logging-Tests waren erfolgreich!" << std::endl;
}

void Tests::runAllTests() {
    test_Datum();
    test_Produkt();
    test_Person();
    test_Kunde();
    test_Haendler();
    test_Warenkorb();
    test_Konto();
    test_Kassenzettel();
    test_Supermarkt();
    test_ReadData();
    test_Statistik();
	test_Logging();

    std::cout << "Alle Tests erfolgreich!" << std::endl;
}