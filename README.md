# **Projekt Supermarkt**

## **Ziele**

- **Implementierung eines Supermarktes:** Systemverstaendnis foerden
- **Integration von Komponenten aus unterschiedlichen Programmiersprachen:** Modulare und mehrsprachige Architektur:
Durch die Aufteilung in klar getrennte Module und die gezielte Nutzung von C++ (Backend) sowie Python (Frontend) wird Skalierbarkeit ermöglicht
- **Umgang von Zugriffsrechten auf Dateisysteme und Ressourcen:** Sicherstellung des synchronisierten Zugriffs
(z. B. per std::mutex), um Race Conditions und Deadlocks bei gleichzeitiger Dateiverarbeitung zu verhindern.
- **Schnelle Testbarkeit trotz hoher Komplexität:** Trotz hohem Overhead durch C++ sollen die Tests in Python weniger Millisekunden brauchen
- **Erfassung der Coverage:** Mittels Befehlen im Terminal wird die Coverage in C++ und Python ermittelt

## **Lizenz**

- Dieses Projekt verwendet die MIT-Lizenz

## **Ausführung**

- **Projekt-Setup:** ./start.sh
- **C++-Modul in Python integrieren:** pip install .

## **Design**

- **Basisklassen:** Datum, Kunde, Haendler, Produkt, Konto, Warenkorb, Supermarkt, Kassenzettel
- **Datensätze:** Export von Kassenzetteln, Inventur- und Kunden-, Haendler-, sowie Warenkorbdateien
- **Fokus:** Trennung von Datenzugriff (`ReadData`) und Auswertung (`Statistik`) sowie Monitoring (`Logging`)
- **Vermeidung von Race Conditions:** Multithreading-fähiger Dateizugriff mittels Mutexen

## **Hauptfunktionen**

### **CMakeLists.txt**

- Zentrales Dokument zur Steuerung vom Compile-Vorgang
- **src:** Ablageort für die Source-Dateien
- **inc:** Ablageort für die Header-Dateien, Unterteilung in base und utils
- **Verwendeter Standard:** CXX 17
- **ccache:** Zwischenspeichern der Build-Objekte im Cache zur Beschleunigung vom Build-Vorgang
- **Optimierung O2:** Beschleunigung vom Build-Vorgang und Debugging sind möglich
- **Debugging:** Aktivierung vom Debuggung, um die Fehlersuche zu vereinfachen

## **Ordner data**

- Aufbewahrungsort fuer die generierten Kassenzettel, Warenbestaende, Kundenliste, Haendlerlisten
- Referenzpunkt fuer die Datenverarbeitung

## **Integration von C++ in Python**

### **bindings**

- Ablageort fuer die Executables aus C++, um mit pybind11 zu interagieren
- Deklaration der Funktionen aus C++ fuer Python, **Achtung:** Funktionen müssen
*Snake-Case* sein, damit Sie in Python nahtlos funktionieren

### **pybind11**

- **Integration** API zwischen C++ und Python


## **Ergebnisse**

- **CI/CD-Tests:** Tests laufen stabil, inklusive C++- und Python-Komponenten auf GitHub Actions.
- **Pybind11:** konsistente Schnittstelle zwischen C++ und Python.
- **Python-Tests über C++-Module:** Worst Case benötigt unter 200 ms, im Best-Case ca. 140 ms
- **Formatierung für C++:** clang-format, cpplint
- **C++-Style von Google:** Skalierbar und wartbar dank durchdachter Architektur
