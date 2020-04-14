#include <iostream>
#include "TestRunner.h"
#include "phone_number.h"

void testCotructor() {
  try {
    PhoneNumber ph1("+7-925-aba");
    PhoneNumber ph2("+7-925-3333--3--3123123-33");
    PhoneNumber ph3("7-925-333");
    PhoneNumber ph4("+7-1233");
  } catch (invalid_argument &arg) {
    cout << arg.what() << endl;
  }
}
void testGets() {
  {
    PhoneNumber ph1("+7-923-1233311");
    AssertEqual(ph1.GetInternationalNumber(), "+7-923-1233311", "test1");
    AssertEqual(ph1.GetCountryCode(), "7", "test2");
    AssertEqual(ph1.GetCityCode(), "923", "test3");
    AssertEqual(ph1.GetLocalNumber(), "1233311", "test4");
  }
}

int main() {
  TestRunner tr;
  tr.RunTest(testCotructor, "Constructor Test");
  tr.RunTest(testGets, "Gets Tests");

  return 0;
}
