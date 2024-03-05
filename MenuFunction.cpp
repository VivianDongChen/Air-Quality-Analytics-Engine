#include <sstream>
#include "MenuFunction.h"
#include "Date.h"
#include "MinHeap.h"
#include <iostream>
#include <stdexcept>
#include <map>
#include "DateTime.h"
#include "Vector.h"

using namespace std;

const double NEGATIVE_ONE = -1.0;
const double ZERO = 0;
const double ONE = 1;
const double TWO = 2;
const double THREE = 3;
const double TWELE = 12;
const double MONTH_DAY = 31;

const int C1=24 ;
const int C2=60 ;



Vector<int> MenuFunction::splitString(const string& input, char delimiter) {
    istringstream ss(input);
    string token;
    Vector<int> tokens;

    while (getline(ss, token, delimiter)) {
        try {
            int intValue = stoi(token);
            tokens.push_back(intValue);
        } catch (const std::invalid_argument& e) {
            cerr << "Invalid argument: " << e.what() << endl;
        } catch (const std::out_of_range& e) {
            cerr << "Out of range: " << e.what() << endl;
        }
    }
    return tokens;
}

bool MenuFunction::isValidMonth(const Vector<int>& input) {
    return input.getSize() == TWO && input[ZERO] >= ONE && input[ZERO] <= TWELE && input[ONE] > ZERO;
}

bool MenuFunction::isValidDate(const Vector<int>& input) {
    return input.getSize() == THREE && input[ZERO] >= ONE && input[ZERO] <= MONTH_DAY && input[ONE] >= ONE && input[ONE] <= TWELE && input[TWO] > ZERO;
}

bool MenuFunction::isValidTime(const Vector<int>& input) {
    return input.getSize() == THREE && input[ZERO] >= ZERO && input[ZERO] < C1 && input[ONE] >= ZERO && input[ONE] < C2 && input[TWO] >= ZERO
           && input[TWO] <C2;
}

double MenuFunction::promptAvgTempOfMonth(map<Date, MinHeap> tempMap, Date monthYear) {
    auto it = tempMap.find(monthYear);
    if (it == tempMap.end()) {
        cout << "No temperature data for this month." << endl;
    } else {
        double avgTemp = NEGATIVE_ONE*(it->second.averageFirstElements());
        cout << "Average temperature for this month: " << avgTemp << endl;
        return avgTemp;
    }
}

double MenuFunction::promptAvgRelHumOfMonth(map<Date, MinHeap> relHumMap, Date monthYear) {
    auto it = relHumMap.find(monthYear);
    if (it == relHumMap.end()) {
        cout << "No relative humidity data for this month." << endl;
    } else {
        double avgRelHum = NEGATIVE_ONE*(it->second.averageFirstElements());
        cout << "Average relative humidity for this month: " << avgRelHum << endl;
        return avgRelHum;
    }
}

double MenuFunction::promptAvgAbsHumOfMonth(map<Date, MinHeap> absHumMap, Date monthYear) {
    auto it = absHumMap.find(monthYear);
    if (it == absHumMap.end()) {
        cout << "No absolute humidity data for this month." << endl;
    } else {
        double avgAbsHum = NEGATIVE_ONE*(it->second.averageFirstElements());
        cout << "Average absolute humidity for this month: " << avgAbsHum << endl;
        return avgAbsHum;
    }
}


void MenuFunction::promptTempAndRelHumAtDateTime(map<Date, MinHeap> mapMinHeap, DateTime dateTime) {
    // Creat monthYear
    int monthInput = dateTime.getDate().getMonth();
    int yearInput = dateTime.getDate().getYear();
    // find this monthYear in map
    Date monthYear = *new Date(ZERO,monthInput,yearInput);
    auto it = mapMinHeap.find(monthYear);
    if (it == mapMinHeap.end()) {
        cout << "No This Date data in file." << endl;
    }
    // find
    else {
        while (!mapMinHeap[monthYear].isEmpty()) {
            auto topElement = mapMinHeap[monthYear].top();
            AirQuality curAq = topElement.second;
            Date curDate = curAq.getDate();
            Time curTime =  curAq.getTime();
            // if find return
            if (curDate==dateTime.getDate() && curTime==dateTime.getTime() ) {
                cout<<"Temperature: " << curAq.getTemp()<<endl;
                cout<< "Relative Humidity: "<<curAq.getRelativeHumidity() <<endl;
                return;
            }
            // if not found get next
            mapMinHeap[monthYear].pop();
        }
        cout << "No time data of this month in file." << endl;
    }
}



