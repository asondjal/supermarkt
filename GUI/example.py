"""This is an example of how to use the py_bindings module in Python."""

import sys
import os

import py_bindings as pys

build_path = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'build'))
sys.path.insert(0, build_path)

reader = pys.ReadData("./data/numbers.csv")
stat = pys.Statistik()
stat.lade_daten(reader)

print("Wörter:", stat.wortanzahl())
print("Zeichen:", stat.zeichenanzahl())
print("Zeilen:", stat.zaehle_linen())
print("Mittelwert:", stat.mittelwert())
print("Median:", stat.median())
print("Varianz:", round(stat.varianz(),2))
print("Standardabweichung:", round(stat.standardabweichung(),2))

print("Import erfolgreich!")
