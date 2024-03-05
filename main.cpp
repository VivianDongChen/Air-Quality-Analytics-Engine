#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Time.h"
#include "Date.h"
#include "MenuFunction.h"
#include "AirQuality.h"
#include "MinHeap.h"
#include <map>
#include <cmath>
#include "Test.cpp"
#include "DateTime.h"
#include "Vector.h"

using namespace std;

const int COLUMN = 5;
const int THOUSAND = 1000;
const double DOUBLE_ZERO = 0.00;


int main() {
    ifstream inFile("AirQualityUCI.csv");
    string line;

    if (!inFile) {
        std::cerr << "Unable to open file";
        return 1;
    }

    // skip first line
    getline(inFile, line);

    Vector<AirQuality> airQualities;
    // create map to fast search
    map<Date, MinHeap> tempMap;
    map<Date, MinHeap> relHumMap;
    map<Date, MinHeap> absHumMap;

    while (getline(inFile, line)) {

        const int columnNeeded = COLUMN;

        int columnCount = ONE; // Start at 1 because there's always at least one column
        for (char ch: line) {
             if (ch == ',') {
                 columnCount++;
             }
        }

        stringstream ss(line);
        string dateStr, timeStr;
        string tempStr, absHumidityStr, relHumidityStr;
        double temp, absHumidity, relHumidity;

        // Read the date and time columns as strings
        getline(ss, dateStr, ',');
        getline(ss, timeStr, ',');


        // Skip middle columns by ignoring characters up to the last three columns
        // the number 1000 is large enough of the characters in each middle column
        const int numberOfColumnsToIgnore = columnCount - columnNeeded;
        for (int i = 0; i < numberOfColumnsToIgnore; ++i) {
             ss.ignore(THOUSAND, ',');
        }

        // Read the last three columns as strings
        getline(ss, tempStr, ',');
        getline(ss, relHumidityStr, ',');
        getline(ss, absHumidityStr);


        // Convert the string values of last three columns to double
        try {
            temp = stod(tempStr);
            absHumidity = stod(absHumidityStr);
            relHumidity = stod(relHumidityStr);
        } catch (const std::exception& e) {
            cerr << "Error converting string to double: " << e.what() << endl;
            // Handle or skip this line
            continue;
        }

        // Parse dateStr and timeStr to class date and time
        Date date = Date::parseDateString(dateStr);
        Time time = Time::parseTimeString(timeStr);


        AirQuality aq(date.getDay(),date.getMonth(),date.getYear(), time.getHour(), time.getMin(),time.getSec() ,temp, absHumidity, relHumidity);

        // map store
            // map<Date, MinHeap>   MinHeap<double,AirQuality>  add date into map key is monthYear value is (-1*temp,aq)
            // that will give us max temp value and detail of AirQuality in specific month。if want to get second largest value
            // can use MinHeap.pop then MinHeap.top

        tempMap[Date(ZERO,date.getMonth(),date.getYear())].insert(NEGATIVE_ONE*temp,aq);
        relHumMap[Date(ZERO,date.getMonth(),date.getYear())].insert(NEGATIVE_ONE*relHumidity,aq);
        absHumMap[Date(ZERO,date.getMonth(),date.getYear())].insert(NEGATIVE_ONE*absHumidity,aq);

    }

    inFile.close();


    MenuFunction menu;
    int choice;
    string input;
    do {
        cout << "Menu:\n"
                  << "1) Average Temperature for specific Month\n"
                  << "2) Average Relative Humidity for specific Month\n"
                  << "3) Average Absolute Humidity for specific Month\n"
                  << "4) Display the temperature,relative humidity by specific Date\n"
                  << "5) Highest Temperature for specific Month\n"
                  << "6) Highest Relative Humidity for specific Month\n"
                  << "7) Highest Absolute Humidity for specific Month\n"
                  << "8) Dates/Time with Temperature above average for specific Month\n"
                  << "9) Dates/Time with Relative Humidity above average for specific Month\n"
                  << "10) Dates/Time with Absolute Humidity above average for specific Month\n"
                  << "11) Run Test\n"
                  << "0) Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
            case ONE:
               // 1) Average Temperature\n"
                try {
                    cout << "Enter the month and the program will display " << "the average temperature" << "(format Month/Year 1/2005): " << endl;
                    Date monthYear = menu.cinDateYear();
                    menu.promptAvgTempOfMonth(tempMap,monthYear);
                } catch (const exception& e) {
                    cerr << "An exception occurred: " << e.what() << "\n";
                }

                break;

            case TWO:
                // 2) Average Relative Humidity\n"
                try {
                    cout << "Enter the month and the program will display " << "the average relative humidity" << "(format Month/Year 1/2005): " << endl;
                    Date monthYear = menu.cinDateYear();
                    menu.promptAvgRelHumOfMonth(relHumMap,monthYear);
                } catch (const exception& e) {
                    cerr << "An exception occurred: " << e.what() << "\n";
                }

                break;

            case THREE:
                // 3) Average Absolute Humidity\n
                try {
                    cout << "Enter the month and the program will display " << "he average absolute humidity" << "(format Month/Year 1/2005): " << endl;
                    Date monthYear = menu.cinDateYear();
                    menu.promptAvgAbsHumOfMonth(absHumMap,monthYear);
                } catch (const exception& e) {
                    cerr << "An exception occurred: " << e.what() << "\n";
                }

                break;

            case FOUR:
                 // 4) Data by Date and Time\n"
                try {
                    DateTime dateTime = menu.cinTime("the temperature, relative humidity");
                    // find date time data in file
                    menu.promptTempAndRelHumAtDateTime(tempMap, dateTime);
                } catch (const exception& e) {
                    cerr << "An exception occurred: " << e.what() << "\n";
                }

                break;

            case FIVE:
                // 5) Highest Temperature for specific Month\n
                try {
                    cout << "Enter the month and the program will display " << "Highest Temperature " << "(format Month/Year 1/2005): " << endl;
                    Date monthYear = menu.cinDateYear();
                    menu.promptHTempOfMonth(tempMap,monthYear);
                } catch (const std::exception& e) {
                    std::cerr << "An exception occurred: " << e.what() << "\n";
                }

                break;

            case SIX:
                // 6) Highest Relative Humidity for specific Month\n"
                try {
                    cout << "Enter the month and the program will display " << "Highest Relative Humidity " << "(format Month/Year 1/2005): " << endl;
                    Date monthYear = menu.cinDateYear();
                    menu.promptHRelHumOfMonth(relHumMap,monthYear);
                } catch (const std::exception& e) {
                    std::cerr << "An exception occurred: " << e.what() << "\n";
                }
                break;

            case SEVEN:
                // "7) Highest Absolute Humidity for specific Month\n"
                try {
                    cout << "Enter the month and the program will display " << "Highest Absolute Humidity " << "(format Month/Year 1/2005): " << endl;

                    Date monthYear = menu.cinDateYear();
                    menu.promptHAbsTempOfMonth(absHumMap,monthYear);
                } catch (const std::exception& e) {
                    std::cerr << "An exception occurred: " << e.what() << "\n";
                }
                break;

            case EIGHT:
                // "8) Dates/Time with Temperature above average for specific Month\n"
                try {
                    cout << "Enter the month and the program will display " << "Temperature above average " << "(format Month/Year 1/2005): " << endl;
                    Date monthYear = menu.cinDateYear();
                    double avg =menu.promptAvgTempOfMonth(tempMap,monthYear);
                    // if no month found break
                    if (isnan(avg)) {
                        break;
                    }
                   menu.promptTempAboveAvgOfMonth(tempMap,DOUBLE_ZERO,monthYear);
                } catch (const std::exception& e) {
                    std::cerr << "An exception occurred: " << e.what() << "\n";
                }
                break;

            case NINE:
                // "9) Dates/Time with Relative Humidity above average for specific Month\n"
                try {
                    cout << "Enter the month and the program will display " << "Relative Humidity above average " << "(format Month/Year 1/2005): " << endl;
                    Date monthYear = menu.cinDateYear();
                    double avg = menu.promptAvgRelHumOfMonth(relHumMap,monthYear);
                    // if no month found break
                    if (isnan(avg)) {
                        break;
                    }
                   menu.promptRelHumAboveAvgOfMonth(relHumMap, avg,monthYear);
                } catch (const std::exception& e) {
                    std::cerr << "An exception occurred: " << e.what() << "\n";
                }
                break;

            case TEN:
                //10) Dates/Time with Absolute Humidity above average for specific Month\n"
                try {
                    cout << "Enter the month and the program will display " << "Absolute Humidity above average " << "(format Month/Year 1/2005): " << endl;
                    Date monthYear = menu.cinDateYear();
                    double avg = menu.promptAvgAbsHumOfMonth(absHumMap,monthYear);
                    // if no month found break
                    if (isnan(avg)) {
                        break;
                    }
                    menu.promptAbsHumAboveAvgOfMonth(absHumMap, avg,monthYear);
                } catch (const std::exception& e) {
                    std::cerr << "An exception occurred: " << e.what() << "\n";
                }
                break;

            case ELEVEN:
                // run test
                Test t;
                t.testDefaultDateConstructor();
                t.testParameterizedDateConstructor();
                t.testDateSetAndGetMethods();
                t.testParseDateString();
                t.testDateComparisonOperators();
                t.testAirQualityDefaultConstructor();
                t.testAirQualityParameterizedConstructor();
                t.testAirQualitySetAndGetMethods();
                t.runTest();
                break;

            case ZERO:
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }

    } while (choice != ZERO);

    return 0;
}