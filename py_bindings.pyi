"""C++-Schnittstelle in Python fuer die Datenverarbeitung und die Statistik."""

from enum import Enum

class ReadData:
    """Klasse zum Auslesen von Dateien aus unterschiedlichen Formaten."""

    readdata_counter = 0

    def __init__(self, path: str) -> None:
        ReadData.readdata_counter += 1
        self.path = path

    def read_txt(self) -> str:
        """Lese Daten aus einer Text-Datei"""

    def read_csv(self) -> str:
        """Lese Daten aus einer CSV-Datei."""

    def read_json(self) -> str:
        """Lese Daten aus einer JSON-Datei"""

    def read_pdf(self) -> str:
        """Lese Daten aus einer PDF-Datei"""

    def read_auto(self) -> str:
        """Lese Daten aus einer Datei, die automatisch erkannt wird."""

class Statistik:
    """Klasse zur Berechnung von Statistiken."""

    statistik_counter = 0

    def __init__(self) -> None:
        Statistik.statistik_counter += 1

    def lade_daten(self, reader: ReadData) -> None:
        """Lade Daten in die Statistik-Klasse."""

    def entferne_daten(self, data: str) -> None:
        """Entferne Daten aus der Statistik-Klasse."""

    def zaehle_eintraege(self) -> int:
        """Count the number of entries in the dataset."""

    def zeichenanzahl(self) -> int:
        """Zähle die Anzahl der Zeichen in den Daten."""

    def wortanzahl(self) -> int:
        """Zähle die Anzahl der Wörter in den Daten."""

    def zaehle_linen(self) -> int:
        """Zähle die Anzahl der Zeilen in den Daten."""

    def zaehle_variable(self, variable: str) -> int:
        """Zähle die Anzahl der Variable in den Daten."""

    def mittelwert(self) -> float:
        """Berechne den Mittelwert der Daten."""

    def median(self) -> float:
        """Berechne den Median der Daten."""

    def standardabweichung(self) -> float:
        """Berechne die Standardabweichung der Daten."""

    def erwartungswert(self) -> float:
        """Berechne den Erwartungswert der Daten."""

class Person:
    """Basis-Klasse Person zur Erzeugung einer Person"""

    person_counter = 0

    def __init__(
        self, name: str, geschlecht: str, alter: int, email: str, adresse: str
    ) -> None:
        Person.person_counter += 1
        self.name = name
        self.geschlecht = geschlecht
        self.alter = alter
        self.email = email
        self.adresse = adresse

    def __repr__(self) -> str:
        return f"Person: {self.name}"

    def get_name(self) -> str:
        """Wiedergabe vom Namen einer Person"""

    def get_geschlecht(self) -> str:
        """Wiedergabe vom Geschlecht einer Person"""

    def get_alter(self) -> int:
        """Wiedergabe vom Alter einer Person"""

    def get_email(self) -> str:
        """Wiedergabe der E-Mail einer Person"""

    def get_adresse(self) -> str:
        """Wiedergabe der E-Mail eienr Person"""

    def display_person(self) -> str:
        """Wiedergabe der Informationen einer Person"""

    def vergleiche_person(self, person: "Person") -> bool:
        """Vergleiche zwei Personen"""

    def get_person_id(self) -> int:
        """Wiedergabe der ID einer Person"""

class Kunde(Person):
    "Abgeleitete Klasse Kunde"

    kunden_counter = 0

    def __init__(self, name, geschlecht, alter, email, adresse) -> None:
        super().__init__(name, geschlecht, alter, email, adresse)
        Kunde.kunden_counter += 1

    def get_kunden_id(self) -> int:
        """Wiedergabe der ID eines Kunden"""

    def display_kunde(self) -> None:
        """Wiedergabe der Informationen eines Kundens"""

    def vergleiche_kunde(self) -> bool:
        """Vergleiche zwei Kunden"""

class Haendler(Person):
    "Abgeleitete Klasse Haendler"

    haendler_counter = 0

    def __init__(self, name, geschlecht, alter, email, adresse) -> None:
        super().__init__(name, geschlecht, alter, email, adresse)
        Haendler.haendler_counter += 1

    def get_haendler_id(self) -> int:
        """Wiedergabe der ID eines Haendler"""

    def haendler_kunde(self) -> None:
        """Wiedergabe der Informationen eines Haendler"""

    def vergleiche_haendler(self, haendler: "Haendler") -> bool:
        """Vergleiche zwei Haendler"""

