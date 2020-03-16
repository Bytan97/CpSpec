#include <iostream>

using namespace std;

int main() {
  double N, A, B, X, Y;
  cin >> N >> A >> B >> X >> Y;
  if (N > A and N <= B) {
    cout << N - N * X / 100;
  } else if (N > B) {
    cout << N - N * Y / 100;
  } else {
    cout << N;
  }
  return 0;
}