"""Python-File for testing class Haendler"""

from py_bindings import Haendler

def test_haendler():
    """Funktion zum Testen von Haendler"""
    haendler1 = Haendler("Rihanna", "female", 36, "rihanna@gmail.com", "Hollywood, USA")
    haendler2 = Haendler(
        "ASAP Rocky", "male", 35, "asap.rocky@gmail.com", "Hollywood, USA"
    )

    # assert haendler1.get_haendler_id() == 0 Only work locally
    # assert haendler2.get_haendler_id() == 1
    assert haendler1.vergleiche_haendler(haendler2) is False
