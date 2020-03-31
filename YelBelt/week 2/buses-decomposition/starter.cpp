#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};
struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};
bool operator==(const Query &lhs, const Query &rhs) {
  return tie(lhs.type, lhs.bus, lhs.stop, lhs.stops) == tie(rhs.type, rhs.bus, rhs.stop, rhs.stops);
}
istream &operator>>(istream &is, Query &q) {
  q = {};
  string str_type;
  is >> str_type;

  if (str_type == "NEW_BUS") {
    q.type = QueryType::NewBus;
    is >> q.bus;
    int stops_count;
    is >> stops_count;
    for (int i = 0; i < stops_count; ++i) {
      string cur_stop;
      is >> cur_stop;
      q.stops.push_back(cur_stop);
    }
  } else if (str_type == "BUSES_FOR_STOP") {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
    return is;
  } else if (str_type == "STOPS_FOR_BUS") {
    q.type = QueryType::StopsForBus;
    is >> q.bus;
    return is;
  } else if (str_type == "ALL_BUSES") {
    q.type = QueryType::AllBuses;
    return is;
  }
  return is;
}

struct BusesForStopResponse {
  string stop;
  vector<string> buses;
};
ostream &operator<<(ostream &os, const BusesForStopResponse &r) {
  if (r.stop.empty()) {
    os << "No stop";
  } else {
    bool is_first = true;
    for (const string &bus : r.buses) {
      if (!is_first) {
        os << " ";
      }
      is_first = false;
      os << bus;
    }
  }
  return os;
}
struct StopsForBusResponse {
  string bus;
  vector<string> stops;
  map<string, vector<string>> stb;
};

ostream &operator<<(ostream &os, const StopsForBusResponse &r) {
  if (r.bus.empty()) {
    os << "No bus";
  } else {
    bool fline = true;
    for (const string &stop : r.stops) {
      if (!fline) {
        os << endl;
      }
      fline = false;
      os << "Stop " << stop << ": ";
      if (r.stb.at(stop).size() == 1) {
        os << "no interchange";
      } else {
        bool is_first = true;
        for (const string &other_bus : r.stb.at(stop)) {
          if (!is_first) {
            os << " ";
          }
          is_first = false;
          if (r.bus != other_bus) {
            os << other_bus;
          }
        }
      }
    }
  }
  return os;
}
struct AllBusesResponse {
  map<string, vector<string>> bts;
};
ostream &operator<<(ostream &os, const AllBusesResponse &r) {
  if (r.bts.empty()) {
    os << "No buses";
  } else {
    bool is_fline = true;
    for (const auto &b : r.bts) {
      if (!is_fline) {
        os << endl;
      }
      is_fline = false;
      os << "Bus " << b.first << ": ";
      bool is_first = true;
      for (const auto &s :b.second) {
        if (!is_first) {
          os << " ";
        }
        is_first = false;
        os << s;
      }
    }
  }
  return os;
}
class BusManager {
 private:
  map<string, vector<string>> buses_to_stops, stops_to_buses;
 public:
  void AddBus(const string &bus, const vector<string> &stops) {
    buses_to_stops[bus] = stops;
    for (const string &s : stops) {
      stops_to_buses[s].push_back(bus);
    }
  }
  BusesForStopResponse GetBusesForStop(const string &stop) const {
    BusesForStopResponse response;
    if (stops_to_buses.count(stop)) {
      response = {stop, stops_to_buses.at(stop)};
    } else {
      response = {"", {}};
    }
    return response;
  }
  StopsForBusResponse GetStopsForBus(const string &bus) const {
    StopsForBusResponse response;
    if (buses_to_stops.count(bus)) {
      response = {bus, buses_to_stops.at(bus), stops_to_buses};
    } else {
      response = {"", {}, {}};
    }
    return response;
  }
  AllBusesResponse GetAllBuses() const {
    return {buses_to_stops};
  }
};

int main() {
  int query_count;
  cin >> query_count;

  Query q;
  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
      case QueryType::NewBus:bm.AddBus(q.bus, q.stops);
        break;
      case QueryType::BusesForStop:cout << bm.GetBusesForStop(q.stop) << endl;
        break;
      case QueryType::StopsForBus:cout << bm.GetStopsForBus(q.bus) << endl;
        break;
      case QueryType::AllBuses:cout << bm.GetAllBuses() << endl;
        break;
    }
  }

  return 0;
}
