//#include "stuff.h"

void PrintStats(std::vector<Person> persons) {
  std::cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << std::endl;
  auto it = std::partition(persons.begin(), persons.end(), [](const Person &p) {
    return p.gender == Gender::FEMALE;
  });
  std::cout << "Median age for females = " << ComputeMedianAge(persons.begin(), it) << std::endl;
  it = std::partition(persons.begin(), persons.end(), [](const Person &p) {
    return p.gender == Gender::MALE;
  });
  std::cout << "Median age for males = " << ComputeMedianAge(persons.begin(), it) << std::endl;
  it = std::partition(persons.begin(), persons.end(), [](const Person &p) {
    return p.gender == Gender::FEMALE and p.is_employed;
  });
  std::cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), it) << std::endl;
  it = std::partition(persons.begin(), persons.end(), [](const Person &p) {
    return p.gender == Gender::FEMALE and not p.is_employed;
  });
  std::cout << "Median age for unemployed females = " << ComputeMedianAge(persons.begin(), it) << std::endl;
  it = std::partition(persons.begin(), persons.end(), [](const Person &p) {
    return p.gender == Gender::MALE and p.is_employed;
  });
  std::cout << "Median age for employed males = " << ComputeMedianAge(persons.begin(), it) << std::endl;
  it = std::partition(persons.begin(), persons.end(), [](const Person &p) {
    return p.gender == Gender::MALE and not p.is_employed;
  });
  std::cout << "Median age for unemployed males  = " << ComputeMedianAge(persons.begin(), it) << std::endl;
}
