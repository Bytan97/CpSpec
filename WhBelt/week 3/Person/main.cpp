#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Person {
 public:
  void ChangeFirstName(int year, const string& first_name) {
    if (history[year].empty()) {
      history[year].push_back(first_name);
      history[year].push_back("unknown");
    } else {
      history[year][0] = first_name;
    }
  }
  void ChangeLastName(int year, const string& last_name) {
    if (history[year].empty()) {
      history[year].push_back("unknown");
      history[year].push_back(last_name);
    } else {
      history[year][1] = last_name;
    }
  }
  string GetFullName(int year) {
    string first_name = "unknown", last_name = "unknown";
    for (const auto& [key, value] : history) {
      if (key <= year) {
        if (value[0] != "unknown") {
          first_name = value[0];
        }
        if (value[1] != "unknown") {
          last_name = value[1];
        }
      }
    }
    if (first_name == "unknown" and last_name == "unknown") {
      return "Incognito";
    } else if (first_name == "unknown" and last_name != "unknown") {
      return last_name + " with unknown first name";
    } else if (first_name != "unknown" and last_name == "unknown") {
      return first_name + " with unknown last name";
    } else {
      return first_name + " " + last_name;
    }
  }

 private:
  map<int, vector<string>> history;
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}
