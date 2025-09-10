#!/bin/bash
pytest --cov=./python_tests --cov-report=json
python export_metrics.py
