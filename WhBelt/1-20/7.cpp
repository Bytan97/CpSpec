#include <iostream>
#include <string>

using namespace std;

int main() {
  string word;
  cin >> word;
  int counter = 0;
  for (int i = 0; i <= word.size(); ++i) {
    if (word[i] == 'f') {
      counter += 1;
    }
    if (counter == 2) {
      cout << i;
      break;
    }
  }
  if (counter == 1) {
    cout << -1;
  }
  if (counter == 0) {
    cout << -2;
  }
  return 0;
}