#ifndef BUDGET_H
#define BUDGET_H

#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class Budget
{
    UserManager userManager;
    BudgetManager *budgetManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;
    void BudgetMenu();
    void logOutUser();
    void changeUserPassword();
    void loadIncomeOfLoggedUserFromFile();
    void addIncome ();
    void addExpense ();
    void displayBalanceSheetForCurrentMonth();
    void displayBalanceSheetForLastMonth();
    void displayBalanceSheetForSelectedPeriod();

public:
        Budget(string usersFileName,string incomesFileName, string expensesFileName ):
            userManager(usersFileName),INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName)
    {
        budgetManager = NULL;
    };
    ~Budget()
    {
        delete budgetManager;
        budgetManager= NULL;
    }
     void logInUser();
     void userRegistration();

};
#endif
