#include <map>
#include <iostream>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template<class T>
ostream &operator<<(ostream &os, const vector<T> &s) {
  os << "{";
  bool first = true;
  for (const auto &x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template<class T>
ostream &operator<<(ostream &os, const set<T> &s) {
  os << "{";
  bool first = true;
  for (const auto &x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template<class K, class V>
ostream &operator<<(ostream &os, const map<K, V> &m) {
  os << "{";
  bool first = true;
  for (const auto &kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T &t, const U &u, const string &hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string &hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
 public:
  template<class TestFunc>
  void RunTest(TestFunc func, const string &test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception &e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

 private:
  int fail_count = 0;
};

int GetDistinctRealRootCount(double a, double b, double c) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
  return 0;
}
void TestCzerro() {
  {
    int expected = 2;
    AssertEqual(GetDistinctRealRootCount(3, 1, 0), expected);
  }
  {
    int expected = 2;
    AssertEqual(GetDistinctRealRootCount(3, 3, 0), expected);
  }
  {
    int expected = 2;
    AssertEqual(GetDistinctRealRootCount(3, 5, 0), expected);
  }
  {
    int expected = 2;
    AssertEqual(GetDistinctRealRootCount(-3, 3, 0), expected);
  }
  {
    int expected = 2;
    AssertEqual(GetDistinctRealRootCount(-3, -3, 0), expected);
  }
  {
    int expected = 2;
    AssertEqual(GetDistinctRealRootCount(3, -3, 0), expected);
  }
}
void TestBzerro() {
  {
    int expected = 0;
    AssertEqual(GetDistinctRealRootCount(1, 0, 1), expected);
  }
  {
    int expected = 0;
    AssertEqual(GetDistinctRealRootCount(1, 0, 2), expected);
  }
  {
    int expected = 0;
    AssertEqual(GetDistinctRealRootCount(2, 0, 1), expected);
  }
  {
    int expected = 2;
    AssertEqual(GetDistinctRealRootCount(-1, 0, 1), expected);
  }
  {
    int expected = 2;
    AssertEqual(GetDistinctRealRootCount(1, 0, -1), expected);
  }
  {
    int expected = 0;
    AssertEqual(GetDistinctRealRootCount(-1, 0, -1), expected);
  }
}
void TestAzerro() {
  {
    int expected = 1;
    AssertEqual(GetDistinctRealRootCount(0, 1, 1), expected);
  }
  {
    int expected = 1;
    AssertEqual(GetDistinctRealRootCount(0, 1, 2), expected);
  }
  {
    int expected = 1;
    AssertEqual(GetDistinctRealRootCount(0, 2, 1), expected);
  }
  {
    int expected = 1;
    AssertEqual(GetDistinctRealRootCount(0, 1, -1), expected);
  }
  {
    int expected = 1;
    AssertEqual(GetDistinctRealRootCount(0, -1, 1), expected);
  }
  {
    int expected = 1;
    AssertEqual(GetDistinctRealRootCount(0, -1, -1), expected);
  }
}
void TestSeveralZerro() {
  {
    int expected = 0;
    AssertEqual(GetDistinctRealRootCount(0, 0, 1), expected);
  }
  {
    int expected = 0;
    AssertEqual(GetDistinctRealRootCount(0, 0, -1), expected);
  }
  {
    int expected = 1;
    AssertEqual(GetDistinctRealRootCount(0, 1, 0), expected);
  }
  {
    int expected = 1;
    AssertEqual(GetDistinctRealRootCount(0, -1, 0), expected);
  }
  {
    int expected = 1;
    AssertEqual(GetDistinctRealRootCount(1, 0, 0), expected);
  }
  {
    int expected = 1;
    AssertEqual(GetDistinctRealRootCount(-1, 0, 0), expected);
  }

}

int main() {
  TestRunner runner;
  runner.RunTest(TestAzerro, "test a");
  runner.RunTest(TestBzerro, "test b");
  runner.RunTest(TestCzerro, "test c");
  runner.RunTest(TestSeveralZerro, "test several");
  return 0;
}
