#include "DateTime.h"

DateTime::DateTime(Date d, Time t) : date(d), time(t) {}

Time DateTime::getTime() {
    return time;
}

Date DateTime::getDate() {
    return date;
}
