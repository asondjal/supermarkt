// #include <pybind11/pybind11.h>
// #include <pybind11/stl.h>
// #include "./inc/utils/statistik.hpp"  // Adjusted path to match the correct location

// namespace py = pybind11;

// PYBIND11_MODULE(statistik, m) {
//     py::class_<Statistik>(m, "Statistik")
//         .def(py::init<>())
//         .def("lade_daten", &Statistik::LadeDaten, "Setzt den Datenpuffer")
//         .def("entferne_daten", &Statistik::EntferneDaten, "Entfernt Daten aus dem Puffer")
//         .def("zaehle_eintraege", &Statistik::ZaehleEintraege, "Zählt die Einträge im Puffer")
//         .def("zeichenanzahl", &Statistik::ZaehleZeichen, "Zählt die Zeichen im Text")
//         .def("wortanzahl", &Statistik::ZaehleWorte, "Zählt die Wörter im Text")
//         .def("zaehle_linen", &Statistik::ZaehleLinien, "Zählt die Zeilen im Puffer")
//         .def("zaehle_variable", &Statistik::ZaehleVariable, "Zählt die Variablen im Puffer")
//         .def("mittelwert", &Statistik::Mittelwert, "Berechnet den Mittelwert der Zahlen im Text")
//         .def("median", &Statistik::Median, "Berechnet den Median der Zahlen im Text")
//         .def("varianz", &Statistik::Varianz, "Berechnet die Varianz der Zahlen im Text")
//         .def("erwartungswert", &Statistik::Erwartungswert, "Berechnet den Erwartungswert der Zahlen im Text");
// }
