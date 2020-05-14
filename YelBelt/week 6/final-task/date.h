#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Date {
public:
	Date(int year, int month, int day);
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;

private:
	int year;
	int month;
	int day;
};

Date ParseDate(istringstream &iss);

ostream operator<<(ostream &os, const Date &d);
