#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

template<typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const std::string &prefix) {
  auto it_begin = std::upper_bound(range_begin, range_end, prefix, [](std::string pref, std::string s){
    std::string temp(s.begin(), s.begin() + pref.size());
    pref.back()--;
    return temp > pref;
  });
  auto it_end = std::lower_bound(range_begin, range_end, prefix, [](std::string s, const std::string &pref) {
      std::string temp(s.begin(), s.begin() + pref.size());
      return temp <= pref;
  });

  return {it_begin, it_end};
}

int main() {
  const std::vector<std::string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
//  const std::vector<std::string> sorted_strings = {"moscow"};

  const auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "moscow");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  const auto mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
  std::cout << (mt_result.first - begin(sorted_strings)) << " " <<
            (mt_result.second - begin(sorted_strings)) << std::endl;

  const auto na_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
  std::cout << (na_result.first - begin(sorted_strings)) << " " <<
            (na_result.second - begin(sorted_strings)) << std::endl;

  return 0;
}
