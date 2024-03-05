#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

/**
 * @class Date
 * @brief Represents a date with day, month, and year components.
 */
class Date
{
public:
    /**
   * @brief Default constructor, initializes the date to 01/01/0000.
   */
    Date();

    /**
     * @brief Parameterized constructor.
     * @param dd The day.
     * @param mm The month.
     * @param yy The year.
     */
    Date(int dd, int mm, int yy);
    /**
   * @brief Gets the day component of the date.
   * @return The day.
   */
    int getDay() const;

    /**
     * @brief Gets the month component of the date.
     * @return The month.
     */
	int getMonth() const;

    /**
     * @brief Gets the year component of the date.
     * @return The year.
     */
	int getYear() const;

    /**
     * @brief Sets the day component of the date.
     * @param dd The day.
     */
    void setDay(int dd);
    /**
  * @brief Sets the month component of the date.
  * @param mm The month.
  */
    void setMonth(int mm);
    /**
  * @brief Sets the year component of the date.
  * @param yy The year.
  */
    void setYear(int yy);
    /**
   * @brief Sets the complete date.
   * @param dd The day.
   * @param mm The month.
   * @param yy The year.
   */
	void setDate(int dd, int mm, int yy);

    /**
    * @brief Prints the date in DD/MM/YYYY format.
    */
	void printDate() const;
    /**
    * @brief Parses a date string in DD/MM/YYYY format and returns a Date object.
    * @param dateString The input date string.
    * @return The Date object.
    */
    static Date parseDateString(const string& dateString);

    /**
     * @brief Overloaded compare operator for comparing two Date objects.
     * @param otherDate The other Date object.
     * @return True if greater than, false otherwise.
     */
    bool operator>(const Date& otherDate) const;
    bool operator<(const Date& otherDate) const;
    bool operator==(const Date& otherDate) const;
    bool operator<=(const Date& otherDate) const;
    bool operator>=(const Date& otherDate) const;
    bool operator!=(const Date& otherDate) const;

private:
    int day;
    int month;
    int year;
};
/**
* @brief Outputs the date to an ostream in DD/MM/YYYY format.
* @param os The output stream.
* @param D The Date object to output.
* @return The output stream.
*/
	ostream & operator <<( ostream & os, const Date & D );
/**
* @brief Inputs the date from an istream.
* @param input The input stream.
* @param D The Date object to input into.
* @return The input stream.
*/
	istream & operator >>( istream & input, Date & D );
#endif // DATE_H
