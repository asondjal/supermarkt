#include "datum.hpp"

Datum::Datum(uint32_t tag, uint32_t monat, uint32_t jahr) : tag_(tag), monat_(monat), jahr_(jahr) {}

uint32_t Datum::GetTag() const {
    return tag_;
}

uint32_t Datum::GetMonat() const {
    return monat_;
}

uint32_t Datum::GetJahr() const {
    return jahr_;
}

void Datum::Print() const {
    std::cout << "Datum: " << std::setfill('0') << std::setw(2) << tag_ << "." << std::setfill('0') << std::setw(2) << monat_ << "." << jahr_ << std::endl;
}