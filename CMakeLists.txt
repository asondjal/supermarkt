cmake_minimum_required(VERSION 3.6)
project(supermarkt)
project(supermarkt_bindings)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_COMPILER_LAUNCHER ccache)
set(CMAKE_CXX_COMPILER_LAUNCHER ccache)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall -Wextra -pedantic")

# Haupt-Executable: supermarkt
add_executable(supermarkt 
    src/main.cpp
    src/tests.cpp
    src/datum.cpp
    src/produkt.cpp
    src/person.cpp
    src/haendler.cpp
    src/kunde.cpp
    src/warenkorb.cpp
    src/konto.cpp
    src/kassenzettel.cpp
    src/supermarkt.cpp
    src/read_data.cpp
    src/statistik.cpp
    src/logging.cpp
)

# Executable für Bindings: supermarkt_bindings
add_executable(supermarkt_bindings
    src/main.cpp
    src/tests.cpp
    src/datum.cpp
    src/produkt.cpp
    src/person.cpp
    src/haendler.cpp
    src/kunde.cpp
    src/warenkorb.cpp
    src/konto.cpp
    src/kassenzettel.cpp
    src/supermarkt.cpp
    src/read_data.cpp
    src/statistik.cpp
    src/logging.cpp
    bindings/statistik_bind.cpp
)

# Pybind11 einbinden
add_subdirectory(pybind11)
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

# pybind11_bindings mit Python-Bibliotheken linken
target_link_libraries(supermarkt_bindings PRIVATE Python3::Python)

include_directories(${Python3_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/pybind11/include)

# Modul für Python (Statistik-Pybind11)
pybind11_add_module(py_statistik
    bindings/statistik_bind.cpp
    src/statistik.cpp
    src/read_data.cpp
)

target_link_libraries(py_statistik PRIVATE poppler-cpp)

target_include_directories(supermarkt_bindings PRIVATE inc/utils)

# Includes
target_include_directories(supermarkt PRIVATE
    inc/base
    inc/utils
)

# Includes fuer Bindings
target_include_directories(supermarkt_bindings PRIVATE
    inc/base
    inc/utils
)

# Libraries
target_link_libraries(supermarkt PRIVATE poppler-cpp)
target_link_libraries(supermarkt_bindings PRIVATE poppler-cpp)

# Compiler-Flags
target_compile_options(supermarkt PRIVATE -Wall -Wextra -pedantic)
target_compile_options(supermarkt_bindings PRIVATE -Wall -Wextra -pedantic)
