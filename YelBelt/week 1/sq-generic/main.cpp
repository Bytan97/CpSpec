#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <string>

using namespace std;
// ----------------------------------------- //
//template<typename First, typename Second>
//ostream &operator<<(ostream &out, const pair<First, Second> &p);
template<typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second> &lhs, const pair<First, Second> &rhs);
template<typename type>
vector<type> operator*(const vector<type> &lhs, const vector<type> &rhs);
template<typename First, typename Second>
map<First, Second> operator*(const map<First, Second> &lhs, const map<First, Second> &rhs);
// ----------------------------------------- //
//template<typename First, typename Second>
//ostream &operator<<(ostream &out, const pair<First, Second> &p) {
//  return out << "(" << p.first << ", " << p.second << ")";
//}
template<typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second> &lhs, const pair<First, Second> &rhs) {
  First f = lhs.first * rhs.first;
  Second s = lhs.second * rhs.second;
  return {f, s};
}

template<typename type>
vector<type> operator*(const vector<type> &lhs, const vector<type> &rhs) {
  vector<type> result(lhs.size());
  for (size_t i = 0; i < lhs.size(); ++i) {
    result[i] = lhs[i] * rhs[i];
  }
  return result;
}

template<typename First, typename Second>
map<First, Second> operator*(const map<First, Second> &lhs, const map<First, Second> &rhs) {
  map<First, Second> result(lhs);
  for (const auto elem : rhs) {
    auto sq = result[elem.first] * elem.second;
    result[elem.first] = sq;
  }
  return result;
}

template<typename type>
type Sqr(type x) {
  return x * x;
}

//int main() {
////  pair<int, int> p1{2, 2};
////  pair<int, int> p2{4, 3};
////  cout << p1 << " " << p2 << endl;
////  cout << p1 * p2 << endl;
////  cout << Sqr(p1) << endl;
////  cout << Sqr(p2) << endl;
//  vector<int> v = {1, 2, 3, 0, -1, -10};
//  cout << "vector:";
//  for (int x : Sqr(v)) {
//    cout << ' ' << x;
//  }
//  cout << endl;
//  map<int, pair<int, int>> map_of_pairs = {
//      {4, {2, 2}},
//      {7, {4, 3}}
//  };
//  cout << "map of pairs:" << endl;
//  for (const auto& x : Sqr(map_of_pairs)) {
//    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
//  }
//  return 0;
//}
