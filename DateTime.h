#ifndef DATETIME_H
#define DATETIME_H

#include "Date.h"  // Include the Date class header
#include "Time.h"  // Include the Time class header
/**
 * @brief The DateTime class represents a combination of date and time.
 *
 * This class combines the functionalities of the Date and Time classes
 * to represent a specific date and time.
 */
class DateTime {
public:
    /**
    * @brief Constructs a DateTime object with a given date and time.
    *
    * @param d The Date object.
    * @param t The Time object.
    */
    DateTime(Date d, Time t);
    /**
   * @brief Gets the Time component of the DateTime object.
   *
   * @return The Time object.
   */
    Time getTime();
    /**
   * @brief Gets the Date component of the DateTime object.
   *
   * @return The Date object.
   */
    Date getDate();
private:
    Date date;
    Time time;

};

#endif // DATETIME_H

