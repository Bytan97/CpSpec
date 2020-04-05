void Tests() {
  AssertEqual(IsPalindrom(""), true);
  AssertEqual(IsPalindrom(" "), true);
  AssertEqual(IsPalindrom("  "), true);
  AssertEqual(IsPalindrom("madam"), true);
  AssertEqual(IsPalindrom("maddam"), true);
  AssertEqual(IsPalindrom(" maddam "), true);
  AssertEqual(IsPalindrom("matddam"), false);
  AssertEqual(IsPalindrom("maddtam"), false);
  AssertEqual(IsPalindrom("saddam"), false);
  AssertEqual(IsPalindrom("maddas"), false);
  AssertEqual(IsPalindrom("ma d das"), false);
  AssertEqual(IsPalindrom(" madam"), false);
  AssertEqual(IsPalindrom("madam "), false);
  AssertEqual(IsPalindrom("123"), false);
  AssertEqual(IsPalindrom("123 "), false);
  AssertEqual(IsPalindrom(" 123 "), false);
  AssertEqual(IsPalindrom(" 123"), false);
  AssertEqual(IsPalindrom("777"), true);
}
