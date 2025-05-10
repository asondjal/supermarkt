#ifndef TESTS_HPP_
#define TESTS_HPP_

#include <iostream>
#include <cassert>
#include "read_data.hpp"
#include "statistik.hpp"
#include "logging.hpp"

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
    void test_Kassenzettel(); // Funktioniert einwandfrei
    void test_Supermarkt(); // Funktioniert einwandfrei
    void test_ReadData(); // Funktioniert einwandfrei
    void test_Statistik(); // Funktioniert einwandfrei
    void test_Logging(); // Funktioniert einwandfrei
    void runAllTests();
};

#endif /* TESTS_HPP_ */