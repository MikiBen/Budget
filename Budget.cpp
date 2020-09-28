#include "Budget.h"

void Budget::logInUser()
{
    userManager.logInUser();
    if(userManager.checkUserLoggingIn())
    {
        budgetManager = new BudgetManager(INCOMES_FILE_NAME,EXPENSES_FILE_NAME,userManager.loadLoggedUserId());

        BudgetMenu();
    }
}

void Budget::userRegistration()
{
    userManager.userRegistration();
}

void Budget::addIncome()
{
    budgetManager->addIncome();
}

void Budget::addExpense()
{
    budgetManager->addExpense();
}

void Budget::displayBalanceSheetForCurrentMonth()
{
    budgetManager->displayBalanceSheetForCurrentMonth();
}

void Budget::displayBalanceSheetForLastMonth()
{
    budgetManager->displayBalanceSheetForLastMonth();
}

void Budget::displayBalanceSheetForSelectedPeriod()
{
    budgetManager->displayBalanceSheetForSelectedPeriod();
}

void Budget::BudgetMenu()
{
    char choice;
    while(true)
    {
        choice = SupplementaryMethods::selectOptionsFromBudgetMenu();
        switch (choice)
        {
        case '1':
            addIncome();
            break;
        case '2':
            addExpense();
            break;
        case '3':
            displayBalanceSheetForCurrentMonth();
            break;
        case '4':
            displayBalanceSheetForLastMonth();
            break;
        case '5':
            displayBalanceSheetForSelectedPeriod();
            break;
        case '8':
            changeUserPassword();
            break;
        case '9':
            logOutUser();
            return;
        }
    }
}

void Budget::logOutUser()
{
    userManager.logOutUser();
    delete budgetManager;
    budgetManager = NULL;
}

void Budget::changeUserPassword()
{
    userManager.changeUserPassword();
}

void Budget::loadIncomeOfLoggedUserFromFile()
{
    budgetManager->loadIncomeOfLoggedUserFromFile();
}


