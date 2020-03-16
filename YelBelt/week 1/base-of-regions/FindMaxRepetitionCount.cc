#include <algorithm>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

enum class Lang { DE, FR, IT };

struct Region {
  std::string std_name;
  std::string parent_std_name;
  std::map<Lang, std::string> names;
  int64_t population;
};

auto Calc(const Region &r) {
  return std::tie(r.std_name, r.parent_std_name, r.names, r.population);
}

bool operator==(const Region &lhs, const Region &rhs) {
  return Calc(lhs) == Calc(rhs);
}

int FindMaxRepetitionCount(const std::vector<Region> &regions) {
  if (regions.size() == 0) {
    return 0;
  }
  int max_rep = 1;
  for (const auto &reg : regions) {
    int temp = std::count(regions.begin(), regions.end(), reg);
    if (temp > max_rep) {
      max_rep = temp;
    }
  }
  return max_rep;
}

int main() {
  std::cout
      << FindMaxRepetitionCount({
             {"Moscow",
              "Russia",
              {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
              89},
             {"Russia",
              "Eurasia",
              {{Lang::DE, "Russland"},
               {Lang::FR, "Russie"},
               {Lang::IT, "Russia"}},
              89},
             {"Moscow",
              "Russia",
              {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
              89},
             {"Moscow",
              "Russia",
              {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
              89},
             {"Russia",
              "Eurasia",
              {{Lang::DE, "Russland"},
               {Lang::FR, "Russie"},
               {Lang::IT, "Russia"}},
              89},
         })
      << std::endl;

  std::cout
      << FindMaxRepetitionCount({
             {"Moscow",
              "Russia",
              {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
              89},
             {"Russia",
              "Eurasia",
              {{Lang::DE, "Russland"},
               {Lang::FR, "Russie"},
               {Lang::IT, "Russia"}},
              89},
             {"Moscow",
              "Russia",
              {{Lang::DE, "Moskau"},
               {Lang::FR, "Moscou deux"},
               {Lang::IT, "Mosca"}},
              89},
             {"Moscow",
              "Toulouse",
              {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
              89},
             {"Moscow",
              "Russia",
              {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
              31},
         })
      << std::endl;

  return 0;
}