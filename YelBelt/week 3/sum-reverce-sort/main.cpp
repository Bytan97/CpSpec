#include <iostream>
#include "sum_reverse_sort.h"
#include "TestRunner.h"

void testSum() {
  AssertEqual(Sum(0, 0), 0, "test 0 + 0");
  AssertEqual(Sum(0, 1), 1, "test 0 + 1");
  AssertEqual(Sum(1, 0), 1, "test 1 + 0");
  AssertEqual(Sum(1, 1), 2, "test 1 + 0");
}
void testReverse() {
  AssertEqual(Reverse("ab"), std::string("ba"), "test ab == ba");
  AssertEqual(Reverse(""), std::string(""), "test  == ");
  AssertEqual(Reverse("a"), "a", "test  a == a");
  AssertEqual(Reverse("abbes"), "sebba", "test  abbes == sebba");
}
void testSort(){
  vector<int> a = {2, 1, 3, 4, 0};
  vector<int> expected = {0, 1, 2, 3, 4};
  Sort(a);
  AssertEqual(a, expected, "test sort");
}

int main() {
  TestRunner tr;
  tr.RunTest(testSum, "test sum");
  tr.RunTest(testReverse, "test reverse");
  tr.RunTest(testSort, "test sort");
  
  return 0;
}
