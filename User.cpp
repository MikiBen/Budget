#include "User.h"

void User::setUserId(int newUserId)
{
    if(newUserId>=0)
    userId = newUserId;
}

void User::setUserLogin(string newUserLogin)
{
    userLogin = newUserLogin;
}

void User::setPassword(string newPassword)
{
    password = newPassword;
}

int User::getUserId()
{
    return userId;
}

string User::getUserLogin()
{
    return userLogin;
}

string User::getPassword()
{
    return password;
}
