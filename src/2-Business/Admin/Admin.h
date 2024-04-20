#pragma once
#include <string>
#include <vector>
#include "../Person.h"
#include "../../../include/libs/Data_Manip/DataManip_helpers.h"


using std::string;
using std::vector;

struct AdminInfos
{
    string name;
    string username;
    string email;
    string phone;
    string password;
    short permissions;
};
AdminInfos __CurrentAdmin__;
class Admin : protected Person
{
private:
    string _username;
    string _password;
    short _permissions;
    static AdminInfos convertRecordToInfos(string adminRecord);
    static string convertInfosToRecord(AdminInfos adminInfos);
    static vector<AdminInfos> formatAdminsData(vector<string> Data);
    static vector<AdminInfos> loadAdminsInfo();
public:

    Admin(AdminInfos infos);
    AdminInfos getInfos();
    bool save();
    static bool isExist(string username);
    static bool login(string username,string password);

};

#include "Admin.cpp"
