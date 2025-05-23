"""Python zum Testen von den Klassen aus py_bindings.pyi"""

from py_bindings import Person, Kunde, Haendler, Datum, Produkt, Konto, Warenkorb


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
    produkt1 = Produkt("Bananen", 1.992, 2.35, Datum(20, 5, 2025), "Lebensmittel")
    produkt2 = Produkt("Kirschen", 1.992, 2.35, Datum(20, 5, 2025), "Lebensmittel")
    warenkorb = Warenkorb(kunde1)
    shopping = Warenkorb(kunde1)

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
