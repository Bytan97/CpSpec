#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

struct BusesForStopResponse {
  string stop;
  vector<string> buses;
};

ostream &operator<<(ostream &os, const BusesForStopResponse &r);

struct StopsForBusResponse {
  string bus;
  vector<string> stops;
  map<string, vector<string>> stb;
};
ostream &operator<<(ostream &os, const StopsForBusResponse &r);

struct AllBusesResponse {
  map<string, vector<string>> bts;
};
ostream &operator<<(ostream &os, const AllBusesResponse &r);