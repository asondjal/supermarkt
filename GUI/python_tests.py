"""Python zum Testen von den Klassen aus py_bindings.pyi"""

from py_bindings import Person, Kunde, Haendler

def test_person():
    """Funktion zum Testen von der Klasse Person"""
    person1 = Person("LeBron James", "male", 40, "lebron.james@gmail.com", "Los Angeles, USA")
    person2 = Person("Magic Johnson", "male", 64, "magic.johnson@yahoo.hotmail", "Los Angeles, USA")

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
    kunde2 = Kunde("Captial Bra", "male", 36, "capital.bra@egj.com", "Berlin, Neu-Kölln")

    assert kunde1.get_kunden_id() == 0
    assert kunde2.get_kunden_id() == 1
    assert kunde2.vergleiche_kunde(kunde1) is False

def test_haendler():
    """Funktion zum Testen von Haendler"""
    haendler1 = Haendler("Rihanna", "female", 36, "rihanna@gmail.com", "Hollywood, USA")
    haendler2 = Haendler("ASAP Rocky", "male", 35, "asap.rocky@gmail.com", "Hollywood, USA")

    assert haendler1.get_haendler_id() == 0
    assert haendler2.get_haendler_id() == 1
    assert haendler1.vergleiche_haendler(haendler2) is False