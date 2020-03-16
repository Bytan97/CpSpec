#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  std::ifstream input("input.txt");
  std::cout << std::fixed << std::setprecision(3);
  if (input) {
    double line;
    while (input >> line) {
      std::cout << line << std::endl;
    }
  }
  return 0;
}