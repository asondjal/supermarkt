"""Python bindings fuer Datenverarbeitung und Statistik."""

# py_bindings.pyi

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

    def varianz(self) -> float:
        """Berechne die Varianz der Daten."""

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

    def __init__(self, kunde: Kunde) -> None:
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
