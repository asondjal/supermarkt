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

echo "--- Starte Python Virtual Environment (VENV) Setup ---"

VENV_NAME=".venv"
PROJECT_DIR=$(pwd)
VENV_PATH="${PROJECT_DIR}/${VENV_NAME}"
VENV_PYTHON="${VENV_PATH}/bin/python"
VENV_PIP="${VENV_PATH}/bin/pip"

# Überprüfen, ob der Python-Interpreter verfügbar ist
if ! command -v python3 &> /dev/null; then
    echo "Fehler: Python 3 Interpreter nicht auf dem System gefunden. Installation von 'python3-full' oder 'python3-venv' fehlgeschlagen."
    exit 1
fi

# 1. Erstellen der virtuellen Umgebung
if [ ! -d "$VENV_PATH" ]; then
    echo "Versuche, die virtuelle Umgebung '$VENV_NAME' zu erstellen..."
    if python3 -m venv "$VENV_PATH"; then
        echo "Virtuelle Umgebung '$VENV_NAME' erfolgreich erstellt."
    else
        echo "Fataler Fehler: Erstellung der virtuellen Umgebung mittels 'python3 -m venv' fehlgeschlagen. Abbruch."
        exit 1
    fi
fi

# 2. Überprüfung, ob die ausführbare Datei existiert (muss erfolgreich sein)
if [ ! -f "$VENV_PYTHON" ]; then
    echo "Fataler Fehler: Python Executable ('$VENV_PYTHON') nach der VENV-Erstellung nicht gefunden. Abbruch."
    exit 1
fi

# 3. Installiert Python-Pakete unter Verwendung des expliziten venv-pip
echo "Installiere Build-Abhängigkeiten (setuptools, wheel, pybind11) in der VENV..."
if ! "$VENV_PIP" install --upgrade pip setuptools wheel pybind11; then
    echo "Fehler: Installation der Python-Abhängigkeiten via pip fehlgeschlagen. Abbruch."
    exit 1
fi

echo "--- Python VENV Setup abgeschlossen! ---"
echo "Um die Umgebung zu aktivieren und zu nutzen, führen Sie bitte aus:"
echo "source .venv/bin/activate"

echo "--- Starte Python Virtual Environment (VENV) Setup ---"

VENV_NAME=".venv"
PROJECT_DIR=$(pwd)
VENV_PATH="${PROJECT_DIR}/${VENV_NAME}"
VENV_PYTHON="${VENV_PATH}/bin/python"
VENV_PIP="${VENV_PATH}/bin/pip"

# Überprüfen, ob der Python-Interpreter verfügbar ist
if ! command -v python3 &> /dev/null; then
    echo "Fehler: Python 3 Interpreter nicht auf dem System gefunden. Installation von 'python3-full' erforderlich."
    exit 1
fi

# 1. Bereinigung und Erstellung der virtuellen Umgebung
#    Lösche das Verzeichnis, um frühere Fehler zu vermeiden.
if [ -d "$VENV_PATH" ]; then
    echo "Lösche das bestehende VENV-Verzeichnis '$VENV_NAME', um eine saubere Erstellung zu erzwingen..."
    rm -rf "$VENV_PATH"
fi

echo "Versuche, die virtuelle Umgebung '$VENV_NAME' zu erstellen..."
if python3 -m venv "$VENV_PATH"; then
    echo "Virtuelle Umgebung '$VENV_NAME' erfolgreich erstellt."
else
    echo "Fataler Fehler: Erstellung der virtuellen Umgebung mittels 'python3 -m venv' fehlgeschlagen. Abbruch."
    exit 1
fi

# 2. Überprüfung, ob die ausführbare Datei existiert (Muss jetzt funktionieren)
if [ ! -f "$VENV_PYTHON" ]; then
    echo "Fataler Fehler: Python Executable ('$VENV_PYTHON') nach der VENV-Erstellung NICHT gefunden."
    echo "DIAGNOSE: Dies deutet auf einen kritischen Fehler in der Systemkonfiguration oder den Dateisystemrechten hin."
    echo "EMPFEHLUNG: Versuchen Sie, Python-Abhängigkeiten neu zu installieren:"
    echo "sudo apt install --reinstall python3-full python3-venv"
    exit 1
fi

# 3. Installiert Python-Pakete unter Verwendung des expliziten venv-pip
echo "Installiere Build-Abhängigkeiten (setuptools, wheel, pybind11) in der VENV..."
if ! "$VENV_PIP" install --upgrade pip setuptools wheel pybind11; then
    echo "Fehler: Installation der Python-Abhängigkeiten via pip fehlgeschlagen. Abbruch."
    exit 1
fi

echo "--- Python VENV Setup abgeschlossen! ---"
echo "Um die Umgebung zu aktivieren und zu nutzen, führen Sie bitte aus:"
echo "source .venv/bin/activate"