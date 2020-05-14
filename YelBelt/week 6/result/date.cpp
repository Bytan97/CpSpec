#include "date.h"

Date::Date(int n_year, int n_month, int n_day) {
    year = n_year;
    if (n_month > 12 or n_month < 1) {
        throw std::logic_error("Month value is invalid: " + std::to_string(n_month));
    }
    month = n_month;
    if (n_day > 31 or n_day < 1) {
        throw std::logic_error("Day value is invalid: " + std::to_string(n_day));
    }
    day = n_day;
}

int Date::GetYear() const {
    return year;
}

int Date::GetMonth() const {
    return month;
}

int Date::GetDay() const {
    return day;
}

Date ParseDate(std::istream &is) {

    char delim1, delim2;
    int year, month, day;
    is >> year >> delim1 >> month >> delim2 >> day;
//    if (delim1 != '-' or delim2 != '-' or is.fail() or is.peek() != EOF) {
//        throw std::invalid_argument("Wrong date format: ");
//    }
    return Date(year, month, day);
}

bool operator==(const Date &lhs, const Date &rhs) {
    return std::tie(lhs.year, lhs.month, lhs.day) ==
           std::tie(rhs.year, rhs.month, rhs.day);
}

bool operator!=(const Date &lhs, const Date &rhs) {
    return std::tie(lhs.year, lhs.month, lhs.day) !=
           std::tie(rhs.year, rhs.month, rhs.day);
}

bool operator<(const Date &lhs, const Date &rhs) {
    return std::tie(lhs.year, lhs.month, lhs.day) <
           std::tie(rhs.year, rhs.month, rhs.day);
}

bool operator>(const Date &lhs, const Date &rhs) {
    return std::tie(lhs.year, lhs.month, lhs.day) >
           std::tie(rhs.year, rhs.month, rhs.day);
}

std::ostream &operator<<(std::ostream &stream, const Date &date) {
    stream << std::setw(4) << std::setfill('0') << date.GetYear() <<
           "-" << std::setw(2) << std::setfill('0') << date.GetMonth() <<
           "-" << std::setw(2) << std::setfill('0') << date.GetDay();
    return stream;
}
