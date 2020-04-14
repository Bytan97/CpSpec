#include "sum_reverse_sort.h"
#include <algorithm>

int Sum(int x, int y) {
  return x + y;
}
std::string Reverse(std::string s) {
  if (s.empty()){
    return s;
  }
  for (size_t i = 0, j = s.size() - 1; i < j; ++i, --j) {
    int temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
  return s;
}
void Sort(std::vector<int> &nums) {
  std::sort(nums.begin(), nums.end());
}
