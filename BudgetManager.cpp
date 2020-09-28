#include "BudgetManager.h"


void BudgetManager::loadIncomeOfLoggedUserFromFile()
{
    incomes = budgetfile.loadIncomeOfLoggedUserFromFile(LOGGED_USER_ID);
}

void BudgetManager::loadExpenseOfLoggedUserFromFile()
{
    expenses = budgetfile.loadExpenseOfLoggedUserFromFile(LOGGED_USER_ID);
}

void BudgetManager::display(vector<BalanceSheet> balanceSheet)
{
    for (int i=0; i<balanceSheet.size(); i++)
    {
        cout<<balanceSheet[i].getDate()<<endl;
        cout<<balanceSheet[i].getItem()<<endl;
        cout<<balanceSheet[i].getAmount()<<" PLN"<<endl<<endl;
    }
}

void BudgetManager::addIncome()
{
    BalanceSheet income;

    system("cls");
    cout << " >>> Add income <<<" << endl << endl;
    income = writeIncome();

    incomes.push_back(income);
    budgetfile.writeIncomeToFile(income);
}

void BudgetManager::addExpense()
{
    BalanceSheet expense;

    system("cls");
    cout << " >>> Add expense <<<" << endl << endl;
    expense = writeExpense();
    expenses.push_back(expense);
    budgetfile.writeExpenseToFile(expense);
}

BalanceSheet BudgetManager::writeExpense()
{
    BalanceSheet expense;
    int id =   budgetfile.loadLastExpenseId()+1;
    char choice;

    expense.setId(id);
    expense.setUserId(LOGGED_USER_ID);

    cout << "Expense is from today? "<<endl;
    expense.setDate(DateMethods::addDate());

    cout << "Write item: ";

    expense.setItem(SupplementaryMethods::loadLine());
    expense.setAmount(stod(SupplementaryMethods::addAmount()));

    return expense;
}


BalanceSheet BudgetManager::writeIncome()
{
    BalanceSheet income;
    int id =   budgetfile.loadLastIncomeId()+1;
    char choice;

    income.setId(id);
    income.setUserId(LOGGED_USER_ID);
    cout << "Income is from today? "<<endl;
    income.setDate(DateMethods::addDate());

    cout << "Write item: ";

    income.setItem(SupplementaryMethods::loadLine());
    income.setAmount(stod(SupplementaryMethods::addAmount()));

    return income;
}

void BudgetManager::displayBalanceSheetForCurrentMonth()
{
    vector<BalanceSheet> incomesForCurrentMonth;
    vector<BalanceSheet> expensesForCurrentMonth;
    double incomesSumary=0;
    double expensesSumary=0;
    int actualYear;
    int actualMonth;

    actualMonth =DateMethods::loadActualMonth();
    actualYear =DateMethods::loadActualYear();


    for (int i=0; i<incomes.size(); i++)
    {

        if(DateMethods::loadYearFromDate(incomes[i].getDate())==actualYear&&DateMethods::loadMonthFromDate(incomes[i].getDate())==actualMonth)
        {
            incomesSumary += incomes[i].getAmount();
            incomesForCurrentMonth.push_back(incomes[i]);
        }
    }
    for (int i=0; i<expenses.size(); i++)
    {

        if(DateMethods::loadYearFromDate(expenses[i].getDate())==actualYear&&DateMethods::loadMonthFromDate(expenses[i].getDate())==actualMonth)
        {
            expensesSumary += expenses[i].getAmount();
            expensesForCurrentMonth.push_back(expenses[i]);
        }
    }


    incomesForCurrentMonth = SupplementaryMethods::sorting( incomesForCurrentMonth);
    expensesForCurrentMonth = SupplementaryMethods::sorting( expensesForCurrentMonth);
    system("cls");
    cout<<" INCOMES:"<<endl;
    display(incomesForCurrentMonth);
    cout<<" EXPENSES:"<<endl;
    display(expensesForCurrentMonth);

    cout<< " INCOMES: "<<incomesSumary<< " PLN"<<endl;
    cout<< " EXPENSES: "<<expensesSumary<< " PLN"<<endl;
    cout<< " Balance "<<incomesSumary - expensesSumary<< " PLN"<<endl;
    system("pause");
}

