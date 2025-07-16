#include "base/person.hpp"

#include <iostream>
#include <string>

static int personen_counter = 0;

Person::Person(std::string name, std::string gender, int age, std::string email,
               std::string adresse)
    : name_{name},
      gender_{gender},
      age_{age},
      email_{email},
      adresse_{adresse},
      personID_{personen_counter++} {}

/**
 * @brief Überladung des Vergleichsoperators
 * @param other: andere Person
 * @return true, wenn die Personen gleich sind, false sonst
 */
bool Person::operator==(const Person& other) const { return personID_ == other.personID_; }
/**
 * @brief Funktion liefert den Namen einer Person zurück
 * @return name_: Name der Person
 */
std::string Person::GetName() const { return name_; }

/**
 * @brief Funktion liefert das Geschlecht einer Person zurück
 * @return gender_: Geschlecht der Person
 */
std::string Person::GetGender() const {
  std::string genders[3] = {"male", "female", "neutral"};
  for (int i = 0; i < 3; i++) {
    if (gender_ == genders[i]) {
      return gender_;
    }
  }
  throw std::invalid_argument("Ihr Geschlecht ist ungueltig!");
}

/**
 * @brief Funktion liefert das Alter einer Person zurück
 * @return age_: Alter der Person
 */
int Person::GetAge() const { return age_; }

/**
 * @brief Funktion liefert die E-Mail einer Person zurück
 * @return email_: E-Mail der Person
 */
std::string Person::GetEmail() const {
  size_t at_count = std::count(email_.begin(), email_.end(), '@');
  if (at_count == 1) {
    return email_;
  }
  return "Ihre E-Mail ist ungueltig!";
}

/**
 * @brief Rückgabwert der Funktion ist die Adresse einer Person
 * @return adresse_: Adresse der Person
 */
std::string Person::GetAdresse() const { return adresse_; }

/**
 * @brief Funktion liefert die ID einer Person zurück
 * @return personID_: ID der Person
 */
int Person::GetPersonID() const { return personID_; }

/**
 * @brief Funktion zur Zusammenfassung aller Informationen für eine Person
 */
void Person::Print() const {
  std::cout << "Name: " << name_ << "\n"
            << "Alter: " << age_ << "\n"
            << "Geschlecht: " << gender_ << "\n"
            << "Email: " << email_ << "\n"
            << "Adresse: " << adresse_ << std::endl;
}
