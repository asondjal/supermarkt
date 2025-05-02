#include "tests.hpp"

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
    // assert(kunde.GetKundeID()== 2);

    std::cout << "Kunde Test erfolgreich!" << std::endl;
}

void Tests::test_Haendler() {
    Haendler haendler{"Leonidas Arkona", "M", 28, "leonidas.arkona@esn.com", "Protein 1, 82617, Proteinos"};

    assert(haendler.GetName() == "Leonidas Arkona");
    assert(haendler.GetAge() == 28);
    assert(haendler.GetAdresse() == "Protein 1, 82617, Proteinos");
    assert(haendler.GetGender() == "M");
    assert(haendler.GetEmail() ==  "leonidas.arkona@esn.com");
    // assert(haendler.GetHaendlerID() == 1);

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
	
	Warenkorb warenkorb1(kunde1);
	warenkorb1.AddProdukt(&produkt1);
	warenkorb1.AddProdukt(&produkt2);
	warenkorb1.GetProdukte();

	Warenkorb warenkorb2{kunde2};
	warenkorb2.AddProdukt(&produkt1);
	warenkorb2.AddProdukt(&produkt2);

	Konto konto1{kunde1,"Bank of America"};
	Konto konto2{kunde2,"Deutsche Bank"};

	Datum datum1{1, 1, 2022};
	Datum datum2{12, 11, 2009};

	Kassenzettel kassenzettel1{datum1, kunde1, haendler1, warenkorb1, konto1};
	kassenzettel1.CreateKassenzettel();

	Kassenzettel kassenzettel2{datum2, kunde2, haendler1, warenkorb1, konto2};
	kassenzettel2.CreateKassenzettel();

    std::cout << "Test für Kassenzettel alle erfolgreich!" << std::endl;
}

void Tests::test_Supermarkt() {
    Produkt produkt1{"Apfel", 1.170, 1.230, Datum{1, 1, 2022}, "Lebensmittel"};
	Produkt produkt2{"Birne", 5.20, 2.420, Datum{1, 1, 2022}, "Lebensmittel"};

	Kunde kunde1{"Kujo Jotaro", "maennlich", 30, "jotaro.kujo@gmail.com", "Tokyo, Japan"};
	Kunde kunde2{"Josuke Higashikata", "maennlich", 16, "josuke.higashikata@yahoo.com", "Morioh, Japan"};

	Haendler haendler1{"Jonathan Joestar", "maennlich", 76, "jonathan.joestar@gmx.net", "London, England"};
    Haendler haendler2{"Girono Giovanna", "maennlich", 19, "giorno.giovanna@gmail.com", "Rom, Italien"};
	
	Warenkorb warenkorb1(kunde1);
	warenkorb1.AddProdukt(&produkt1);
	warenkorb1.AddProdukt(&produkt2);
	warenkorb1.GetProdukte();

	Warenkorb warenkorb2{kunde2};
	warenkorb2.AddProdukt(&produkt1);
	warenkorb2.AddProdukt(&produkt2);

	Konto konto1{kunde1,"Bank of America"};
	Konto konto2{kunde2,"Deutsche Bank"};

	Datum datum1{1, 1, 2022};
	Datum datum2{12, 11, 2009};

	Kassenzettel kassenzettel1{datum1, kunde1, haendler1, warenkorb1, konto1};
	kassenzettel1.CreateKassenzettel();

	Kassenzettel kassenzettel2{datum2, kunde2, haendler1, warenkorb1, konto2};
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
    supermarkt1.CreateKundeDatabase();
    assert(supermarkt1.CreateKundeDatabase() == "./data/supermarkt_0/kunden.txt");
    supermarkt1.CreateHaendlerDatabase();
    assert(supermarkt1.CreateHaendlerDatabase() == "./data/supermarkt_0/haendler.txt");
    supermarkt1.CreateWarenkorbDatabase();
    assert(supermarkt1.CreateWarenkorbDatabase() == "./data/supermarkt_0/warenkoerbe.txt");

    Supermarkt supermarkt2{"DM", "Prag, Tschechien"};
    supermarkt2.AddProdukt(produkt1);
	supermarkt2.AddProdukt(produkt2);
	supermarkt2.AddKunde(kunde1);
	supermarkt2.AddKunde(kunde2);
	supermarkt2.AddHaendler(haendler1);
	supermarkt2.AddWarenkorb(warenkorb1);
	supermarkt2.AddWarenkorb(warenkorb2);
    assert(supermarkt2.CreateProduktDatabase() == "./data/supermarkt_1/produkte.txt");
    supermarkt2.CreateKundeDatabase();
    assert(supermarkt2.CreateKundeDatabase() == "./data/supermarkt_1/kunden.txt");
    supermarkt2.CreateHaendlerDatabase();
    assert(supermarkt2.CreateHaendlerDatabase() == "./data/supermarkt_1/haendler.txt");
    supermarkt2.CreateWarenkorbDatabase();
    assert(supermarkt2.CreateWarenkorbDatabase() == "./data/supermarkt_1/warenkoerbe.txt");

    std::cout << "Alle Test für Supermarkt waren erfolgreich!" << std::endl;
}

