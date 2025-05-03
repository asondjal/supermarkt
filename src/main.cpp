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

int main() {

	Tests tests;
	tests.runAllTests();
	return 0;
}
