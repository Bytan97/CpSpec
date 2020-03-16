#include <iostream>
#include <sstream>

using namespace std;

// один из способов вычисления наибольшего общего делителя (НОД) — рекурсивный:
// вместо цикла функция будет вызывать себя же, но с другими аргументами
int GreatestCommonDivisor(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return GreatestCommonDivisor(b, a % b);
  }
}

class Rational {
public:
  Rational() { // дробь по умолчанию — 0/1
    numerator = 0;
    denominator = 1;
  }
  Rational(int new_numerator, int new_denominator) {
    if (new_denominator == 0) {
      throw invalid_argument("Invalid argument");
    }
    const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
    // сократим дробь, разделив числитель и знаменатель на их НОД
    numerator = new_numerator / gcd;
    denominator = new_denominator / gcd;
    // знаменатель должен быть положительным
    if (denominator < 0) {
      denominator = -denominator;
      numerator = -numerator;
    }
  }

  int Numerator() const { return numerator; }

  int Denominator() const { return denominator; }

private:
  int numerator;
  int denominator;
};

// поскольку дроби сокращены, достаточно сравнить числители и знаменатели
bool operator==(const Rational &lhs, const Rational &rhs) {
  return lhs.Numerator() == rhs.Numerator() &&
         lhs.Denominator() == rhs.Denominator();
}

// используем обычную формулу сложения дробей, основанную на приведении
// слагаемых к общему знаменателю
Rational operator+(const Rational &lhs, const Rational &rhs) {
  return {lhs.Numerator() * rhs.Denominator() +
              rhs.Numerator() * lhs.Denominator(),
          lhs.Denominator() * rhs.Denominator()};
}

// вычитание реализуем аналогично сложению
// дублирования кода можно было избежать, определив для класса Rational операцию
// унарного минуса: тогда разность lhs и rhs можно было бы вычислить как lhs +
// (-rhs)
Rational operator-(const Rational &lhs, const Rational &rhs) {
  return {lhs.Numerator() * rhs.Denominator() -
              rhs.Numerator() * lhs.Denominator(),
          lhs.Denominator() * rhs.Denominator()};
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
  return {lhs.Numerator() * rhs.Numerator(),
          lhs.Denominator() * rhs.Denominator()};
}

// деление равносильно умножению на обратную («перевёрнутую») дробь
Rational operator/(const Rational &lhs, const Rational &rhs) {
  if (rhs.Numerator() == 0 or rhs.Denominator() == 0) {
    stringstream ss;
    ss << "Division by zero";
    throw domain_error(ss.str());
  }
  return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

istream &operator>>(istream &is, Rational &r) {
  int n, d;
  char c;

  if (is) {
    is >> n >> c >> d;
    if (is && c == '/') {
      r = Rational(n, d);
    }
  }

  return is;
}

ostream &operator<<(ostream &os, const Rational &r) {
  return os << r.Numerator() << '/' << r.Denominator();
}

// чтобы сравнить lhs с rhs, сравним их разность с нулём, что равносильно
// сравнению с нулём числителя
bool operator<(const Rational &lhs, const Rational &rhs) {
  return (lhs - rhs).Numerator() < 0;
}

int main() {
  try {
    Rational f1, f2;
    char command;
    cin >> f1 >> command >> f2;

    if (command == '+') {
      cout << f1 + f2 << endl;
    } else if (command == '-') {
      cout << f1 - f2 << endl;
    } else if (command == '/') {
      cout << f1 / f2 << endl;
    } else if (command == '*') {
      cout << f1 * f2 << endl;
    }
  } catch (const invalid_argument &arg) {
    cout << arg.what() << endl;
  } catch (const domain_error &de) {
    cout << de.what() << endl;
  }

  return 0;
}