void Tests::test_ReadData() {

	Produkt produkt1{"Apfel", 1.170, 1.230, Datum{1, 1, 2022}, "Lebensmittel"};
	Produkt produkt2{"Birne", 5.20, 2.420, Datum{1, 1, 2022}, "Lebensmittel"};

	Kunde kunde1{"Kujo Jotaro", "maennlich", 30, "jotaro.kujo@gmail.com", "Tokyo, Japan"};
	Kunde kunde2{"Josuke Higashikata", "maennlich", 16, "josuke.higashikata@yahoo.com", "Morioh, Japan"};

	Haendler haendler{"Jonathan Joestar", "maennlich", 76, "jonathan.joestar@gmx.net", "London, England"};
	
	Warenkorb warenkorb1(kunde1);
	warenkorb1.AddProdukt(&produkt1);
	warenkorb1.AddProdukt(&produkt2);

	warenkorb1.GetProdukte();

	Warenkorb warenkorb2{kunde2};

	warenkorb2.AddProdukt(&produkt1);
	warenkorb2.AddProdukt(&produkt2);

	Konto konto1{kunde1, "Bank of America"};
	Konto konto2{kunde2, "Deutsche Bank"};

	Datum datum1{1, 1, 2022};
	Datum datum2{1, 1, 2023};

	Kassenzettel kassenzettel1{datum1, kunde1, haendler, warenkorb1, konto1};
	kassenzettel1.CreateKassenzettel();

	Kassenzettel kassenzettel2{datum2, kunde2, haendler, warenkorb1, konto2};
	kassenzettel2.CreateKassenzettel();

	Supermarkt supermarkt{"REAL", "Muenchen, Deutschland"};
	supermarkt.AddProdukt(produkt1);
	supermarkt.AddProdukt(produkt2);
	supermarkt.AddKunde(kunde1);
	supermarkt.AddKunde(kunde2);
	supermarkt.AddHaendler(haendler);
	supermarkt.AddWarenkorb(warenkorb1);
	supermarkt.AddWarenkorb(warenkorb2);
	
	// ReadData inventur{"./data/inventur.txt"};
	// std::string data = inventur.ReadTxt();
	// std::cout << "Data from file: " << std::endl;
	// std::cout << data << std::endl;

	// ReadData kunden{"./data/kunden.txt"};
	// std::string kundenData = kunden.ReadTxt();

	// ReadData verkaeufer{"./data/haendler.txt"};
	// std::string verkaeuferData = verkaeufer.ReadTxt();

	// ReadData warenkoerbe{"./data/warenkoerbe.txt"};
	// std::string warenkoerbeData = warenkoerbe.ReadTxt();

	// ReadData settings{"./.vscode/settings.json"};
	// std::string settingsData = settings.ReadJSON();
	// // std::cout << "Settings from file: " << std::endl;
	// // std::cout << settingsData << std::endl;

	// ReadData numbers{"./data/numbers.csv"};
	// std::string numbersData = numbers.ReadCSV();
	// // std::cout << "Numbers from file: " << std::endl;
	// // std::cout << numbersData << std::endl;

	// ReadData pdf{"README.pdf"};
	// std::string pdfData = pdf.ReadPDF();
	// // std::cout << "PDF from file: " << std::endl;
	// // std::cout << pdfData << std::endl;

	// ReadData autoFile{"CMakeLists.txt"};
	// std::string autoData = autoFile.ReadAuto();
	// // std::cout << "Auto from file: " << std::endl;
	// // std::cout << autoData << std::endl;
}

