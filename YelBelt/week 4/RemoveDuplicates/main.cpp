#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void RemoveDuplicates(std::vector<T> &elements);

int main() {
  std::vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
  RemoveDuplicates(v1);
  for (int x : v1) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  std::vector<std::string> v2 = {"c", "c","c","c"};
  RemoveDuplicates(v2);
  for (const std::string &s : v2) {
    std::cout << s << " ";
  }
  std::cout << std::endl;
  return 0;
}
template<typename T>
void RemoveDuplicates(std::vector<T> &elements) {
  std::sort(elements.begin(), elements.end());
  elements.erase(std::unique(elements.begin(), elements.end()), elements.end());
}
