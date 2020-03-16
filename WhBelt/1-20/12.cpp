#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool IsPalindrom(string word) {
  if (word == "") {
    return true;
  }
  string temp = word;
  reverse(temp.begin(), temp.end());
  if (temp == word) {
    return true;
  } else {
    return false;
  }
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
  vector<string> results;
  for (auto word : words) {
    if (IsPalindrom(word) and word.size() >= minLength) {
      results.push_back(word);
    }
  }
  return results;
}

int main() {
  vector<string> words = {"weew", "bro", "code"};
  words = PalindromFilter(words, 4);
  for (auto word : words) {
    cout << word << " ";
  }

  return 0;
}