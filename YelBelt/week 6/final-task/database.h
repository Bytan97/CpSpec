#pragma once
#include "date.h"
#include "node.h"
#include <string>
#include <ostream>

using namespace std;

class Database {
public:
	Database();
	void Add(const Date &date, const string &event);
	void Print(ostream &os);
	int RemoveIf();
private:

};