void BudgetManager::displayBalanceSheetForLastMonth()
{
    vector<BalanceSheet> incomesForLastMonth;
    vector<BalanceSheet> expensesForLastMonth;
    double incomesSumary=0;
    double expensesSumary=0;
    int actualYear;
    int LastMonth;

    LastMonth =DateMethods::loadActualMonth()-1;
    actualYear =DateMethods::loadActualYear();

    if(LastMonth==0)
    {
        LastMonth=12;
        actualYear = actualYear-1;
    }

    for (int i=0; i<incomes.size(); i++)
    {

        if(DateMethods::loadYearFromDate(incomes[i].getDate())==actualYear&&DateMethods::loadMonthFromDate(incomes[i].getDate())==LastMonth)
        {
            incomesSumary += incomes[i].getAmount();
            incomesForLastMonth.push_back(incomes[i]);
        }
    }
    for (int i=0; i<expenses.size(); i++)
    {

        if(DateMethods::loadYearFromDate(expenses[i].getDate())==actualYear&&DateMethods::loadMonthFromDate(expenses[i].getDate())==LastMonth)
        {
            expensesSumary += expenses[i].getAmount();
            expensesForLastMonth.push_back(expenses[i]);
        }
    }
    incomesForLastMonth = SupplementaryMethods::sorting( incomesForLastMonth);
    expensesForLastMonth = SupplementaryMethods::sorting( expensesForLastMonth);

    system("cls");
    cout<<" INCOMES:"<<endl;
    display(incomesForLastMonth);
    cout<<" EXPENSES:"<<endl;
    display(expensesForLastMonth);

    cout<< " INCOMES: "<<incomesSumary<< " PLN"<<endl;
    cout<< " EXPENSES: "<<expensesSumary<< " PLN"<<endl;
    cout<< " Balance "<<incomesSumary - expensesSumary<< " PLN"<<endl;
    system("pause");
}


void BudgetManager::displayBalanceSheetForSelectedPeriod()
{
    vector<BalanceSheet> incomesForSelectedPeriod;
    vector<BalanceSheet> expensesForSelectedPeriod;
    double incomesSumary=0;
    double expensesSumary=0;
    string dateOfBeginPeriod;
    string dateOfEndPeriod;
    string checkedDate;

    do
    {
        cout<<"Begin of the period: "<<endl;
        dateOfBeginPeriod = DateMethods::addDateManualy();
        cout<<"End of the period: "<<endl;
        dateOfEndPeriod = DateMethods::addDateManualy();


    }
    while(DateMethods::checkPeriod(dateOfBeginPeriod, dateOfEndPeriod)==false);
    for(int i=0; i<incomes.size(); i++)
    {
        checkedDate = incomes[i].getDate();
        if(dateOfBeginPeriod<=checkedDate&&checkedDate<=dateOfEndPeriod)
        {
            incomesSumary += incomes[i].getAmount();
            incomesForSelectedPeriod.push_back(incomes[i]);
        }

    }

    for(int i=0; i<expenses.size(); i++)

    {
        checkedDate = expenses[i].getDate();
        if(dateOfBeginPeriod<=checkedDate&&checkedDate<=dateOfEndPeriod)
        {
            expensesSumary += expenses[i].getAmount();
            expensesForSelectedPeriod.push_back(expenses[i]);
        }
    }

    incomesForSelectedPeriod = SupplementaryMethods::sorting( incomesForSelectedPeriod);
    expensesForSelectedPeriod = SupplementaryMethods::sorting( expensesForSelectedPeriod);
    system("cls");



    cout<<" INCOMES:"<<endl;
    display(incomesForSelectedPeriod);
    cout<<" EXPENSES:"<<endl;
    display(expensesForSelectedPeriod);

    cout<< " INCOMES: "<<incomesSumary<< " PLN"<<endl;
    cout<< " EXPENSES: "<<expensesSumary<< " PLN"<<endl;
    cout<< " Balance "<<incomesSumary - expensesSumary<< " PLN"<<endl;
    system("pause");

}

