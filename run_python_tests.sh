#!/bin/bash

pytest --cov=./ \
       --cov-report=html \
       --cov-fail-under=85 \
       --cov-config=<(echo -e "[run]\nomit = setup.py") \
       python_tests/

lynx -dump htmlcov/index.html > coverage.txt

echo "Coverage als Text in coverage.txt gespeichert."
