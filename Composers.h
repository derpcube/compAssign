#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

class Composer {
private:
	string name;
	int date;
	static int size;
public:
	Composer();
	Composer(string n, int d);
	void setName(string n);
	string getName();
	int getDeathYear();
	void setDeathYear(int d);
	bool operator==(const Composer& composer) const;
	~Composer();
	friend ostream& operator<<(ostream& os, const Composer& composer);
};