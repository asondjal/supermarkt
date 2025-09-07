"""Python-File zum Einstellen der Integration von C++ in Python"""

from setuptools import setup, Extension
import pybind11

ext_modules = [
    Extension(
        "py_bindings",
        ["bindings/python_bindings.cpp",
         "src/main.cpp",
         "src/datum.cpp",
         "src/kunde.cpp",
         "src/konto.cpp",
         "src/haendler.cpp", 
         "src/person.cpp",
         "src/produkt.cpp",
         "src/warenkorb.cpp",
         "src/supermarkt.cpp",
         "src/kassenzettel.cpp",
         "src/read_data.cpp",
         "src/logging.cpp",
         "src/statistik.cpp"],
        include_dirs=[pybind11.get_include(), "inc"],
        language="c++",
        libraries=["poppler-cpp"],
        extra_compile_args=["-O3", "-std=c++17"],
    ),
]

setup(
    name="py_bindings",
    version="0.1.0",
    author="Arrif Sondjalim",
    description="Python-Bindings für mein Supermarkt-Projekt",
    ext_modules=ext_modules,
)
