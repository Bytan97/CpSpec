#pragma once

#include <stdexcept>
#include <istream>
#include <iomanip>
#include <iostream>
#include <string>
#include <set>
#include <tuple>

class Date {
public:
    Date(int n_year, int n_month, int n_day);

    int GetYear() const;

    int GetMonth() const;

    int GetDay() const;

    friend bool operator==(const Date &lhs, const Date& rhs);
    friend bool operator!=(const Date &lhs, const Date& rhs);
    friend bool operator<(const Date &lhs, const Date &rhs);
    friend bool operator>(const Date &lhs, const Date &rhs);
private:
    int year;
    int month;
    int day;
};

Date ParseDate(std::istream &is);

std::ostream& operator<<(std::ostream &os, const Date &date);

