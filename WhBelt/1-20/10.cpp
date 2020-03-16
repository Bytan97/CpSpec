#include <iostream>

using namespace std;

int Factorial(int value) {
  if (value <= 0) {
    return 1;
  }
  if (value == 1) {
    return 1;
  } else {
    return value * Factorial(value - 1);
  }
}

int main() {
  int value;
  cin >> value;
  cout << Factorial(value);
  return 0;
}