void MenuFunction::displayHighestValue(map<Date, MinHeap>& dataMap, const string& dataType,Date monthYear) {
    auto it = dataMap.find(monthYear);

    if (it == dataMap.end()) {
        cout << "No data for this month." << endl;
    } else {
        double curValue = it->second.top().first * NEGATIVE_ONE ;
        cout << "The highest " << dataType << " for this month: " << curValue << endl;
    }
}

void MenuFunction::promptHTempOfMonth(map<Date, MinHeap> tempMap,Date monthYear) {
    displayHighestValue(tempMap, "temperature",monthYear);
}

void MenuFunction::promptHRelHumOfMonth(map<Date, MinHeap> relHumMap,Date monthYear) {
    displayHighestValue(relHumMap, "relative humidity",monthYear);
}

void MenuFunction::promptHAbsTempOfMonth(map<Date, MinHeap> absHumMap,Date monthYear) {
    displayHighestValue(absHumMap, "absolute humidity",monthYear);
}


void MenuFunction::displayValuesAboveAvgOfMonth(map<Date, MinHeap>& dataMap, double avgValue,Date montYear) {
    auto it = dataMap.find(montYear);

    if (it == dataMap.end()) {
        cout << "No data for this month." << endl;
    } else {

        while (!dataMap[montYear].isEmpty()) {
            auto topElement = dataMap[montYear].top();
            double curValue = NEGATIVE_ONE * topElement.first;

            if (curValue > avgValue) {
                cout << "Above";
                topElement.second.getDate().printDate();
                topElement.second.getTime().printTime();
                cout << endl;
                cout << "Above value: " << curValue << endl;
                cout << endl;
            } else {
                break;
            }

            dataMap[montYear].pop();
        }
    }
}



void MenuFunction::promptTempAboveAvgOfMonth(map<Date, MinHeap> tempMap, double avgValue,Date monthYear) {
    displayValuesAboveAvgOfMonth(tempMap, avgValue,monthYear);
}

void MenuFunction::promptRelHumAboveAvgOfMonth(map<Date, MinHeap> relHumMap, double avgValue,Date monthYear) {
    displayValuesAboveAvgOfMonth(relHumMap, avgValue,monthYear);
}

void MenuFunction::promptAbsHumAboveAvgOfMonth(map<Date, MinHeap> absHumMap, double avgValue,Date monthYear) {
    displayValuesAboveAvgOfMonth(absHumMap, avgValue,monthYear);
}

Date MenuFunction::cinDateYear() {
    string input;
    cin >> input;

    Vector<int> inputVector = splitString(input, '/');
    if (!isValidMonth(inputVector)) {
        throw invalid_argument("Invalid date and time format. Format Month/Year 1/2005");
    }

    int month = inputVector[ZERO];
    int year = inputVector[ONE];

    Date monthYear = Date(ZERO, month, year);
    return monthYear;
}


DateTime MenuFunction::cinTime(const string& dataType) {
    cout << "Enter the date and time, and the program will display " << dataType << " (format DD/MM/YYYY HH:MM:SS, e.g., 1/1/2005 1:0:0): " << endl;
    string input;
    getline(cin, input); // Read the entire line

    // Split the input into date and time parts
    stringstream ss(input);
    string datePart, timePart;

    // Read date part
    getline(ss, datePart, ' ');

    // Read time part
    getline(ss, timePart);

    // Parse the date part
    Vector<int> dateParts = splitString(datePart, '/');
    if (dateParts.getSize() != THREE || !isValidDate(dateParts)) {
        throw invalid_argument("Invalid date format. Expected format DD/MM/YYYY, e.g., 1/1/2005");
    }

    // Parse the time part
    Vector<int> timeParts = splitString(timePart, ':');
    if (timeParts.getSize() != THREE || !isValidTime(timeParts)) {
        throw invalid_argument("Invalid time format. Expected format HH:MM:SS, e.g., 1:0:0");
    }
    return DateTime(Date(dateParts[ZERO], dateParts[ONE], dateParts[TWO]), Time(timeParts[ZERO], timeParts[ONE], timeParts[TWO]));
}

