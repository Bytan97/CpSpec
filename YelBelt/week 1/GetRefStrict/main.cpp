#include <iostream>
#include <map>

using namespace std;

template<typename first, typename second>
second &GetRefStrict(map<first, second> &m, first key) {
  if (m.count(key)) {
    return m[key];
  }
  throw runtime_error("Value not exist");
}

//int main() {
//  try {
//    map<int, string> m = {{0, "value"}};
//    string &item = GetRefStrict(m, 1);
//    item = "newvalue";
//    cout << m[0] << endl;
//  } catch (const runtime_error &er) {
//    cout << er.what() << endl;
//  }
//
//  return 0;
//}
