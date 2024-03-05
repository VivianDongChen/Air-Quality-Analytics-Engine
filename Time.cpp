#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include "Time.h"

using namespace std;
const int ZERO = 0;
const int TWELVE = 12;
const int ONE = 1;
const int TWO = 2;
const string AM = "AM";
const string PM = "PM";


Time::Time()
{
	hour=ZERO;
	min=ZERO;
    sec=ZERO;
}
Time::Time(int hh, int mm,int s)
{
	hour=hh;
	min=mm;
    sec=s;
}

int Time::getHour() const
{
	return hour;
}
int Time::getMin() const
{
	return min;
}
int Time::getSec() const
{
    return sec;
}
void Time::setHour(int hh)
{
	hour=hh;
}
void Time::setMin(int mm)
{
	min=mm;
}
void Time::setSec(int s)
{
    sec=s;
}

void Time::setTime(int hh, int mm,int s)
{
	hour=hh;
	min=mm;
    sec=s;
}
void Time::printTime() const
{
	cout<<"Time: "<<hour<<":"<<min<<":"<<sec;
}


Time Time::parseTimeString(const string& timeString) {
    istringstream timeStream(timeString);
    int hours, minutes, seconds;
    string am_pm;

    timeStream >> setw(TWO) >> hours;     // Read hour (fixed width of 2 characters)
    timeStream.ignore(ONE);                    // Ignore the colon
    timeStream >> setw(TWO) >> minutes;   // Read minutes
    timeStream.ignore(ONE);                    // Ignore the colon
    timeStream >> setw(TWO) >> seconds;   // Read seconds
    timeStream >> am_pm;                     // Read AM or PM

    // Convert to 24-hour format if necessary
    if (am_pm == PM && hours != TWELVE) {
        hours += TWELVE;
    } else if (am_pm == AM && hours == TWELVE) {
        hours = ZERO;  // Midnight is 00 in 24-hour format
    }

    return Time(hours, minutes, seconds);
}



// Overloading
    // Overloading cin
istream & operator >>( istream & input, Time & T )
{
	string sHH,sMM,sSS;
	int hh, mm,ss;

	getline(input,sHH,'.');
	getline(input,sMM,'.');
    getline(input,sSS,' ');

    hh=stoi(sHH);
	mm=stoi(sMM);
    ss=stoi(sSS);

	T.setTime(hh,mm,ss);
	return input;
}

// Overloading cout
ostream & operator <<( ostream & os, const Time & T )
{
	os<<"Time: "<<T.getHour()<<":"<<T.getMin()<<":"<<T.getSec();
	return os;
}

// Overloading compare operator==
bool Time:: operator==(const Time& otherDate) const{
    if (hour==otherDate.hour && min==otherDate.min && sec==otherDate.sec){
        return true;
    }
    return false;
}

// Overloading compare operator!=
bool Time:: operator!=(const Time& otherDate) const {
    return !(*this == otherDate);
}

// Overloading compare operator<
bool Time:: operator<(const Time& otherDate) const {
    if (hour<otherDate.hour){
        return true;
    }
    else if (hour==otherDate.hour && min<otherDate.min){
        return true;
    }
    else if (hour == otherDate.hour && min == otherDate.min && sec<otherDate.sec){
        return true;
    }
    return false;
}

// Overloading compare operator<=
bool Time:: operator<=(const Time& otherDate) const {
    return (*this==otherDate || *this<otherDate);
}

// Overloading compare operator>
bool Time:: operator>(const Time& otherDate) const {
    return !(*this<otherDate || *this==otherDate);
}

// Overloading compare operator>
bool Time:: operator>=(const Time& otherDate) const {
    return (*this>otherDate || *this==otherDate);
}









