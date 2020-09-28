#ifndef USER_H
#define USER_H

#include <iostream>


using namespace std;

class User
{
    int userId;
    string userLogin;
    string password;

    public:
    void setUserId(int newUserId);
    void setUserLogin(string newUserLogin);
    void setPassword(string newPassword);

    int getUserId();
    string getUserLogin();
    string getPassword();

};
#endif
