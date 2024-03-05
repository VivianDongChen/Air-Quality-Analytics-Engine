
#include "Test.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Vector.h"
#include "Time.h"
#include "Date.h"
#include "MenuFunction.h"
#include "AirQuality.h"
#include "MinHeap.h"
#include <cassert>
#include <map>

using namespace std;

const double NEGATIVE_ONE = -1.0;
const int ONE = 1;
const int ZERO = 0;
const int TWO = 2;
const int THREE = 3;
const int FOUR = 4;
const int FIVE = 5;
const int SIX = 6;
const int SEVEN = 7;
const int EIGHT = 8;
const int NINE = 9;
const int ELEVEN = 11;
const int TEN = 10;
const int TWELVE = 12;
const int FIFTEEN = 15;
const int TWENTY_FIVE =25;
const int THIRTY = 30;
const int FORTY_FIVE = 45;
const int YEAR = 2023;
const int YEAR1 = 2005;
const int YEAR2 = 2000;
const int YEAR3 = 2021;
const int YEAR4 = 2022;
const int YEAR5 = 2004;



const int SIZE = 1000;
const double C1 = 20.3;
const double C2 = 25.5;
const double C3 = 12.3;
const double C4 = 50.0;
const double C5 = 28.0;
const double C6 = 15.2;
const double C7 = 45.0;
const double C8 = 60.0;
const double C9 =10.5;
const double C10 = -8.85168;
const double C11 = 35.5285;
const double C12 = -15.8148;
const double C13 = -9999.0;



void areAlmostEqual(double num1, double num2, int decimalPlaces) {
    double roundedNum1 = std::round(num1 * std::pow(TEN, decimalPlaces)) / std::pow(TEN, decimalPlaces);
    double roundedNum2 = std::round(num2 * std::pow(TEN, decimalPlaces)) / std::pow(TEN, decimalPlaces);
    if (roundedNum1 == roundedNum2){
        cout << "Two Number Match";
    }
    else{
        cout << "Two Number Not Match";
    }

}

void Test::testDefaultDateConstructor() {
    Date date;
    assert(date.getDay() == ONE);
    assert(date.getMonth() == ONE);
    assert(date.getYear() == YEAR2);
    std::cout << "Default Constructor Test Passed\n";
}

void Test::testParameterizedDateConstructor() {
    Date date(TWELVE, ELEVEN, YEAR3);
    assert(date.getDay() == TWELVE);
    assert(date.getMonth() == ELEVEN);
    assert(date.getYear() == YEAR3);
    std::cout << "Parameterized Constructor Test Passed\n";
}

void Test::testDateSetAndGetMethods() {
    Date date;
    date.setDay(FIFTEEN);
    date.setMonth(TEN);
    date.setYear(YEAR4);

    assert(date.getDay() == FIFTEEN);
    assert(date.getMonth() == TEN);
    assert(date.getYear() == YEAR4);
    std::cout << "Set and Get Methods Test Passed\n";
}

void Test::testParseDateString() {
    Date date = Date::parseDateString("10/15/2022");
    assert(date.getDay() == FIFTEEN);
    assert(date.getMonth() == TEN);
    assert(date.getYear() == YEAR4);
    std::cout << "Parse Date String Test Passed\n";
}

void Test::testDateComparisonOperators() {
    Date date1(ONE, ONE, YEAR2);
    Date date2(ONE, ONE, YEAR2);
    Date date3(TWO, ONE, YEAR2);

    assert(date1 == date2);
    assert(date1 != date3);
    assert(date3 > date1);
    assert(date1 < date3);
    assert(date1 <= date2);
    assert(date3 >= date1);
    std::cout << "Comparison Operators Test Passed\n";
}

void Test::testAirQualityDefaultConstructor() {
    AirQuality airQuality;
    assert(airQuality.getDate() == Date(ONE, ONE, 1800));
    assert(airQuality.getTime() == Time(ZERO, ZERO, ZERO));
    assert(airQuality.getTemp() == C13);
    assert(airQuality.getAbsoluteHumidity() == C13);
    assert(airQuality.getRelativeHumidity() == C13);
    std::cout << "AirQuality Default Constructor Test Passed\n";
}

void Test::testAirQualityParameterizedConstructor() {
    AirQuality airQuality(ONE, ONE, YEAR3, ONE, ONE, ONE, C1, C1, C1);
    assert(airQuality.getDate() == Date(ONE, ONE, YEAR3));
    assert(airQuality.getTime() == Time(ONE, ONE, ONE));
    assert(airQuality.getTemp() == C1);
    assert(airQuality.getAbsoluteHumidity() == C1);
    assert(airQuality.getRelativeHumidity() == C1);
    std::cout << "AirQuality Parameterized Constructor Test Passed\n";
}

