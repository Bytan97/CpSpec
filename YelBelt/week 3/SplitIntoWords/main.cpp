#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> SplitIntoWords(const std::string &s);

int main() {
  std::string s = "C Cpp Java Python";

  std::vector<std::string> words = SplitIntoWords(s);
  std::cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      std::cout << "/";
    }
    std::cout << *it;
  }
  std::cout << std::endl;

  return 0;
}

std::vector<std::string> SplitIntoWords(const std::string &s) {
  std::vector<std::string> result;
  auto cur_it = s.begin();

  while (true) {
    auto next_it = std::find(cur_it, s.end(), ' ');
    result.push_back(std::string(cur_it, next_it));
    if (next_it != s.end()) {
      cur_it = ++next_it;
    } else {
      break;
    }
  }

  return result;
}