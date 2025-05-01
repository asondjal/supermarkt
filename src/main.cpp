#include <iostream>
#include "datum.hpp"
#include "produkt.hpp"
#include "person.hpp"
#include "kunde.hpp"
#include "warenkorb.hpp"
#include "konto.hpp"
#include "haendler.hpp"
#include "kassenzettel.hpp"
#include "supermarkt.hpp"
#include "read_data.hpp"
#include "statistik.hpp"

// Auskommentierte Funktionen: Erfolgreiche Tests

int main() {

	Produkt produkt1{"Apfel", 1.170, 1.230, Datum{1, 1, 2022}, "Lebensmittel"};
	// produkt1.Display();
	// std::cout << "Gesamtpreis: " << produkt.GetGesamtPreis() << " €" << std::endl;
	// std::cout << "ID: " << produkt.GetID() << std::endl;

	Produkt produkt2{"Birne", 5.20, 2.420, Datum{1, 1, 2022}, "Lebensmittel"};
	// produkt2.Display();
	// std::cout << "Gesamtpreis: " << produkt2.GetGesamtPreis() << " €" << std::endl;
	// std::cout << "ID: " << produkt2.GetID() << std::endl;

	Kunde kunde1{"Kujo Jotaro", "maennlich", 30, "jotaro.kujo@gmail.com", "Tokyo, Japan"};
	// std::cout << kunde1.GetEmail() << std::endl;
	// std::cout << kunde1.GetAdresse() << std::endl;
	// std::cout << kunde1.GetKundeID() << std::endl;
	// kunde1.Print();

	Kunde kunde2{"Josuke Higashikata", "maennlich", 16, "josuke.higashikata@yahoo.com", "Morioh, Japan"};
	// std::cout << kunde2.GetKundeID() << std::endl;
	// kunde2.Print();

	Haendler haendler{"Jonathan Joestar", "maennlich", 76, "jonathan.joestar@gmx.net", "London, England"};
	
	Warenkorb warenkorb1(kunde1);
	warenkorb1.AddProdukt(&produkt1);
	// std::cout << warenkorb.GetGesamtPreis() << std::endl;
	warenkorb1.AddProdukt(&produkt2);
	// std::cout << warenkorb.GetGesamtPreis() << std::endl;

	warenkorb1.GetProdukte();

	Warenkorb warenkorb2{kunde2};

	warenkorb2.AddProdukt(&produkt1);
	// std::cout << warenkorb2.GetGesamtPreis() << std::endl;
	warenkorb2.AddProdukt(&produkt2);
	// std::cout << warenkorb2.GetGesamtPreis() << std::endl;

	Konto konto1{kunde1, "Bank of America"};
	// std::cout << konto1.GetBank() << std::endl;
	// std::cout << konto1.GetKontoID() << std::endl;
	// std::cout << konto1.GetKontostand() << std::endl;
	// konto1.Einzahlen(100.00);
	// std::cout << konto1.GetKontostand() << std::endl;

	Konto konto2{kunde2, "Deutsche Bank"};

	Datum datum1{1, 1, 2022};

	Datum datum2{1, 1, 2023};

	Kassenzettel kassenzettel1{datum1, kunde1, haendler, warenkorb1, konto1};
	kassenzettel1.CreateKassenzettel();
	// std::cout << kassenzettel1.GetKassenzettelID() << std::endl;

	Kassenzettel kassenzettel2{datum2, kunde2, haendler, warenkorb1, konto2};
	kassenzettel2.CreateKassenzettel();
	// std::cout << kassenzettel2.GetKassenzettelID() << std::endl

	Supermarkt supermarkt{"REAL", "Muenchen, Deutschland"};
	supermarkt.AddProdukt(produkt1);
	supermarkt.AddProdukt(produkt2);
	supermarkt.AddKunde(kunde1);
	supermarkt.AddKunde(kunde2);
	supermarkt.AddHaendler(haendler);
	supermarkt.AddWarenkorb(warenkorb1);
	supermarkt.AddWarenkorb(warenkorb2);

	// supermarkt.CreateProduktDatabase();
	// supermarkt.RemoveProdukt(produkt1);
	// supermarkt.CreateProduktDatabase();

	// supermarkt.CreateKundeDatabase();
	// supermarkt.RemoveKunde(kunde1);
	// supermarkt.CreateKundeDatabase();
	// supermarkt.CreateKundeDatabase();
	// supermarkt.AddKunde(kunde1);
	// supermarkt.CreateKundeDatabase();

	// supermarkt.AddHaendler(haendler);
	// supermarkt.CreateHaendlerDatabase();
	// supermarkt.RemoveHaendler(haendler);
	// supermarkt.CreateHaendlerDatabase();
	// supermarkt.AddHaendler(haendler);
	// supermarkt.CreateHaendlerDatabase();

	// supermarkt.AddWarenkorb(warenkorb1);
	// supermarkt.RemoveWarenkorb(warenkorb1);
	// supermarkt.CreateWarenkorbDatabase();
	// supermarkt.RemoveWarenkorb(warenkorb1);
	// supermarkt.CreateWarenkorbDatabase();
	// supermarkt.AddWarenkorb(warenkorb1);
	// supermarkt.CreateWarenkorbDatabase();
	// supermarkt.AddWarenkorb(warenkorb2);
	
	ReadData inventur{"./data/inventur.txt"};
	std::string data = inventur.ReadTxt();
	// std::cout << "Data from file: " << std::endl;
	// std::cout << data << std::endl;

	ReadData kunden{"./data/kunden.txt"};
	std::string kundenData = kunden.ReadTxt();

	ReadData verkaeufer{"./data/haendler.txt"};
	std::string verkaeuferData = verkaeufer.ReadTxt();

	ReadData warenkoerbe{"./data/warenkoerbe.txt"};
	std::string warenkoerbeData = warenkoerbe.ReadTxt();

	ReadData settings{"./.vscode/settings.json"};
	std::string settingsData = settings.ReadJSON();
	// std::cout << "Settings from file: " << std::endl;
	// std::cout << settingsData << std::endl;

	ReadData numbers{"./data/numbers.csv"};
	std::string numbersData = numbers.ReadCSV();
	// std::cout << "Numbers from file: " << std::endl;
	// std::cout << numbersData << std::endl;

	ReadData pdf{"README.pdf"};
	std::string pdfData = pdf.ReadPDF();
	// std::cout << "PDF from file: " << std::endl;
	// std::cout << pdfData << std::endl;

	ReadData autoFile{"CMakeLists.txt"};
	std::string autoData = autoFile.ReadAuto();
	// std::cout << "Auto from file: " << std::endl;
	// std::cout << autoData << std::endl;

	Statistik statistik;
	statistik.LadeDaten(warenkoerbe);
	// std::cout << "Anzahl Daten: " << statistik.ZaehleElemente() << std::endl;
	// statistik.EntferneDaten(data);
	// std::cout << "Anzahl Daten nach Entfernen: " << statistik.ZaehleElemente() << std::endl;
	// statistik.LadeDaten(inventur);
	// std::cout << "Anzahl Daten: " << statistik.ZaehleElemente() << std::endl;
	// statistik.LadeDaten(numbers);
	// std::cout << "Anzahl Daten: " << statistik.ZaehleEintraege() << std::endl;
	// std::cout << "Anzahl Zeilen: " << statistik.ZaehleLinien() << std::endl;
	// std::cout << "Anzahl Worte: " << statistik.ZaehleWorte() << std::endl;
	// std::cout << "Anzahl Zeichen: " << statistik.ZaehleZeichen() << std::endl;
	// std::cout << "Mittelwert: " << statistik.Mittelwert() << std::endl;
	// std::cout << "\n";

	statistik.LadeDaten(kunden);
	// std::cout << "Anzahl Daten: " << statistik.ZaehleEintraege() << std::endl;
	// std::cout << "Anzahl Zeilen: " << statistik.ZaehleLinien() << std::endl;
	// std::cout << "Anzahl Worte: " << statistik.ZaehleWorte() << std::endl;
	// std::cout << "Anzahl Zeichen: " << statistik.ZaehleZeichen() << std::endl;
	// std::cout << "Mittelwert: " << statistik.Mittelwert() << std::endl;
	// std::cout << "Median: " << statistik.Median() << std::endl;
	// std::cout << "Erwartungswert: " << statistik.Erwartungswert() << std::endl;
	// std::cout << "Varianz: " << statistik.Varianz() << std::endl;
	// std::cout << "\n";

	statistik.LadeDaten(verkaeufer);
	// std::cout << "Anzahl Daten: " << statistik.ZaehleEintraege() << std::endl;
	// std::cout << "Anzahl Zeilen: " << statistik.ZaehleLinien() << std::endl;
	// std::cout << "Anzahl Worte: " << statistik.ZaehleWorte() << std::endl;
	// std::cout << "Anzahl Zeichen: " << statistik.ZaehleZeichen() << std::endl;
	// std::cout << "Mittelwert: " << statistik.Mittelwert() << std::endl;
	// std::cout << "Median: " << statistik.Median() << std::endl;
	// std::cout << "Anzahl Database: " << statistik.ZaehleVariable("DATABASE") << std::endl;
	// std::cout << "Anzahl Joestar: " << statistik.ZaehleVariable("Joestar") << std::endl;
	// std::cout << "Anzahl REAL: " << statistik.ZaehleVariable("REAL") << std::endl;
	// std::cout << "\n";

	statistik.LadeDaten(inventur);
	// std::cout << "Anzahl Daten: " << statistik.ZaehleEintraege() << std::endl;
	// std::cout << "Anzahl Database: " << statistik.ZaehleVariable("DATABASE") << std::endl;
	// std::cout << "Anzahl REAL: " << statistik.ZaehleVariable("REAL") << std::endl;

	return 0;
}
