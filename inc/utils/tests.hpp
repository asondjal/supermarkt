#ifndef TESTS_HPP_
#define TESTS_HPP_

#include <iostream>
#include <cassert>
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

class Tests {
    public:
    Tests();
    void test_Datum(); // Funktioniert einwandfrei
    void test_Produkt(); // Funktioniert einwandfrei
    void test_Person(); // Funktioniert einwandfrei
    void test_Kunde(); // Funktioniert einwandfrei
    void test_Haendler(); // Funktioniert einwandfrei
    void test_Warenkorb(); // Funktioniert einwandfrei
    void test_Konto(); // Funktioniert einwandfrei
    void test_Kassenzettel();
    void test_Supermarkt();
    void test_ReadData();
    void test_Statistik();
    void runAllTests();
};

#endif /* TESTS_HPP_ */