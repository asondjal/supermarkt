#ifndef STATISTIK_HPP_
#define STATISTIK_HPP_

#include "read_data.hpp"
#include "utilities.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

class Statistik {
public:
    explicit Statistik();
    void LadeDaten(ReadData& reader);
    void EntferneDaten(const std::string& data);
    uint32_t AnzahlDaten() const;
    float Mittelwert() const;
    float Median() const;
    float Erwartungswert() const;
    float Varianz() const;

private:
    std::vector<std::string> datenBuffer_;
    mutable std::mutex datenMutex_;
};

#endif /* STATISTIK_HPP_ */