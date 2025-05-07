
import sys
import os

sys.path.append(os.path.dirname(__file__))  # build/ ist im selben Verzeichnis

from py_statistik import ReadData
from py_statistik import Statistik

reader = ReadData("data/numbers.csv")
stat = Statistik()
stat.lade_daten(reader)


print("Wörter:", stat.wortanzahl())
print("Zeichen:", stat.zeichenanzahl())
print("Zeilen:", stat.zaehle_linen())
print("Mittelwert:", stat.mittelwert())
print("Median:", stat.median())
print("Varianz:", stat.varianz())
