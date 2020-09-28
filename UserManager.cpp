#include "UserManager.h"

void UserManager::logOutUser()
{
    loggedUserId=0;
}

bool UserManager::checkUserLoggingIn()
{
    if (loggedUserId>0)
        return true;
    else
        return false;
}

int UserManager::loadLoggedUserId()
{
    return loggedUserId;
}

void UserManager::userRegistration()
{
    User user = writeNewUserData();

    users.push_back(user);
    fileWithUsers.saveUserInToTheFile(user);

    cout << endl << "New profil created" << endl << endl;
    system("pause");
}

void UserManager::logInUser()
{
    string login = "", password = "";

    cout << endl << "Write login: ";
    login = SupplementaryMethods::loadLine();

    for (int i=0; i<users.size(); i++)
    {
        if (users[i].getUserLogin() == login)
        {
            for (int numberOfTries = 3; numberOfTries > 0; numberOfTries--)
            {
                cout << "Write password. Left tries: " << numberOfTries << ": ";
                password = SupplementaryMethods::loadLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "You log in." << endl << endl;
                    loggedUserId = users[i].getUserId();
                    system("pause");
                    return;
                }
            }
            cout << "You entered the wrong password 3 times." << endl;
            system("pause");
            return;
        }

    }
    cout << "No users with this login" << endl << endl;
    system("pause");
    return;
}

User UserManager::writeNewUserData()
{

    User user;

    user.setUserId(loadNewUserId());
    string login,password;
    do
    {
        cout << "Write login: ";
        cin>>login;
        user.setUserLogin(login);

    }
    while (isUserLoginExist(user.getUserLogin()) == true);

    cout << "Write password: ";
    cin>>password;
    user.setPassword(password);
    return user;
}

bool UserManager::isUserLoginExist(string login)
{
    for (int i=0; i<users.size(); i++)
    {

        if (users[i].getUserLogin() == login)
        {
            cout << endl << "User exist with this login." << endl;
            return true;
        }

    }
    return false;
}


int UserManager::loadNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

void UserManager::changeUserPassword()
{
    string newPassword = "";
    cout << "Write new password ";
    newPassword = SupplementaryMethods::loadLine();

    for (int i=0; i<users.size(); i++)
    {
        if (users[i].getUserId() == loggedUserId)
        {
            users[i].setPassword(newPassword);
            cout << "Password was change" << endl << endl;
            system("pause");
        }
    }

    fileWithUsers.saveAllUsersIntoTheFile(users);
}
