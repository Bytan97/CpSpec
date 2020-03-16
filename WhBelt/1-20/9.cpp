#include <iostream>
#include <vector>

using namespace std;

int main() {
  int number;
  vector<int> binaryNumber;
  cin >> number;
  if (number > 0) {
    while (number >= 2) {
      binaryNumber.push_back(number % 2);
      number /= 2;
    }
    if (number > 0) {
      binaryNumber.push_back(number);
    }
    for (int i = binaryNumber.size() - 1; i >= 0; --i) {
      cout << binaryNumber[i];
    }
  } else {
    cout << 0;
  }

  return 0;
}