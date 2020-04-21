#include <iostream>
#include <vector>

void PrintVectorPart(const std::vector<int> &numbers);

int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  std::cout << std::endl;
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  std::cout << std::endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  std::cout << std::endl;
//  PrintVectorPart({});
//  std::cout << std::endl;
  PrintVectorPart({0,0,0,0,1,-1});
  std::cout << std::endl;
  return 0;
}

void PrintVectorPart(const std::vector<int> &numbers) {
  auto it = numbers.begin();
  while (it != numbers.end() and *it >= 0) {
    ++it;
  }
  while(it != numbers.begin()){
    --it;
    std::cout << *it << " ";
  }
}

