#include <iostream>

struct Specialization {
  std::string value;
  explicit Specialization(std::string new_value) { value = new_value; }
};
struct Course {
  std::string value;
  explicit Course(std::string new_value) { value = new_value; }
};
struct Week {
  std::string value;
  explicit Week(std::string new_value) { value = new_value; }
};

struct LectureTitle {
  std::string specialization;
  std::string course;
  std::string week;
  LectureTitle(Specialization s, Course c, Week w) {
    specialization = s.value;
    course = c.value;
    week = w.value;
  }
};

void PrintLecture(const LectureTitle& lec) {
  std::cout << lec.specialization << " " << lec.course << " " << lec.week
            << std::endl;
}

int main() {
  LectureTitle title(Specialization("C++"), Course("White belt"), Week("4th"));
  // LectureTitle title("C++", "White belt", "4th");
  // LectureTitle title(string("C++"), string("White belt"), string("4th"));
  // LectureTitle title = {"C++", "White belt", "4th"};
  // LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};
  // LectureTitle title(Course("White belt"), Specialization("C++"),
  // Week("4th"));
  // LectureTitle title(Specialization("C++"), Week("4th"), Course("White
  // belt"));

  PrintLecture(title);

  return 0;
}