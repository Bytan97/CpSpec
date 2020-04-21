#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int N = 0;
  std::cin >> N;
  std::vector<int> v(N);
  std::generate(v.begin(), v.end(), [n = 1]() mutable { return n++; });
  do {
    std::cout << std::endl;
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
      std::cout << *it << " ";
    }
  } while (std::prev_permutation(v.rbegin(), v.rend()));

  return 0;
}
