#include "query.h"

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