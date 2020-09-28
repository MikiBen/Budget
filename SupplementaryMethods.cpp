#include "SupplementaryMethods.h"

string SupplementaryMethods::loadLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

string SupplementaryMethods::conversionIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
string SupplementaryMethods::conversionDoubleToString(double number)
{
    ostringstream strs;
    strs << number;
    string str = strs.str();
    return str;
}

char SupplementaryMethods::selectOptionsFromBudgetMenu()
{
    char choice;

    system("cls");
    cout << " >>> User Menu <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Balance sheet for  current month" << endl;
    cout << "4. Balance sheet for  last month" << endl;
    cout << "5. Balance sheet for the selected period" << endl;
    cout << "---------------------------" << endl;
    cout << "8. Change password" << endl;
    cout << "9. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = loadSign();

    return choice;
}

char SupplementaryMethods::loadSign()
{
    string input = "";
    char sign = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            sign = input[0];
            break;
        }
        cout << "This wrong sign." << endl;
    }

    return sign;

}

Date SupplementaryMethods::convertDateToProperFormat(string date)
{

    Date checkedDate;
    string singleSignDate= "";
    int numberOfSingleSign = 1;


    for (int positionOfSign = 0; positionOfSign < date.length(); positionOfSign++)
    {
        if (date[positionOfSign] != '-')
        {
            singleSignDate += date[positionOfSign];
        }
        else
        {
            switch(numberOfSingleSign)
            {
            case 1:
                checkedDate.setYear(atoi(singleSignDate.c_str()));
                break;
            case 2:
                checkedDate.setMonth(atoi(singleSignDate.c_str()));
                break;
            }
            singleSignDate = "";
            numberOfSingleSign++;
        }

    }
    checkedDate.setDay(atoi(singleSignDate.c_str()));
    return checkedDate;
}

string SupplementaryMethods::addAmount()
{
    string amount;
    cout << "Write amount: ";
    amount = loadLine();
    string singleSignAmount= "";

    for (int positionOfSign = 0; positionOfSign < amount.length(); positionOfSign++)
    {
        if(amount[positionOfSign]==',')
        {
            singleSignAmount += ".";
        }
        else singleSignAmount +=amount[positionOfSign];
    }

    return singleSignAmount;
}

vector<BalanceSheet> SupplementaryMethods::sorting(vector<BalanceSheet> balanceSheet)
{
    BalanceSheet temporaryBalanceSheet;

    for(int i=0; i<balanceSheet.size(); i++)
        for(int j=0; j<balanceSheet.size()-1; j++)
        {
            if(balanceSheet[j].getDate()>balanceSheet[j+1].getDate())
            {
                temporaryBalanceSheet = balanceSheet[j];
                balanceSheet[j] = balanceSheet[j+1]  ;
                balanceSheet[j+1] = temporaryBalanceSheet;
            }
        }
    return balanceSheet;
}


