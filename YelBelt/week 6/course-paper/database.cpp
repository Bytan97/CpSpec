#include "database.h"

void Database::Add(const Date &date, const std::string &event) {
  if (!data_unique[date].count(event)) {
    data[date].push_back(event);
  }
  data_unique[date].insert(event);
}

void Database::Print(std::ostream &os) const {
  for (const auto &[key, value] : data) {
    for (const auto &event : value) {
      os << key << " " << event << std::endl;
    }
  }
}

std::string Database::Last(Date date) const {
  if (data.empty()) {
    throw std::invalid_argument("");
  }
  auto left = data.upper_bound(date);
  if (left == data.begin()) {
    throw std::invalid_argument("");
  }
  --left;
  if (left->first > date) {
    throw std::invalid_argument("");
  }

  std::ostringstream os;
  os << left->first << " " << left->second.back();
  return os.str();
}

int Database::RemoveIf(const std::function<bool(const Date &, const std::string &)> &predicate) {
  int cnt = 0;
  std::map<Date, std::vector<std::string>> updated_data;
  std::map<Date, std::set<std::string>> updated_unique_data;

  for (auto &events_date : data) {
    auto date = events_date.first;
    auto boundary = std::stable_partition(events_date.second.begin(),
                                          events_date.second.end(),
                                          [predicate, date](const auto &event) {
                                            return !predicate(date, event);
                                          });
    if (boundary != events_date.second.begin()) {
      updated_data[date] = std::vector<std::string>(events_date.second.begin(), boundary);
      updated_unique_data[date] = std::set<std::string>(events_date.second.begin(), boundary);
      cnt += static_cast<int>(events_date.second.size() - updated_data[date].size());
    } else {
      cnt += static_cast<int>(events_date.second.size());
    }
  }

  data = updated_data;
  data_unique = updated_unique_data;
  return cnt;
}

std::vector<std::pair<Date, std::string>> Database::FindIf(const std::function<bool(const Date &,
                                                                                    const std::string &)> &predicate) const {
  std::vector<std::pair<Date, std::string>> result;
  for (const auto &[date, events] : data) {
    for (const auto &event : events) {
      if (predicate(date, event)) {
        result.push_back({date, event});
      }
    }
  }
  return result;
}
std::ostream &operator<<(std::ostream &os, const std::pair<Date, std::string> &entry) {
  os << entry.first << " " << entry.second;
  return os;
}
