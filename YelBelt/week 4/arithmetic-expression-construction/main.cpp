#include <iostream>
#include <deque>

int main() {
  std::string def_value;
  std::cin >> def_value;
  int operations_count;
  std::cin >> operations_count;
  if (operations_count == 0) {
    std::cout << def_value;
  } else {
    std::deque<std::string> res;
    res.push_front("(");
    res.push_back(def_value);
    res.push_back(")");
    char sign;
    int num;
    for (int i = 0; i < operations_count - 1; ++i) {
      std::cin >> sign >> num;
      res.push_front("(");
      res.push_back(" " + std::string(1, sign) + " ");
      res.push_back(std::to_string(num));
      res.push_back(")");
    }
    std::cin >> sign >> num;
    res.push_back(" " + std::string(1, sign) + " ");
    res.push_back(std::to_string(num));
    while (!res.empty()) {
      std::cout << res.front();
      res.pop_front();
    }
  }
  return 0;
}
