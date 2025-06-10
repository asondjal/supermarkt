"""Python-File for testing class Produkt"""

from py_bindings import Produkt, Datum

def test_produkt():
    """Funktion zum Testen eines Produktes"""
    datum = Datum(20, 5, 2025)
    produkt1 = Produkt("Bananen", 1.992, 2.35, datum, "Lebensmittel")
    produkt2 = Produkt("Kirschen", 1.992, 2.35, datum, "Lebensmittel")

    assert produkt1.get_bezeichnung() == "Bananen"
    assert abs(1.992 - produkt1.get_menge()) < 0.0001
    assert abs(2.35 - produkt1.get_preis()) < 0.0001
    assert abs((1.992 * 2.35) - produkt1.get_gesamtpreis()) < 0.0001
    assert produkt1.get_haltbarkeit().vergleiche_datum(datum) is True
    assert produkt1.get_produkt_abteilung() == "Lebensmittel"
    # assert produkt1.get_produkt_id() == 0 Only work locally
    assert produkt1.vergleiche_produkte(produkt2) is False
