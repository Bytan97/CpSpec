#include <iostream>
#include <map>

using namespace std;
int main() {
  map<string, string> countries;
  int num;
  cin >> num;
  for (int i = 0; i < num; ++i) {
    string command;
    cin >> command;
    if (command == "CHANGE_CAPITAL") {
      string country, new_capital;
      cin >> country >> new_capital;
      if (countries.count(country) == 0) {
        cout << "Introduce new country " << country << " with capital "
             << new_capital << endl;
        countries[country] = new_capital;
      } else {
        if (countries[country] == new_capital) {
          cout << "Country " << country << " hasn't changed its capital"
               << endl;
        } else {
          cout << "Country " << country << " has changed its capital from "
               << countries[country] << " to " << new_capital << endl;
          countries[country] = new_capital;
        }
      }
    } else if (command == "RENAME") {
      string old_country_name, new_country_name;
      cin >> old_country_name >> new_country_name;
      if (countries.count(old_country_name) == 0 or
          countries.count(new_country_name) == 1 or
          old_country_name == new_country_name) {
        cout << "Incorrect rename, skip" << endl;
      } else {
        cout << "Country " << old_country_name << " with capital "
             << countries[old_country_name] << " has been renamed to "
             << new_country_name << endl;
        string capital = countries[old_country_name];
        countries.erase(old_country_name);
        countries[new_country_name] = capital;
      }
    } else if (command == "ABOUT") {
      string country;
      cin >> country;
      if (countries.count(country) == 0) {
        cout << "Country " << country << " doesn't exist" << endl;
      } else {
        cout << "Country " << country << " has capital " << countries[country]
             << endl;
      }
    } else if (command == "DUMP") {
      if (countries.size() == 0) {
        cout << "There are no countries in the world" << endl;
      } else {
        for (const auto& [country, capital] : countries) {
          cout << country << "/" << capital << " ";
        }
        cout << endl;
      }
    }
  }

  return 0;
}

/*
6
CHANGE_CAPITAL RussianEmpire Petrograd
RENAME RussianEmpire RussianRepublic
ABOUT RussianRepublic
RENAME RussianRepublic USSR
CHANGE_CAPITAL USSR Moscow
DUMP
*/

/*
24
RENAME FakeCountry FarFarAway
ABOUT FarFarAway
DUMP
CHANGE_CAPITAL TsardomOfRussia Moscow
CHANGE_CAPITAL TsardomOfRussia Moscow
CHANGE_CAPITAL ColonialBrazil Salvador
CHANGE_CAPITAL TsardomOfRussia SaintPetersburg
RENAME TsardomOfRussia RussianEmpire
CHANGE_CAPITAL RussianEmpire Moscow
CHANGE_CAPITAL RussianEmpire SaintPetersburg
CHANGE_CAPITAL ColonialBrazil RioDeJaneiro
DUMP
RENAME ColonialBrazil EmpireOfBrazil
ABOUT RussianEmpire
RENAME EmpireOfBrazil UnitedStatesOfBrazil
CHANGE_CAPITAL RussianEmpire Petrograd
RENAME RussianEmpire RussianRepublic
RENAME RussianRepublic USSR
CHANGE_CAPITAL USSR Moscow
CHANGE_CAPITAL UnitedStatesOfBrazil Brasilia
RENAME UnitedStatesOfBrazil FederativeRepublicOfBrazil
ABOUT RussianEmpire
DUMP
RENAME USSR USSR
*/