#include "tests/test_datum.hpp"
#include "tests/test_read_data.hpp"
#include "tests/test_statistik.hpp"
#include "tests/test_statistik.hpp"

#include <iostream>

int main() {
    TestDatum();
    TestReadData();
    TestStatistik();
    TestStatistik();
    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}
