"""Python zum Testen von den Klassen aus py_bindings.pyi"""

from py_bindings import (
    Kunde,
    Haendler,
    Datum,
    Produkt,
    Warenkorb,
    Supermarkt
)

def test_supermarkt():
    """Funktion zum Testen von Supermarkt"""

    supermarkt = Supermarkt("REAL", "In the Hood 1, New York")
    discounter = Supermarkt("NORMA", "In der Nachbarschaft 1, Hamburg")
    assert supermarkt.get_supermarkt_id() == 0
    assert supermarkt.vergleiche_supermarkt(discounter) is False

    kunde1 = Kunde(
        "LeBron James", "male", 40, "lebron.james@gmail.com", "Los Angeles, USA"
    )
    kunde2 = Kunde("Luciano", "male", 31, "luciano@cocoloco.com", "Berlin, Kreuzberg")
    haendler1 = Haendler("Rihanna", "female", 36, "rihanna@gmail.com", "Hollywood, USA")
    haendler2 = Haendler(
        "ASAP Rocky", "male", 35, "asap.rocky@gmail.com", "Hollywood, USA"
    )

    produkt1 = Produkt("Bananen", 1.992, 2.35, Datum(20, 5, 2025), "Lebensmittel")
    produkt2 = Produkt("Kirschen", 2.355, 4.99, Datum(20, 5, 2025), "Lebensmittel")
    warenkorb = Warenkorb(kunde1)
    warenkorb.fuege_produkt_hinzu(produkt1)
    warenkorb.fuege_produkt_hinzu(produkt2)

    supermarkt.fuege_produkt_ein(produkt1)
    supermarkt.erzeuge_produktliste()
    assert supermarkt.erzeuge_produktliste() == "./data/supermarkt_0/produkte.txt"
    supermarkt.fuege_produkt_ein(produkt1)
    supermarkt.erzeuge_produktliste()
    supermarkt.entferne_produkt(produkt1)
    supermarkt.erzeuge_produktliste()
    supermarkt.entferne_produkt(produkt1)
    supermarkt.erzeuge_produktliste()
    supermarkt.fuege_produkt_ein(produkt1)
    supermarkt.erzeuge_produktliste()
    supermarkt.fuege_produkt_ein(produkt2)
    supermarkt.erzeuge_produktliste()

    supermarkt.fuege_kunden_ein(kunde1)
    supermarkt.erzeuge_kundenliste()
    assert supermarkt.erzeuge_kundenliste() == "./data/supermarkt_0/kunden.txt"
    supermarkt.fuege_kunden_ein(kunde1)
    supermarkt.erzeuge_kundenliste()
    supermarkt.entferne_kunden(kunde1)
    supermarkt.erzeuge_kundenliste()
    supermarkt.fuege_kunden_ein(kunde1)
    supermarkt.erzeuge_kundenliste()
    supermarkt.fuege_kunden_ein(kunde2)
    supermarkt.erzeuge_kundenliste()

    supermarkt.fueg_haendler_hinzu(haendler1)
    supermarkt.erzeuge_haendlerliste()
    assert supermarkt.erzeuge_haendlerliste() == "./data/supermarkt_0/haendler.txt"
    supermarkt.fueg_haendler_hinzu(haendler1)
    supermarkt.erzeuge_haendlerliste()
    supermarkt.entferne_haendler(haendler1)
    supermarkt.erzeuge_haendlerliste()
    supermarkt.fueg_haendler_hinzu(haendler1)
    supermarkt.erzeuge_haendlerliste()
    supermarkt.fueg_haendler_hinzu(haendler2)
    supermarkt.erzeuge_haendlerliste()

    supermarkt.fuege_warenkorb_hinzu(warenkorb)
    supermarkt.erzeuge_warenkorbliste()
    assert supermarkt.erzeuge_warenkorbliste() == "./data/supermarkt_0/warenkoerbe.txt"
    supermarkt.fuege_warenkorb_hinzu(warenkorb)
    supermarkt.erzeuge_warenkorbliste()
    supermarkt.entferne_warenkorb(warenkorb)
    supermarkt.erzeuge_warenkorbliste()
    supermarkt.fuege_warenkorb_hinzu(warenkorb)
    supermarkt.erzeuge_warenkorbliste()

    assert 16.43 - supermarkt.get_umsatz() < 0.0001
