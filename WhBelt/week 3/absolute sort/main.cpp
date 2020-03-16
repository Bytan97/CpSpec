#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool exch(int x, int y) { return abs(x) < abs(y); }
void Print(vector<int> vec) {
  for (const auto& v : vec) {
    cout << v << " ";
  }
  cout << endl;
}

int main() {
  int size;
  vector<int> to_sort;
  cin >> size;
  for (int i = 0; i < size; ++i) {
    int temp;
    cin >> temp;
    to_sort.push_back(temp);
  }
  //   Print(to_sort);
  sort(begin(to_sort), end(to_sort), exch);
  Print(to_sort);
  return 0;
}