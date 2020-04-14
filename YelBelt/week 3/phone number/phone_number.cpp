#include "phone_number.h"
#include <string>
#include <iostream>

PhoneNumber::PhoneNumber(const string &international_number) {
  std::stringstream ss(international_number);
//  char sign, d1, d2;
  char sign;
  ss >> sign;
  getline(ss, country_code_, '-');
//  ss >> d1;
  getline(ss, city_code_, '-');
  ss >> local_number_;

  if (sign != '+' or country_code_.empty() or city_code_.empty() or local_number_.empty()
      or ss.fail() or ss.peek() != EOF) {
    throw invalid_argument("Wrong date format: " + international_number);
  }
}
string PhoneNumber::GetCountryCode() const {
  return country_code_;
}
string PhoneNumber::GetCityCode() const {
  return city_code_;
}
string PhoneNumber::GetLocalNumber() const {
  return local_number_;
}
string PhoneNumber::GetInternationalNumber() const {
  return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}
