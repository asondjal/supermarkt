#!/bin/bash

set -e  # Script beendet sich bei Fehlern

# Coverage-Ordner vorbereiten
REPORT_DIR="c++_coverage"
mkdir -p "$REPORT_DIR"

# Dateien in C++ korrekt formatieren 
echo "Formatiere C++-Dateien entsprechend .clang-format..."
find ./src ./cpp_tests ./inc -regex '.*\.\(cpp\|hpp\)$' -exec clang-format -i {} \;

# Coverage-Berichte erzeugen
gcovr -r . \
  --exclude='src/' \
  --filter='cpp_tests/' \
  --exclude='pybind11/' \
  --exclude='bindings/' \
  --exclude='external/' \
  --html-details "$REPORT_DIR/index.html" \
  --txt "$REPORT_DIR/summary.txt"

echo "✅ Coverage-Reports erstellt:"
echo "   - HTML: $REPORT_DIR/index.html"
echo "   - Text: $REPORT_DIR/summary.txt"
