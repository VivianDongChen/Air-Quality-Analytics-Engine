#ifndef Time_h
#define Time_h

#include <iostream>
#include <string>

using namespace std;
/**
 * @class Time
 * @brief Represents a time with hours, minutes, and seconds.
 */
class Time{
public:
    /**
    * @brief Default constructor, initializes the time to 00:00:00.
    */
	Time();
    /**
    * @brief Parameterized constructor.
    * @param hh The hours.
    * @param mm The minutes.
    * @param s The seconds.
    */
	Time(int hh, int mm,int s);
    // Setter functions
    /**
     * @brief Sets the hour component of the time.
     * @param hh The hours.
     */
	void setHour(int hh);
    /**
       * @brief Sets the minute component of the time.
       * @param mm The minutes.
       */
	void setMin(int mm);
    /**
   * @brief Sets the second component of the time.
   * @param s The seconds.
   */
    void setSec(int s);
    /**
   * @brief Sets the complete time.
   * @param hh The hours.
   * @param mm The minutes.
   * @param s The seconds.
   */
    void setTime(int hh, int mm,int s);
    /**
    * @brief Prints the time in HH:MM:SS format.
    */
	void printTime() const;

    // Getter functions
    /**
     * @brief Gets the hour component of the time.
     * @return The hours.
     */
	int getHour() const;
    /**
   * @brief Gets the minute component of the time.
   * @return The minutes.
   */
	int getMin() const;
    /**
   * @brief Gets the second component of the time.
   * @return The seconds.
   */
    int getSec() const;

    /**
    * @brief Parses a time string in HH:MM:SS format and returns a Time object.
    * @param timeString The input time string.
    * @return The Time object.
    */
    static Time parseTimeString(const string& timeString);

    // Overloaded comparison operators
    /**
     * @brief Equality operator for comparing two Time objects.
     * @param otherTime The other Time object.
     * @return True if equal, false otherwise.
     */
    bool operator==(const Time& otherDate) const;
    bool operator!=(const Time& otherDate) const;
    bool operator<(const Time& otherDate) const;
    bool operator<=(const Time& otherDate) const;
    bool operator>(const Time& otherDate) const;
    bool operator>=(const Time& otherDate) const;

private:
	int hour;
	int min;
    int sec;
};
/**
* @brief Outputs the time to an ostream in HH:MM:SS format.
* @param os The output stream.
* @param T The Time object to output.
* @return The output stream.
*/
	ostream & operator <<( ostream & os, const Time & T );
/**
* @brief Inputs the time from an istream.
* @param input The input stream.
* @param T The Time object to input into.
* @return The input stream.
*/
	istream & operator >>( istream & input, Time & T );

#endif