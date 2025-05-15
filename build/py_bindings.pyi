"""Python bindings fuer Datenverarbeitung und Statistik."""

# py_bindings.pyi

class ReadData:
    """Klasse zum Auslesen von Dateien aus unterschiedlichen Formaten."""

    def __init__(self, path: str) -> None:
        pass

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

    def __init__(self) -> None:
        pass

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

    def __init__(
        self, name: str, geschlecht: str, alter: int, email: str, adresse: str
    ) -> None:
        """"""
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