class Datum:
    """Klasse Datum"""

    datum_counter = 0

    def __init__(self, tag: int, monat: int, jahr: int) -> None:
        Datum.datum_counter += 1
        self.tag = tag
        self.monat = monat
        self.jahr = jahr

    def get_tag(self) -> int:
        """Wiedergab vom Tag"""

    def get_monat(self) -> int:
        """Wiedergabe vom Monat"""

    def get_jahr(self) -> int:
        """Wiedergabe vom Jahr"""

    def vergleiche_datum(self, datum: "Datum") -> bool:
        """Vergleiche Daten miteinander"""

    def datum_anzeige(self) -> str:
        """Wiedergabe vom Datum im Format TT:MM:JJ"""

class Produkt:
    """Klasse Produkt"""

    produkt_counter = 0

    def __init__(
        self, name: str, menge: float, preis: float, datum: Datum, abteilung: str
    ) -> None:
        Produkt.produkt_counter += 1
        self.name = name
        self.menge = menge
        self.preis = preis
        self.datum = datum
        self.abteilung = abteilung

    def get_bezeichnung(self) -> str:
        """Wiedergabe vom Namen des Produktes"""

    def get_menge(self) -> float:
        """Wiedergabe von der Warenmenge"""

    def get_preis(self) -> float:
        """Wiedergabe vom Preis in € mit 2 Dezimalstellen"""

    def get_gesamtpreis(self) -> float:
        """Gesamtpreis in € mit 2 Dezimalstellen"""

    def get_haltbarkeit(self) -> Datum:
        """Wiedergabe der MHD bzw. Garantie eines Produktes"""

    def get_produkt_id(self) -> int:
        """Wiedergabe der ID eines Produktes zur Identifikation"""

    def get_produkt_abteilung(self) -> str:
        """Wiedergabe der Abteilung vom Produkt"""

    def display_produkt(self) -> None:
        """Darstellung der wichtigsten Informationen"""

    def vergleiche_produkte(self, produkt: "Produkt") -> bool:
        """Vergleiche Produkte basierend auf der ID miteinander"""

class Konto:
    """Klasse Konto"""

    konto_counter = 0

    def __init__(self, kunde: Kunde, institut: str) -> None:
        Konto.konto_counter += 1
        self.kunde = kunde
        self.institut = institut

    def einzahlen(self) -> None:
        """Geld einzahlen aufs Konto"""

    def abheben(self) -> None:
        """Geld abheben vom Konto"""

    def get_kontostand(self) -> float:
        """Wiedergabe vom aktuellen Kontostand"""

    def get_konto_id(self) -> int:
        """Wiedergabe der ID eines Kontos"""

    def get_institut(self) -> str:
        """ "Wiedergabe vom Namen vom Institut"""

    def vergleiche_konto(self, konto: "Konto") -> bool:
        """Vergleich zwischen Konten basierend auf deren ID"""

    def get_kontoinhaber(self) -> Kunde:
        """Wiedergabe vom Besitzer vom Konto"""

class Warenkorb:
    """Klasse Warenkorb"""

    warenkorb_counter = 0

    def __init__(self, kunde: Kunde) -> None:
        Warenkorb.warenkorb_counter += 1
        self.kunde = kunde

    def get_warenkorb_id(self) -> int:
        """Wiedergabe der ID vom Warenkorb"""

    def fuege_produkt_hinzu(self, produkt: Produkt) -> None:
        """Fuege ein Produkt in den Warenkorb hinzu"""

    def entferne_produkt(self, produkt: Produkt) -> None:
        """Entferne ein Produkt aus dem Warenkorb"""

    def get_kunde(self) -> Kunde:
        """Wiedergabe vom Besitzer vom Warenkorb"""

    def get_warenkorb_gesamtpreis(self) -> float:
        """Wiedergabe vom Gesamtpreis vom Einkauf in € bei 2 Dezimalstellen"""

    def erhalte_produkte(self) -> list[Produkt]:
        """Wiedergabe aller im Warenkorb vorhandenen Produkte"""

    def vergleiche_warenkorb(self, warenkorb: "Warenkorb") -> bool:
        """Vergleich zweier Warenkörbe basierend auf deren ID"""

