#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "User.h"
#include "SupplementaryMethods.h"
#include "Markup.h"


using namespace std;
class FileWithUsers
{
    string USER_FILE_NAME;
   string convertUserDataToSingleLineFromDataSeperatedByVerticalLine(User user);
   User getUserData(string userDataWithVerticalLines);

public:
    FileWithUsers(string nameFile) : USER_FILE_NAME(nameFile) {};


    vector<User> loadUserFromFile();
    void saveUserInToTheFile(User user);
    void saveAllUsersIntoTheFile(vector <User> users);

};
#endif
