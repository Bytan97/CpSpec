#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
  int Q;
  cin >> Q;
  set<set<string>> dictionary;
  map<string, int> counts;

  for (int i = 0; i < Q; ++i) {
    string command;
    cin >> command;
    if (command == "ADD") {
      string word1, word2;
      cin >> word1 >> word2;
      if (dictionary.count({word1, word2}) == 0) {
        dictionary.insert({word1, word2});
        ++counts[word1];
        ++counts[word2];
      }
    } else if (command == "COUNT") {
      string word;
      cin >> word;
      cout << counts[word] << endl;
    } else if (command == "CHECK") {
      string word1, word2;
      cin >> word1 >> word2;
      if (dictionary.count({word1, word2})) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}