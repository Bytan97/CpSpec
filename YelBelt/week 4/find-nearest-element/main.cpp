#include <iostream>
#include <set>

std::set<int>::const_iterator FindNearestElement(const std::set<int> &numbers, int border) {
  auto lb = numbers.lower_bound(border);
  if (lb == numbers.begin()) {
    return lb;
  }
  if (lb == numbers.end()) {
    return std::prev(lb);
  }
  if (border - *std::prev(lb) <= *lb - border) {
    return std::prev(lb);
  }
  return lb;
}

int main() {
//  std::set<int> numbers = {1, 4, 6, 7};
//  std::cout <<
//            *FindNearestElement(numbers, 0) << " " <<
//            *FindNearestElement(numbers, 3) << " " <<
//            *FindNearestElement(numbers, 5) << " " <<
//            *FindNearestElement(numbers, 6) << " " <<
//            *FindNearestElement(numbers, 7) << " " <<
//            *FindNearestElement(numbers, 0) << " " <<
//            *FindNearestElement(numbers, -10) << " " <<
//
//            *FindNearestElement(numbers, 100) << std::endl;
//
//  std::set<int> empty_set;
//
//  std::cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << std::endl;
//  std::cout << *FindNearestElement(empty_set, 1000) << std::endl;
  std::set<int> n = {0,1,2,3,7};
  std::cout << *FindNearestElement(n, 1000) << std::endl;
  std::cout << *FindNearestElement(n, 1) << std::endl;
  std::cout << *FindNearestElement(n, 0) << std::endl;
  std::cout << *FindNearestElement(n, 2) << std::endl;
  std::cout << *FindNearestElement(n, 3) << std::endl;
  std::cout << *FindNearestElement(n, 4) << std::endl;

  return 0;
}