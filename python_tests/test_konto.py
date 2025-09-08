"""Python-file for testing class Konto"""

from py_bindings import Konto, Kunde


def test_konto():
    """Funktion zum Testen eines Kontos"""
    kunde1 = Kunde("Luciano", "male", 31, "luciano@cocoloco.com", "Berlin, Kreuzberg")
    konto1 = Konto(kunde1, "Commerzbank")
    konto2 = Konto(kunde1, "Deutsche Post")

    assert konto1.get_konto_id() != konto2.get_konto_id()
    assert konto2.get_konto_id() > konto1.get_konto_id()
    konto1.einzahlen(1000.00)
    assert konto1.get_kontostand() == 1000.00
    konto1.abheben(500.00)
    assert konto1.get_kontostand() == 500.00
    konto1.abheben(500.00)
    assert konto1.get_kontostand() == 0.00
    assert konto1.get_kontostand() == 0.00
    konto1.einzahlen(1250.00)
    assert konto1.get_kontostand() == 1250.00
    assert konto1.get_institut() == "Commerzbank"
    assert konto1.vergleiche_konto(konto2) is False
    assert konto1.get_kontoinhaber().vergleiche_kunde(kunde1) is True
    assert str(konto1) == f"Kontoinhaber: {konto1.get_kontoinhaber().get_name()}"

test_konto()
