#include <iostream>
#include <vector>
#include <algorithm>

template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  if (range_end - range_begin < 2) {
    return;
  }
  std::vector<typename RandomIt::value_type> elements(range_begin, range_end);
  auto middle = elements.begin() + static_cast<int>(elements.size()) / 2;
  MergeSort(elements.begin(), middle);
  MergeSort(middle, elements.end());

  std::merge(elements.begin(), middle, middle, elements.end(), range_begin);
}

int main() {
  std::cout << "Hello, World!" << std::endl;
  std::vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));

  return 0;
}
