#include "responses.h"

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