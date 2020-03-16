#include <iostream>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string &word) {
  map<char, int> result;
  for (const char &w : word) {
    ++result[w];
  }
  return result;
}

int main() {
  int num;
  cin >> num;
  for (int i = 0; i < num; ++i) {
    string word1, word2;
    cin >> word1 >> word2;
    auto m1 = BuildCharCounters(word1);
    auto m2 = BuildCharCounters(word2);
    if (m1 == m2) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}