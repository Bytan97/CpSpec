#include <iostream>
#include <vector>

int main() {
  long long N = 0, sum = 0, avr = 0;
  std::vector<long long> days;
  std::vector<size_t> result;
  std::cin >> N;
  if (N == 0) {
    return 0;
  }
  for (long long i = 0; i < N; ++i) {
    long long temp;
    std::cin >> temp;
    days.push_back(temp);
    sum += temp;
  }
  avr = sum / static_cast<long long>(days.size());
  for (size_t i = 0; i < days.size(); ++i) {
    if (days[i] > avr) {
      result.push_back(i);
    }
  }
  std::cout << result.size() << std::endl;
  for (const auto &r : result) {
    std::cout << r << " ";
  }
  std::cout << std::endl;
  return 0;
}