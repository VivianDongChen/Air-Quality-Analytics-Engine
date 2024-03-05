#include "Date.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
const int ONE = 1;
const int DEFAULT_YEAR = 2000;

Date::Date(){
    day=ONE;
    month=ONE;
    year=DEFAULT_YEAR;
}
Date::Date(int dd, int mm, int yy){
    day=dd;
    month=mm;
    year=yy;
}
int Date::getDay() const{
    return day;
}
void Date::setDay(int dd){
    day=dd;
}
int Date::getMonth() const{
    return month;
}
void Date::setMonth(int mm){
    month=mm;
}
int Date::getYear() const{
    return year;
}
void Date::setYear(int yy){
    year=yy;
}
void Date::setDate(int dd, int mm, int yy)
{
	day=dd;
	month=mm;
	year=yy;
}

void Date::printDate() const
{
	cout <<"  Date:  " << day <<" "<< month<<" "<<year<<'\n';
}

Date Date:: parseDateString(const string& dateString) {
    istringstream dateStream(dateString);
    string part;
    int day, month, year;

    // Get month
    getline(dateStream, part, '/');
    month = stoi(part);

    // Get day
    getline(dateStream, part, '/');
    day = stoi(part);

    // Get year
    getline(dateStream, part);
    year = stoi(part);

    return Date(day, month, year);
}


//Overloading
// Overloading cin
istream & operator >>( istream & input, Date & D )
{
	string stringdd, stringmm, stringyy;
	int dd,mm, yy;

	getline(input, stringdd, '/');
	getline(input, stringmm,'/');
	getline(input, stringyy,' ');

	dd=stoi(stringdd);
	mm=stoi(stringmm);
	yy=stoi(stringyy);
	
	D.setDate(dd, mm, yy);

	return input;
}

// Overloading cout
ostream & operator <<( ostream & os, const Date & D )
{
	os << "  Date:  " << D.getDay() << D.getMonth() <<D.getYear()<<'\n';
  return os;
}

// Overloading compare: equal operator==
bool Date:: operator==(const Date& otherDate) const{
    if (day==otherDate.day && month==otherDate.month && year==otherDate.year){
        return true;
    }
    return false;
}
// Overloading compare: Not equal operator !=
bool Date::operator!=(const Date& otherDate) const {
    return !(*this == otherDate);
}
// Overloading compare: Less than operator <
bool Date::operator<(const Date &otherDate) const {
    if (year < otherDate.year) {
        return true;
    }
    else if (year == otherDate.year && month < otherDate.month) {
        return true;
    }
    else if (year == otherDate.year && month == otherDate.month && day < otherDate.day) {
        return true;
    }
    return false;
}
// Overloading compare: larger than operator >
bool Date::operator>(const Date &otherDate) const {
   return !(*this == otherDate || *this<otherDate);
}

// Overloading compare: Less or equal than operator <=
bool Date::operator<=(const Date& otherDate) const{
    return !(*this > otherDate);
}

// Overloading compare: Larger or equal than operator <=
bool Date::operator>=(const Date& otherDate) const{
    return !(*this < otherDate);
}
