#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../inc/utils/statistik.hpp"
#include "../inc/base/supermarkt.hpp"
#include "../inc/base/kassenzettel.hpp"  // Adjusted path to match the correct location

namespace py = pybind11;

PYBIND11_MODULE(py_bindings, py_module) {
    py::class_<ReadData>(py_module, "ReadData")
        .def(py::init<const std::string&>())
        .def("read_txt", &ReadData::ReadTxt)
        .def("read_csv", &ReadData::ReadCSV)
        .def("read_json", &ReadData::ReadJSON)
        .def("read_pdf", &ReadData::ReadPDF)
        .def("read_auto", &ReadData::ReadAuto);

    py::class_<Statistik>(py_module, "Statistik")
        .def(py::init<>())
        .def("lade_daten", &Statistik::LadeDaten)
        .def("entferne_daten", &Statistik::EntferneDaten)
        .def("zaehle_eintraege", &Statistik::ZaehleEintraege)
        .def("zeichenanzahl", &Statistik::ZaehleZeichen)
        .def("wortanzahl", &Statistik::ZaehleWorte)
        .def("zaehle_linen", &Statistik::ZaehleLinien)
        .def("zaehle_variable", &Statistik::ZaehleVariable)
        .def("mittelwert", &Statistik::Mittelwert)
        .def("median", &Statistik::Median)
        .def("varianz", &Statistik::Varianz)
        .def("erwartungswert", &Statistik::Erwartungswert)
        .def("standardabweichung", &Statistik::Standardabweichung);

    // Muss noch in py_bindings_.pyi implementiert werden!!

    py::class_<Kassenzettel>(py_module, "Kassenzettel")
        .def(pybind11::init<const Datum, const Kunde, const Haendler, const Warenkorb, const std::shared_ptr<Konto>>())
        .def("get_kassenzettel_ID", &Kassenzettel::GetKassenzettelID)
        .def("erzeuge_kassenzettel", &Kassenzettel::CreateKassenzettel)
        .def("vergleiche_kassenzettel", &Kassenzettel::operator==);
    
    py::class_<Warenkorb>(py_module, "Warenkorb")
        .def(py::init<Kunde>())
        .def("get_warenkorb_ID", &Warenkorb::GetWarenkorbID)
        .def("fuege_produkt_hinzu", &Warenkorb::AddProdukt)
        .def("entferne_produkt", &Warenkorb::RemoveProdukt)
        .def("get_kunde", &Warenkorb::GetKunde)
        .def("get_warenkorb_gesamtpreis", &Warenkorb::GetGesamtPreis)
        .def("erhalte_produkte", &Warenkorb::GetProdukte)
        .def("verleiche_warenkorb", &Warenkorb::operator==);
    
    py::class_<Supermarkt>(py_module, "Supermarkt")
        .def(py::init<std::string, std::string>())
        .def("fuerge_produkt_ein", &Supermarkt::AddProdukt)
        .def("entferne_produkt", &Supermarkt::RemoveProdukt)
        .def("fuege_kunden_ein", &Supermarkt::AddKunde)
        .def("entferne_kunden", &Supermarkt::RemoveKunde)
        .def("fuege_warenkorb_hinzu", &Supermarkt::AddWarenkorb)
        .def("entferne_warenkorb", &Supermarkt::RemoveWarenkorb)
        .def("fueg_haendler_hinzu", &Supermarkt::AddHaendler)
        .def("entferne_haendler", &Supermarkt::RemoveHaendler)
        .def("erzeuge_warenliste", &Supermarkt::CreateProduktDatabase)
        .def("erzeuge_kundenliste", &Supermarkt::CreateKundeDatabase)
        .def("erzeuge_haendlerliste", &Supermarkt::CreateHaendlerDatabase)
        .def("erzeuge_warenkorbliste", &Supermarkt::CreateWarenkorbDatabase)
        .def("get_umsatz", &Supermarkt::GetGesamtWert)
        .def("get_supermarkt_ID", &Supermarkt::GetSupermarktID)
        .def("vergleiche_supermarkt", &Supermarkt::operator==);

    py::class_<Konto>(py_module, "Konto")
        .def(py::init<const Kunde&, std::string>())
        .def("einzahlen", &Konto::Einzahlen)
        .def("abheben", &Konto::Auszahlen)
        .def("get_kontostand", &Konto::GetKontostand)
        .def("get_konto_ID", &Konto::GetKontoID)
        .def("get_institut", &Konto::GetBank)
        .def("vergleiche_konto", &Konto::operator==)
        .def("get_kontoinhaber", &Konto::GetUser);
    
    py::class_<Kunde>(py_module, "Kunde")
        .def(py::init<std::string, std::string, int, std::string, std::string>())
        .def("get_kunden_ID", &Kunde::GetKundeID)
        .def("display_kunde", &Kunde::Print)
        .def("vergleiche_konto", &Kunde::operator==);

    py::class_<Haendler>(py_module, "Haendler")
        .def(py::init<std::string, std::string, int, std::string, std::string>())
        .def("get_haendler_ID", &Haendler::GetHaendlerID)
        .def("display_haendler", &Haendler::Print)
        .def("vergleiche_haendler", &Haendler::operator==);

    py::class_<Person>(py_module, "Person")
        .def(py::init<std::string, std::string, int, std::string, std::string>())
        .def("get_name", &Person::GetName)
        .def("get_geschlecht", &Person::GetGender)
        .def("get_alter", &Person::GetAge)
        .def("get_email", &Person::GetEmail)
        .def("get_adress", &Person::GetAdresse)
        .def("display_person", &Person::Print)
        .def("vergleiche_person", &Person::operator==);
    
    py::class_<Datum>(py_module, "Datum")
        .def(py::init<uint32_t, uint32_t, uint32_t>())
        .def("get_tag", &Datum::GetTag)
        .def("get_monat", &Datum::GetMonat)
        .def("get_jahr", &Datum::GetJahr)
        .def("anzeige", &Datum::Print);
    
    py::class_<Produkt>(py_module, "Produkt")
        .def(py::init<std::string, float, float, Datum, std::string>())
        .def("get_bezeichnung", &Produkt::GetName)
        .def("get_menge", &Produkt::GetMenge)
        .def("get_gesamtpreis", &Produkt::GetGesamtPreis)
        .def("get_haltbarkeit", &Produkt::GetHaltbarkeit)
        .def("get_produkt_ID", &Produkt::GetID)
        .def("get_produkt_abteilung", &Produkt::GetAbteilung)
        .def("display_produkt", &Produkt::Display)
        .def("vergleiche_produkte", &Produkt::operator==);

}
