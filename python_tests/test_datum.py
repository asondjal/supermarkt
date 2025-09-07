"""Python-file for testing class Datum"""

from py_bindings import Datum

def test_datum():
    """Funktion zum Testen von Datum"""
    datum1 = Datum(1, 1, 2025)
    datum2 = Datum(10, 12, 2022)

    assert datum1.get_tag() == 1
    assert datum1.get_monat() == 1
    assert datum1.get_jahr() == 2025
    assert datum1.datum_anzeige() == "01.01.2025"
    assert datum1.vergleiche_datum(datum2) is False
    assert str(datum2) == f"Datum: {datum2.datum_anzeige()}"

test_datum()