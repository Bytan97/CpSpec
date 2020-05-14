#include "date.h"

using namespace std;

Date::Date(int new_year, int new_month, int new_day) {
	year = new_year;
	if (new_month > 12 || new_month < 1) {
		throw logic_error("Month value is invalid: " + to_string(new_month));
	}
	month = new_month;
	if (new_day > 31 || new_day < 1) {
		throw logic_error("Day value is invalid: " + to_string(new_day));
	}
	day = new_day;
}

Date::Date ParseDate(istringstream &iss) {
	char d1, d2;
	int y, m, d;
	iss >> y >> d1 >> m >> d2 >> d;
	if (d1 != '-' or d2 != '-' or iss.fail() or iss.peek() != EOF) {
		throw invalid_argument("Wrong date format");
	}
	return {y, m, d};
}

Date:: operator<<(ostream &os, const Date &d);

