"""Python-file for testing class Kassenzettel"""

from py_bindings import Datum, Kunde, Haendler, Produkt, Konto, Warenkorb, Kassenzettel

def test_kassenzettel():
    """Funktion zum Testen der Klasse Kassenzettel"""

    datum = Datum(12, 12, 2012)
    kunde1 = Kunde(
        "LeBron James", "male", 40, "lebron.james@gmail.com", "Los Angeles, USA"
    )
    kunde2 = Kunde("Luciano", "male", 31, "luciano@cocoloco.com", "Berlin, Kreuzberg")
    haendler = Haendler("Rihanna", "female", 36, "rihanna@gmail.com", "Hollywood, USA")

    produkt1 = Produkt("Bananen", 1.992, 2.35, Datum(20, 5, 2025), "Lebensmittel")
    produkt2 = Produkt("Kirschen", 2.646, 4.99, Datum(20, 5, 2025), "Lebensmittel")
    warenkorb = Warenkorb(kunde1)
    warenkorb.fuege_produkt_hinzu(produkt1)
    warenkorb.fuege_produkt_hinzu(produkt2)

    konto = Konto(kunde1, "American Express")
    konto.einzahlen(120.00)

    kassenzettel1 = Kassenzettel(datum, kunde1, haendler, warenkorb, konto)
    kassenzettel2 = Kassenzettel(datum, kunde2, haendler, warenkorb, konto)

    assert kassenzettel1.get_kassenzettel_id() == 0
    kassenzettel1.erzeuge_kassenzettel()
    assert (
        120.00 - warenkorb.get_warenkorb_gesamtpreis()
    ) - konto.get_kontostand() < 0.001
    assert kassenzettel1.erzeuge_kassenzettel() == "./data/kassenzettel/kunde_0.txt"
    assert kassenzettel1.vergleiche_kassenzettel(kassenzettel2) is False
