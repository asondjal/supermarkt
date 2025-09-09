"""Python-File for testing class Haendler"""

from py_bindings import Haendler

def test_haendler() -> None:
    """Funktion zum Testen von Haendler"""
    haendler1 = Haendler("Rihanna", "female", 36, "rihanna@gmail.com", "Hollywood, USA")
    haendler2 = Haendler(
        "ASAP Rocky", "male", 35, "asap.rocky@gmail.com", "Hollywood, USA"
    )
    assert haendler1.get_haendler_id() != haendler2.get_haendler_id()
    assert haendler1.vergleiche_haendler(haendler2) is False
    assert str(haendler1) == f"Haendler: {haendler1.get_name()}"
 