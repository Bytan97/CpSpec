#include <algorithm>
#include <iostream>
#include <string>

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

int main() {
  string input;
  cin >> input;
  cout << IsPalindrom(input);
  return 0;
}