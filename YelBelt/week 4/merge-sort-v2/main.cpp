#include <iostream>
#include <vector>
#include <algorithm>

template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  if (range_end - range_begin < 2) {
    return;
  }
  std::vector<typename RandomIt::value_type> elements(range_begin, range_end);
  auto part1 = elements.begin() + static_cast<int>(elements.size()) / 3;
  auto part2 = part1 + static_cast<int>(elements.size()) / 3;
  MergeSort(elements.begin(), part1);
  MergeSort(part1, part2);
  MergeSort(part2, elements.end());
  std::vector<typename RandomIt::value_type> temp;
  std::merge(elements.begin(), part1, part1, part2, std::back_inserter(temp));
  std::merge(temp.begin(), temp.end(), part2, elements.end(), range_begin);
}

int main() {
  std::vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSort(begin(v), end(v));

  return 0;
}
