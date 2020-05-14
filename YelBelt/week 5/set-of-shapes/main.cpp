#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include <cmath>

class Figure {
public:
  Figure(const std::string &name) : name(name) {}
  virtual std::string Name() const = 0;
  virtual double Perimeter() const = 0;
  virtual double Area() const = 0;
protected:
  std::string name;
};

class Triangle : public Figure {
public:
  Triangle(int a, int b, int c) : Figure("TRIANGLE"), a(a), b(b), c(c) {}
  std::string Name() const override { return name; }
  double Perimeter() const override { return a + b + c; }
  double Area() const override {
    double p = Perimeter() / 2.;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
  }
private:
  double a, b, c;
};

class Rect : public Figure {
public:
  Rect(int a, int b) : Figure("RECT"), a(a), b() {}
  std::string Name() const override { return name; }
  double Perimeter() const override { return a + b; }
  double Area() const override { return a * b; }
private:
  int a, b;
};


std::shared_ptr<Figure> CreateFigure(std::istringstream &is) {
  std::string shape;
  is >> shape;
  if (shape == "TRIANGLE") {
    double a, b, c;
    is >> a >> b >> c;
    return std::make_shared<Triangle>(a, b, c);
  }
}

int main() {
  std::vector<std::shared_ptr<Figure>> figures;
  for (std::string line; getline(std::cin, line);) {
    std::istringstream is(line);

    std::string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto &current_figure : figures) {
        std::cout << std::fixed << std::setprecision(3)
                  << current_figure->Name() << " "
                  << current_figure->Perimeter() << " "
                  << current_figure->Area() << std::endl;
      }
    }
  }
  return 0;
}