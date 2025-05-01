cmake_minimum_required(VERSION 3.6)
project(supermarkt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_COMPILER_LAUNCHER ccache)
set(CMAKE_CXX_COMPILER_LAUNCHER ccache)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall -Wextra -pedantic")

## Hauptzweig
add_executable(${PROJECT_NAME} 
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
)

target_include_directories(${PROJECT_NAME} PRIVATE
    inc/base
    inc/utils
)

target_link_libraries(supermarkt PRIVATE poppler-cpp)

target_compile_options(supermarkt PRIVATE -Wall -Wextra -pedantic)