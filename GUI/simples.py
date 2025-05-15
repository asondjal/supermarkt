"""Python zum Testen von den Klassen aus py_bindings.pyi"""
from py_bindings import Person

person1 = Person("LeBron James", "male", 40, "lebron.james@gmail.com", "Los Angeles, USA")
person2 = Person("Magic Johnson", "male", 64, "magic.johnson@yahoo.hotmail", "Los Angeles, USA")
print(person1)
print(person1.get_name())
print(person1.get_geschlecht())
print(person1.get_alter())
print(person1.get_email())
print(person1.get_adresse())
print(person1.vergleiche_person(person2))
