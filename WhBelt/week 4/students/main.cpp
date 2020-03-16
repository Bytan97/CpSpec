#include <iostream>
#include <vector>

class Student {
private:
  std::string first_name;
  std::string last_name;
  long long day;
  long long month;
  long long year;

public:
  explicit Student(std::string f, std::string l, long long d, long long m,
                   long long y)
      : first_name(f), last_name(l), day(d), month(m), year(y) {}

  std::string GetName() const { return first_name + " " + last_name; }
  std::string GetDate() const {
    return std::to_string(day) + "." + std::to_string(month) + "." +
           std::to_string(year);
  }
};

int main() {
  int student_counts;
  std::cin >> student_counts;
  std::vector<Student> students;

  for (int i = 0; i < student_counts; ++i) {
    std::string first_name, last_name;
    long long day, month, year;
    std::cin >> first_name >> last_name >> day >> month >> year;
    students.push_back(Student(first_name, last_name, day, month, year));
  }
  int command_counts;
  std::cin >> command_counts;
  for (int i = 0; i < command_counts; ++i) {
    std::string command;
    std::cin >> command;
    if (command == "name") {
      long long index;
      std::cin >> index;
      if (index > students.size() or index <= 0) {
        std::cout << "bad request" << std::endl;
      } else {
        std::cout << students[index - 1].GetName() << std::endl;
      }
    } else if (command == "date") {
      long long index;
      std::cin >> index;
      if (index > students.size() or index <= 0) {
        std::cout << "bad request" << std::endl;
      } else {
        std::cout << students[index - 1].GetDate() << std::endl;
      }
    } else {
      long long index;
      std::cin >> index;
      std::cout << "bad request" << std::endl;
    }
  }
  return 0;
}