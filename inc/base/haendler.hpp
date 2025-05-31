#ifndef INC_BASE_HAENDLER_HPP_
#define INC_BASE_HAENDLER_HPP_

#include <string>

#include "base/person.hpp"

class Haendler : public Person {
private:
  const int haendlerID_;

public:
  Haendler(std::string name, std::string gender, int alter, std::string email,
           std::string adresse);
  int GetHaendlerID() const;
  void Print() const final;
  bool operator==(const Haendler& other) const;
};

#endif  // INC_BASE_HAENDLER_HPP_
