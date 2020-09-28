#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#include <algorithm>

#include "BalanceSheet.h"
#include "BudgetFile.h"
#include "SupplementaryMethods.h"
#include "DateMethods.h"

using namespace std;

class BudgetManager
{

    const int LOGGED_USER_ID;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;
    BudgetFile budgetfile;

    vector<BalanceSheet> incomes;
    vector<BalanceSheet> expenses;
    vector<BalanceSheet> allIncomes;
    vector<BalanceSheet> allEpenses;

    BalanceSheet writeIncome();
    BalanceSheet writeExpense();

public:
    BudgetManager(string incomesFileName, string expensesFileName, int loggedUserId):
        budgetfile(incomesFileName, expensesFileName),LOGGED_USER_ID(loggedUserId)
    {

        incomes = budgetfile.loadIncomeOfLoggedUserFromFile(loggedUserId);
        expenses = budgetfile.loadExpenseOfLoggedUserFromFile(loggedUserId);
    };
    void loadIncomeOfLoggedUserFromFile();
    void loadExpenseOfLoggedUserFromFile();
    void addIncome();
    void addExpense();
    void displayBalanceSheetForCurrentMonth();
    void displayBalanceSheetForLastMonth();
    void displayBalanceSheetForSelectedPeriod();
    void display(vector<BalanceSheet> balanceSheet);
};
#endif
