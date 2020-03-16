#include <iostream>

int main() {
  int N;
  uint64_t R, W, H, D;
  uint64_t sum = 0;
  std::cin >> N >> R;
  for (int i = 0; i < N; ++i) {
    std::cin >> W >> H >> D;
    sum += R * W * H * D;
  }
  std::cout << sum << std::endl;
  return 0;
}