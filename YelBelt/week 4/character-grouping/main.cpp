#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

template<typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix) {
  auto it_begin = std::upper_bound(range_begin, range_end, prefix, [](auto c, auto s) {
    return s[0] > static_cast<char>(c - 1);
  });
  auto it_end = std::lower_bound(range_begin, range_end, prefix, [](auto s, auto c) {
    return s[0] <= c;
  });

  return {it_begin, it_end};
}

int main() {
//  const std::vector<std::string> sorted_strings = {"moscow", "murmansk", "vologda"};
  const std::vector<std::string> sorted_strings = {"moscow"};
  const auto m_result = FindStartsWith(std::begin(sorted_strings), std::end(sorted_strings), 'm');
  for (auto it = m_result.first; it != m_result.second; ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  const auto p_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'a');
  std::cout << (p_result.first - begin(sorted_strings)) << " " <<
            (p_result.second - begin(sorted_strings)) << std::endl;

  const auto z_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
  std::cout << (z_result.first - begin(sorted_strings)) << " " <<
            (z_result.second - begin(sorted_strings)) << std::endl;

  return 0;
}
