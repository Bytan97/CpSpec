#include <algorithm>
#include <iostream>
#include <vector>

class Function;
class FunctionPart;
struct Image;
struct Params;

class FunctionPart {
private:
  char sign;
  double value;

public:
  FunctionPart(char s, double v) {
    sign = s;
    value = v;
  }
  double Apply(double source_value) const {
    if (sign == '+') {
      return source_value + value;
    } else {
      return source_value - value;
    }
  }
  void Invert() {
    if (sign == '+') {
      sign = '-';
    } else {
      sign = '+';
    }
  }
};

class Function {
private:
  std::vector<FunctionPart> parts;

public:
  void AddPart(char sign, double value) { parts.push_back({sign, value}); }
  double Apply(double value) const {
    for (const FunctionPart &part : parts) {
      value = part.Apply(value);
    }
    return value;
  }
  void Invert() {
    for (FunctionPart &part : parts) {
      part.Invert();
    }
    std::reverse(parts.begin(), parts.end());
  }
};

// struct Image {
//   double quality;
//   double freshness;
//   double rating;
// };

// struct Params {
//   double a;
//   double b;
//   double c;
// };

// Function MakeWeightFunction(const Params &params, const Image &image) {
//   Function function;
//   function.AddPart('-', image.freshness * params.a + params.b);
//   function.AddPart('+', image.rating * params.c);
//   return function;
// }

// double ComputeImageWeight(const Params &params, const Image &image) {
//   Function function = MakeWeightFunction(params, image);
//   return function.Apply(image.quality);
// }

// double ComputeQualityByWeight(const Params &params, const Image &image,
//                               double weight) {
//   Function function = MakeWeightFunction(params, image);
//   function.Invert();
//   return function.Apply(weight);
// }

// int main() {
//   Image image = {10, 2, 6};
//   Params params = {4, 2, 6};
//   std::cout << ComputeImageWeight(params, image) << std::endl;
//   std::cout << ComputeQualityByWeight(params, image, 46) << std::endl;
//   return 0;
// }