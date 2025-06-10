"""Python-File for testing class Kunde"""

from py_bindings import Kunde

def test_kunde():
    """Funktion zum Testen von der Klasse Kunde"""
    kunde1 = Kunde("Luciano", "male", 31, "luciano@cocoloco.com", "Berlin, Kreuzberg")
    kunde2 = Kunde(
        "Captial Bra", "male", 36, "capital.bra@egj.com", "Berlin, Neu-Kölln"
    )

    assert kunde1.get_kunden_id() == 0
    assert kunde2.get_kunden_id() == 1
    assert kunde2.vergleiche_kunde(kunde1) is False
    