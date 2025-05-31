#ifndef INC_BASE_DATUM_HPP_
#define INC_BASE_DATUM_HPP_

#include <string>
#include <sstream>
#include <cinttypes>
#include <iostream>
#include <iomanip>

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

#endif // INC_BASE_DATUM_HPP_
