#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
  Person(const string &n, const string &t) : name(n), type(t) {}
  string GetType() const { return type; }
  string GetName() const { return name; }
  virtual void Walk(const string &destination) const = 0;
protected:
  string name; // Не делаем const , чтобы оставить возможнность  добовления функции изменнения имени
  const string type;
};

class Student : public Person {
public:
  Student(const string &name, const string &favouriteSong) :
      Person(name, "Student"),
      FavouriteSong(favouriteSong) {}
  void Learn() const {
    cout << "Student: " << name << " learns" << endl;
  }
  void Walk(const string &destination) const override {
    cout << "Student: " << name << " walks to: " << destination << endl;
    cout << "Student: " << name << " sings a song: " << FavouriteSong << endl;
  }
  void SingSong() const {
    cout << "Student: " << name << " sings a song: " << FavouriteSong << endl;
  }
private:
  string FavouriteSong;  // Не делаем const , чтобы оставить возможнность  добовления функции изменнения любимой песни
};

class Teacher : public Person {
public:
  Teacher(const string &name, const string &subject) :
      Person(name, "Teacher"),
      Subject(subject) {}
  void Teach() const {
    cout << "Teacher: " << name << " teaches: " << Subject << endl;
  }
  void Walk(const string &destination) const override {
    cout << "Teacher: " << name << " walks to: " << destination << endl;
  }
private:
  string Subject;  // Не делаем const , чтобы оставить возможнность  добовления функции изменнения предмета
};

//
class Policeman : public Person {
public:
  Policeman(const string &name) :
      Person(name, "Policeman") {}

  void Check(const Person &p) const {
    cout << "Policeman: " << name << " checks " << p.GetType() << ". " << p.GetType() << "'s name is: " << p.GetName()
         << endl;
  }

  void Walk(const string &destination) const override {
    cout << "Policeman: " << name << " walks to: " << destination << endl;
  }
};

void VisitPlaces(const Person &person, const vector<string> &places) {
  for (auto p : places) {
    person.Walk(p);
  }
}

int main() {
  Teacher t("Jim", "Math");
  Student s("Ann", "We will rock you");
  Policeman p("Bob");

  VisitPlaces(t, {"Moscow", "London"});
  p.Check(s);
  VisitPlaces(s, {"Moscow", "London"});
  return 0;
}
