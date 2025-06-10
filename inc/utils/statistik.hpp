#ifndef INC_UTILS_STATISTIK_HPP_
#define INC_UTILS_STATISTIK_HPP_

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <regex>
#include <string>
#include <vector>
#include <set>
#include <mutex>

#include "utils/read_data.hpp"

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
  std::set<std::string> datenBuffer_; // Use set to prevent duplicates
  mutable std::mutex datenMutex_;

  float Varianz() const;
  float MittelwertIntern() const;
};

#endif  // INC_UTILS_STATISTIK_HPP_
