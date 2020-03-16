#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
int main() {
  int N;
  cin >> N;

  map<string, vector<string>> buses;
  map<string, vector<string>> stops;
  vector<string> buses_order;

  for (int i = 0; i < N; ++i) {
    string command;
    cin >> command;
    if (command == "ALL_BUSES") {
      if (buses.empty()) {
        cout << "No buses" << endl;
      } else {
        for (const auto& [key, value] : buses) {
          cout << "Bus " << key << ": ";
          for (const string& s : value) {
            cout << s << " ";
          }
          cout << endl;
        }
      }
    } else if (command == "NEW_BUS") {
      string new_bus;
      int stops_count;
      cin >> new_bus >> stops_count;
      buses_order.push_back(new_bus);
      for (int i = 0; i < stops_count; ++i) {
        string temp_stop;
        cin >> temp_stop;
        buses[new_bus].push_back(temp_stop);
        stops[temp_stop].push_back(new_bus);
      }
    } else if (command == "BUSES_FOR_STOP") {
      string stop;
      cin >> stop;
      if (stops.count(stop) == 0) {
        cout << "No stop" << endl;
      } else {
        for (const auto& b : stops[stop]) {
          cout << b << " ";
        }
        cout << endl;
      }
    } else if (command == "STOPS_FOR_BUS") {
      string bus;
      cin >> bus;
      if (buses.count(bus) == 0) {
        cout << "No bus" << endl;
      } else {
        auto stops_for_bus = buses[bus];
        for (const auto& stop : stops_for_bus) {
          auto cur_buses = stops[stop];
          cout << "Stop " << stop << ": ";
          string to_cout = "";
          for (const string& b : buses_order) {
            if (count(begin(cur_buses), end(cur_buses), b) and b != bus) {
              to_cout += b + " ";
            }
          }
          if (to_cout.empty()) {
            cout << "no interchange" << endl;
          } else {
            cout << to_cout << endl;
          }
        }
      }
    }
  }

  return 0;
}