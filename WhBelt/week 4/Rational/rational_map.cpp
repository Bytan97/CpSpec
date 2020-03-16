#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
class Rational {
public:
  Rational() {
    p = 0;
    q = 1;
  }

  Rational(int numerator, int denominator) {
    int sign = numerator * denominator;
    numerator = numerator > 0 ? numerator : -numerator;
    denominator = denominator > 0 ? denominator : -denominator;
    int g = gcd(numerator, denominator);
    if (sign == 0) {
      p = 0;
      q = 1;
    }
    if (sign < 0) {
      p = -numerator / g;
      q = denominator / g;
    }
    if (sign > 0) {
      p = numerator / g;
      q = denominator / g;
    }
  }

  int Numerator() const { return p; }
  int Denominator() const { return q; }
  void SetNumerator(int new_p) { p = new_p; }
  void SetDenominator(int new_q) { q = new_q; }

private:
  int p;
  int q;
  int gcd(int a, int b) {
    if (a < b) {
      int temp = a;
      a = b;
      b = temp;
    }
    while (b != 0) {
      int remainder = a % b;
      a = b;
      b = remainder;
    }
    return a;
  }
};
bool operator==(const Rational &lhs, const Rational &rhs) {
  return lhs.Numerator() * rhs.Denominator() ==
         rhs.Numerator() * lhs.Denominator();
}

ostream &operator<<(ostream &stream, const Rational &r) {
  stream << r.Numerator() << "/" << r.Denominator();
  return stream;
}
// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а
bool operator<(const Rational &lhs, const Rational &rhs) {
  int p1 = lhs.Numerator() * rhs.Denominator();
  int p2 = rhs.Numerator() * lhs.Denominator();
  return p1 < p2 ? true : false;
}

int main() {
  {
    const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
    if (rs.size() != 3) {
      cout << "Wrong amount of items in the set" << endl;
      return 1;
    }

    vector<Rational> v;
    for (auto x : rs) {
      v.push_back(x);
    }
    if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
      cout << "Rationals comparison works incorrectly" << endl;
      return 2;
    }
  }

  {
    map<Rational, int> count;
    ++count[{1, 2}];
    ++count[{1, 2}];

    ++count[{2, 3}];

    if (count.size() != 2) {
      cout << "Wrong amount of items in the map" << endl;
      return 3;
    }
  }

  cout << "OK" << endl;
  return 0;
}
