#pragma once

#include "date.h"

#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <ostream>
#include <functional>
#include <vector>
#include <algorithm>

class Database {
public:
  void Add(const Date &date, const std::string &event);

  void Print(std::ostream &os) const;

  std::string Last(Date date) const;

  int RemoveIf(const std::function<bool(const Date &, const std::string &)> &predicate);

  std::vector<std::pair<Date, std::string>> FindIf(const std::function<bool(const Date &,
                                                                            const std::string &)> &predicate) const;

private:
  std::map<Date, std::set<std::string>> data_unique;
  std::map<Date, std::vector<std::string>> data;
};

std::ostream &operator<<(std::ostream &os, const std::pair<Date, std::string> &entry);