from prometheus_client import start_http_server, Gauge
import json, time

# Metriken definieren
coverage_total = Gauge("coverage_total_percent", "Gesamtabdeckung in Prozent")
coverage_missing = Gauge("coverage_missing_lines", "Anzahl der fehlenden Zeilen")

def load_coverage():
    with open("coverage.json", encoding="utf-8") as f:
        data = json.load(f)
        totals = data["totals"]
        return totals["percent_covered"], totals["missing_lines"]

if __name__ == "__main__":
    # Prometheus-Exporter starten
    start_http_server(8000)
    print("[INFO] Prometheus-Exporter läuft auf http://localhost:8000/metrics")
    
    while True:
        total, missing = load_coverage()
        coverage_total.set(total)
        coverage_missing.set(missing)
        time.sleep(10)  # alle 10 Sekunden aktualisieren
