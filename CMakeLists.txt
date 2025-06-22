cmake_minimum_required(VERSION 3.6)
project(supermarkt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_COMPILER_LAUNCHER ccache)
set(CMAKE_CXX_COMPILER_LAUNCHER ccache)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall -Wextra -pedantic")

# Executable fuers Hauptprojekt
add_executable(supermarkt 
    src/main.cpp
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

target_include_directories(supermarkt PRIVATE ${PROJECT_SOURCE_DIR}/inc)
target_link_libraries(supermarkt PRIVATE poppler-cpp)
target_compile_options(supermarkt PRIVATE -Wall -Wextra -pedantic)

# Executable zum Testen der C++-Klassen
add_executable(cpp_tests
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
    
    cpp_tests/main.cpp
    cpp_tests/test_read_data.cpp
    cpp_tests/test_statistik.cpp
    cpp_tests/test_logging.cpp
    cpp_tests/test_produkt.cpp
    cpp_tests/test_datum.cpp
    cpp_tests/test_person.cpp
    cpp_tests/test_kunde.cpp
    cpp_tests/test_haendler.cpp
    cpp_tests/test_warenkorb.cpp
    cpp_tests/test_kassenzettel.cpp
    cpp_tests/test_supermarkt.cpp
)

target_include_directories(cpp_tests PRIVATE ${PROJECT_SOURCE_DIR}/inc)

target_link_libraries(cpp_tests PRIVATE poppler-cpp)

target_compile_options(cpp_tests PRIVATE -Wall -Wextra -pedantic)

add_subdirectory(pybind11)
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
target_link_libraries(supermarkt PRIVATE Python3::Python)

include_directories(${Python3_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/pybind11/include)

# Executable fuer die Integration von C++ in Python
pybind11_add_module(py_bindings
    bindings/python_bindings.cpp
    
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

target_link_libraries(py_bindings PRIVATE poppler-cpp)
target_include_directories(py_bindings PRIVATE ${PROJECT_SOURCE_DIR}/inc)
