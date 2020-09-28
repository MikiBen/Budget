#ifndef BUDGETFILE_H
#define BUDGETFILE_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "BalanceSheet.h"
#include "SupplementaryMethods.h"

#include "Markup.h"
using namespace std;

class BudgetFile
{

    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

    BalanceSheet getIncomeData(string balanceSheetDataWithVerticalLines);
    string convertBalanceSheetDataToSingleLineFromDataSeperatedByVerticalLine(BalanceSheet income);

public:
    BudgetFile(string incomesFileName, string expensesFileName):
        INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName)
    {};

    vector<BalanceSheet> loadIncomeOfLoggedUserFromFile(int loggedUserId);
    vector<BalanceSheet> loadExpenseOfLoggedUserFromFile(int loggedUserId);
    int loadLastIncomeId();
    int loadLastExpenseId();
    void writeIncomeToFile(BalanceSheet income);
    void writeExpenseToFile(BalanceSheet Expense);
};
#endif
