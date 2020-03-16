#include <iostream>
#include <set>

using namespace std;
int main() {
  int string_counts;
  cin >> string_counts;
  set<string> unique_string;
  for (int i = 0; i < string_counts; ++i) {
    string temp;
    cin >> temp;
    unique_string.insert(temp);
  }
  cout << unique_string.size() << endl;

  return 0;
}