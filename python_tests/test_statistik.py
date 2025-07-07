"""Python-file for testing class Statistik"""

from py_bindings import ReadData, Statistik

def test_statistik():
    """Funktion zum Testen von Statistik"""
    text = ReadData("./data/supermarkt_0/produkte.txt")
    kunden_data = ReadData("./data/supermarkt_0/kunden.txt")

    statistik = Statistik()
    statistik.lade_daten(text)
    statistik.entferne_daten(text.read_txt())
    statistik.lade_daten(text)
    assert statistik.zaehle_linen() == 11
    assert statistik.wortanzahl() == 14
    assert statistik.zaehle_variable("Produkt") == 1
    assert statistik.zaehle_eintraege() == 1
    assert statistik.zeichenanzahl() == 596
    statistik.lade_daten(kunden_data)
    assert statistik.zaehle_linen() == 22
    assert statistik.wortanzahl() == 33
    assert statistik.zaehle_variable("Kunde") == 1
    assert statistik.zaehle_eintraege() == 2
    assert 7.508571147 - statistik.mittelwert() < 0.0001
    assert statistik.zeichenanzahl() == 1202
    assert 601.00001321 - statistik.median() < 0.0001
    assert 7.836666584014893- statistik.erwartungswert() < 0.0001
    assert 8.048698425292969 - statistik.standardabweichung() < 0.0001

test_statistik()
