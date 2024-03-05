#ifndef FINALPROJECT_AIRQUALITY_H
#define FINALPROJECT_AIRQUALITY_H

#include <iostream>
#include <string>
#include "Time.h"
#include "Date.h"

using namespace std;

/**
 * @class AirQuality
 * @brief Represents air quality data with date, time, temperature, and humidity components.
 */
class AirQuality {
public:
    /**
   * @brief Default constructor, initializes the air quality data to default values.
   */
    AirQuality();
    /**
    * @brief Parameterized constructor.
    * @param day The day component of the date.
    * @param month The month component of the date.
    * @param year The year component of the date.
    * @param hour The hour component of the time.
    * @param minute The minute component of the time.
    * @param sec The second component of the time.
    * @param Temperature The temperature value.
    * @param absHumidity The absolute humidity value.
    * @param relHumidity The relative humidity value.
    */
    AirQuality(int day, int month, int year, int hour, int minute,int sec, double Temperature, double absHumidity, double relHumidity);
    /**
        * @brief Sets the date component of the air quality data.
        * @param date The Date object representing the date.
        */
    void setDate(Date date);

    /**
     * @brief Sets the time component of the air quality data.
     * @param time The Time object representing the time.
     */
    void setTime(Time time);
    /**
    * @brief Sets the temperature value of the air quality data.
    * @param temp The temperature value.
    */
    void setTemp(double temp);
    /**
    * @brief Sets the absolute humidity value of the air quality data.
    * @param absHumidity The absolute humidity value.
    */
    void setAbsoluteHumidity(double absHumidity);
    /**
   * @brief Sets the relative humidity value of the air quality data.
   * @param relHumidity The relative humidity value.
   */
    void setRelHumidity(double relHumidity);
    /**
       * @brief Gets the date component of the air quality data.
       * @return The Date object representing the date.
       */
    Date getDate() const;
    /**
    * @brief Gets the time component of the air quality data.
    * @return The Time object representing the time.
    */
    Time getTime() const;
    /**
    * @brief Gets the temperature value of the air quality data.
    * @return The temperature value.
    */
    double getTemp() const;

    /**
     * @brief Gets the absolute humidity value of the air quality data.
     * @return The absolute humidity value.
     */
    double getAbsoluteHumidity() const;

    /**
     * @brief Gets the relative humidity value of the air quality data.
     * @return The relative humidity value.
     */
    double getRelativeHumidity() const;


private:
    Date date;
    Time time;
    double temp;
    double absoluteHumidity;
    double relativeHumidity;


};


#endif //FINALPROJECT_AIRQUALITY_H
