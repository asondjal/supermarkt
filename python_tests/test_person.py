"""Python-File for testing class Person"""

from py_bindings import Person

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
    # assert person1.get_person_id() == 0 Only work locally
    # assert person2.get_person_id() == 1
