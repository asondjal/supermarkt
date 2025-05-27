"""Python-File fuer die GUI"""

import os
import glob

import tkinter as tk
from tkinter import messagebox
from datetime import datetime

from py_bindings import (
    Kunde,
    Produkt,
    Haendler,
    Warenkorb,
    Konto,
    Statistik,
    Datum,
    Kassenzettel,
    Supermarkt,
    Logging,
    LogLevel,
    ReadData,
)


class SupermarktApp:
    """Hauptklasse für die Supermarkt GUI-Anwendung"""

    def __init__(self, master):
        self.root = master
        self.root.title("Supermarkt GUI")
        self.root.geometry("1080x810")
        self.root.configure(bg="white")

        heute = datetime.today()

        self.current_date = Datum(heute.day, heute.month, heute.year)
        self.current_kunde = None
        self.current_haendler = None
        self.current_konto = None
        self.current_warenkorb = None
        self.produkte_liste = []
        self.supermarkt = Supermarkt("REAL", "Musterstraße 1, 12345 Musterstadt")

        dummy_kunde = Kunde("x", "neutral", 0, "x@x.com", "Nothing")
        dummy_haendler = Haendler("y", "neutral", 0, "y@x.com", "Nowhere")
        dummy_warenkorb = Warenkorb(dummy_kunde)
        dummy_konto = Konto(dummy_kunde, "Stupid")
        self.current_kassenzettel = Kassenzettel(
            self.current_date, dummy_kunde, dummy_haendler, dummy_warenkorb, dummy_konto
        )

        self.statistik = Statistik()
        self.logging = Logging("supermarkt_logging.txt", LogLevel.INFO, True)
        self.logging.start_log("Supermarkt GUI gestartet", LogLevel.INFO)
        self.read_data = ReadData("supermarkt_logging.txt")

        self.create_widgets()

    def create_widgets(self):
        """Erstellt die GUI-Widgets"""
        title = tk.Label(
            self.root,
            text=f"🛒 Supermarkt-Verwaltung fuer {self.supermarkt.get_supermarkt_name()}",
            font=("Arial", 20),
            bg="white",
        )
        title.pack(pady=20)

        subtitle = tk.Label(
            self.root,
            text=f"Aktuelles Datum: {self.current_date.datum_anzeige()}",
            font=("Arial", 20),
            bg="white",
        )
        subtitle.pack(pady=20)

        button_frame = tk.Frame(self.root, bg="white")
        button_frame.pack(pady=40)

        # Graue Buttons für die Klassen
        buttons_info = [
            ("Kunde hinzufügen", self.handle_kunde),
            ("Konto hinzufügen", self.handle_konto),
            ("Aktueller Warenkorb", self.handle_warenkorb),
            ("Haendler hinzufügen", self.handle_haendler),
            ("Produkt hinzufügen", self.handle_produkt),
            ("Erzeuge Kassenzettel", self.create_kassenzettel),
            ("Zeige Kassenzettel", self.show_kassenzettel),
            ("Zeige Statistiken", self.show_data),
            ("Supermarkt schließen", self.close_supermarkt),
        ]

        for text, command in buttons_info:
            button = tk.Button(
                button_frame,
                text=text,
                command=command,
                bg="gray",
                fg="white",
                font=("Arial", 14),
                width=25,
                height=2,
            )
            button.pack(pady=10)

        # Statusanzeige
        self.status = tk.Label(
            self.root, text="", bg="white", fg="green", font=("Arial", 12)
        )
        self.status.pack(pady=10)

    def handle_kunde(self):
        """Fenster zum Anlegen eines Kunden"""

        def create_kunde():
            name = entry_name.get()
            geschlecht = entry_geschlecht.get()
            alter = int(entry_alter.get())
            email = entry_email.get()
            adresse = entry_adresse.get()
            self.current_kunde = Kunde(name, geschlecht, alter, email, adresse)
            self.status.config(
                text=f"Kunde '{self.current_kunde.get_name()}' wurde gespeichert."
            )
            self.logging.start_log(
                f"Neuer Kunde: {self.current_kunde.get_name()}", LogLevel.INFO
            )
            kunde_window.destroy()

        kunde_window = tk.Toplevel(self.root)
        kunde_window.title("Kunde hinzufügen")
        kunde_window.geometry("400x300")

        labels = ["Name", "Geschlecht", "Alter", "E-Mail", "Adresse"]
        entries = []

        for label_text in labels:
            tk.Label(kunde_window, text=label_text).pack()
            entry = tk.Entry(kunde_window)
            entry.pack()
            entries.append(entry)

        entry_name, entry_geschlecht, entry_alter, entry_email, entry_adresse = entries

        tk.Button(kunde_window, text="Kunde erstellen", command=create_kunde).pack(
            pady=10
        )

    def handle_haendler(self):
        """Öffnet ein Fenster zur Eingabe eines neuen Haendlers"""

        def create_haendler():
            try:
                name = entry_name.get()
                geschlecht = entry_geschlecht.get()
                alter = int(entry_alter.get())
                email = entry_email.get()
                adresse = entry_adresse.get()

                self.current_haendler = Haendler(
                    name, geschlecht, alter, email, adresse
                )
                self.status.config(
                    text=f"Haendler '{self.current_haendler.get_name()}' wurde erstellt."
                )
                self.logging.start_log(
                    f"Neuer Haendler: {self.current_haendler.get_name()}", LogLevel.INFO
                )
                haendler_fenster.destroy()
            except ValueError as e:
                messagebox.showerror("Fehler", str(e))

        haendler_fenster = tk.Toplevel(self.root)
        haendler_fenster.title("Neuen Haendler anlegen")
        haendler_fenster.geometry("400x300")
        haendler_fenster.configure(bg="white")

        labels = ["Name", "Geschlecht", "Alter", "E-Mail", "Adresse"]
        entries = []

        for i, label in enumerate(labels):
            tk.Label(haendler_fenster, text=label, bg="white").grid(
                row=i, column=0, padx=10, pady=5, sticky="e"
            )
            entry = tk.Entry(haendler_fenster, width=30)
            entry.grid(row=i, column=1, padx=10, pady=5)
            entries.append(entry)

        entry_name, entry_geschlecht, entry_alter, entry_email, entry_adresse = entries

        tk.Button(
            haendler_fenster,
            text="Haendler erstellen",
            command=create_haendler,
            bg="gray",
            fg="white",
        ).grid(row=len(labels), columnspan=2, pady=20)

    def handle_konto(self):
        """Fenster zum Erstellen eines Kontos für den aktuellen Kunden"""
        if not self.current_kunde:
            self.status.config(text="Bitte zuerst einen Kunden anlegen.")
            return

        def create_konto():
            bank = entry_bank.get()
            self.current_konto = Konto(self.current_kunde, bank)
            self.status.config(
                text=f"Konto für {self.current_kunde.get_name()} bei {self.current_konto.get_institut()} wurde angelegt."
            )
            self.current_konto.einzahlen(1000.00)
            konto_window.destroy()

        konto_window = tk.Toplevel(self.root)
        konto_window.title("Konto anlegen")
        konto_window.geometry("400x150")

        tk.Label(konto_window, text="Bankname").pack()
        entry_bank = tk.Entry(konto_window)
        entry_bank.pack()

        tk.Button(konto_window, text="Konto erstellen", command=create_konto).pack(
            pady=10
        )
        self.logging.start_log(
            f"Neues Konto fuer: {self.current_kunde.get_name()}", LogLevel.INFO
        )

    def handle_produkt(self):
        """Öffnet ein Fenster zur Eingabe eines neuen Produkts"""

        def create_produkt():
            try:
                name = entry_name.get()
                menge = float(entry_menge.get())
                preis = float(entry_preis.get())
                abteilung = entry_abteilung.get()

                produkt = Produkt(name, menge, preis, Datum(10, 12, 2024), abteilung)
                self.logging.start_log(
                    f"Neues Produkt: {entry_name.get()}", LogLevel.INFO
                )
                self.produkte_liste.append(produkt)

                jugendschutz = ["Alkohol", "Hochprozentiges"]
                if (
                    abteilung in jugendschutz
                    and self.current_konto.get_kontoinhaber().get_alter() < 18
                ):
                    self.produkte_liste.remove(produkt)
                    self.logging.start_log(
                        f"{self.current_konto.get_kontoinhaber().get_name()} ist minderjaehrig!",
                        LogLevel.ERROR,
                    )
                self.status.config(text=f"Produkt '{name}' wurde erstellt.")
                produkt_fenster.destroy()
            except ValueError as e:
                messagebox.showerror("Fehler", str(e))

        produkt_fenster = tk.Toplevel(self.root)
        produkt_fenster.title("Neues Produkt anlegen")
        produkt_fenster.geometry("400x300")
        produkt_fenster.configure(bg="white")

        labels = ["Name", "Menge", "Preis", "Abteilung"]
        entries = []

        for i, label in enumerate(labels):
            tk.Label(produkt_fenster, text=label, bg="white").grid(
                row=i, column=0, padx=10, pady=5, sticky="e"
            )
            entry = tk.Entry(produkt_fenster, width=30)
            entry.grid(row=i, column=1, padx=10, pady=5)
            entries.append(entry)

        entry_name, entry_menge, entry_preis, entry_abteilung = entries

        tk.Button(
            produkt_fenster,
            text="Produkt erstellen",
            command=create_produkt,
            bg="gray",
            fg="white",
        ).grid(row=len(labels), columnspan=2, pady=20)

    def handle_warenkorb(self):
        """Fenster zum Erstellen eines Warenkorbs für den aktuellen Kunden"""
        if not self.current_kunde:
            self.status.config(text="Bitte zuerst einen Kunden anlegen.")
            return

        self.current_warenkorb = Warenkorb(self.current_kunde)
        message = f"Warenkorb für {self.current_kunde.get_name()} wurde angelegt."

        for produkt in self.produkte_liste:
            self.current_warenkorb.fuege_produkt_hinzu(produkt)

        kosten = self.current_warenkorb.get_warenkorb_gesamtpreis()
        self.current_konto.abheben(kosten)
        if self.current_konto.get_kontostand() > 0:
            self.logging.start_log(
                f"{self.current_konto.get_kontoinhaber().get_name()} ist zahlungsfaehig!",
                LogLevel.INFO,
            )
        else:
            self.logging.start_log(
                f"{self.current_konto.get_kontoinhaber().get_name()} ist insolvent!",
                LogLevel.ERROR,
            )
        items = self.current_warenkorb.erhalte_produkte()
        if not items:
            self.status.config(text="Warenkorb ist leer.")
            self.logging.start_log("Leerer Warenkorb!", LogLevel.WARNING)
            return

        message = "Artikel im Warenkorb:\n"
        for i, item in enumerate(items, 0):
            message += f"{i+1}. {item.get_bezeichnung()}\n"
        self.status.config(text=message)
        message += f"\nGesamtkosten vom Einkauf: {kosten:.2f} €"
        self.logging.start_log(message, LogLevel.INFO)

        self.status.config(text=message)

    def create_kassenzettel(self):
        """Erzeugt und speichert einen neuen Kassenzettel"""
        if not all([self.current_kunde, self.current_warenkorb, self.current_konto]):
            self.status.config(text="Fehlende Daten – Kunde, Warenkorb oder Konto.")
            return

        self.current_kassenzettel = Kassenzettel(
            self.current_date,
            self.current_kunde,
            self.current_haendler,
            self.current_warenkorb,
            self.current_konto,
        )

        pfad = self.current_kassenzettel.erzeuge_kassenzettel()
        self.status.config(text=f"Kassenzettel wurde erzeugt: {pfad}")
        self.logging.start_log(f"Kassenzettel erzeugt: {pfad}", LogLevel.INFO)

    def show_kassenzettel(self):
        """Zeigt den erzeugten Kassenzettel an"""
        if not hasattr(self, "current_kassenzettel"):
            self.status.config(text="Kein Kassenzettel vorhanden.")
            return

        try:
            pfad = self.current_kassenzettel.erzeuge_kassenzettel()
            with open(pfad, "r", encoding="utf-8") as file:
                content = file.read()
        except (OSError, IOError) as e:
            self.status.config(text=f"Fehler beim Lesen: {e}")
            return

        anzeige = tk.Toplevel(self.root)
        anzeige.title("Kassenzettel")
        anzeige.geometry("600x600")
        anzeige.configure(bg="white")

        textfeld = tk.Text(anzeige, wrap=tk.WORD, bg="white", font=("Courier", 12))
        textfeld.insert(tk.END, content)
        textfeld.pack(expand=True, fill=tk.BOTH)

        self.status.config(text="Kassenzettel wird angezeigt.")

    def show_data(self):
        """Zeigt statistische Auswertung des zuletzt gespeicherten Kassenzettels an"""
        path = "./data/kassenzettel/"
        search_pattern = os.path.join(path, "*.txt")
        files = glob.glob(search_pattern)

        if not files:
            self.status.config(text="Kein Kassenzettel gefunden.")
            return

        # Neueste Datei finden
        files.sort(key=os.path.getmtime, reverse=True)
        neueste_datei = files[0]

        # Daten lesen und analysieren
        reader = ReadData(neueste_datei)
        statistik = Statistik()
        statistik.lade_daten(reader)

        # Statistikdaten erfassen
        zeilen = statistik.zaehle_linen()
        woerter = statistik.wortanzahl()
        produkte = statistik.zaehle_variable("Produkt")
        zeichen = statistik.zeichenanzahl()
        mittelwert = statistik.mittelwert()
        erwartungswert = statistik.erwartungswert()

        # Neues Fenster zur Anzeige der Daten
        statistik_fenster = tk.Toplevel(self.root)
        statistik_fenster.title("Statistik-Auswertung")
        statistik_fenster.geometry("600x500")
        statistik_fenster.configure(bg="white")

        text = (
            f"📊 Statistik zum aktuellen Kassenzettel\n\n"
            f"📄 Zeilen: {zeilen}\n"
            f"🔤 Wörter: {woerter}\n"
            f"🔎 'Produkt'-Vorkommen: {produkte}\n"
            f"📝 Zeichen: {zeichen}\n"
            f"📈 Mittelwert: {mittelwert:.2f}\n"
            f"🎯 Erwartungswert: {erwartungswert:.2f}\n"
        )

        label = tk.Label(
            statistik_fenster, text=text, bg="white", justify="left", font=("Arial", 12)
        )
        label.pack(padx=20, pady=20)

        self.status.config(text="Statistik angezeigt.")

    def close_supermarkt(self):
        """Schließt die Anwendung sauber."""
        self.logging.start_log("Supermarkt GUI wird geschlossen", LogLevel.INFO)
        self.root.destroy()


if __name__ == "__main__":
    root = tk.Tk()
    app = SupermarktApp(root)
    root.mainloop()