void Tests::test_Statistik() {

	Produkt produkt1{"Apfel", 1.170, 1.230, Datum{1, 1, 2022}, "Lebensmittel"};
	Produkt produkt2{"Birne", 5.20, 2.420, Datum{1, 1, 2022}, "Lebensmittel"};

	Kunde kunde1{"Kujo Jotaro", "maennlich", 30, "jotaro.kujo@gmail.com", "Tokyo, Japan"};
	Kunde kunde2{"Josuke Higashikata", "maennlich", 16, "josuke.higashikata@yahoo.com", "Morioh, Japan"};

	Haendler haendler{"Jonathan Joestar", "maennlich", 76, "jonathan.joestar@gmx.net", "London, England"};
	
	Warenkorb warenkorb1(kunde1);
	warenkorb1.AddProdukt(&produkt1);
	warenkorb1.AddProdukt(&produkt2);

	warenkorb1.GetProdukte();

	Warenkorb warenkorb2{kunde2};

	warenkorb2.AddProdukt(&produkt1);
	warenkorb2.AddProdukt(&produkt2);

	Konto konto1{kunde1, "Bank of America"};
	Konto konto2{kunde2, "Deutsche Bank"};

	Datum datum1{1, 1, 2022};
	Datum datum2{1, 1, 2023};

	Kassenzettel kassenzettel1{datum1, kunde1, haendler, warenkorb1, konto1};
	kassenzettel1.CreateKassenzettel();

	Kassenzettel kassenzettel2{datum2, kunde2, haendler, warenkorb1, konto2};
	kassenzettel2.CreateKassenzettel();

	Supermarkt supermarkt{"REAL", "Muenchen, Deutschland"};
	supermarkt.AddProdukt(produkt1);
	supermarkt.AddProdukt(produkt2);
	supermarkt.AddKunde(kunde1);
	supermarkt.AddKunde(kunde2);
	supermarkt.AddHaendler(haendler);
	supermarkt.AddWarenkorb(warenkorb1);
	supermarkt.AddWarenkorb(warenkorb2);
	
	// ReadData inventur{"./data/inventur.txt"};
	// std::string data = inventur.ReadTxt();
	// std::cout << "Data from file: " << std::endl;
	// std::cout << data << std::endl;

	// ReadData kunden{"./data/kunden.txt"};
	// std::string kundenData = kunden.ReadTxt();

	// ReadData verkaeufer{"./data/haendler.txt"};
	// std::string verkaeuferData = verkaeufer.ReadTxt();

	// ReadData warenkoerbe{"./data/warenkoerbe.txt"};
	// std::string warenkoerbeData = warenkoerbe.ReadTxt();

	// ReadData settings{"./.vscode/settings.json"};
	// std::string settingsData = settings.ReadJSON();
	// // std::cout << "Settings from file: " << std::endl;
	// // std::cout << settingsData << std::endl;

	// ReadData numbers{"./data/numbers.csv"};
	// std::string numbersData = numbers.ReadCSV();
	// // std::cout << "Numbers from file: " << std::endl;
	// // std::cout << numbersData << std::endl;

	// ReadData pdf{"README.pdf"};
	// std::string pdfData = pdf.ReadPDF();
	// // std::cout << "PDF from file: " << std::endl;
	// // std::cout << pdfData << std::endl;

	// ReadData autoFile{"CMakeLists.txt"};
	// std::string autoData = autoFile.ReadAuto();
	// // std::cout << "Auto from file: " << std::endl;
	// // std::cout << autoData << std::endl;

	// Statistik statistik;
	// statistik.LadeDaten(warenkoerbe);
	// // std::cout << "Anzahl Daten: " << statistik.ZaehleElemente() << std::endl;
	// // statistik.EntferneDaten(data);
	// // std::cout << "Anzahl Daten nach Entfernen: " << statistik.ZaehleElemente() << std::endl;
	// // statistik.LadeDaten(inventur);
	// // std::cout << "Anzahl Daten: " << statistik.ZaehleElemente() << std::endl;
	// // statistik.LadeDaten(numbers);
	// // std::cout << "Anzahl Daten: " << statistik.ZaehleEintraege() << std::endl;
	// // std::cout << "Anzahl Zeilen: " << statistik.ZaehleLinien() << std::endl;
	// // std::cout << "Anzahl Worte: " << statistik.ZaehleWorte() << std::endl;
	// // std::cout << "Anzahl Zeichen: " << statistik.ZaehleZeichen() << std::endl;
	// // std::cout << "Mittelwert: " << statistik.Mittelwert() << std::endl;
	// // std::cout << "\n";

	// statistik.LadeDaten(kunden);
	// // std::cout << "Anzahl Daten: " << statistik.ZaehleEintraege() << std::endl;
	// // std::cout << "Anzahl Zeilen: " << statistik.ZaehleLinien() << std::endl;
	// // std::cout << "Anzahl Worte: " << statistik.ZaehleWorte() << std::endl;
	// // std::cout << "Anzahl Zeichen: " << statistik.ZaehleZeichen() << std::endl;
	// // std::cout << "Mittelwert: " << statistik.Mittelwert() << std::endl;
	// // std::cout << "Median: " << statistik.Median() << std::endl;
	// // std::cout << "Erwartungswert: " << statistik.Erwartungswert() << std::endl;
	// // std::cout << "Varianz: " << statistik.Varianz() << std::endl;
	// // std::cout << "\n";

	// statistik.LadeDaten(verkaeufer);
	// // std::cout << "Anzahl Daten: " << statistik.ZaehleEintraege() << std::endl;
	// // std::cout << "Anzahl Zeilen: " << statistik.ZaehleLinien() << std::endl;
	// // std::cout << "Anzahl Worte: " << statistik.ZaehleWorte() << std::endl;
	// // std::cout << "Anzahl Zeichen: " << statistik.ZaehleZeichen() << std::endl;
	// // std::cout << "Mittelwert: " << statistik.Mittelwert() << std::endl;
	// // std::cout << "Median: " << statistik.Median() << std::endl;
	// // std::cout << "Anzahl Database: " << statistik.ZaehleVariable("DATABASE") << std::endl;
	// // std::cout << "Anzahl Joestar: " << statistik.ZaehleVariable("Joestar") << std::endl;
	// // std::cout << "Anzahl REAL: " << statistik.ZaehleVariable("REAL") << std::endl;
	// // std::cout << "\n";

	// statistik.LadeDaten(inventur);
	// // std::cout << "Anzahl Daten: " << statistik.ZaehleEintraege() << std::endl;
	// // std::cout << "Anzahl Database: " << statistik.ZaehleVariable("DATABASE") << std::endl;
	// // std::cout << "Anzahl REAL: " << statistik.ZaehleVariable("REAL") << std::endl;
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

    std::cout << "Alle Tests erfolgreich!" << std::endl;
}