#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Date {
private:
  int day;
  int month;
  int year;

public:
  Date(string date) {
    stringstream ss(date);
    char d1, d2;
    int y, m, d;
    ss >> y >> d1 >> m >> d2 >> d;
    if (d1 != '-' or d2 != '-' or ss.fail() or ss.peek() != EOF) {
      throw invalid_argument("Wrong date format: " + date);
    }
    if (m <= 0 or m > 12) {
      throw invalid_argument("Month value is invalid: " + to_string(m));
    }
    if (d <= 0 or d > 31) {
      throw invalid_argument("Day value is invalid: " + to_string(d));
    }
    year = y;
    month = m;
    day = d;
  };

  int GetYear() const { return year; }

  int GetMonth() const { return month; }

  int GetDay() const { return day; }
};

bool operator<(const Date &lhs, const Date &rhs) {
  return (lhs.GetYear() * 10000 + lhs.GetMonth() * 100 + lhs.GetDay()) <
         (rhs.GetYear() * 10000 + rhs.GetMonth() * 100 + rhs.GetDay());
}

ostream &operator<<(ostream &stream, const Date &date) {
  stream << setfill('0') << setw(4) << date.GetYear() << "-" << setfill('0')
         << setw(2) << date.GetMonth() << "-" << setfill('0') << setw(2)
         << date.GetDay();
  return stream;
}

class Database {
private:
  map<Date, set<string>> data;

public:
  void AddEvent(const Date &date, const string &event) {
    data[date].insert(event);
  }

  void DeleteEvent(const Date &date, const string &event) {
    if (data.count(date)) {
      if (data[date].count(event)) {
        data[date].erase(event);
        cout << "Deleted successfully" << endl;
      } else {
        throw domain_error("Event not found");
      }
    } else {
      throw domain_error("Event not found");
    }
  }

  int DeleteDate(const Date &date) {
    if (data.count(date)) {
      int n = data[date].size();
      data.erase(date);
      return n;
    } else {
      return 0;
    }
  }

  auto Find(const Date &date) const { return data.at(date); }

  void Print() const {
    for (const auto &[key, value] : data) {
      for (const auto &event : value) {
        cout << key << " " << event << endl;
      }
    }
  }
};

int main() {
  Database db;
  string command;
  while (getline(cin, command)) {
    stringstream ss(command);
    string cmd, date, event;
    ss >> cmd >> date >> event;
    if (cmd == "Print") {
      db.Print();
    } else if (cmd == "Add" or cmd == "Del" or cmd == "Find") {
      try {
        Date temp(date);
        if (cmd == "Add") {
          db.AddEvent(date, event);
        }
        if (cmd == "Del") {
          if (event == "") {
            int n = db.DeleteDate(date);
            cout << "Deleted " << n << " events" << endl;
          } else {
            db.DeleteEvent(temp, event);
          }
        }
        if (cmd == "Find") {
          try {
            auto f = db.Find(date);
            for (const auto &event : f) {
              cout << event << endl;
            }
          } catch (const exception &ex) {
          }
        }
      } catch (const invalid_argument &iarg) {
        cout << iarg.what() << endl;
      } catch (const domain_error &derr) {
        cout << derr.what() << endl;
      }
    } else if (cmd != "") {
      cout << "Unknown command: " << cmd << endl;
    }
  }

  return 0;
}