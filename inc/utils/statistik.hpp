#ifndef STATISTIK_HPP_
#define STATISTIK_HPP_

#include "read_data.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <regex>
#include <cmath>

class Statistik {
public:
    explicit Statistik();
    void LadeDaten(ReadData& reader);
    void EntferneDaten(const std::string& data);
    uint32_t ZaehleEintraege() const;
    uint32_t ZaehleLinien() const;
    uint32_t ZaehleWorte() const;
    uint32_t ZaehleZeichen() const;
    uint32_t ZaehleVariable(std::string variable) const;
    float Mittelwert() const;
    float Median() const;
    float Erwartungswert() const;
    float Standardabweichung() const;

private:
    std::vector<std::string> datenBuffer_;
    mutable std::mutex datenMutex_;

    float Varianz() const;
    float MittelwertIntern() const;
};

#endif /* STATISTIK_HPP_ */