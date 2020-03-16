#include <iostream>
#include <sstream>
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
// Реализуйте для класса Rational операторы ==, + и -
bool operator==(const Rational &lhs, const Rational &rhs) {
  return lhs.Numerator() * rhs.Denominator() ==
         rhs.Numerator() * lhs.Denominator();
}

ostream &operator<<(ostream &stream, const Rational &r) {
  stream << r.Numerator() << "/" << r.Denominator();
  return stream;
}
istream &operator>>(istream &stream, Rational &r) {
  int p = 0, q = 1;
  stream >> p;
  stream.ignore(1);
  stream >> q;
  if (!stream) {
    return stream;
  }
  r.SetNumerator(p);
  r.SetDenominator(q);
  return stream;
}

int main() {
  {
    ostringstream output;
    output << Rational(-6, 8);
    if (output.str() != "-3/4") {
      cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
      return 1;
    }
  }

  {
    istringstream input("5/7");
    Rational r;
    input >> r;
    bool equal = r == Rational(5, 7);
    if (!equal) {
      cout << "5/7 is incorrectly read as " << r << endl;
      return 2;
    }
  }

  {
    istringstream input("5/7 10/8");
    Rational r1, r2;
    input >> r1 >> r2;
    bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
    if (!correct) {
      cout << "Multiple values are read incorrectly: " << r1 << " " << r2
           << endl;
      return 3;
    }
    input >> r1;
    input >> r2;
    correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
    if (!correct) {
      cout << "Read from empty stream shouldn't change arguments: " << r1 << " "
           << r2 << endl;
      return 4;
    }
  }

  cout << "OK" << endl;
  return 0;
}
