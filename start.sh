#!/bin/bash

# Dieses Skript fokussiert sich nur auf die Installation der C++-Build-Kette und den Kompiliervorgang.
# Die Einrichtung der Python-Umgebung (VENV) wurde vorübergehend entfernt, um Fehler zu isolieren.

echo "Starte reinen C++-Build-Prozess für das Projekt 'supermarkt'..."

# --- 1. System-Abhängigkeiten installieren ---
echo -e "\n--- Installiere Build-Werkzeuge (CMake, Ninja, Ccache, Compiler) ---"
# Wir installieren nur die für den C++-Build nötigen Tools (Python VENV wurde entfernt)
sudo apt update -y
sudo apt install build-essential gdb cmake ninja-build ccache git -y

# Projekt-Root definieren
PROJECT_DIR=$(pwd)

# --- 2. pybind11 klonen ---
echo -e "\n--- Klone pybind11 Bibliothek (Sicherstellung einer sauberen Kopie) ---"

PYBIND11_DIR="pybind11" 

if [ -d "$PYBIND11_DIR" ]; then
    echo "Entferne bestehendes pybind11 Verzeichnis..."
    rm -rf "$PYBIND11_DIR"
fi

echo "Klone pybind11 nach $PYBIND11_DIR..."
if ! git clone https://github.com/pybind/pybind11.git "$PYBIND11_DIR"; then
    echo "Fehler: Klonen von pybind11 Repository fehlgeschlagen. Abbruch."
    exit 1
fi

# --- 3. Projekt bauen (Fokus auf Build-Ordner und CMake) ---
echo -e "\n--- Starte CMake Konfiguration und Build (Ninja) ---"

BUILD_DIR="${PROJECT_DIR}/build"

echo "Bereinige vorheriges Build-Verzeichnis..."
rm -rf "$BUILD_DIR"

echo "Erstelle Build-Verzeichnis '$BUILD_DIR'..."
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

# Führt CMake aus, basierend auf dem System-Python-Interpreter (kein -DPYTHON_EXECUTABLE mehr nötig)
echo "Führe CMake Konfiguration aus..."
if cmake .. -G Ninja; then
    echo "Running Ninja build..."
    if ninja; then
        echo -e "\n--- Build erfolgreich! ---"
        echo "Das Modul 'supermarkt' wurde kompiliert."
    else
        echo -e "\n--- Build FEHLGESCHLAGEN ---"
        echo "Kompilierung fehlgeschlagen. Überprüfen Sie C++-Quelldateien."
    fi
else
    echo -e "\n--- CMake Konfiguration FEHLGESCHLAGEN ---"
    echo "Konfiguration fehlgeschlagen. Überprüfen Sie Ihre CMakeLists.txt Datei."
fi

cd "$PROJECT_DIR" # Zurück zum Projekt-Root

echo -e "\n--- Prozess abgeschlossen! ---"