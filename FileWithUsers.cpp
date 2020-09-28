#include "FileWithUsers.h"

vector<User> FileWithUsers::loadUserFromFile()
{
    CMarkup xml;
    User user;
    string userDataWithVerticalLines;
    vector <User> users;

    xml.Load(USER_FILE_NAME);

    while ( xml.FindElem("USERS") )
    {

        xml.IntoElem();
        while(xml.FindElem( "USER" ))
        {
            userDataWithVerticalLines =  xml.GetData();
            user = getUserData(userDataWithVerticalLines);
            users.push_back(user);
        }
    }

    return users;
}

void FileWithUsers::saveUserInToTheFile(User user)
{
    CMarkup xml;
    string lineWithUserData = "";
    lineWithUserData = convertUserDataToSingleLineFromDataSeperatedByVerticalLine(user);
    xml.Load(USER_FILE_NAME);


    if (xml.FindElem("USERS") == true)
    {
        xml.IntoElem();
        xml.AddElem( "USER", lineWithUserData);
        xml.Save( USER_FILE_NAME);
    }
    else
    {
        xml.AddElem( "USERS" );
        xml.IntoElem();
        xml.AddElem( "USER", lineWithUserData);
        xml.Save(USER_FILE_NAME);
    }
}

string FileWithUsers::convertUserDataToSingleLineFromDataSeperatedByVerticalLine(User user)
{
    string lineWithUserData="";

    lineWithUserData = SupplementaryMethods::conversionIntToString(user.getUserId())+"|" +  user.getUserLogin()+"|"+user.getPassword()+"|";
    return lineWithUserData;

}

void FileWithUsers::saveAllUsersIntoTheFile(vector <User> users)
{
    string lineWithUserData = "";
    CMarkup xml;

    xml.AddElem( "USERS" );
    xml.IntoElem();
    for (int i=0; i<users.size(); i++)
    {
        lineWithUserData = convertUserDataToSingleLineFromDataSeperatedByVerticalLine(users[i]);
        xml.AddElem( "USER", lineWithUserData);
    }

    xml.Save(USER_FILE_NAME);
}

User FileWithUsers::getUserData(string userDataWithVerticalLines)
{

    User user;
    string singleUserData = "";
    int numberOfSingleSign = 1;

    for (int positionOfSign = 0; positionOfSign < userDataWithVerticalLines.length(); positionOfSign++)
    {
        if (userDataWithVerticalLines[positionOfSign] != '|')
        {
            singleUserData += userDataWithVerticalLines[positionOfSign];
        }
        else
        {
            switch(numberOfSingleSign)
            {
            case 1:
                user.setUserId(atoi(singleUserData.c_str()));
                break;
            case 2:
                user.setUserLogin(singleUserData);
                break;
            case 3:
                user.setPassword(singleUserData);
                break;
            }
            singleUserData = "";
            numberOfSingleSign++;
        }
    }
    return user;


}
