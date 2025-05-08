"""Python-File zum Testen der py_bindings"""

# Testdatei für die py_bindings

import sys
import os

build_path = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'build'))
sys.path.insert(0, build_path)

import py_bindings as pys

reader = pys.ReadData("data/numbers.csv")
stat = pys.Statistik()
stat.lade_daten(reader)

print("Wörter:", stat.wortanzahl())
print("Zeichen:", stat.zeichenanzahl())
print("Zeilen:", stat.zaehle_linen())
print("Mittelwert:", stat.mittelwert())
print("Median:", stat.median())
print("Varianz:", round(stat.varianz(),2))

print("Build Path:", build_path)