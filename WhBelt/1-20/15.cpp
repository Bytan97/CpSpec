#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v) { reverse(begin(v), end(v)); }

int main() {
  vector<int> a = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  Reverse(a);
  for (auto num : a) {
    cout << num << " ";
  }

  return 0;
}