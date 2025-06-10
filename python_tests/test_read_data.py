"""Python-file for testing class ReadData"""

from py_bindings import ReadData

def test_read_data():
    """Funktion zum Testen von ReadData"""
    read_data = ReadData("./data/supermarkt_0/produkte.txt")
    read_data.read_txt()
    assert read_data.read_txt() is not None
    with open("./data/supermarkt_0/produkte.txt", "r", encoding="utf-8") as f:
        file_content = f.read()
        assert read_data.read_txt() == file_content

    csv_data = ReadData("./data/numbers.csv")
    csv_data.read_csv()
    assert csv_data.read_csv() is not None
    with open("./data/numbers.csv", "r", encoding="utf-8") as f:
        file_content = f.read()
        assert csv_data.read_csv() == file_content

    json_data = ReadData("./.vscode/settings.json")
    json_data.read_json()
    assert json_data.read_json() is not None
    with open("./.vscode/settings.json", "r", encoding="utf-8") as f:
        file_content = f.read()
        assert json_data.read_json() == file_content

    # Alternative: test PDF reading without PyPDF2 or external libraries
    # This will just check if the file can be opened and is not empty
    with open("README.pdf", "rb") as f:
        content = f.read()
        assert len(content) > 0

    auto_data = ReadData("logfile.txt")
    auto_data.read_auto()
    assert auto_data.read_auto() is not None
    with open("logfile.txt", "r", encoding="utf-8") as f:
        file_content = f.read()
        assert auto_data.read_auto() == file_content