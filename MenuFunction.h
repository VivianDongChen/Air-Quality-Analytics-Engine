
#ifndef FINALPROJECT_MENUFUNCTION_H
#define FINALPROJECT_MENUFUNCTION_H

#include "Time.h"
#include "Date.h"
#include "AirQuality.h"
#include "MinHeap.h"
#include "DateTime.h"
#include <map>
#include "Vector.h"

using namespace std;

/**
 * @class MenuFunction
 * @brief Provides various functions for interacting with air quality data and performing analysis.
 */
class MenuFunction {
public:
/**
     * @brief Computes the average temperature of a specific month and year.
     * @param tempMap The map containing temperature data.
     * @param monthYear The target month and year.
     * @return The average temperature.
     */
    double promptAvgTempOfMonth(map<Date, MinHeap> tempMap, Date monthYear);

    /**
     * @brief Computes the average relative humidity of a specific month and year.
     * @param relHumMap The map containing relative humidity data.
     * @param monthYear The target month and year.
     * @return The average relative humidity.
     */
    double promptAvgRelHumOfMonth(map<Date, MinHeap> relHumMap, Date monthYear);
    /**
   * @brief Computes the average absolute humidity of a specific month and year.
   * @param absHumMap The map containing absolute humidity data.
   * @param monthYear The target month and year.
   * @return The average absolute humidity.
   */
    double promptAvgAbsHumOfMonth(map<Date, MinHeap> relHumMap, Date monthYear);
    /**
   * @brief Displays temperature and relative humidity at a specific date and time.
   * @param airQualities The vector of air quality data.
   * @param dateTime The target date and time.
   */

    void promptTempAndRelHumAtDateTime(map<Date, MinHeap> mapMinHeap, DateTime dateTime);
    /**
    * @brief Reads a date (month and year) from the console for a specific data type.
    * @param dataType The type of data for which the date is input.
    * @return The entered date.
    */
    DateTime cinTime(const string& dataType);

    /**
     * @brief Prompts the highest temperature of a specific month.
     * @param tempMap The map containing temperature data.
     * @param monthYear The target month and year.
     */
    void promptHTempOfMonth(map<Date, MinHeap> tempMap,Date monthYear);

    /**
 * @brief Prompts the highest relative humidity of a specific month.
 * @param relHumMap The map containing relative humidity data.
 * @param monthYear The target month and year.
 */
    void promptHRelHumOfMonth(map<Date, MinHeap> relHumMap,Date monthYear);

    /**
 * @brief Prompts the highest absolute humidity of a specific month.
 * @param absHumMap The map containing absolute humidity data.
 * @param monthYear The target month and year.
 */
    void promptHAbsTempOfMonth(map<Date, MinHeap> absHumMap,Date monthYear);

    /**
 * @brief Prompts temperatures above the average for a specific month.
 * @param tempMap The map containing temperature data.
 * @param avgValue The average temperature.
 * @param monthYear The target month and year.
 */
    void promptTempAboveAvgOfMonth(map<Date, MinHeap> tempMap,double avgValue,Date monthYear);

    /**
 * @brief Prompts relative humidity above the average for a specific month.
 * @param relHumMap The map containing relative humidity data.
 * @param avgValue The average relative humidity.
 * @param monthYear The target month and year.
 */
    void promptRelHumAboveAvgOfMonth(map<Date, MinHeap> relHumMap,double avgValue,Date monthYear);

    /**
 * @brief Prompts absolute humidity above the average for a specific month.
 * @param absHumMap The map containing absolute humidity data.
 * @param avgValue The average absolute humidity.
 * @param monthYear The target month and year.
 */
    void promptAbsHumAboveAvgOfMonth(map<Date, MinHeap> absHumMap,double avgValue,Date monthYear);

    /**
 * @brief Reads a date (year) from the console for a specific data type.
 * @return The entered date.
 */
    Date cinDateYear() ;


private:
    /**
     * @brief Splits a string into a vector of integers using a specified delimiter.
     * @param input The input string.
     * @param delimiter The delimiter character.
     * @return A vector of integers.
     */
    Vector<int> splitString(const string& input, char delimiter);

    /**
  * @brief Checks if the entered month is valid.
  * @param input The vector of integers representing the date.
  * @return True if the month is valid, false otherwise.
  */
    bool isValidMonth(const Vector<int>& input);

    /**
   * @brief Checks if the entered date is valid.
   * @param input The vector of integers representing the date.
   * @return True if the date is valid, false otherwise.
   */
    bool isValidDate(const Vector<int>& input);

    bool isValidTime(const Vector<int>& input);

    /**
  * @brief Displays the highest value in the data for a specific month and year.
  * @param dataMap The map containing the data.
  * @param dataType The type of data.
  * @param monthYear The target month and year.
  */
    void displayHighestValue(map<Date, MinHeap>& dataMap, const string& dataType,Date monthYear);

    /**
 * @brief Displays values above the average for a specific month and year.
 * @param dataMap The map containing the data.
 * @param avgValue The average value.
 * @param monthYear The target month and year.
 */
    void displayValuesAboveAvgOfMonth(map<Date, MinHeap>& dataMap,double avgValue,Date montYear);

    };


#endif //FINALPROJECT_MENUFUNCTION_H
