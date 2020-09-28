#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;
class UserManager
{

    int loggedUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;
    const string nazwaPliku;

    User writeNewUserData();


    bool isUserLoginExist(string login);
    int loadNewUserId();

public:

    UserManager(string usersFileName): fileWithUsers(usersFileName)
    {
        loggedUserId= 0;
        users = fileWithUsers.loadUserFromFile();

    };

    bool checkUserLoggingIn();
    void userRegistration();
    void logInUser();
    int loadLoggedUserId();
    void logOutUser();
    void changeUserPassword();

};
#endif
