#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include "Composers.h"
#include "LinkedList.h"
#include "Node.h"

using namespace std;

//initializes the name and date to empty and 0, respectively
Composer::Composer() {
	name = "";
	date = 0;
}

//constructor
Composer::Composer(string name, int date) {
	this->name = name;
	this->date = date;
}

//sets name
void Composer::setName(string n) {
	name = n;
}

//returns name
string Composer::getName() {
	return name;
}

//assigns year of death
void Composer::setDeathYear(int d) {
	date = d;
}

//returns year of death
int Composer::getDeathYear() {
	return date;
}

//== operator overload (compares)
bool Composer::operator==(const Composer& composer) const {
	return (name == composer.name);
}

//destructor
Composer::~Composer() {

}

//<< operator overload (to print out)
ostream& operator<<(ostream& os, const Composer& composer) {
	os << composer.name << ", " << composer.date << endl;
	return os;
}
