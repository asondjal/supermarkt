# **Projekt Supermarkt**

## **Ziele**

- **Implementierung eines Supermarktes:** Systemverstaendnis foerden
- **Integration von Komponenten aus unterschiedlichen Programmiersprachen:** Sich Gedanken darüber zu machen,
ob es nicht sinnvoll waere,das Projekt in Komponenten aufzuteilen und falls noetig auch die Komponenten
in anderen Sprachen implementieren, wodurch das Projekt skalierbar wird
- **Umgang von Zugriffsrechten auf Dateisysteme und Ressourcen:** Sehr wichtig, denn bei der Verarbeitung
und Verwaltung von Dokumenten muss sichergestellt werden, dass Race Conditions und Deadlocks vermieden

## **Erstes Design**

- Verwaltung von Kunden, Haendlern, Produkten, Kontos, Warenkörben, Supermaerkte
- Export von Kassenzetteln, Inventur- und Kunden-, Haendler-, sowie Warenkorbdateien
- Trennung von Datenzugriff (`ReadData`) und Auswertung (`Statistik`)
- Multithreading-fähiger Dateizugriff mittels Mutexen

## **Hauptfunktionen**

### **CMakeLists.txt**

- Zentrales Dokument zur Steuerung vom Compile-Vorgang
- **src:** Ablageort für die Source-Dateien
- **inc:** Ablageort für die Header-Dateien, Unterteilung in base und utils
- **Verwendeter Standard:** CXX 17
- **ccache:** Zwischenspeichern der Build-Objekte im Cache zur Beschleunigung vom Build-Vorgang
- **Optimierung O2:** Beschleunigung vom Build-Vorgang und Debugging sind möglich
- **Debugging:** Aktivierung vom Debuggung, um die Fehlersuche zu vereinfachen

### **.vscode**

- **tasks.json:** JSON-Datei fuers Steuern vom Kompilier-Vorgang inkl. Shortcuts fuer die Tastatur,
vor allem CTRL+SHIFT+B zum Kompilieren
- **settings.json:** JSON-Datei zur Konfiguration für C++ und meinem Modul py_bindings

### **build**

- Speicherort fuer die Executables, Binärdateien und Befehle fürs Komplieren

### **inc**

- Ablageort für die Header-Dateien
- **base:** Unterordner für die einfachen Klassen
- **utils:** Unterordner für die Template-Klassen, die in anderen Projekten nutzbar sind

### **src**

- Speicherort für die Source-Dateien
- **tests.cpp:** Test-File fuer alle Executables

## Ordner data

- Aufbewahrungsort fuer die generierten Kassenzettel, Warenbestaende, Kundenliste, Haendlerlisten
- Referenzpunkt fuer die Datenverarbeitung

## **Integration von C++ in Python**

### **Erweiterungen in der CMakeLists.txt:**

- **Pybind11 einbinden**

    add_subdirectory(pybind11)
    find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

- **pybind11_bindings mit Python-Bibliotheken linken**

    target_link_libraries(supermarkt PRIVATE Python3::Python)
    include_directories(${Python3_INCLUDE_DIRS})
    include_directories(${PROJECT_SOURCE_DIR}/include)
    include_directories(${CMAKE_SOURCE_DIR}/pybind11/include)

### **bindings**

- Ablageort fuer die Executables aus C++, um mit pybind11 zu interagieren
- Deklaration der Funktionen aus C++ fuer Python, **Achtung:** Funktionen müssen
*Snake-Case* sein, damit Sie in Python nahtlos funktionieren

### **py_bindings.pyi**

- **Zweck:** Minimierung der Fehlermeldungen, die durch Pylint erkennt werden
- **Umsetzung:** Reine Deklaration der Funktionen aus der Datei ./bindings/py_bindings.cpp,
damit der Compiler erkennt, dass diese Funktionen bereits in C++ definiert wurden.

### **pybind11**

- **Installation:** Klonen vom Git-Repository [Pybind11](https://github.com/pybind/pybind11.git)
- **Warum:** Noetig, um eine Schnittstelle zwischen C++ und Python zu ermoeglichen

- **Modul für Python (Statistik-Pybind11)**

    pybind11_add_module(py_bindings
        Verwenden der gleichen Executables aus src, aber ohne main.cpp
    )

- **Linken von py_bindings mit poppler-cpp fuer Konventierung von PDFs in String**

    target_link_libraries(py_bindings PRIVATE poppler-cpp)

### **Erweiterungen fuer settings.json:**

    "C_Cpp.errorSquiggles": "disabled",
    "C_Cpp.default.compilerPath": "/usr/bin/gcc",

    "python.analysis.extraPaths": ["./build"],
    "python.analysis.diagnosticSeverityOverrides": {
        "reportMissingImports": "none",
        "reportMissingModuleSource": "none"
    },
    "python.analysis.typeCheckingMode": "off",
    "python.envFile": "${workspaceFolder}/.env",
    "python.analysis.ignore": ["./GUI/gui.py", "./tests/test_supermarkt.py"] # Noetig, da pylint Schwierigkeiten mit stat. Variablen hat

### **Behebung der Pylint-Fehlermeldungen:**

- **Inhalt von .pylintrc:**

    [MASTER]
    init-hook='import sys; sys.path.append("build")'

    [TYPECHECK]
    extension-pkg-whitelist=py_bindings
    ignored-modules=py_bindings

- **Inhalt von.env:** PYTHONPATH=absolute_path_to_executable

## **Ausführung vom Executable**

- Eingabe vom Befehl **export PYTHONPATH=absolute_path_to_executable** im Terminal
- **Hinweis:** Der absolute Pfad lässt sich mittels find -name build ermitteln

## **Integration in GitHub**

- **ci.yml im Ordner .github:** Konfiguration von CI/CD
- **.gitignore:** Ordner und Dateien, die ignoriert werden koennen
- **gitmodules:** Mitteilung gegenüber dem System, dass pybind11 als Submodul zu verwenden ist
