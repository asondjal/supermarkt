# Projekt Supermarkt

## Ziele

- Implementierung eines Supermarktes
- Integration einer GUI zur nutzerfreundlichen Bedienung
- Datenerfassung und -speicherung in seperaten Dateien bzw. Ordnern

## Hauptfunktionen

- Verwaltung von Kunden, Händlern, Produkten und Warenkörben
- Export von Kassenzetteln, Inventur- und Kundendateien
- Trennung von Datenzugriff (`ReadData`) und Auswertung (`Statistik`)
- Multithreading-fähiger Dateizugriff

## CMakeLists.txt

- Zentrales Dokument zur Steuerung vom Compile-Vorgang
- **src:** Ablageort für die Source-Dateien
- **inc:** Ablageort für die Header-Dateien, Unterteilung in base und utils
- **Verwendeter Standard:** CXX 17
- **ccache:** Zwischenspeichern der Build-Objekte im Cache zur Beschleunigung vom Build-Vorgang
- **Optimierung O2:** Beschleunigung vom Build-Vorgang und Debugging sind möglich

## .vscode

- **tasks.json:** JSON-Datei fürs Steuern vom Kompilier-Vorgang inkl. Shortcuts für die Tastatur
- **settings.json:** JSON-Datei zur Konfiguration für C++

## build

- Speicherort fuer die Executables, Binärdateien und Befehle fürs Komplieren

## inc

- Ablageort für die Header-Dateien
- **base:** Unterordner für die einfachen Klassen
- **utils:** Unterordner für die Template-Klassen

## src

- Speicherort für die Source-Dateien

## Noch zu implementierende Dateien

- Statistik: Header sowie Source // Kleinere Funktionen fehlen, aber erst bei der Gestaltung der GUI von Relevanz
- Logging: Header sowie Source
- GUI: Header sowie Source
