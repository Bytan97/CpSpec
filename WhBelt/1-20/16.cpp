#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
  vector<int> result = v;
  reverse(begin(result), end(result));
  return result;
}

int main() {
  vector<int> a = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  vector<int> temp = Reversed(a);
  for (auto num : temp) {
    cout << num << " ";
  }

  return 0;
}