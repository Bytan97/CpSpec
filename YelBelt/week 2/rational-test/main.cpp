void TestRational() {
  {
    Rational r;
    int expected_num = 0, expected_den = 1;
    AssertEqual(r.Numerator(), expected_num);
    AssertEqual(r.Denominator(), expected_den);
  }
  {
    Rational r(1, 3);
    int expected_num = 1, expected_den = 3;
    AssertEqual(r.Numerator(), expected_num);
  }
  {
    Rational r(3, 3);
    int expected_num = 1, expected_den = 1;
    AssertEqual(r.Numerator(), expected_num);
    AssertEqual(r.Denominator(), expected_den);
  }
  {
    Rational r(-1, 3);
    int expected_num = -1, expected_den = 3;
    AssertEqual(r.Numerator(), expected_num);
    AssertEqual(r.Denominator(), expected_den);
  }
  {
    Rational r(1, -3);
    int expected_num = -1, expected_den = 3;
    AssertEqual(r.Numerator(), expected_num);
    AssertEqual(r.Denominator(), expected_den);
  }
  {
    Rational r(-1, -3);
    int expected_num = 1, expected_den = 3;
    AssertEqual(r.Numerator(), expected_num);
    AssertEqual(r.Denominator(), expected_den);
  }
  {
    Rational r(0, -3);
    int expected_num = 0, expected_den = 1;
    AssertEqual(r.Numerator(), expected_num);
    AssertEqual(r.Denominator(), expected_den);
  }

}
