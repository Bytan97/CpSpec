#include <iostream>
using namespace std;

class Rational {
public:
  Rational() {
    p = 0;
    q = 1;
  }

  Rational(long numerator, long denominator) {
    long long sign = numerator * denominator;
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
// Реализуйте для класса Rational операторы ==, + и -
Rational operator+(const Rational &lhs, const Rational &rhs) {
  int p =
      lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
  int q = rhs.Denominator() * lhs.Denominator();
  return Rational(p, q);
}
Rational operator-(const Rational &lhs, const Rational &rhs) {
  int p =
      lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
  int q = rhs.Denominator() * lhs.Denominator();
  return Rational(p, q);
}
bool operator==(const Rational &lhs, const Rational &rhs) {
  return lhs.Numerator() * rhs.Denominator() ==
         rhs.Numerator() * lhs.Denominator();
}
Rational operator*(const Rational &lhs, const Rational &rhs) {
  int p = lhs.Numerator() * rhs.Numerator();
  int q = lhs.Denominator() * rhs.Denominator();
  return Rational(p, q);
}
Rational operator/(const Rational &lhs, const Rational &rhs) {
  int p = lhs.Numerator() * rhs.Denominator();
  int q = lhs.Denominator() * rhs.Numerator();
  return Rational(p, q);
}

int main() {
  {
    Rational a(2, 3);
    Rational b(4, 3);
    Rational c = a * b;
    bool equal = c == Rational(8, 9);
    if (!equal) {
      cout << "2/3 * 4/3 != 8/9" << endl;
      return 1;
    }
  }
  {
    Rational a(2, -3);
    Rational b(4, -3);
    Rational c = a * b;
    bool equal = c == Rational(8, 9);
    if (!equal) {
      cout << "2/3 * 4/3 != 8/9" << endl;
      return 1;
    }
  }

  {
    Rational a(5, 4);
    Rational b(15, 8);
    Rational c = a / b;
    bool equal = c == Rational(2, 3);
    if (!equal) {
      cout << "5/4 / 15/8 != 2/3" << endl;
      return 2;
    }
  }

  cout << "OK" << endl;
  return 0;
}
