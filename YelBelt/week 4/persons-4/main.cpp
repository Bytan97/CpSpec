#include<iostream>
#include <map>

class Person {
public:
  void ChangeFirstName(int year, const std::string &f_name) {
    first_names[year] = f_name;
  }
  void ChangeLastName(int year, const std::string &l_name) {
    last_names[year] = l_name;
  }
  std::string GetFullName(int year) {
    auto it_first_name = first_names.upper_bound(year);
    auto it_last_name = last_names.upper_bound(year);
    std::string first_name, last_name;

    if (it_first_name == first_names.begin()) {
      first_name = "";
    } else {
      first_name = std::prev(it_first_name)->second;
    }
    if (it_last_name == last_names.begin()) {
      last_name = "";
    } else {
      last_name = std::prev(it_last_name)->second;
    }
    if (first_name.empty() && last_name.empty()) {
      return "Incognito";
    } else if (first_name.empty()) {
      return last_name + " with unknown first name";
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";
    } else {
      return first_name + " " + last_name;
    }

  }
private:
  std::map<int, std::string> first_names;
  std::map<int, std::string> last_names;
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    std::cout << person.GetFullName(year) << std::endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullName(year) << std::endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullName(year) << std::endl;
  }

  return 0;
}