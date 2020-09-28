#ifndef SUPPLEMENTARYMETHODS_H
#define SUPPLEMENTARYMETHODS_H

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "BalanceSheet.h"
#include "Date.h"

using namespace std;

class SupplementaryMethods
{

public:

    static string conversionIntToString(int number);
    static string conversionDoubleToString(double number);
    static string loadLine();
    static char selectOptionsFromBudgetMenu();
    static Date convertDateToProperFormat(string date);
    static char loadSign();
    static string addAmount();
    static     vector<BalanceSheet> sorting(vector<BalanceSheet> balanceSheet);

};

#endif
