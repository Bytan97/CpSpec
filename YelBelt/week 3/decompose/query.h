#pragma once
#include <string>
#include <vector>
#include <iostream>

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
//bool operator==(const Query &lhs, const Query &rhs) {
//  return tie(lhs.type, lhs.bus, lhs.stop, lhs.stops) == tie(rhs.type, rhs.bus, rhs.stop, rhs.stops);
//}
istream &operator>>(istream &is, Query &q);