#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Person {
 public:
  Person(string f_name, string l_name, int b_year) {
    history[b_year].push_back(f_name);
    history[b_year].push_back(l_name);
    bd_year = b_year;
  }
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
  string GetFullName(int year) const {
    if (year < bd_year) {
      return "No person";
    }
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
  string GetFullNameWithHistory(int year) const {
    if (year < bd_year) {
      return "No person";
    }
    string first_name = "unknown", last_name = "unknown";
    string hist_first_name = "", hist_last_name = "";
    for (const auto& [key, value] : history) {
      if (key <= year) {
        if (value[0] != "unknown" and value[0] != first_name) {
          if (first_name != "unknown") {
            hist_first_name = first_name + ", " + hist_first_name;
          }
          first_name = value[0];
        }
        if (value[1] != "unknown" and value[1] != last_name) {
          if (last_name != "unknown") {
            hist_last_name = last_name + ", " + hist_last_name;
          }
          last_name = value[1];
        }
      }
    }
    if (hist_first_name.size() != 0) {
      hist_first_name.erase(begin(hist_first_name) + hist_first_name.size() - 2,
                            end(hist_first_name));
    }
    if (hist_last_name.size() != 0) {
      hist_last_name.erase(begin(hist_last_name) + hist_last_name.size() - 2,
                           end(hist_last_name));
    }
    if (first_name == "unknown" and last_name == "unknown") {
      return "Incognito";
    } else if (first_name == "unknown" and last_name != "unknown") {
      if (hist_last_name != "") {
        return last_name + " (" + hist_last_name + ")" +
               " with unknown first name";
      }
      return last_name + " with unknown first name";
    } else if (first_name != "unknown" and last_name == "unknown") {
      if (hist_first_name != "") {
        return first_name + " (" + hist_first_name + ")" +
               " with unknown last name";
      }
      return first_name + " with unknown last name";
    } else {
      auto res = first_name + " ";
      if (hist_first_name != "") {
        res += "(" + hist_first_name + ") ";
      }
      res += last_name;
      if (hist_last_name != "") {
        res += " (" + hist_last_name + ")";
      }
      return res;
    }
  }

 private:
  map<int, vector<string>> history;
  int bd_year;
};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}