class Kassenzettel:
    """Klasse Kassenzettel"""

    kassenzettel_counter = 0

    def __init__(
        self,
        datum: Datum,
        kunde: Kunde,
        haendler: Haendler,
        warenkorb: Warenkorb,
        konto: Konto,
    ) -> None:
        Kassenzettel.kassenzettel_counter += 1
        self.datum = datum
        self.kunde = kunde
        self.haendler = haendler
        self.warenkorb = warenkorb
        self.konto = konto

    def get_kassenzettel_id(self) -> int:
        """Wiedergabe der ID eines Kassenzettels"""

    def erzeuge_kassenzettel(self) -> str:
        """
        Erzeuge einen Kassenzettel

        Returns: Wiedergabe vom Dateipfad vom Kassenzettel
        """

    def vergleiche_kassenzettel(self) -> bool:
        """Vergleich zwischen 2 Kassenzetteln basierend auf der ID"""

class Supermarkt:
    """Klasse Supermarkt"""

    supermarkt_counter = 0

    def __init__(self, name: str, adresse: str) -> None:
        Supermarkt.supermarkt_counter += 1
        self.name = name
        self.adresse = adresse

    def get_supermarkt_name(self) -> str:
        """Wiedergabe vom Namen des Supermarkts"""

    def get_supermarkt_adress(self) -> str:
        """Wiedergabe von der Adresse vom Supermarkt"""

    def fuege_produkt_ein(self, produkt: Produkt) -> None:
        """Fuege ein Produkt in den Supermarkt ein"""

    def entferne_produkt(self, produkt: Produkt) -> None:
        """Entferne ein Produkt aus dem Supermarkt"""

    def fuege_kunden_ein(self, kunde: Kunde) -> None:
        """Fuege einen Kunden in den Supermarkt ein"""

    def entferne_kunden(self, kunde: Kunde) -> None:
        """Entferne Kunden aus dem Supermarkt"""

    def fuege_warenkorb_hinzu(self, warenkorb: Warenkorb) -> None:
        """Fuege einen Warenkorb in den Supermarkt ein"""

    def entferne_warenkorb(self, warenkorb: Warenkorb) -> None:
        """Entferne einen Warenkorb aus dem Supermarkt"""

    def fueg_haendler_hinzu(self, haendler: Haendler) -> None:
        """Fuege einen Haendler in den Supermarkt ein"""

    def entferne_haendler(self, haendler: Haendler) -> None:
        """Entferne einen Haendler aus dem Supermarkt"""

    def erzeuge_produktliste(self) -> str:
        """
        Erzeuge eine Dokument mit vorhandenen Produkten

        Returns: Wiedergabe vom Dateipfad vom Dokument als str
        """

    def erzeuge_kundenliste(self) -> str:
        """
        Erzeuge eine Dokument mit vorhandenen Kunden

        Returns: Wiedergabe vom Dateipfad vom Dokument als str
        """

    def erzeuge_haendlerliste(self) -> str:
        """
        Erzeuge eine Dokument mit vorhandenen Haendlern

        Returns: Wiedergabe vom Dateipfad vom Dokument als str
        """

    def erzeuge_warenkorbliste(self) -> str:
        """
        Erzeuge eine Dokument mit vorhandenen Kunden

        Returns: Wiedergabe vom Dateipfad vom Dokument als str
        """

    def get_umsatz(self) -> float:
        """Wiedergabe vom generierten Umsatz in € bei einer Genauigkeit von 2 Dezimalstellen"""

    def get_supermarkt_id(self) -> int:
        """Wiedergabge der ID vom Supermarkt"""

    def vergleiche_supermarkt(self, supermarkt: "Supermarkt") -> bool:
        """Vergleiche zwei Supermaerkte basierend auf der ID"""

class LogLevel(Enum):
    """Enum-Klasse fuer Klasse Logging"""

    DEBUG = 0
    INFO = 1
    WARNING = 2
    ERROR = 3

class Logging:
    """Klasse Logging"""

    def __init__(
        self,
        file_path: str,
        status: LogLevel = LogLevel.INFO,
        console_output: bool = True,
    ) -> None:
        self.file_path = file_path
        self.status = status
        self.console_output = console_output

    def start_log(self, message: str, level: LogLevel) -> None:
        """Start vom Logging-Prozess"""

    def set_loglevel(self, level: LogLevel) -> None:
        """Einstellen vom Status vom Log"""

    def enable_console_output(self, status: bool) -> None:
        """Ermoegliche Ausgabe via Konsole"""

    def get_level(self) -> str:
        """Wiedergabe vom Status als zusammenhaengender String"""
