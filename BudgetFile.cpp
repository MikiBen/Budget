#include "BudgetFile.h"

vector<BalanceSheet> BudgetFile::loadIncomeOfLoggedUserFromFile(int loggedUserId)
{
    CMarkup xml;
    BalanceSheet income;
    string balanceSheetDataWithVerticalLines;
    vector <BalanceSheet> incomes;

    xml.Load(INCOMES_FILE_NAME);

    while ( xml.FindElem("INCOMES") )
    {
        xml.IntoElem();
        while(xml.FindElem( "INCOME" ))
        {
            balanceSheetDataWithVerticalLines =  xml.GetData();
            income = getIncomeData(balanceSheetDataWithVerticalLines);
            if(loggedUserId==income.getUserId())
                incomes.push_back(income);
        }
    }
    return incomes;
}


BalanceSheet BudgetFile::getIncomeData(string balanceSheetDataWithVerticalLines)
{
    BalanceSheet balanceSheet;
    string singleBalananceSheetData= "";
    int numberOfSingleSign = 1;

    for (int positionOfSign = 0; positionOfSign < balanceSheetDataWithVerticalLines.length(); positionOfSign++)
    {
        if (balanceSheetDataWithVerticalLines[positionOfSign] != '|')
        {
            singleBalananceSheetData += balanceSheetDataWithVerticalLines[positionOfSign];
        }
        else
        {
            switch(numberOfSingleSign)
            {
            case 1:
                balanceSheet.setId(atoi(singleBalananceSheetData.c_str()));
                break;
            case 2:
                balanceSheet.setUserId(atoi(singleBalananceSheetData.c_str()));
                break;
            case 3:
                balanceSheet.setDate(singleBalananceSheetData);

                break;
            case 4:
                balanceSheet.setItem(singleBalananceSheetData);
                break;
            case 5:
                balanceSheet.setAmount(stod(singleBalananceSheetData));
                break;
            }
            singleBalananceSheetData = "";
            numberOfSingleSign++;
        }

    }

    return balanceSheet;
}

int BudgetFile::loadLastIncomeId()
{
    CMarkup xml;
    BalanceSheet income;
    string balanceSheetDataWithVerticalLines="0|0|0|0|0|";

    if(xml.Load(INCOMES_FILE_NAME)==false)
        return 0;
    else
    {
        while ( xml.FindElem("INCOMES") )
        {

            xml.IntoElem();
            while(xml.FindElem( "INCOME" ))
            {

                balanceSheetDataWithVerticalLines =  xml.GetData();
            }
        }
        income = getIncomeData(balanceSheetDataWithVerticalLines);
        return income.getId();
    }

}

int BudgetFile::loadLastExpenseId()
{
    CMarkup xml;
    BalanceSheet expense;
    string balanceSheetDataWithVerticalLines="0|0|0|0|0|";
    if(xml.Load(EXPENSES_FILE_NAME)==false)
        return 0;
    else
    {
        while ( xml.FindElem("EXPENSES") )
        {

            xml.IntoElem();
            while(xml.FindElem( "EXPENSE" ))
            {

                balanceSheetDataWithVerticalLines =  xml.GetData();
            }
        }
        expense = getIncomeData(balanceSheetDataWithVerticalLines);
        return expense.getId();
    }

}
void BudgetFile::writeIncomeToFile(BalanceSheet income)
{

    CMarkup xml;
    string lineWithBalanceSheetData = "";
    lineWithBalanceSheetData = convertBalanceSheetDataToSingleLineFromDataSeperatedByVerticalLine(income);
    xml.Load(INCOMES_FILE_NAME);


    if (xml.FindElem("INCOMES") == true)
    {
        xml.IntoElem();
        xml.AddElem( "INCOME", lineWithBalanceSheetData);
        xml.Save( INCOMES_FILE_NAME);
    }
    else
    {
        xml.AddElem( "INCOMES" );
        xml.IntoElem();
        xml.AddElem( "INCOME", lineWithBalanceSheetData);
        xml.Save(INCOMES_FILE_NAME);
    }
}
void BudgetFile::writeExpenseToFile(BalanceSheet expense)
{
    CMarkup xml;
    string lineWithBalanceSheetData = "";
    lineWithBalanceSheetData = convertBalanceSheetDataToSingleLineFromDataSeperatedByVerticalLine(expense);
    xml.Load(EXPENSES_FILE_NAME);


    if (xml.FindElem("EXPENSES") == true)
    {
        xml.IntoElem();
        xml.AddElem( "EXPENSE", lineWithBalanceSheetData);
        xml.Save( EXPENSES_FILE_NAME);
    }
    else
    {
        xml.AddElem( "EXPENSES" );
        xml.IntoElem();
        xml.AddElem( "EXPENSE", lineWithBalanceSheetData);
        xml.Save(EXPENSES_FILE_NAME);
    }
}


string BudgetFile::convertBalanceSheetDataToSingleLineFromDataSeperatedByVerticalLine(BalanceSheet income)
{
    string lineWithBalanceSheetData="";

    lineWithBalanceSheetData =SupplementaryMethods::conversionIntToString(income.getId())+"|" + SupplementaryMethods::conversionIntToString(income.getUserId())+"|" +
                              income.getDate()+"|"+income.getItem()+"|"+SupplementaryMethods::conversionDoubleToString(income.getAmount())+"|";
    return lineWithBalanceSheetData;
}

vector<BalanceSheet> BudgetFile::loadExpenseOfLoggedUserFromFile(int loggedUserId)
{
    CMarkup xml;
    BalanceSheet expense;
    string balanceSheetDataWithVerticalLines;
    vector <BalanceSheet> expenses;

    xml.Load(EXPENSES_FILE_NAME);

    while ( xml.FindElem("EXPENSES") )
    {

        xml.IntoElem();
        while(xml.FindElem( "EXPENSE" ))
        {
            balanceSheetDataWithVerticalLines =  xml.GetData();
            expense = getIncomeData(balanceSheetDataWithVerticalLines);
            if(loggedUserId==expense.getUserId())
                expenses.push_back(expense);
        }

    }
    return expenses;
}
