"""Python zum Testen von den Klassen aus py_bindings.pyi"""

from py_bindings import (
    Person,
    Kunde,
    Haendler,
    Datum,
    Produkt,
    Konto,
    Warenkorb,
    Kassenzettel,
    Supermarkt,
    Logging,
    LogLevel,
)


def test_person():
    """Funktion zum Testen von der Klasse Person"""
    person1 = Person(
        "LeBron James", "male", 40, "lebron.james@gmail.com", "Los Angeles, USA"
    )
    person2 = Person(
        "Magic Johnson", "male", 64, "magic.johnson@yahoo.hotmail", "Los Angeles, USA"
    )

    assert person1.get_name() == "LeBron James"
    assert person1.get_geschlecht() == "male"
    assert person1.get_alter() == 40
    assert person1.get_email() == "lebron.james@gmail.com"
    assert person1.get_adresse() == "Los Angeles, USA"
    assert person1.vergleiche_person(person2) is False
    assert person1.get_person_id() == 0
    assert person2.get_person_id() == 1


def test_kunde():
    """Funktion zum Testen von der Klasse Kunde"""
    kunde1 = Kunde("Luciano", "male", 31, "luciano@cocoloco.com", "Berlin, Kreuzberg")
    kunde2 = Kunde(
        "Captial Bra", "male", 36, "capital.bra@egj.com", "Berlin, Neu-Kölln"
    )

    assert kunde1.get_kunden_id() == 0
    assert kunde2.get_kunden_id() == 1
    assert kunde2.vergleiche_kunde(kunde1) is False


def test_haendler():
    """Funktion zum Testen von Haendler"""
    haendler1 = Haendler("Rihanna", "female", 36, "rihanna@gmail.com", "Hollywood, USA")
    haendler2 = Haendler(
        "ASAP Rocky", "male", 35, "asap.rocky@gmail.com", "Hollywood, USA"
    )

    assert haendler1.get_haendler_id() == 0
    assert haendler2.get_haendler_id() == 1
    assert haendler1.vergleiche_haendler(haendler2) is False


def test_datum():
    """Funktion zum Testen von Datum"""
    datum1 = Datum(1, 1, 2025)
    datum2 = Datum(10, 12, 2022)

    assert datum1.get_tag() == 1
    assert datum1.get_monat() == 1
    assert datum1.get_jahr() == 2025
    assert datum1.datum_anzeige() == "01.01.2025"
    assert datum1.vergleiche_datum(datum2) is False


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
    assert produkt1.get_produkt_id() == 0
    assert produkt1.vergleiche_produkte(produkt2) is False


def test_konto():
    """Funktion zum Testen eines Kontos"""
    kunde1 = Kunde("Luciano", "male", 31, "luciano@cocoloco.com", "Berlin, Kreuzberg")
    konto1 = Konto(kunde1, "Commerzbank")
    konto2 = Konto(kunde1, "Deutsche Post")

    assert konto1.get_konto_id() == 0
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
    assert konto2.get_konto_id() == 1
    assert konto1.get_kontoinhaber().vergleiche_kunde(kunde1) is True


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


def test_logging():
    """Funktion zum Testen von LogLevel"""

    logger = Logging("loggingfile.txt", LogLevel.DEBUG, True)
    assert logger.get_level() == "DEBUG"
    logger.set_loglevel(LogLevel.ERROR)
    assert logger.get_level() == "ERROR"
    logger.set_loglevel(LogLevel.DEBUG)
    logger.enable_console_output(True)
    logger.start_log("System initialized.", LogLevel.INFO)
    logger.start_log("System deactivated.", LogLevel.INFO)
    logger.start_log("System restarted.", LogLevel.INFO)
    logger.start_log("ChatPGT free is expired!", LogLevel.WARNING)
    logger.start_log("FBI has hacked your PC!", LogLevel.WARNING)
    logger.start_log("WIFI-Connection was interrupted!", LogLevel.ERROR)
    logger.start_log("WIFI-Connection was interrupted by HTTP-Port 241", LogLevel.DEBUG)
