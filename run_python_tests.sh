#!/bin/bash
pytest --cov=./ --cov-report=html python_tests/
lynx -dump htmlcov/index.html > coverage.txt
echo "Coverage als Text in coverage.txt gespeichert."
