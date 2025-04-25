#ifndef STATISTIK_HPP_
#define STATISTIK_HPP_

#include "readdata.hpp"
#include <vector>
#include <string>

class Statistik {
public:
    explicit Statistik(ReadData& dataReader);
    float Mittelwert() const;
    float Median() const;
    float Erwartungswert() const;
    float Varianz() const;

private:
    std::vector<std::string> datenBuffer_;
    void LadeDaten(ReadData& reader);
};

#endif /* STATISTIK_HPP_ */
