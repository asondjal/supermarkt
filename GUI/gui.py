import tkinter as tk
from py_bindings import (
    Person,
    Kunde,
    Haendler,
    Datum,
    Produkt,
    Konto,
    Warenkorb,
    Kassenzettel,
    Supermarkt,
    Logging,
    LogLevel,
    ReadData,
    Statistik,
)


class SupermarktApp:
    """Hauptklasse für die Supermarkt GUI-Anwendung"""
    def __init__(self, root):
        self.root = root
        self.root.title("Supermarkt GUI")
        self.root.geometry("1080x810")
        self.root.configure(bg="white")

        self.create_widgets()

    def create_widgets(self):
        """Erstellt die GUI-Widgets"""
        title = tk.Label(self.root, text="🛒 Supermarkt-Verwaltung", font=("Arial", 20), bg="white")
        title.pack(pady=20)

        button_frame = tk.Frame(self.root, bg="white")
        button_frame.pack(pady=40)

        buttons_info = [
            ("Kunde hinzufügen", self.handle_kunde),
            ("Produkt anzeigen", self.handle_produkt),
            ("Haendler anzeigen", self.handle_haendler),
            ("Warenkorb anzeigen", self.handle_warenkorb),
            ("Konto anzeigen", self.handle_konto),
            ("Statistik anzeigen", self.handle_statistik),
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
                height=2
            )
            button.pack(pady=10)

    def open_info_window(self, title: str, content: str):
        """Öffnet ein neues Fenster mit Informationen"""
        window = tk.Toplevel(self.root)
        window.title(title)
        window.geometry("500x300")
        window.configure(bg="white")

        label = tk.Label(window, text=title, font=("Arial", 16, "bold"), bg="white")
        label.pack(pady=10)

        content_label = tk.Label(window, text=content, bg="white", font=("Arial", 12), wraplength=480, justify="left")
        content_label.pack(pady=10)

    def handle_kunde(self):
        """Erstellt einen Dummy-Kunden"""
        kunde = Kunde("Max Mustermann", "male", 30, "max@web.de", "Musterstraße 1, 12345 Musterstadt")
        self.open_info_window("🧍 Kunde erstellt", repr(kunde))

    def handle_produkt(self):
        """Zeigt ein Beispielprodukt an"""
        datum = Datum(25, 12, 2025)
        produkt = Produkt("Apfel", 1.99, 3.5, datum, "Obst")
        self.open_info_window("🍎 Produkt erstellt", repr(produkt))

    def handle_haendler(self):
        """Erstellt einen Dummy-Händler"""
        haendler = Haendler("Lisa Händler", "female", 45, "lisa@handel.de", "Marktweg 7, 54321 Händlertown")
        self.open_info_window("🏪 Händler erstellt", repr(haendler))

    def handle_warenkorb(self):
        """Erstellt einen Warenkorb mit einem Produkt"""
        kunde = Kunde("Anna", "female", 25, "anna@supermail.de", "Feldweg 2, 10115 Berlin")
        produkt = Produkt("Bananen", 2.00, 1.5, Datum(15, 6, 2025), "Obst")
        warenkorb = Warenkorb(kunde)
        warenkorb.fuege_produkt_hinzu(produkt)
        produkte = warenkorb.erhalte_produkte()
        content = "\n".join([repr(p) for p in produkte])
        self.open_info_window("🧺 Warenkorb erstellt", content)

    def handle_konto(self):
        """Zeigt ein Beispiel-Konto"""
        kunde = Kunde("Tim Konto", "male", 32, "tim@konto.de", "Bankstraße 9, 45678 Geldstadt")
        konto = Konto(kunde, "Sparkasse")
        konto.einzahlen(100.0)
        konto.abheben(25.0)
        text = f"💳 Konto erstellt für: {kunde.get_name()}\nKontostand: {konto.get_kontostand():.2f} €"
        self.open_info_window("💳 Konto", text)

    def handle_statistik(self):
        """Berechnet einfache Statistik aus Zahlen"""
        statistik = Statistik()
        data = "Wert: 100, 200, 150, 250, 300\nWeitere Zeile mit 50 und 75"
        try:
            reader = ReadData.from_string(data)
            statistik.lade_daten(reader)
        except (AttributeError, ValueError, TypeError):
            statistik.lade_daten(ReadData("./GUI/dummy.csv"))  # Fallback
        mw = statistik.mittelwert()
        med = statistik.median()
        content = f"📊 Statistik:\nMittelwert: {mw:.2f}\nMedian: {med:.2f}\n"
        self.open_info_window("📊 Statistik Ergebnisse", content)


if __name__ == "__main__":
    root = tk.Tk()
    app = SupermarktApp(root)
    root.mainloop()
