"""Python-file for testing class Warenkorb"""

from py_bindings import Kunde, Datum, Produkt, Warenkorb

def test_warenkorb():
    """Funktion zum Testen vom Warenkrob"""
    kunde1 = Kunde(
        "Captial Bra", "male", 36, "capital.bra@egj.com", "Berlin, Neu-Kölln"
    )

    kunde2 = Kunde("Luciano", "male", 31, "luciano@cocoloco.com", "Berlin, Kreuzberg")

    produkt1 = Produkt("Bananen", 1.992, 2.35, Datum(20, 5, 2025), "Lebensmittel")
    produkt2 = Produkt("Kirschen", 1.992, 2.35, Datum(20, 5, 2025), "Lebensmittel")
    warenkorb = Warenkorb(kunde1)
    shopping = Warenkorb(kunde1)

    assert warenkorb.get_warenkorb_id() == 0
    warenkorb.fuege_produkt_hinzu(produkt1)
    produkte = warenkorb.erhalte_produkte()

    assert repr(produkte[0]) == "Produkt: Bananen"
    assert len(produkte) == 1
    assert produkt1.get_gesamtpreis() - warenkorb.get_warenkorb_gesamtpreis() < 0.0001

    warenkorb.entferne_produkt(produkt1)
    produkte = warenkorb.erhalte_produkte()
    assert repr(produkte) == "[]"
    assert len(produkte) == 0
    assert warenkorb.get_warenkorb_gesamtpreis() == 0.0000

    warenkorb.entferne_produkt(produkt1)
    print(warenkorb.erhalte_produkte())
    produkte = warenkorb.erhalte_produkte()
    assert repr(produkte) == "[]"
    assert len(produkte) == 0
    assert warenkorb.get_warenkorb_gesamtpreis() == 0.0000

    warenkorb.fuege_produkt_hinzu(produkt1)
    produkte = warenkorb.erhalte_produkte()
    assert repr(produkte[0]) == "Produkt: Bananen"
    assert len(produkte) == 1
    assert produkt1.get_gesamtpreis() - warenkorb.get_warenkorb_gesamtpreis() < 0.0001

    warenkorb.fuege_produkt_hinzu(produkt2)
    print(warenkorb.erhalte_produkte())
    produkte = warenkorb.erhalte_produkte()
    assert repr(produkte[0]) == "Produkt: Bananen"
    assert repr(produkte[1]) == "Produkt: Kirschen"
    assert len(produkte) == 2
    assert (
        produkt1.get_gesamtpreis() + produkt2.get_gesamtpreis()
    ) - warenkorb.get_warenkorb_gesamtpreis() < 0.0001

    assert warenkorb.vergleiche_warenkorb(shopping) is False
    assert warenkorb.get_kunde().vergleiche_kunde(kunde2) is False
    print(warenkorb)

test_warenkorb()