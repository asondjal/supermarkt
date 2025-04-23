#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <string>
#include <iostream>

class Person {
    
    private:
    const std::string name_;
    const std::string gender_;
    const int age_;
    const std::string email_;
    const std::string adresse_;
    const int personID_;

    public:
    Person(std::string name, std::string gender, int age, std::string email, std::string adresse);
    virtual ~Person() = default;
    std::string GetName() const;
    std::string GetGender() const;
    int GetAge() const;
    std::string GetEmail() const;
    std::string GetAdresse() const;
    virtual void Print() const;
};

#endif /* PERSON_HPP_ */