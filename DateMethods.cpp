#include "DateMethods.h"


string DateMethods::loadActualDate()
{
    string actualDate;
    time_t actualTime = time( 0 );
    tm * time = localtime( & actualTime );


    int actualYear = 1900 + time->tm_year;
    int actualMonth = 1 + time->tm_mon;
    int actualDay = time->tm_mday;

    actualDate=SupplementaryMethods::conversionIntToString(actualYear) + "-" + SupplementaryMethods::conversionIntToString(actualMonth) + "-" +
               SupplementaryMethods::conversionIntToString(actualDay) ;
    return actualDate;
}

int DateMethods::loadActualYear()
{
    string actualDate;
    time_t actualTime = time( 0 );
    tm * time = localtime( & actualTime );


    int actualYear = 1900 + time->tm_year;
    return actualYear;
}

int DateMethods::loadActualMonth()
{
    string actualDate;
    time_t actualTime = time( 0 );
    tm * time = localtime( & actualTime );


    int actualMonth = 1 + time->tm_mon;
    return actualMonth;
}

int DateMethods::checkHowManyDaysHaveMonth(int monthNumber, int year)
{
    int numberOfDays;

    switch( monthNumber )
    {
    case 1:
    {
        numberOfDays = 31;
        break;
    }
    case 2:
    {
        if(checkLeapYear(year)==1)
            numberOfDays = 29;
        else numberOfDays=28;
        break;
    }
    case 3:
    {
        numberOfDays = 31;
        break;
    }
    case 4:
    {
        numberOfDays = 30;
        break;
    }
    case 5:
    {
        numberOfDays = 31;
        break;
    }
    case 6:
    {
        numberOfDays = 30;
        break;
    }
    case 7:
    {
        numberOfDays = 31;
        break;
    }
    case 8:
    {
        numberOfDays = 31;
        break;
    }
    case 9:
    {
        numberOfDays = 30;
        break;
    }
    case 10:
    {
        numberOfDays = 31;
        break;
    }
    case 11:
    {
        numberOfDays = 30;
        break;
    }
    case 12:
    {
        numberOfDays = 31;
        break;
    }
    }

    return numberOfDays;
}


bool DateMethods::checkLeapYear(int year)
{
    return(year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

bool DateMethods::checkDate(string checkedDateInString)
{
    Date checkedDate;
    Date actualDate;
    checkedDate = SupplementaryMethods::convertDateToProperFormat(checkedDateInString);
    actualDate = SupplementaryMethods::convertDateToProperFormat(loadActualDate());

    if(checkedDate.getYear()>=2000&&checkedDate.getYear()<actualDate.getYear())
    {

        if(checkedDate.getMonth()>0&&checkedDate.getMonth()<=12)
            if(checkedDate.getDay()>0&&checkedDate.getDay()<=DateMethods::checkHowManyDaysHaveMonth(checkedDate.getMonth(), checkedDate.getYear()))
            {

                return true;
            }
    }
    else if(checkedDate.getYear()==actualDate.getYear())
    {
        if(checkedDate.getMonth()>0&&checkedDate.getMonth()<=actualDate.getMonth())
            if(checkedDate.getDay()>0&&checkedDate.getDay()<=DateMethods::checkHowManyDaysHaveMonth(checkedDate.getMonth(), checkedDate.getYear()))
            {

                return true;
            }
    }
    else
    {

        return false;
    }


}
string DateMethods::addZeroInDate(string date)
{

    Date checkedDate;
    string DateInFormatYYYMMDD;
    checkedDate = SupplementaryMethods::convertDateToProperFormat(date);

    DateInFormatYYYMMDD = SupplementaryMethods::conversionIntToString(checkedDate.getYear()) +"-";

    if(checkedDate.getMonth()<10)
        DateInFormatYYYMMDD = DateInFormatYYYMMDD +"0" + SupplementaryMethods::conversionIntToString(checkedDate.getMonth()) +"-";
    else
        DateInFormatYYYMMDD = DateInFormatYYYMMDD +SupplementaryMethods::conversionIntToString(checkedDate.getMonth()) +"-";

    if(checkedDate.getDay()<10)
        DateInFormatYYYMMDD = DateInFormatYYYMMDD + "0" + SupplementaryMethods::conversionIntToString(checkedDate.getDay());
    else
        DateInFormatYYYMMDD = DateInFormatYYYMMDD +SupplementaryMethods::conversionIntToString(checkedDate.getDay());


    return DateInFormatYYYMMDD;
}

string  DateMethods::addDate()
{
    char choice;
    string date;
    cout <<endl<<"Y/N"<<endl;
    choice=SupplementaryMethods::loadSign();
    if(choice =='Y'||choice=='y' )
    {
        return addZeroInDate(loadActualDate());
    }
    else
    {
        return addDateManualy();
    }

}

string DateMethods::addDateManualy()
{
    cout << "Write date: ";
    string date = SupplementaryMethods::loadLine();

    while(checkDate( date)==false)
    {
        cout << "You write wrong date: "<<endl<<"Write date: ";
        date = SupplementaryMethods::loadLine();

    }
    date = addZeroInDate(date);
    return date;
}

int  DateMethods::loadYearFromDate(string date)
{
    Date checkedDate;
    checkedDate = SupplementaryMethods::convertDateToProperFormat(date);

    return checkedDate.getYear();
}

int  DateMethods::loadMonthFromDate(string date)
{
    Date checkedDate;
    checkedDate = SupplementaryMethods::convertDateToProperFormat( date);

    return checkedDate.getMonth();
}

int  DateMethods::loadDayFromDate(string date)
{
    Date checkedDate;
    checkedDate = SupplementaryMethods::convertDateToProperFormat( date);

    return checkedDate.getDay();
}


bool DateMethods::checkPeriod(string dateOfBeginPeriod, string dateOfEndPeriod)
{
    Date beginPeriod;
    Date endPeriod;

    beginPeriod = SupplementaryMethods::convertDateToProperFormat( dateOfBeginPeriod);
    endPeriod = SupplementaryMethods::convertDateToProperFormat( dateOfEndPeriod);

    if (beginPeriod.getYear()<endPeriod.getYear())
    {
        return true;
    }
    else if (beginPeriod.getYear()==endPeriod.getYear())
    {
        if (beginPeriod.getMonth()<endPeriod.getMonth())
            return true;
    }
    else if (beginPeriod.getMonth()==endPeriod.getMonth())
    {
        if (beginPeriod.getDay()<=endPeriod.getDay())
            return true;
    }
    cout<< " You write wrong period ";
    system("pause");
    return false;

}

int DateMethods::convesrionDateToInt(string date)
{
    string dateWithoutDash = "";
    for (int positionOfSign = 0; positionOfSign < date.length(); positionOfSign++)
    {
        if(date[positionOfSign]>=48&&date[positionOfSign]<=57)
            dateWithoutDash += date[positionOfSign];
    }
    return atoi(dateWithoutDash.c_str());

}





