#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

void Print(vector<string> vec) {
  for (const auto& v : vec) {
    cout << v << " ";
  }
  cout << endl;
}

string str_tolower(string s) {
  transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c) { return tolower(c); });
  return s;
}

int main() {
  int size;
  vector<string> vec;
  cin >> size;
  for (int i = 0; i < size; ++i) {
    string temp;
    cin >> temp;
    vec.push_back(temp);
  }
  sort(begin(vec), end(vec), [](string a, string b) {
    string tempa = str_tolower(a), tempb = str_tolower(b);
    return tempa < tempb;
  });
  Print(vec);

  return 0;
}