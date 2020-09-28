#include "BalanceSheet.h"


void BalanceSheet::setId(int newId)
{
    if(newId>=0)
        id = newId;
}

void BalanceSheet::setUserId(int newUserId)
{
    if(newUserId>=0)
        userId = newUserId;
}

void BalanceSheet::setDate(string newDate)
{
    date = newDate;
}
void BalanceSheet::setItem(string newItem)
{
    item = newItem;
}

void BalanceSheet::setAmount(double newAmount)
{
    amount = newAmount;
}

int BalanceSheet::getId()
{
    return id;
}

int BalanceSheet::getUserId()
{
    return userId;
}

string BalanceSheet::getDate()
{
    return date;
}

string BalanceSheet::getItem()
{
    return item;
}

double BalanceSheet::getAmount()
{
    return amount;
}




