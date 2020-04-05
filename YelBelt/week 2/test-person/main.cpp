void TestGetFullName() {
  {
    Person p;
    string expected = "Incognito";
    AssertEqual(p.GetFullName(1990), expected);
  }
  {
    Person p;
    p.ChangeFirstName(1990, "f1");
    string expected = "f1 with unknown last name";
    AssertEqual(p.GetFullName(1990), expected);
  }
  {
    Person p;
    p.ChangeFirstName(1990, "f1");
    p.ChangeLastName(1990, "l1");
    string expected = "f1 l1";
    AssertEqual(p.GetFullName(1990), expected);
  }
  {
    Person p;
    p.ChangeLastName(1990, "l1");
    string expected = "l1 with unknown first name";
    AssertEqual(p.GetFullName(1990), expected);
  }

}
