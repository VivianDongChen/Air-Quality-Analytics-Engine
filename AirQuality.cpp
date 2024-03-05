#include "AirQuality.h"
const int ZERO = 0;
const int ONE = 1;
const int DEFAULT_YEAR = 1800;
const double DEFAULT_VALUE = -9999.0;

AirQuality:: AirQuality(){
    date = Date(ONE,ONE, DEFAULT_YEAR);
    time = Time(ZERO,ZERO,ZERO);
    temp = DEFAULT_VALUE;
    absoluteHumidity =DEFAULT_VALUE;
    relativeHumidity=DEFAULT_VALUE;
};


AirQuality:: AirQuality(int day, int month, int year, int hour, int minute,int sec, double Temperature, double absHumidity, double relHumidity)
{
    date = Date(day,month, year);
    time = Time(hour,minute,sec);
    temp = Temperature;
    absoluteHumidity =absHumidity;
    relativeHumidity=relHumidity;
}

void AirQuality::setDate(Date d){
    date = d;
}
void AirQuality::setTime(Time t){
    time = t;
}
void AirQuality::setTemp(double Temperature){
    temp = Temperature;
}
void AirQuality::setAbsoluteHumidity(double absHumidity){
    absoluteHumidity = absHumidity;
}
void AirQuality::setRelHumidity(double relHumidity){
    relativeHumidity = relHumidity;
}

Date AirQuality::getDate() const {
    return date;
}

Time AirQuality::getTime() const {
    return time;
}

double AirQuality::getTemp() const {
    return temp;
}

double AirQuality::getAbsoluteHumidity() const {
    return absoluteHumidity;
}

double AirQuality::getRelativeHumidity() const {
    return relativeHumidity;
}