void Test::testAirQualitySetAndGetMethods() {
    AirQuality airQuality;
    airQuality.setDate(Date(ONE, ONE,YEAR3));
    airQuality.setTime(Time(ONE, ONE, ONE));
    airQuality.setTemp(C1);
    airQuality.setAbsoluteHumidity(C1);
    airQuality.setRelHumidity(C1);

    assert(airQuality.getDate() == Date(ONE, ONE, YEAR3));
    assert(airQuality.getTime() == Time(ONE, ONE, ONE));
    assert(airQuality.getTemp() == C1);
    assert(airQuality.getAbsoluteHumidity() == C1);
    assert(airQuality.getRelativeHumidity() == C1);
    std::cout << "AirQuality Set and Get Methods Test Passed\n";
}

void Test::runTest(){

    cout << "Time Test "<<endl;

    Time t1;
    if (t1.getHour() == ZERO && t1.getMin() == ZERO && t1.getSec() == ZERO) {
        cout << "Default constructor and printTime function passed." << endl;
    } else {
        cout << "Default constructor and printTime function failed." << endl;
    }

    Time t2(TWELVE, THIRTY, FORTY_FIVE);
    if (t2.getHour() == TWELVE && t2.getMin() == THIRTY && t2.getSec() == FORTY_FIVE) {
        cout << "Parameterized constructor and printTime function passed." << endl;
    } else {
        cout << "Parameterized constructor and printTime function failed." << endl;
    }

    // set
    t1.setHour(EIGHT);
    t1.setMin(FORTY_FIVE);
    t1.setSec(FIFTEEN);
    if (t1.getHour() == EIGHT && t1.getMin() == FORTY_FIVE && t1.getSec() == FIFTEEN) {
        cout << "setHour,getHour,setMin,getMin,setSec,getSec,setTime,getTime functions passed." << endl;
    } else {
        cout << "setHour,getHour,setMin,getMin,setSec,getSec,setTime,getTime functions failed." << endl;
    }

    // compare
    if (t1 < t2) {
        cout << "Compare < pass" << endl;
    } else {
        cout << "Compare < not pass" << endl;
    }

    if (t1 != t2) {
        cout << "Compare !=  pass" << endl;
    } else {
        cout << "Compare !=  not pass" << endl;
    }

    if (t1 > t2) {
        cout << "Compare > not pass" << endl;
    } else {
        cout << "Compare >  pass"  << endl;
    }

    if (t1 <= t2) {
        cout << "Compare <= pass" << endl;
    } else {
        cout << "Compare <= not pass" << endl;
    }

    if (t1 >= t2) {
        cout << "Compare >= not pass" << endl;
    } else {
        cout << "Compare >=  pass" << endl;
    }

    string timeString = "10:45:30";
    Time t4 = Time::parseTimeString(timeString);
    Time t5(TEN, FORTY_FIVE, THIRTY);
    if (t4 == t5) {
        cout << "parseTimeString pass" << endl;
    } else {
        cout << "parseTimeString not pass" << endl;
    }

    Time t6(TWELVE, THIRTY, FORTY_FIVE);
    cout<<"Should print: "<< "Time: "<<TWELVE<<":"<<THIRTY<<":"<<TWENTY_FIVE<<endl;
    t6.printTime();
    cout <<endl;

// minHeap Test
    cout <<endl;

    cout << "MinHeap Test "<<endl;
    MinHeap minHeap;
    if (minHeap.isEmpty()) {
        cout << "Default constructor and isEmpty function passed." << endl;
    } else {
        cout << "Default constructor and isEmpty function not passed." << endl;
    }

    AirQuality air1(ONE, ONE, YEAR, TWELVE, ZERO, ZERO, C2, C3, C4);
    minHeap.insert(air1.getTemp(), air1);

    AirQuality air2(ONE, ONE, YEAR, TWELVE, FIFTEEN, ZERO, C5, C6, C7);
    minHeap.insert(air2.getTemp(), air2);

    AirQuality air3(ONE, ONE, YEAR, TWELVE, THIRTY, ZERO, C1, C9, C8);
    minHeap.insert(air3.getTemp(), air3);

    if (!minHeap.isEmpty()) {
        auto topElement = minHeap.top();
        if (topElement.first == C1 && topElement.second.getRelativeHumidity() == C8) {
            cout << "Top function passed." << endl;
        } else {
            cout << "Top function not passed." << endl;
        }
    } else {
        cout << "Insert and top functions not passed." << endl;
    }

    minHeap.pop();
    if (!minHeap.isEmpty()) {
        auto newTopElement = minHeap.top();
        if (newTopElement.first == C2 && newTopElement.second.getRelativeHumidity() == C4) {
            cout << "Pop function passed." << endl;
        } else {
            cout << "Pop function not passed." << endl;
        }
    } else {
        cout << "Pop function not passed." << endl;
    }

// MenuFunction Test
    cout << endl;
    cout <<endl;
    cout << "MenuFunction Test "<<endl;

     // read csv
     ifstream inFile("AirQualityUCI.csv");
    string line;

    if (!inFile) {
        std::cerr << "Unable to open file";
        return ;
    }

    // skip first line
    getline(inFile, line);

    Vector<AirQuality> airQualities;
    // create map to fast search
    map<Date, MinHeap> tempMap;
    map<Date, MinHeap> relHumMap;
    map<Date, MinHeap> absHumMap;


    while (getline(inFile, line)) {

        const int columnNeeded = FIVE;

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
        for (int i = ZERO; i < numberOfColumnsToIgnore; ++i) {
             ss.ignore(SIZE, ',');
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
        tempMap[Date(ZERO,date.getMonth(),date.getYear())].insert(NEGATIVE_ONE*temp,aq);
        relHumMap[Date(ZERO,date.getMonth(),date.getYear())].insert(NEGATIVE_ONE*relHumidity,aq);
        absHumMap[Date(ZERO,date.getMonth(),date.getYear())].insert(NEGATIVE_ONE*absHumidity,aq);

    }

    inFile.close();

    MenuFunction menu;
    Date date = Date(ZERO,ONE,YEAR1);

    cout << "Question1 Test "<<endl;
    double  q1 = menu.promptAvgTempOfMonth(tempMap,date);
    areAlmostEqual( C10, q1, FOUR);
    cout <<endl;

    cout << "Question2 Test "<<endl;
    double  q2 = menu.promptAvgRelHumOfMonth(relHumMap,date);
    areAlmostEqual(C11 , q2, FOUR);

    cout <<endl;
    cout << "Question3 Test "<<endl;
    double  q3 = menu.promptAvgAbsHumOfMonth(absHumMap,date);
    areAlmostEqual(C12 , q3, FOUR);

    cout <<endl;
    cout << "Question4 Test "<<endl;
    DateTime dateCheck = *new DateTime(Date(ONE,ONE,YEAR1),Time(ONE,ZERO,ZERO));
    menu.promptTempAndRelHumAtDateTime(relHumMap, dateCheck);
    cout << "Temperature: 5.325 \n"
            "Relative Humidity: 50.725"<<endl;
    cout <<endl;

    cout << "Question5 Test "<<endl;
    cout <<"Should print The highest temperature for this month: 16.875"<<endl;
    menu.promptHTempOfMonth(tempMap,date);


    cout <<endl;
    cout << "Question6 Test "<<endl;
    cout <<"Should print The highest relative humidity for this month: 83.225"<<endl;
    menu.promptHRelHumOfMonth(relHumMap,Date(ZERO,THREE,YEAR5));

    cout <<endl;
    cout << "Question7 Test "<<endl;
    cout <<"Should print The highest absolute humidity for this month: 1.05674"<<endl;
    menu.promptHAbsTempOfMonth(absHumMap,date);

    cout <<endl;
    cout << "Question8 Test "<<endl;
    double avg =menu.promptAvgTempOfMonth(tempMap,date);
    menu.promptTempAboveAvgOfMonth(tempMap,avg,date);
    cout <<"Last value should be Above:  Date:  29 1 2005\n"
           "Above value: 1 "<<endl;

    cout << "Question9 Test "<<endl;
    double avg1 =menu.promptAvgRelHumOfMonth(relHumMap,date);
    menu.promptRelHumAboveAvgOfMonth(relHumMap,avg1,date);
    cout <<"Last value should be Above  Date:  30 1 2005\n"
           "Above value: 35.6"<<endl;

    cout << "Question10 Test "<<endl;
    double avg2 = menu.promptAvgAbsHumOfMonth(absHumMap,date);
    menu.promptAbsHumAboveAvgOfMonth(absHumMap,avg2,date);
    cout <<"Last value should be Above  Date:  31 1 2005\n"
           "Above value: 0.247748 "<<endl;

    cout <<"Test complete"<<endl;
    cout <<endl;

};