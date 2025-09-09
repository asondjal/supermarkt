import os
import subprocess

def pytest_sessionfinish(session):
    """Wird nach Ende der Test-Session aufgerufen."""
    html_report = os.path.join("htmlcov", "index.html")
    txt_report = "coverage.txt"

    if os.path.exists(html_report):
        try:
            subprocess.run(
                ["lynx", "-dump", html_report],
                stdout=open(txt_report, "w"),
                check=True
            )
            session.config.pluginmanager.get_plugin("terminalreporter").write_line(
                f"Coverage-Report auch als Text gespeichert: {txt_report}"
            )
        except Exception as e:
            session.config.pluginmanager.get_plugin("terminalreporter").write_line(
                f"[WARNUNG] Konnte HTML nicht nach Text konvertieren: {e}"
            )
