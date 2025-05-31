#ifndef INC_BASE_PERSON_HPP_
#define INC_BASE_PERSON_HPP_

#include <algorithm>
#include <iostream>
#include <string>

class Person {
 private:
  const std::string name_;
  const std::string gender_;
  const int age_;
  const std::string email_;
  const std::string adresse_;
  const int personID_;

 public:
  Person(std::string name, std::string gender, int age, std::string email,
         std::string adresse);
  virtual ~Person() = default;
  std::string GetName() const;
  std::string GetGender() const;
  int GetAge() const;
  int GetPersonID() const;
  std::string GetEmail() const;
  std::string GetAdresse() const;
  virtual void Print() const;
  bool operator==(const Person& other) const;
};

#endif  // INC_BASE_PERSON_HPP_
