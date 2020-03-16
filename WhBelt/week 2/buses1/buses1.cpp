#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int nums;
  cin >> nums;

  map<string, vector<string>> buses;
  vector<string> buses_unordered;

  for (int i = 0; i <= nums; ++i) {
    string command;
    cin >> command;
    if (command == "NEW_BUS") {
      string bus;
      int stop_counts;
      cin >> bus >> stop_counts;
      buses_unordered.push_back(bus);
      for (int j = 0; j < stop_counts; ++j) {
        string temp_stop;
        cin >> temp_stop;
        buses[bus].push_back(temp_stop);
      }

    } else if (command == "BUSES_FOR_STOP") {
      if (buses.size() == 0) {
        cout << "No stop" << endl;
      } else {
        string stop;
        cin >> stop;
        for (const string& bus : buses_unordered) {
          auto stops = buses[bus];
          auto it = find(stops.begin(), stops.end(), stop);
          if (it != stops.end()) {
            cout << bus << " ";
          }
        }
        cout << endl;
      }

    } else if (command == "STOPS_FOR_BUS") {
      string bus;
      cin >> bus;

      if (buses.count(bus) == 0) {
        cout << "No bus" << endl;
      } else {
        vector<string> stops = buses[bus];
        for (const string& stop : stops) {
          cout << "Stop " << stop << ": ";
          vector<string> cout_buses;
          for (const string& cur_bus : buses_unordered) {
            if (cur_bus != bus) {
              vector<string> cur_stops = buses[cur_bus];
              auto it = find(cur_stops.begin(), cur_stops.end(), stop);
              if (it != cur_stops.end()) {
                cout_buses.push_back(cur_bus);
              }
            }
          }
          if (cout_buses.empty()) {
            cout << "no interchange";
          } else {
            for (const string& cb : cout_buses) {
              cout << cb << " ";
            }
          }
          cout << endl;
        }
      }

    } else if (command == "ALL_BUSES") {
      // cout << " **** ALL BUSES **** " << endl;
      if (buses.size() == 0) {
        cout << "No buses" << endl;
      } else {
        for (const auto& [bus, stops] : buses) {
          cout << "Bus " << bus << ": ";
          for (const auto& stop : stops) {
            cout << stop << " ";
          }
          cout << endl;
        }
      }
    }
  }

  return 0;
}