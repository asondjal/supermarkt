#!/bin/bash
set -e

REPORT_DIR="python-coverage"

pytest --cov=./ \
       --cov-report=html:"$REPORT_DIR" \
       --cov-fail-under=85 \
       --cov-config=<(echo -e "[run]\nomit = setup.py") \
       python_tests/

cd "$REPORT_DIR"

find . ! -name 'index.html' -type f -delete
find . ! -name '.' ! -name 'index.html' -type d -exec rm -rf {} +

lynx -dump index.html > coverage.txt

cd ..

echo "Coverage-Bericht wurde in $REPORT_DIR/ gespeichert."
echo "Textversion liegt in $REPORT_DIR/coverage.txt."
