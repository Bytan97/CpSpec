#include "bus_manager.h"

void BusManager::AddBus(const string &bus, const vector<string> &stops) {
  buses_to_stops[bus] = stops;
  for (const string &s : stops) {
    stops_to_buses[s].push_back(bus);
  }
}
BusesForStopResponse BusManager::GetBusesForStop(const string &stop) const {
  BusesForStopResponse response;
  if (stops_to_buses.count(stop)) {
    response = {stop, stops_to_buses.at(stop)};
  } else {
    response = {"", {}};
  }
  return response;
}
StopsForBusResponse BusManager::GetStopsForBus(const string &bus) const {
  StopsForBusResponse response;
  if (buses_to_stops.count(bus)) {
    response = {bus, buses_to_stops.at(bus), stops_to_buses};
  } else {
    response = {"", {}, {}};
  }
  return response;
}
AllBusesResponse BusManager::GetAllBuses() const {
  return {buses_to_stops};
}


