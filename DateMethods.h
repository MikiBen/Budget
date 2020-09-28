#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <ctime>
#include <cstdio>

#include "SupplementaryMethods.h"
#include "Date.h"

using namespace std;

class DateMethods
{
    static int checkHowManyDaysHaveMonth(int monthNumber, int year);
    static bool checkLeapYear(int year);
public:

    static string loadActualDate();
    static bool checkDate(string date);
    static string addZeroInDate(string date);
    static string  addDate();
    static int loadActualMonth();
    static int loadActualYear();
    static int loadYearFromDate(string date);
    static int loadMonthFromDate(string date);
    static int loadDayFromDate(string date);
    static string addDateManualy();
    static bool checkPeriod(string dateOfBeginPeriod, string dateOfEndPeriod);
    static int convesrionDateToInt(string date);

};
#endif
