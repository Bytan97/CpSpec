#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream input("input.txt");
  if (input) {
    int N, M;
    input >> N >> M;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M - 1; ++j) {
        int temp;
        input >> temp;
        std::cout << std::setw(10) << temp << " ";
        input.ignore(1);
      }
      int temp;
      input >> temp;
      std::cout << std::setw(10) << temp << std::endl;
    }
  }

  return 0;
}