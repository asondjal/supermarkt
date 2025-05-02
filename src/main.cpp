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
#include "tests.hpp"

// Auskommentierte Funktionen: Erfolgreiche Tests

int main() {

	Tests tests;
	tests.test_Datum();
	tests.test_Produkt();
	tests.test_Person();
	tests.test_Kunde();
	tests.test_Haendler();
	tests.test_Warenkorb();
	tests.test_Konto();
	tests.test_Kassenzettel();
	tests.test_Supermarkt();
	// tests.test_ReadData();
	// tests.test_Statistik();
	// tests.runAllTests();
	return 0;
}
