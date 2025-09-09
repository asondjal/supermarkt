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
    assert statistik.wortanzahl() in (14, 17)
    assert statistik.zaehle_variable("Produkt") == 1
    assert statistik.zaehle_eintraege() == 1
    assert statistik.zeichenanzahl() in (596, 598)
    statistik.lade_daten(kunden_data)
    assert statistik.zaehle_linen() == 22
    assert statistik.wortanzahl() in (33, 38, 41, 40)
    assert statistik.zaehle_variable("Kunde") == 1
    assert statistik.zaehle_eintraege() == 2
    assert 7.508571147 - statistik.mittelwert() < 0.0001
    assert statistik.zeichenanzahl() in (1206, 1207, 1208, 1209)
    assert 601.00001321 - statistik.median() < 0.0001
    assert 7.5085711479187012 - statistik.erwartungswert() < 0.0001
    assert 12.2170724868774412 - statistik.standardabweichung() < 0.0001

test_statistik()
