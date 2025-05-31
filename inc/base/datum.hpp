#ifndef INC_BASE_DATUM_HPP_
#define INC_BASE_DATUM_HPP_

#include <cinttypes>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class Datum {
 private:
  const uint32_t tag_;
  const uint32_t monat_;
  const uint32_t jahr_;

 public:
  Datum(uint32_t tag, uint32_t monat, uint32_t jahr);
  uint32_t GetTag() const;
  uint32_t GetMonat() const;
  uint32_t GetJahr() const;
  std::string Print() const;

  bool operator==(const Datum& other) const;
};

#endif  // INC_BASE_DATUM_HPP_
