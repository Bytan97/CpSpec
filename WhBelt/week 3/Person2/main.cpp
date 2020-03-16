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
  string GetFullNameWithHistory(int year) {
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
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

  return 0;
}
