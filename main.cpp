#include <iostream>

#include "Budget.h"

using namespace std;

char loadSign()
{
    string line = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, line);

        if (line.length() == 1)
        {
            sign = line[0];
            break;
        }
        cout << "Wrong sign" << endl;
    }
    return sign;
}

char chooseOprionFromMEnu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. End program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = loadSign();

    return choice;
}

int main()
{
    char choice;
    while (true)
    {
            choice = chooseOprionFromMEnu();
            Budget budget ("Users.xml","Incomes.xml", "Expenses.xml");

            switch (choice)
            {
            case '1':
                budget.userRegistration();
                break;
            case '2':
                budget.logInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "We do not have this options" << endl << endl;
                system("pause");
                break;
            }
    }

    return 0;
}

